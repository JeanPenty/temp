// MainDlg.h : interface of the CMainDlg class
//
/////////////////////////////////////////////////////////////////////////////
#pragma once

#include "DialogTopLeft.h"
#include "DialogTopRight.h"
#include "DialogBottomLeft.h"
#include "DialogBottomRight.h"

#include "IDialogCallBack.h"

#include <helper/SMenu.h>
#include "MenuWrapper.h"

class CMainDlg : public SHostWnd
	, public IDialogCallback
{
public:
	enum ChildMaxState
	{
		MAX_NULL = 0,
		MAX_TOPLEFT,
		MAX_TOPRIGHT,
		MAX_BOTTOMLEFT,
		MAX_BOTTOMRIGHT,
	};
public:
	CMainDlg();
	~CMainDlg();

	void OnClose();
	void OnMaximize();
	void OnRestore();
	void OnMinimize();
	void OnSize(UINT nType, CSize size);
	//托盘通知消息处理函数
	//LRESULT OnIconNotify(UINT uMsg, WPARAM wParam, LPARAM lParam, BOOL/* bHandled*/);
	//演示如何响应菜单事件
	void OnCommand(UINT uNotifyCode, int nID, HWND wndCtl);
	int OnCreate(LPCREATESTRUCT lpCreateStruct);
	BOOL OnInitDialog(HWND wndFocus, LPARAM lInitParam);

	void OnLButtonDown(UINT nFlags, CPoint pt);
	void OnMouseMove(UINT nFlags, SOUI::CPoint point);

	void OnBnClickFile();
	void OnBnClickEdit();
	void OnBnClickView();
	void OnBnClickDialog();
	void OnBnClickHelp();

	void InitChildDialogPos();

public:
	virtual void TopLeftDialogMax();
	virtual void TopLeftDialogRestore();

	virtual void TopRightDialogMax();
	virtual void TopRightDialogRestore();

	virtual void BottomLeftDialogMax();
	virtual void BottomLeftDialogRestore();

	virtual void BottomRightDialogMax();
	virtual void BottomRightDialogRestore();
protected:
	//soui消息
	EVENT_MAP_BEGIN()
		EVENT_NAME_COMMAND(L"btn_close", OnClose)
		EVENT_NAME_COMMAND(L"btn_min", OnMinimize)
		EVENT_NAME_COMMAND(L"btn_max", OnMaximize)
		EVENT_NAME_COMMAND(L"btn_restore", OnRestore)

		EVENT_NAME_COMMAND(L"btn_file", OnBnClickFile)
		EVENT_NAME_COMMAND(L"btn_edit", OnBnClickEdit)
		EVENT_NAME_COMMAND(L"btn_view", OnBnClickView)
		EVENT_NAME_COMMAND(L"btn_dialog", OnBnClickDialog)
		EVENT_NAME_COMMAND(L"btn_help", OnBnClickHelp)
	EVENT_MAP_END()
		
	//HostWnd真实窗口消息处理
	BEGIN_MSG_MAP_EX(CMainDlg)
		MSG_WM_CREATE(OnCreate)
		MSG_WM_INITDIALOG(OnInitDialog)
		MSG_WM_MOUSEMOVE(OnMouseMove)
		MSG_WM_CLOSE(OnClose)
		MSG_WM_SIZE(OnSize)
		MSG_WM_LBUTTONDOWN(OnLButtonDown)

	//托盘消息处理
		//MESSAGE_HANDLER(WM_ICONNOTIFY, OnIconNotify)
		MSG_WM_COMMAND(OnCommand)
		CHAIN_MSG_MAP(SHostWnd)
		REFLECT_NOTIFICATIONS_EX()
	END_MSG_MAP()
private:
	BOOL			m_bLayoutInited;	

	SStringW		m_sstrSelectCapIndex;

	CDialogTopLeft*		m_pTLDlg;
	CDialogTopRight*	m_pTRDlg;
	CDialogBottomLeft*	m_pBLDlg;
	CDialogBottomRight*	m_pBRDlg;

	ChildMaxState		m_enChildMax;
};
