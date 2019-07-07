#include "StdAfx.h"
#include "DialogTopRight.h"

CDialogTopRight::CDialogTopRight(IDialogCallback* pCB)
: SHostWnd(UIRES.LAYOUT.XML_DLG_TOPRIGHT)
, m_pCB(pCB)
{
}

CDialogTopRight::~CDialogTopRight(void)
{
}


BOOL CDialogTopRight::OnInitDialog(HWND wndFocus, LPARAM lInitParam)
{
	SetMsgHandled(FALSE);

	return FALSE;
}

void CDialogTopRight::OnMaximize()
{
	//通知主窗口该窗口最大化
	m_pCB->TopRightDialogMax();

	SWindow *pBtnMax = FindChildByName(L"btn_max");
	SWindow *pBtnRestore = FindChildByName(L"btn_restore");
	pBtnRestore->SetVisible(TRUE);
	pBtnMax->SetVisible(FALSE);
}
void CDialogTopRight::OnRestore()
{
	//通知主窗口该窗口最大化恢复
	m_pCB->TopRightDialogRestore();

	SWindow *pBtnMax = FindChildByName(L"btn_max");
	SWindow *pBtnRestore = FindChildByName(L"btn_restore");
	pBtnRestore->SetVisible(FALSE);
	pBtnMax->SetVisible(TRUE);
}