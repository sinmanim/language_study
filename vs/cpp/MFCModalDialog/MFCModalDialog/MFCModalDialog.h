
// MFCModalDialog.h : PROJECT_NAME ���� ���α׷��� ���� �� ��� �����Դϴ�.
//

#pragma once

#ifndef __AFXWIN_H__
	#error "PCH�� ���� �� ������ �����ϱ� ���� 'stdafx.h'�� �����մϴ�."
#endif

#include "resource.h"		// �� ��ȣ�Դϴ�.


// CMFCModalDialogApp:
// �� Ŭ������ ������ ���ؼ��� MFCModalDialog.cpp�� �����Ͻʽÿ�.
//

class CMFCModalDialogApp : public CWinApp
{
public:
	CMFCModalDialogApp();

// �������Դϴ�.
public:
	virtual BOOL InitInstance();

// �����Դϴ�.

	DECLARE_MESSAGE_MAP()
};

extern CMFCModalDialogApp theApp;