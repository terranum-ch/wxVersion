/*
 * DO NOT ALTER OR REMOVE COPYRIGHT NOTICES OR THIS HEADER.
 *
 * The contents of this file are subject to the terms of the
 * Common Development and Distribution License (the "License").
 * You may not use this file except in compliance with the License.
 *
 * You can read the License at http://opensource.org/licenses/CDDL-1.0
 * See the License for the specific language governing permissions
 * and limitations under the License.
 * 
 * When distributing Covered Code, include this CDDL Header Notice in 
 * each file and include the License file (licence.txt). If applicable, 
 * add the following below this CDDL Header, with the fields enclosed
 * by brackets [] replaced by your own identifying information:
 * "Portions Copyright [year] [name of copyright owner]"
 * 
 * The Original Software is wxhgversion. The Initial Developer of the 
 * Original Software is Lucien Schreiber from CREALP. 
 * All Rights Reserved.
 * 
 */

/*
 * Portions Copyright 2013 Lucien Schreiber, CREALP.
 */

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

