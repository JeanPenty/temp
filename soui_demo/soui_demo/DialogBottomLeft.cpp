#include "StdAfx.h"
#include "DialogBottomLeft.h"

CDialogBottomLeft::CDialogBottomLeft(IDialogCallback* pCB)
: SHostWnd(UIRES.LAYOUT.XML_DLG_BOTTOMLEFT)
, m_pCB(pCB)
{
}

CDialogBottomLeft::~CDialogBottomLeft(void)
{
}


BOOL CDialogBottomLeft::OnInitDialog(HWND wndFocus, LPARAM lInitParam)
{
	SetMsgHandled(FALSE);

	return FALSE;
}

void CDialogBottomLeft::OnMaximize()
{
	//通知主窗口该窗口最大化
	m_pCB->BottomLeftDialogMax();

	SWindow *pBtnMax = FindChildByName(L"btn_max");
	SWindow *pBtnRestore = FindChildByName(L"btn_restore");
	pBtnRestore->SetVisible(TRUE);
	pBtnMax->SetVisible(FALSE);
}
void CDialogBottomLeft::OnRestore()
{
	//通知主窗口该窗口最大化恢复
	m_pCB->BottomLeftDialogRestore();

	SWindow *pBtnMax = FindChildByName(L"btn_max");
	SWindow *pBtnRestore = FindChildByName(L"btn_restore");
	pBtnRestore->SetVisible(FALSE);
	pBtnMax->SetVisible(TRUE);
}