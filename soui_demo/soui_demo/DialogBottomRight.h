#pragma once

#include "IDialogCallBack.h"

class CDialogBottomRight : public SHostWnd
{
public:
	CDialogBottomRight(IDialogCallback* pCB);
	~CDialogBottomRight(void);

protected:
	BOOL OnInitDialog(HWND wndFocus, LPARAM lInitParam);

	void OnMaximize();
	void OnRestore();
protected:
	EVENT_MAP_BEGIN()
		EVENT_NAME_COMMAND(L"btn_max", OnMaximize)
		EVENT_NAME_COMMAND(L"btn_restore", OnRestore)
	EVENT_MAP_END()

	BEGIN_MSG_MAP_EX(CDialogBottomRight)
		MSG_WM_INITDIALOG(OnInitDialog)

		CHAIN_MSG_MAP(SHostWnd)
		REFLECT_NOTIFICATIONS_EX()
	END_MSG_MAP()

private:
	IDialogCallback*	m_pCB;
};