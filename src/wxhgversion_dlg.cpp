/***************************************************************************
 wxhgversion_dlg.cpp
 -------------------
 copyright            : (C) 2013  Lucien Schreiber
 email                : lucien.schreiber at gmail dot com
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
  wxString myCopy=_T("(c)");
#ifndef __LINUX__
	myCopy = _T("\u00A9"); // this lead to a crash under linux
#endif
	myCopy.Append(wxString::Format(_T(" Lucien Schreiber, %d"), wxDateTime::Now().GetYear()));
	SetCopyright(myCopy);
    m_ButtonSystemInfoCtrl->Bind(wxEVT_COMMAND_BUTTON_CLICKED, &wxHgVersionDlg::OnButtonSystemInfo, this);

}



wxHgVersionDlg::~wxHgVersionDlg() {
    m_ButtonSystemInfoCtrl->Unbind(wxEVT_COMMAND_BUTTON_CLICKED, &wxHgVersionDlg::OnButtonSystemInfo, this);
}


void wxHgVersionDlg::OnButtonSystemInfo(wxCommandEvent & event){
    wxString myCaption = wxGetOsDescription();
#ifdef __LINUX__
    myCaption.Append(_T("\n"));
    myCaption.Append(wxGetLinuxDistributionInfo().Description + _T("\n") + wxGetLinuxDistributionInfo().CodeName);
#endif
    wxMessageDialog myDlg(this, myCaption, _("System information"));
    myDlg.ShowModal();
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

	m_ProgNameCtrl = new wxStaticText( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxALIGN_CENTRE_HORIZONTAL );
	m_ProgNameCtrl->Wrap( -1 );
	bSizer1->Add( m_ProgNameCtrl, 0, wxALL|wxALIGN_CENTER_HORIZONTAL, 5 );

	m_ModulesCtrl = new wxTextCtrl( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxSize(300,180), wxTE_MULTILINE | wxTE_LEFT);
	bSizer1->Add( m_ModulesCtrl, 1, wxALL|wxEXPAND, 5 );

    wxBoxSizer* bSizer2;
	bSizer2 = new wxBoxSizer( wxHORIZONTAL );

	m_CopyRightCtrl = new wxStaticText( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	m_CopyRightCtrl->Wrap( -1 );
	bSizer2->Add( m_CopyRightCtrl, 1, wxALL|wxALIGN_LEFT | wxALIGN_CENTER_VERTICAL, 5 );

	m_ButtonSystemInfoCtrl = new wxButton( this, wxID_ANY, wxT("System info"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer2->Add( m_ButtonSystemInfoCtrl, 0, wxALL, 5 );
	bSizer1->Add( bSizer2, 0, wxEXPAND, 5 );

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
