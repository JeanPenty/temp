#include "StdAfx.h"
#include "DialogTopLeft.h"

CDialogTopLeft::CDialogTopLeft(IDialogCallback* pCB)
: SHostWnd(UIRES.LAYOUT.XML_DLG_TOPLEFT)
, m_pCB(pCB)
{
}

CDialogTopLeft::~CDialogTopLeft(void)
{
}


BOOL CDialogTopLeft::OnInitDialog(HWND wndFocus, LPARAM lInitParam)
{
	SetMsgHandled(FALSE);

	return FALSE;
}

void CDialogTopLeft::OnMaximize()
{
	//֪ͨ�����ڸô������
	m_pCB->TopLeftDialogMax();

	SWindow *pBtnMax = FindChildByName(L"btn_max");
	SWindow *pBtnRestore = FindChildByName(L"btn_restore");
	pBtnRestore->SetVisible(TRUE);
	pBtnMax->SetVisible(FALSE);
}
void CDialogTopLeft::OnRestore()
{
	//֪ͨ�����ڸô�����󻯻ָ�
	m_pCB->TopLeftDialogRestore();

	SWindow *pBtnMax = FindChildByName(L"btn_max");
	SWindow *pBtnRestore = FindChildByName(L"btn_restore");
	pBtnRestore->SetVisible(FALSE);
	pBtnMax->SetVisible(TRUE);
}