#include "stdafx.h"
#include "database.h"

database::database()
{
}


database::~database()
{
}

void database::init()
{
	//loadDatabase(L"database.txt");
	_isStart = false;
}

void database::release()
{

}


//void database::loadDatabase(wstring name)
//{
//	arrElements vTemp;
//	vTemp = TXTDATA->txtLoad(name.c_str());
//
//	wstring str;
//	int count = 0;
//
//	for (int i = 0; i < vTemp.size(); i++)
//	{
//		if (vTemp[i] == L"|")
//		{
//			elements* em = new elements;
//			str = vTemp[i + 1];
//
//			_mTotalElement.insert(pair<wstring, elements*>(vTemp[i + 1], em));
//
//			if (i != 0) count += 1;
//			continue;
//		}
//
//		iterElement mIter = _mTotalElement.find(str);
//
//		//mIter->second->character = (CHARACTER)_wtoi(vTemp[0].c_str());
//	}
//
//	vTemp.clear();
//}


//¼³Á¤ÀÚ
void database::setElementCharactor(wstring str, int charactor)
{
	iterElement mIter = _mTotalElement.find(str);
}