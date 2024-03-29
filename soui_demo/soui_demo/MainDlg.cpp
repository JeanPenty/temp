// MainDlg.cpp : implementation of the CMainDlg class
//
/////////////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "MainDlg.h"	
	
CMainDlg::CMainDlg() : SHostWnd(_T("LAYOUT:XML_MAINWND"))
{
	m_bLayoutInited = FALSE;
	m_sstrSelectCapIndex = L"";

	m_pTLDlg = NULL;
	m_pTRDlg = NULL;
	m_pBLDlg = NULL;
	m_pBRDlg = NULL;

	m_enChildMax = MAX_NULL;
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

	if (NULL == m_pTLDlg)
	{
		m_pTLDlg = new CDialogTopLeft(this);
		m_pTLDlg->Create(this->m_hWnd, 0,0,0,0);
		m_pTLDlg->SendMessage(WM_INITDIALOG);
	}

	if (NULL == m_pTRDlg)
	{
		m_pTRDlg = new CDialogTopRight(this);
		m_pTRDlg->Create(this->m_hWnd, 0,0,0,0);
		m_pTRDlg->SendMessage(WM_INITDIALOG);
	}

	if (NULL == m_pBLDlg)
	{
		m_pBLDlg = new CDialogBottomLeft(this);
		m_pBLDlg->Create(this->m_hWnd, 0,0,0,0);
		m_pBLDlg->SendMessage(WM_INITDIALOG);
	}

	if (NULL == m_pBRDlg)
	{
		m_pBRDlg = new CDialogBottomRight(this);
		m_pBRDlg->Create(this->m_hWnd, 0,0,0,0);
		m_pBRDlg->SendMessage(WM_INITDIALOG);
	}

	//初始化四个子窗口的位置
	InitChildDialogPos();

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

	InitChildDialogPos();
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
	return;

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

void CMainDlg::OnMouseMove(UINT nFlags, SOUI::CPoint point)
{
	SetMsgHandled(FALSE);
	InitChildDialogPos();
}

void CMainDlg::OnBnClickFile()
{
	//添加菜单
	MenuWrapper menu(L"menu_template", L"SMENU");
	int ret = 0;
    POINT pt;
    ::GetCursorPos(&pt);

	menu.AddMenu(L"新建", 0, TRUE, FALSE);
	menu.AddMenu(L"打开", 1, TRUE, FALSE);
	menu.AddSeperator();
	menu.AddMenu(L"添加", 2, TRUE, FALSE);
	menu.AddSeperator();
	menu.AddMenu(L"关闭", 3, TRUE, FALSE);
	menu.AddMenu(L"关闭解决方案", 4, TRUE, FALSE);
	menu.AddMenu(L"退出", 5, TRUE, FALSE);

	ret = menu.ShowMenu(TPM_RETURNCMD, pt.x, pt.y, m_hWnd);
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

void CMainDlg::InitChildDialogPos()
{
	//
	CRect rcWindow = GetWindowRect();
	CRect rcChild;
	rcChild.left = rcWindow.left + 1;
	rcChild.top = rcWindow.top + 100;
	rcChild.right = rcWindow.right - 1;
	rcChild.bottom = rcWindow.bottom - 30;

	CRect rcTLDialog, rcTRDialog, rcBLDialog, rcBRDialog;
	switch (m_enChildMax)
	{
	case MAX_NULL:
		{
			rcTLDialog.left = rcChild.left;
			rcTLDialog.top = rcChild.top;
			rcTLDialog.right = rcChild.left + rcChild.Width() / 2;
			rcTLDialog.bottom = rcChild.top + rcChild.Height() / 2;
			m_pTLDlg->MoveWindow(&rcTLDialog, TRUE);
			m_pTLDlg->ShowWindow(SW_SHOW);

			rcTRDialog.left = rcTLDialog.right + 1;
			rcTRDialog.top = rcTLDialog.top;
			rcTRDialog.right = rcChild.right;
			rcTRDialog.bottom = rcTLDialog.bottom;
			m_pTRDlg->MoveWindow(&rcTRDialog, TRUE);
			m_pTRDlg->ShowWindow(SW_SHOW);

			rcBLDialog.left = rcTLDialog.left;
			rcBLDialog.top = rcTLDialog.bottom + 1;
			rcBLDialog.right = rcTLDialog.right;
			rcBLDialog.bottom = rcChild.bottom;
			m_pBLDlg->MoveWindow(&rcBLDialog, TRUE);
			m_pBLDlg->ShowWindow(SW_SHOW);

			rcBRDialog.left = rcBLDialog.right + 1;
			rcBRDialog.top = rcBLDialog.top;
			rcBRDialog.right = rcChild.right;
			rcBRDialog.bottom = rcBLDialog.bottom;
			m_pBRDlg->MoveWindow(&rcBRDialog, TRUE);
			m_pBRDlg->ShowWindow(SW_SHOW);
		}
		break;
	case MAX_TOPLEFT:
		{
			m_pTRDlg->ShowWindow(SW_HIDE);
			m_pBLDlg->ShowWindow(SW_HIDE);
			m_pBRDlg->ShowWindow(SW_HIDE);
			m_pTLDlg->MoveWindow(&rcChild, TRUE);
			m_pTLDlg->ShowWindow(SW_SHOW);
		}
		break;
	case MAX_TOPRIGHT:
		{
			m_pTLDlg->ShowWindow(SW_HIDE);
			m_pBLDlg->ShowWindow(SW_HIDE);
			m_pBRDlg->ShowWindow(SW_HIDE);
			m_pTRDlg->MoveWindow(&rcChild, TRUE);
			m_pTRDlg->ShowWindow(SW_SHOW);
		}
		break;
	case MAX_BOTTOMLEFT:
		{
			m_pTLDlg->ShowWindow(SW_HIDE);
			m_pTRDlg->ShowWindow(SW_HIDE);
			m_pBRDlg->ShowWindow(SW_HIDE);
			m_pBLDlg->MoveWindow(&rcChild, TRUE);
			m_pBLDlg->ShowWindow(SW_SHOW);
		}
		break;
	case MAX_BOTTOMRIGHT:
		{
			m_pTLDlg->ShowWindow(SW_HIDE);
			m_pTRDlg->ShowWindow(SW_HIDE);
			m_pBLDlg->ShowWindow(SW_HIDE);
			m_pBRDlg->MoveWindow(&rcChild, TRUE);
			m_pBRDlg->ShowWindow(SW_SHOW);
		}
		break;
	default:
		{
			rcTLDialog.left = rcChild.left;
			rcTLDialog.top = rcChild.top;
			rcTLDialog.right = rcChild.right / 2;
			rcTLDialog.bottom = rcChild.bottom / 2;
			m_pTLDlg->MoveWindow(&rcTLDialog, TRUE);
			m_pTLDlg->ShowWindow(SW_SHOW);

			rcTRDialog.left = rcChild.left;
			rcTRDialog.top = rcChild.top;
			rcTRDialog.right = rcChild.right / 2;
			rcTRDialog.bottom = rcChild.bottom / 2;
			m_pTRDlg->MoveWindow(&rcTLDialog, TRUE);
			m_pTRDlg->ShowWindow(SW_SHOW);

			rcBLDialog.left = rcTLDialog.left;
			rcBLDialog.top = rcTLDialog.bottom + 1;
			rcBLDialog.right = rcTLDialog.right;
			rcBLDialog.bottom = rcChild.bottom;
			m_pBLDlg->MoveWindow(&rcBLDialog, TRUE);
			m_pBLDlg->ShowWindow(SW_SHOW);

			rcBRDialog.left = rcBLDialog.right + 1;
			rcBRDialog.top = rcBLDialog.top;
			rcBRDialog.right = rcChild.right;
			rcBRDialog.bottom = rcBLDialog.bottom;
			m_pBRDlg->MoveWindow(&rcBRDialog, TRUE);
			m_pBRDlg->ShowWindow(SW_SHOW);
		}
		break;
	}
}

void CMainDlg::TopLeftDialogMax()
{
	m_enChildMax = MAX_TOPLEFT;
	InitChildDialogPos();
}
void CMainDlg::TopLeftDialogRestore()
{
	m_enChildMax = MAX_NULL;
	InitChildDialogPos();
}

void CMainDlg::TopRightDialogMax()
{
	m_enChildMax = MAX_TOPRIGHT;
	InitChildDialogPos();
}
void CMainDlg::TopRightDialogRestore()
{
	m_enChildMax = MAX_NULL;
	InitChildDialogPos();
}

void CMainDlg::BottomLeftDialogMax()
{
	m_enChildMax = MAX_BOTTOMLEFT;
	InitChildDialogPos();
}
void CMainDlg::BottomLeftDialogRestore()
{
	m_enChildMax = MAX_NULL;
	InitChildDialogPos();
}

void CMainDlg::BottomRightDialogMax()
{
	m_enChildMax = MAX_BOTTOMRIGHT;
	InitChildDialogPos();
}
void CMainDlg::BottomRightDialogRestore()
{
	m_enChildMax = MAX_NULL;
	InitChildDialogPos();
}