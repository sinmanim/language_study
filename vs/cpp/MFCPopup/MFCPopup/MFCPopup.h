
// MFCPopup.h : MFCPopup ���� ���α׷��� ���� �� ��� ����
//
#pragma once

#ifndef __AFXWIN_H__
	#error "PCH�� ���� �� ������ �����ϱ� ���� 'stdafx.h'�� �����մϴ�."
#endif

#include "resource.h"       // �� ��ȣ�Դϴ�.


// CMFCPopupApp:
// �� Ŭ������ ������ ���ؼ��� MFCPopup.cpp�� �����Ͻʽÿ�.
//

class CMFCPopupApp : public CWinApp
{
public:
	CMFCPopupApp();


// �������Դϴ�.
public:
	virtual BOOL InitInstance();
	virtual int ExitInstance();

// �����Դϴ�.
	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()
};

extern CMFCPopupApp theApp;
