
// GestureTest.h : PROJECT_NAME Ӧ�ó������ͷ�ļ�
//

#pragma once

#ifndef __AFXWIN_H__
	#error "�ڰ������ļ�֮ǰ������stdafx.h�������� PCH �ļ�"
#endif

#include "resource.h"		// ������


// CGestureTestApp:
// �йش����ʵ�֣������ GestureTest.cpp
//

class CGestureTestApp : public CWinApp
{
public:
	CGestureTestApp();

// ��д
public:
	virtual BOOL InitInstance();

// ʵ��

	DECLARE_MESSAGE_MAP()
};

extern CGestureTestApp theApp;