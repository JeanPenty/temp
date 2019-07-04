// MainDlg.cpp : implementation of the CMainDlg class
//
/////////////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "MainDlg.h"	
	
CMainDlg::CMainDlg() : SHostWnd(_T("LAYOUT:XML_MAINWND"))
{
	m_bLayoutInited = FALSE;

	m_sstrSelectCapIndex = L"";
}

CMainDlg::~CMainDlg()
{
}

int CMainDlg::OnCreate(LPCREATESTRUCT lpCreateStruct)
{
	SetMsgHandled(FALSE);
	return 0;
}

BOOL CMainDlg::OnInitDialog(HWND hWnd, LPARAM lParam)
{
	m_bLayoutInited = TRUE;
	//SShellNotifyIcon *notify = FindChildByID2<SShellNotifyIcon>(110);
	//notify->ShowNotify(L"Hello SOUI",L"这可能是一个提示");
	return 0;
}
//TODO:消息映射
void CMainDlg::OnClose()
{
	CSimpleWnd::DestroyWindow();
}

void CMainDlg::OnMaximize()
{
	SendMessage(WM_SYSCOMMAND, SC_MAXIMIZE);
}
void CMainDlg::OnRestore()
{
	SendMessage(WM_SYSCOMMAND, SC_RESTORE);
}
void CMainDlg::OnMinimize()
{
	SendMessage(WM_SYSCOMMAND, SC_MINIMIZE);
}

void CMainDlg::OnSize(UINT nType, CSize size)
{
	SetMsgHandled(FALSE);
	if (!m_bLayoutInited) return;
	
	SWindow *pBtnMax = FindChildByName(L"btn_max");
	SWindow *pBtnRestore = FindChildByName(L"btn_restore");
	if(!pBtnMax || !pBtnRestore) return;
	
	if (nType == SIZE_MAXIMIZED)
	{
		pBtnRestore->SetVisible(TRUE);
		pBtnMax->SetVisible(FALSE);
	}
	else if (nType == SIZE_RESTORED)
	{
		pBtnRestore->SetVisible(FALSE);
		pBtnMax->SetVisible(TRUE);
	}
}


//演示如何响应菜单事件
void CMainDlg::OnCommand(UINT uNotifyCode, int nID, HWND wndCtl)
{
	if (uNotifyCode == 0)
	{
		switch (nID)
		{
		case 6:
			PostMessage(WM_CLOSE);
			break;
		default:
			break;
		}
	}
}


void CMainDlg::OnLButtonDown(UINT nFlags, CPoint pt)
{
	SetMsgHandled(FALSE);

	SCaption* pCap1 = FindChildByName2<SCaption>(L"cap_1");
	SCaption* pCap2 = FindChildByName2<SCaption>(L"cap_2");
	SCaption* pCap3 = FindChildByName2<SCaption>(L"cap_3");
	SCaption* pCap4 = FindChildByName2<SCaption>(L"cap_4");
	SASSERT(pCap1);
	SASSERT(pCap2);
	SASSERT(pCap3);
	SASSERT(pCap4);

	SOUI::CRect rcCap1 = pCap1->GetWindowRect();
	SOUI::CRect rcCap2 = pCap2->GetWindowRect();
	SOUI::CRect rcCap3 = pCap3->GetWindowRect();
	SOUI::CRect rcCap4 = pCap4->GetWindowRect();

	if (PtInRect(&rcCap1, pt))
		m_sstrSelectCapIndex = L"Caption1";
	else if (PtInRect(&rcCap2, pt))
		m_sstrSelectCapIndex = L"Caption2";
	else if (PtInRect(&rcCap3, pt))
		m_sstrSelectCapIndex = L"Caption3";
	else if (PtInRect(&rcCap4, pt))
		m_sstrSelectCapIndex = L"Caption4";
	
	SStatic* pSelectCap = FindChildByName2<SStatic>(L"select_cap");
	SASSERT(pSelectCap);
	pSelectCap->SetWindowTextW(m_sstrSelectCapIndex);
}

void CMainDlg::OnBnClickFile()
{
	//添加菜单
}

void CMainDlg::OnBnClickEdit()
{
	//添加菜单
}

void CMainDlg::OnBnClickView()
{
	//添加菜单
}

void CMainDlg::OnBnClickDialog()
{
	//添加菜单
}

void CMainDlg::OnBnClickHelp()
{
	//添加菜单
}