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
	//֪ͨ�����ڸô������
	m_pCB->BottomLeftDialogMax();

	SWindow *pBtnMax = FindChildByName(L"btn_max");
	SWindow *pBtnRestore = FindChildByName(L"btn_restore");
	pBtnRestore->SetVisible(TRUE);
	pBtnMax->SetVisible(FALSE);
}
void CDialogBottomLeft::OnRestore()
{
	//֪ͨ�����ڸô�����󻯻ָ�
	m_pCB->BottomLeftDialogRestore();

	SWindow *pBtnMax = FindChildByName(L"btn_max");
	SWindow *pBtnRestore = FindChildByName(L"btn_restore");
	pBtnRestore->SetVisible(FALSE);
	pBtnMax->SetVisible(TRUE);
}