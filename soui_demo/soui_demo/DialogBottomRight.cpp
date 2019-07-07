#include "StdAfx.h"
#include "DialogBottomRight.h"

CDialogBottomRight::CDialogBottomRight(IDialogCallback* pCB)
: SHostWnd(UIRES.LAYOUT.XML_DLG_BOTTOMRIGHT)
, m_pCB(pCB)
{
}

CDialogBottomRight::~CDialogBottomRight(void)
{
}


BOOL CDialogBottomRight::OnInitDialog(HWND wndFocus, LPARAM lInitParam)
{
	SetMsgHandled(FALSE);

	return FALSE;
}

void CDialogBottomRight::OnMaximize()
{
	//通知主窗口该窗口最大化
	m_pCB->BottomRightDialogMax();

	SWindow *pBtnMax = FindChildByName(L"btn_max");
	SWindow *pBtnRestore = FindChildByName(L"btn_restore");
	pBtnRestore->SetVisible(TRUE);
	pBtnMax->SetVisible(FALSE);
}
void CDialogBottomRight::OnRestore()
{
	//通知主窗口该窗口最大化恢复
	m_pCB->BottomRightDialogRestore();

	SWindow *pBtnMax = FindChildByName(L"btn_max");
	SWindow *pBtnRestore = FindChildByName(L"btn_restore");
	pBtnRestore->SetVisible(FALSE);
	pBtnMax->SetVisible(TRUE);
}