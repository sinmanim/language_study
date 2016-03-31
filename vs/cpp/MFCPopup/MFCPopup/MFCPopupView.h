
// MFCPopupView.h : CMFCPopupView Ŭ������ �������̽�
//

#pragma once


class CMFCPopupView : public CView
{
protected: // serialization������ ��������ϴ�.
	CMFCPopupView();
	DECLARE_DYNCREATE(CMFCPopupView)

// Ư���Դϴ�.
public:
	CMFCPopupDoc* GetDocument() const;

// �۾��Դϴ�.
public:

// �������Դϴ�.
public:
	virtual void OnDraw(CDC* pDC);  // �� �並 �׸��� ���� �����ǵǾ����ϴ�.
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
	virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);

// �����Դϴ�.
public:
	virtual ~CMFCPopupView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// ������ �޽��� �� �Լ�
protected:
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // MFCPopupView.cpp�� ����� ����
inline CMFCPopupDoc* CMFCPopupView::GetDocument() const
   { return reinterpret_cast<CMFCPopupDoc*>(m_pDocument); }
#endif

