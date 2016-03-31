
// MFCPopupView.cpp : CMFCPopupView Ŭ������ ����
//

#include "stdafx.h"
// SHARED_HANDLERS�� �̸� ����, ����� �׸� �� �˻� ���� ó���⸦ �����ϴ� ATL ������Ʈ���� ������ �� ������
// �ش� ������Ʈ�� ���� �ڵ带 �����ϵ��� �� �ݴϴ�.
#ifndef SHARED_HANDLERS
#include "MFCPopup.h"
#endif

#include "MFCPopupDoc.h"
#include "MFCPopupView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMFCPopupView

IMPLEMENT_DYNCREATE(CMFCPopupView, CView)

BEGIN_MESSAGE_MAP(CMFCPopupView, CView)
	// ǥ�� �μ� ����Դϴ�.
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
END_MESSAGE_MAP()

// CMFCPopupView ����/�Ҹ�

CMFCPopupView::CMFCPopupView()
{
	// TODO: ���⿡ ���� �ڵ带 �߰��մϴ�.

}

CMFCPopupView::~CMFCPopupView()
{
}

BOOL CMFCPopupView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: CREATESTRUCT cs�� �����Ͽ� ���⿡��
	//  Window Ŭ���� �Ǵ� ��Ÿ���� �����մϴ�.

	return CView::PreCreateWindow(cs);
}

// CMFCPopupView �׸���

void CMFCPopupView::OnDraw(CDC* /*pDC*/)
{
	CMFCPopupDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: ���⿡ ���� �����Ϳ� ���� �׸��� �ڵ带 �߰��մϴ�.
}


// CMFCPopupView �μ�

BOOL CMFCPopupView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// �⺻���� �غ�
	return DoPreparePrinting(pInfo);
}

void CMFCPopupView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: �μ��ϱ� ���� �߰� �ʱ�ȭ �۾��� �߰��մϴ�.
}

void CMFCPopupView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: �μ� �� ���� �۾��� �߰��մϴ�.
}


// CMFCPopupView ����

#ifdef _DEBUG
void CMFCPopupView::AssertValid() const
{
	CView::AssertValid();
}

void CMFCPopupView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CMFCPopupDoc* CMFCPopupView::GetDocument() const // ����׵��� ���� ������ �ζ������� �����˴ϴ�.
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMFCPopupDoc)));
	return (CMFCPopupDoc*)m_pDocument;
}
#endif //_DEBUG


// CMFCPopupView �޽��� ó����
