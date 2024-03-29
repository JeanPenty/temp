//stamp:125408aa840aa1bd
/*<------------------------------------------------------------------------------------------------->*/
/*该文件由uiresbuilder生成，请不要手动修改*/
/*<------------------------------------------------------------------------------------------------->*/
#pragma once
#include <res.mgr/snamedvalue.h>
#define ROBJ_IN_CPP \
namespace SOUI \
{\
    const _R R;\
    const _UIRES UIRES;\
}
namespace SOUI
{
	class _UIRES{
		public:
		class _UIDEF{
			public:
			_UIDEF(){
				XML_INIT = _T("UIDEF:XML_INIT");
			}
			const TCHAR * XML_INIT;
		}UIDEF;
		class _LAYOUT{
			public:
			_LAYOUT(){
				XML_MAINWND = _T("LAYOUT:XML_MAINWND");
				XML_DLG_TOPLEFT = _T("LAYOUT:XML_DLG_TOPLEFT");
				XML_DLG_TOPRIGHT = _T("LAYOUT:XML_DLG_TOPRIGHT");
				XML_DLG_BOTTOMLEFT = _T("LAYOUT:XML_DLG_BOTTOMLEFT");
				XML_DLG_BOTTOMRIGHT = _T("LAYOUT:XML_DLG_BOTTOMRIGHT");
			}
			const TCHAR * XML_MAINWND;
			const TCHAR * XML_DLG_TOPLEFT;
			const TCHAR * XML_DLG_TOPRIGHT;
			const TCHAR * XML_DLG_BOTTOMLEFT;
			const TCHAR * XML_DLG_BOTTOMRIGHT;
		}LAYOUT;
		class _values{
			public:
			_values(){
				string = _T("values:string");
				color = _T("values:color");
				skin = _T("values:skin");
			}
			const TCHAR * string;
			const TCHAR * color;
			const TCHAR * skin;
		}values;
		class _IMG{
			public:
			_IMG(){
				traymenu_icons = _T("IMG:traymenu_icons");
			}
			const TCHAR * traymenu_icons;
		}IMG;
		class _ICON{
			public:
			_ICON(){
				ICON_LOGO = _T("ICON:ICON_LOGO");
			}
			const TCHAR * ICON_LOGO;
		}ICON;
		class _SMENU{
			public:
			_SMENU(){
				menu_tray = _T("SMENU:menu_tray");
				menu_template = _T("SMENU:menu_template");
			}
			const TCHAR * menu_tray;
			const TCHAR * menu_template;
		}SMENU;
	};
	const SNamedID::NAMEDVALUE namedXmlID[]={
		{L"_name_start",65535},
		{L"btn_build",65545},
		{L"btn_close",65537},
		{L"btn_debug",65546},
		{L"btn_dialog",65547},
		{L"btn_edit",65542},
		{L"btn_file",65541},
		{L"btn_help",65548},
		{L"btn_max",65538},
		{L"btn_min",65540},
		{L"btn_project",65544},
		{L"btn_restore",65539},
		{L"btn_view",65543},
		{L"main_title",65536},
		{L"select_cap",65549}		};
	class _R{
	public:
		class _name{
		public:
		_name(){
			_name_start = namedXmlID[0].strName;
			btn_build = namedXmlID[1].strName;
			btn_close = namedXmlID[2].strName;
			btn_debug = namedXmlID[3].strName;
			btn_dialog = namedXmlID[4].strName;
			btn_edit = namedXmlID[5].strName;
			btn_file = namedXmlID[6].strName;
			btn_help = namedXmlID[7].strName;
			btn_max = namedXmlID[8].strName;
			btn_min = namedXmlID[9].strName;
			btn_project = namedXmlID[10].strName;
			btn_restore = namedXmlID[11].strName;
			btn_view = namedXmlID[12].strName;
			main_title = namedXmlID[13].strName;
			select_cap = namedXmlID[14].strName;
		}
		 const wchar_t * _name_start;
		 const wchar_t * btn_build;
		 const wchar_t * btn_close;
		 const wchar_t * btn_debug;
		 const wchar_t * btn_dialog;
		 const wchar_t * btn_edit;
		 const wchar_t * btn_file;
		 const wchar_t * btn_help;
		 const wchar_t * btn_max;
		 const wchar_t * btn_min;
		 const wchar_t * btn_project;
		 const wchar_t * btn_restore;
		 const wchar_t * btn_view;
		 const wchar_t * main_title;
		 const wchar_t * select_cap;
		}name;

		class _id{
		public:
		const static int _name_start	=	65535;
		const static int btn_build	=	65545;
		const static int btn_close	=	65537;
		const static int btn_debug	=	65546;
		const static int btn_dialog	=	65547;
		const static int btn_edit	=	65542;
		const static int btn_file	=	65541;
		const static int btn_help	=	65548;
		const static int btn_max	=	65538;
		const static int btn_min	=	65540;
		const static int btn_project	=	65544;
		const static int btn_restore	=	65539;
		const static int btn_view	=	65543;
		const static int main_title	=	65536;
		const static int select_cap	=	65549;
		}id;

		class _string{
		public:
		const static int title	=	0;
		const static int ver	=	1;
		}string;

		class _color{
		public:
		const static int blue	=	0;
		const static int gray	=	1;
		const static int green	=	2;
		const static int red	=	3;
		const static int white	=	4;
		}color;

	};

#ifdef R_IN_CPP
	 extern const _R R;
	 extern const _UIRES UIRES;
#else
	 extern const __declspec(selectany) _R & R = _R();
	 extern const __declspec(selectany) _UIRES & UIRES = _UIRES();
#endif//R_IN_CPP
}
