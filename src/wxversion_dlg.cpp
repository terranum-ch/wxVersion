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

#include "wxversion_dlg.h"
#include "wxversion_core.h"

wxVersionDlg::wxVersionDlg(wxWindow *parent, wxWindowID id, const wxString &title, const wxPoint &pos,
                               const wxSize &size, long style)
        : wxDialog(parent, id, title, pos, size, style)
{
    _CreateControls();

    SetTitleAndCaption(wxVersion::GetSoftName());
    wxString myName = wxString::Format(_("version %s (%s)"), wxVersion::GetSoftNumber(),
                                       wxVersion::GetSoftVersion());

    SetSoftName(myName);

    SetModulesName(wxVersion::GetAllModuleInfo());
    wxString myCopy = _T("(c)");
#ifndef __LINUX__
    myCopy = _T("\u00A9"); // this lead to a crash under linux
#endif
    myCopy.Append(wxString::Format(_T(" Lucien Schreiber, %d"), wxDateTime::Now().GetYear()));
    SetCopyright(myCopy);
    m_buttonSystemInfoCtrl->Bind(wxEVT_COMMAND_BUTTON_CLICKED, &wxVersionDlg::OnButtonSystemInfo, this);

}


wxVersionDlg::~wxVersionDlg()
{
    m_buttonSystemInfoCtrl->Unbind(wxEVT_COMMAND_BUTTON_CLICKED, &wxVersionDlg::OnButtonSystemInfo, this);
}


void wxVersionDlg::OnButtonSystemInfo(wxCommandEvent &event)
{
    wxString myCaption = wxGetOsDescription();
#ifdef __LINUX__
    myCaption.Append(_T("\n"));
    myCaption.Append(wxGetLinuxDistributionInfo().Description + _T("\n") + wxGetLinuxDistributionInfo().CodeName);
#endif
    wxMessageDialog myDlg(this, myCaption, _("System information"));
    myDlg.ShowModal();
}


void wxVersionDlg::SetBitmapLogo(const wxBitmap &bmp)
{
    m_bmpCtrl->SetBitmap(bmp);
}


void wxVersionDlg::SetTitleAndCaption(wxString title)
{
    m_titleCtrl->SetLabel(title);
    this->SetTitle(title);
}


void wxVersionDlg::SetSoftName(wxString name)
{
    m_progNameCtrl->SetLabel(name);
}


void wxVersionDlg::SetModulesName(wxString name)
{
    m_modulesCtrl->SetValue(name);
}


void wxVersionDlg::SetCopyright(wxString name)
{
    m_copyRightCtrl->SetLabel(name);
}


void wxVersionDlg::_CreateControls()
{
    this->SetSizeHints(wxDefaultSize, wxDefaultSize);
    this->SetFont(wxNullFont);

    wxBoxSizer *bSizer1;
    bSizer1 = new wxBoxSizer(wxVERTICAL);

    m_bmpCtrl = new wxStaticBitmap(this, wxID_ANY, wxNullBitmap, wxDefaultPosition, wxDefaultSize, 0);
    bSizer1->Add(m_bmpCtrl, 0, wxALL | wxALIGN_CENTER_HORIZONTAL, 5);

    m_titleCtrl = new wxStaticText(this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0);
    m_titleCtrl->Wrap(-1);

    bSizer1->Add(m_titleCtrl, 0, wxALL | wxALIGN_CENTER_HORIZONTAL, 5);

    m_progNameCtrl = new wxStaticText(this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize,
                                      wxALIGN_CENTRE_HORIZONTAL);
    m_progNameCtrl->Wrap(-1);
    bSizer1->Add(m_progNameCtrl, 0, wxALL | wxALIGN_CENTER_HORIZONTAL, 5);

    m_modulesCtrl = new wxTextCtrl(this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxSize(300, 180),
                                   wxTE_MULTILINE | wxTE_LEFT);
    bSizer1->Add(m_modulesCtrl, 1, wxALL | wxEXPAND, 5);

    wxBoxSizer *bSizer2;
    bSizer2 = new wxBoxSizer(wxHORIZONTAL);

    m_copyRightCtrl = new wxStaticText(this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0);
    m_copyRightCtrl->Wrap(-1);
    bSizer2->Add(m_copyRightCtrl, 1, wxALL | wxALIGN_LEFT | wxALIGN_CENTER_VERTICAL, 5);

    m_buttonSystemInfoCtrl = new wxButton(this, wxID_ANY, wxT("System info"), wxDefaultPosition, wxDefaultSize, 0);
    bSizer2->Add(m_buttonSystemInfoCtrl, 0, wxALL, 5);
    bSizer1->Add(bSizer2, 0, wxEXPAND, 5);

#ifdef __WXOSX__
    m_titleCtrl->SetFont(wxNullFont);
    m_progNameCtrl->SetFont(wxNullFont);
    m_copyRightCtrl->SetFont(wxNullFont);
#endif
    m_titleCtrl->SetFont(m_titleCtrl->GetFont().MakeBold().MakeLarger());

    this->SetSizer(bSizer1);
}


int wxVersionDlg::ShowModal()
{
    this->Layout();
    wxSizer *mySizer = this->GetSizer();
    wxASSERT(mySizer);
    mySizer->Fit(this);
    CenterOnParent(wxBOTH);
    return wxDialog::ShowModal();
}
