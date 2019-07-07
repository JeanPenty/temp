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
	//֪ͨ�����ڸô������
	m_pCB->BottomRightDialogMax();

	SWindow *pBtnMax = FindChildByName(L"btn_max");
	SWindow *pBtnRestore = FindChildByName(L"btn_restore");
	pBtnRestore->SetVisible(TRUE);
	pBtnMax->SetVisible(FALSE);
}
void CDialogBottomRight::OnRestore()
{
	//֪ͨ�����ڸô�����󻯻ָ�
	m_pCB->BottomRightDialogRestore();

	SWindow *pBtnMax = FindChildByName(L"btn_max");
	SWindow *pBtnRestore = FindChildByName(L"btn_restore");
	pBtnRestore->SetVisible(FALSE);
	pBtnMax->SetVisible(TRUE);
}