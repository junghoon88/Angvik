#include "stdafx.h"
#include "DxWindow.h"
#include "mainGame.h"

LRESULT CALLBACK WndProc(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam);

//DxWindow
DxWindow* DxWindow::dxWindow = NULL;

//객체 생성자
DxWindow::DxWindow(HINSTANCE hInstance, LPCWSTR lpClassName, LPCSTR lpszCmdParam, int nCmdShow)
{
	dxWindow = this;

	commandShow = nCmdShow;
	instance = hInstance;
	handle = NULL;

	srand(time(NULL));

	if (lpClassName != NULL)
	{
		int length = wcslen(lpClassName) + 1;

		className = new WCHAR[length];
		wcscpy_s(className, length, lpClassName);
	}
	else
	{
		className = NULL;
	}

	if (lpszCmdParam != NULL)
	{
		int length = strlen(lpszCmdParam) + 1;

		commandLine = new char[length];
		strcpy_s(commandLine, length, lpszCmdParam);
	}
	else
	{
		commandLine = NULL;
	}
}

//객체 소멸자
DxWindow::~DxWindow()
{
	SAFE_RELEASE(device);
	SAFE_RELEASE(d3d);

	if (handle != NULL)	
		DestroyWindow(handle);

	SAFE_DELETE_ARRAY(className);
	SAFE_DELETE_ARRAY(commandLine);
}


void DxWindow::Create(LPCWSTR title)
{
	WNDCLASS wndClass;

	wndClass.cbClsExtra = NULL;
	wndClass.cbWndExtra = NULL;
	wndClass.hbrBackground = (HBRUSH)GetStockObject(WHITE_BRUSH);
	wndClass.hCursor = LoadCursor(NULL, IDC_ARROW);
	wndClass.hIcon = LoadIcon(NULL, IDI_APPLICATION);
	wndClass.hInstance = instance;
	wndClass.lpfnWndProc = WndProc;
	wndClass.lpszClassName = className;
	wndClass.lpszMenuName = NULL;
	wndClass.style = CS_HREDRAW | CS_VREDRAW | CS_DBLCLKS;

	ATOM result = RegisterClass(&wndClass);
	assert(result != 0);

	RECT rect;
	SetRect(&rect, 0, 0, winSize.x, winSize.y);
	AdjustWindowRect(&rect, winStyle, FALSE);

	int sysWidth = GetSystemMetrics(SM_CXSCREEN);
	int sysHeight = GetSystemMetrics(SM_CYSCREEN);

	handle = CreateWindow
	(
		className
		, title
		, winStyle
		, (sysWidth - (rect.right - rect.left)) / 2
		, (sysHeight - (rect.bottom - rect.top)) / 2
		, (rect.right - rect.left)
		, (rect.bottom - rect.top)
		, NULL
		, NULL
		, instance
		, NULL
	);
	assert(handle != NULL);
}

void DxWindow::CreateDevice(void)
{
	D3DPRESENT_PARAMETERS d3dParam;
	ZeroMemory(&d3dParam, sizeof(d3dParam));

	d3dParam.Windowed = isWindow;
	d3dParam.SwapEffect = D3DSWAPEFFECT_DISCARD; //플립시 백버퍼에 영향을 주지 않는다.
	d3dParam.EnableAutoDepthStencil = TRUE; //깊이 스텐실 버퍼 자동 생성
	d3dParam.AutoDepthStencilFormat = D3DFMT_D16; //버퍼 포멧

	d3d = Direct3DCreate9(D3D_SDK_VERSION);
	assert(d3d != NULL);

	D3DCAPS9 caps;
	d3d->GetDeviceCaps(D3DADAPTER_DEFAULT, D3DDEVTYPE_HAL, &caps);

	HRESULT hr = d3d->CreateDevice
	(
		D3DADAPTER_DEFAULT, //디폴트 모니터 선택
		D3DDEVTYPE_HAL, //소프트웨어와 하드웨어 동시 랜더링 사용
		handle, //윈도우 핸들
		D3DCREATE_HARDWARE_VERTEXPROCESSING, //버텍스 정보를 하드웨어로 처리
		&d3dParam, &device
	);
	assert(SUCCEEDED(hr));

	ShowWindow(handle, SW_SHOW); //윈도우 보여주기
	UpdateWindow(handle); //윈도우 갱신
	ShowCursor(isShowCursor); //커서 설정
}

WPARAM DxWindow::Run(void)
{
	MSG message;
	ZeroMemory(&message, sizeof(message));

	//PrintText::GetInstance()->SetDevice(device);

	init();

	while (message.message != WM_QUIT)
	{
		if (PeekMessage(&message, NULL, 0, 0, PM_REMOVE))
		{
			TranslateMessage(&message);
			DispatchMessage(&message);
		}
		else
		{
			//Keyboard::GetInstance()->update();

			update();

			device->Clear(0, NULL, D3DCLEAR_TARGET | D3DCLEAR_ZBUFFER, 0xFFFFFFFF, 1.0f, 0);
			device->BeginScene();

			render();
			//PrintText::GetInstance()->render();

			device->EndScene();
			device->Present(0, 0, 0, 0);
		}
	}

	release();

	//PrintText::DeleteInstance();
	//Keyboard::DeleteInstance();

	UnregisterClass(className, instance);
	return message.wParam;
}

LRESULT DxWindow::MessageLoop(HWND hwnd, UINT message, WPARAM wParam, LPARAM lParam)
{
	switch (message)
	{
		case WM_KEYDOWN:
		{
			if (wParam == VK_ESCAPE)
			{
				SendMessage(hwnd, WM_DESTROY, 0, 0);
				break;
			}

			return 0;
		}

		case WM_DESTROY:
		{
			PostQuitMessage(0);
			return 0;
		}
	}

	return DefWindowProc(hwnd, message, wParam, lParam);
}


//Window
LRESULT CALLBACK WndProc(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam)
{
	return DxWindow::GetDxWindow()->MessageLoop(hWnd, uMsg, wParam, lParam);
}


int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpszCmdParam, int nCmdShow)
{
	mainGame main(hInstance, L"DxClass", lpszCmdParam, nCmdShow);
	main.Create(L"DirectX");
	main.CreateDevice();

	return main.Run();
}
