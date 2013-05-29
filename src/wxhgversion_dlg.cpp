/***************************************************************************
				lsversion_dlg.cpp
                    
                             -------------------
    copyright            : (C) 2010 CREALP Lucien Schreiber 
    email                : lucien.schreiber at crealp dot vs dot ch
 ***************************************************************************/

/***************************************************************************
 *                                                                         *
 *   This program is free software; you can redistribute it and/or modify  *
 *   it under the terms of the GNU General Public License as published by  *
 *   the Free Software Foundation; either version 2 of the License, or     *
 *   (at your option) any later version.                                   *
 *                                                                         *
 ***************************************************************************/

#include "wxhgversion_dlg.h"
#include "wxhgversion_core.h"

wxHgVersionDlg::wxHgVersionDlg(wxWindow * parent, wxWindowID id,
						   const wxString & title, const wxPoint & pos,
						   const wxSize & size, long style) :
wxDialog(parent, id, title, pos, size,style) {
	_CreateControls();

	SetTitleAndCaption(wxHgVersion::GetSoftName());
	wxString myName = wxString::Format(_("version %s (%s)"),
                                       wxHgVersion::GetSoftNumber(),
                                       wxHgVersion::GetSoftVersion());
	SetSoftName(myName);
	SetModulesName(wxHgVersion::GetAllModuleInfo());
	wxString myCopy = wxString::Format("\u00A9 Lucien Schreiber, %d",
									   wxDateTime::Now().GetYear());
	SetCopyright(myCopy);
}



wxHgVersionDlg::~wxHgVersionDlg() {
}



void wxHgVersionDlg::SetBitmapLogo(const wxBitmap & bmp) {
	m_BmpCtrl->SetBitmap(bmp);
}



void wxHgVersionDlg::SetTitleAndCaption(wxString title) {
	m_TitleCtrl->SetLabel(title);
	this->SetTitle(title);
}



void wxHgVersionDlg::SetSoftName(wxString name) {
	m_ProgNameCtrl->SetLabel(name);
}



void wxHgVersionDlg::SetModulesName(wxString name) {
	m_ModulesCtrl->SetValue(name);
}



void wxHgVersionDlg::SetCopyright(wxString name) {
	m_CopyRightCtrl->SetLabel(name);
}



void wxHgVersionDlg::_CreateControls(){
	this->SetSizeHints( wxDefaultSize, wxDefaultSize );
	this->SetFont(wxNullFont);
	
	wxBoxSizer* bSizer1;
	bSizer1 = new wxBoxSizer( wxVERTICAL );
	
	m_BmpCtrl = new wxStaticBitmap( this, wxID_ANY, wxNullBitmap, wxDefaultPosition, wxDefaultSize, 0 );
	bSizer1->Add( m_BmpCtrl, 0, wxALL|wxALIGN_CENTER_HORIZONTAL, 5 );
	
	m_TitleCtrl = new wxStaticText( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	m_TitleCtrl->Wrap( -1 );
		  
	bSizer1->Add( m_TitleCtrl, 0, wxALL|wxALIGN_CENTER_HORIZONTAL, 5 );
    
	m_ProgNameCtrl = new wxStaticText( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	m_ProgNameCtrl->Wrap( -1 );
	bSizer1->Add( m_ProgNameCtrl, 0, wxALL|wxALIGN_CENTER_HORIZONTAL, 5 );
	
	m_ModulesCtrl = new wxTextCtrl( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxSize(250,150), wxTE_MULTILINE | wxTE_CENTRE );
	bSizer1->Add( m_ModulesCtrl, 1, wxALL|wxEXPAND, 5 );
	
	m_CopyRightCtrl = new wxStaticText( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	m_CopyRightCtrl->Wrap( -1 );
	bSizer1->Add( m_CopyRightCtrl, 0, wxALL|wxALIGN_CENTER_HORIZONTAL, 5 );
	
#ifdef __WXOSX__
	m_TitleCtrl->SetFont(wxNullFont);
	m_ProgNameCtrl->SetFont(wxNullFont);
	m_CopyRightCtrl->SetFont(wxNullFont);
#endif
    m_TitleCtrl->SetFont(m_TitleCtrl->GetFont().MakeBold().MakeLarger());
	
	this->SetSizer( bSizer1 );
}



int wxHgVersionDlg::ShowModal(){
	this->Layout();
	wxSizer * mySizer = this->GetSizer();
	wxASSERT(mySizer);
	mySizer->Fit(this);
	CenterOnParent(wxBOTH);
	return wxDialog::ShowModal();
}