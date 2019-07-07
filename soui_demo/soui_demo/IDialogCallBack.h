#pragma once

struct IDialogCallback
{
	virtual void TopLeftDialogMax() = 0;
	virtual void TopLeftDialogRestore() = 0;

	virtual void TopRightDialogMax() = 0;
	virtual void TopRightDialogRestore() = 0;

	virtual void BottomLeftDialogMax() = 0;
	virtual void BottomLeftDialogRestore() = 0;

	virtual void BottomRightDialogMax() = 0;
	virtual void BottomRightDialogRestore() = 0;
};