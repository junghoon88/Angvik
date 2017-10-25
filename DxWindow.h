#pragma once

class DxWindow
{
protected:
	static DxWindow* dxWindow;

	HINSTANCE instance;
	LPWSTR className;
	LPSTR commandLine;
	int commandShow;

	HWND handle;

	POINT winSize = { WINDOWSX, WINDOWSY };
	DWORD winStyle = WS_OVERLAPPEDWINDOW | WS_VISIBLE;

	BOOL isWindow = TRUE;
	BOOL isShowCursor = TRUE;

	LPDIRECT3D9	d3d = NULL;
	LPDIRECT3DDEVICE9 device = NULL;

public:
	//按眉 积己磊
	DxWindow(HINSTANCE hInstance, LPCWSTR lpClassName, LPCSTR lpszCmdParam, int nCmdShow);
	//按眉 家戈磊
	virtual ~DxWindow();

	static DxWindow* GetDxWindow() { return dxWindow; }

	void Create(LPCWSTR title);
	void CreateDevice(void);

	WPARAM Run(void);

	LRESULT MessageLoop(HWND hwnd, UINT message, WPARAM wParam, LPARAM lParam);

	virtual void init(void) = 0;
	virtual void release(void) = 0;
	virtual void update(void) = 0;
	virtual void render(void) = 0;
};