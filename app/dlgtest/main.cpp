
// For compilers that support precompilation, includes "wx/wx.h".
#include "wx/wxprec.h"

#ifdef __BORLANDC__
    #pragma hdrstop
#endif

// for all others, include the necessary headers (this file is usually all you
// need because it includes almost all "standard" wxWidgets headers)
#ifndef WX_PRECOMP
    #include "wx/wx.h"
#endif

#include "dlgbmp.h"
#include "wxversion_core.h"
#include "wxversion_dlg.h"

class MyApp : public wxApp
{
public:
    virtual bool OnInit() wxOVERRIDE;
};


class MyFrame : public wxFrame
{
public:
    MyFrame(const wxString& title);
    void OnQuit(wxCommandEvent& event);
    void OnAbout(wxCommandEvent& event);

private:
    wxDECLARE_EVENT_TABLE();
};


// IDs for the controls and the menu commands
enum
{
    Minimal_Quit = wxID_EXIT,
    Minimal_About = wxID_ABOUT
};

wxBEGIN_EVENT_TABLE(MyFrame, wxFrame)
    EVT_MENU(Minimal_Quit,  MyFrame::OnQuit)
    EVT_MENU(Minimal_About, MyFrame::OnAbout)
wxEND_EVENT_TABLE()

wxIMPLEMENT_APP(MyApp);


// 'Main program' equivalent: the program execution "starts" here
bool MyApp::OnInit()
{
    if ( !wxApp::OnInit() )
        return false;

    wxInitAllImageHandlers();
    dlgtest_initialize_images();
    MyFrame *frame = new MyFrame("testing wxVersion App");
    frame->Show(true);
    return true;
}

MyFrame::MyFrame(const wxString& title)
       : wxFrame(NULL, wxID_ANY, title)
{
    // set the frame icon
    wxIcon myIcon;
    myIcon.CopyFromBitmap(*_img_dlgtest);
    SetIcon(myIcon);

#if wxUSE_MENUS
    wxMenu *fileMenu = new wxMenu;
    wxMenu *helpMenu = new wxMenu;
    helpMenu->Append(Minimal_About, "&About\tF1", "Show about dialog");
    fileMenu->Append(Minimal_Quit, "E&xit\tAlt-X", "Quit this program");
    wxMenuBar *menuBar = new wxMenuBar();
    menuBar->Append(fileMenu, "&File");
    menuBar->Append(helpMenu, "&Help");
    SetMenuBar(menuBar);
#else // !wxUSE_MENUS
    // If menus are not available add a button to access the about box
    wxSizer* sizer = new wxBoxSizer(wxHORIZONTAL);
    wxButton* aboutBtn = new wxButton(this, wxID_ANY, "About...");
    aboutBtn->Bind(wxEVT_BUTTON, &MyFrame::OnAbout, this);
    sizer->Add(aboutBtn, wxSizerFlags().Center());
    SetSizer(sizer);
#endif // wxUSE_MENUS/!wxUSE_MENUS

#if wxUSE_STATUSBAR
    // create a status bar just for fun (by default with 1 pane only)
    CreateStatusBar(2);
    SetStatusText("Welcome to wxVersion ! revision: " + wxVersion::GetSoftNumber());
#endif // wxUSE_STATUSBAR
}


// event handlers

void MyFrame::OnQuit(wxCommandEvent& WXUNUSED(event))
{
    Close(true);
}

void MyFrame::OnAbout(wxCommandEvent& WXUNUSED(event))
{
    wxVersionDlg myDlg(this, wxID_ANY, "About dlgtest");
    myDlg.ShowModal();
}
