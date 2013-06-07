/***************************************************************************
 wxhgversion_dlg.h
 -------------------
 copyright            : (C) 2013 Lucien Schreiber 
 email                : lucien.schreiber at gmail dot com
 ***************************************************************************/

#ifndef _WXHGVERSION_DLG_H
#define _WXHGVERSION_DLG_H

#include "wx/wxprec.h"
#ifndef WX_PRECOMP
#include <wx/wx.h>
#endif


class wxHgVersionDlg : public wxDialog {
	
public:
    wxHgVersionDlg(wxWindow * parent, wxWindowID id, const wxString & title,
				 const wxPoint & pos = wxDefaultPosition,
				 const wxSize & size = wxDefaultSize,
				 long style = wxDEFAULT_DIALOG_STYLE);
    virtual ~wxHgVersionDlg();
	
    void SetBitmapLogo(const wxBitmap & bmp);
    void SetTitleAndCaption(wxString title);
    void SetSoftName(wxString name);
    void SetModulesName(wxString name);
    void SetCopyright(wxString name);
	
	virtual int ShowModal();
    
private:
	wxStaticBitmap* m_BmpCtrl;
	wxStaticText* m_TitleCtrl;
	wxStaticText* m_ProgNameCtrl;
	wxTextCtrl* m_ModulesCtrl;
	wxStaticText* m_CopyRightCtrl;
    wxButton * m_ButtonSystemInfoCtrl;
	
	void _CreateControls();
    
    void OnButtonSystemInfo(wxCommandEvent & event);    
};
#endif

