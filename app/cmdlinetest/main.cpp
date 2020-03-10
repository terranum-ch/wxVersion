#include "wx/wxprec.h"

#ifdef __BORLANDC__
#pragma hdrstop
#endif
#ifndef WX_PRECOMP

#include "wx/wx.h"

#endif

#include <wx/app.h>
#include <wx/cmdline.h>
#include <wx/dir.h>
#include <wx/filename.h>

#include "wxversion_core.h"


static const wxCmdLineEntryDesc cmdLineDesc[] = {{wxCMD_LINE_SWITCH, "h", "help", "show this help message", wxCMD_LINE_VAL_NONE, wxCMD_LINE_OPTION_HELP},
                                                 {wxCMD_LINE_NONE}};


void PrintArray(const wxArrayString &array, const wxString &msg)
{
    wxPrintf(msg + _T("\n"));
    for (unsigned int i = 0; i < array.GetCount(); i++) {
        wxPrintf(array[i] + _T("\n"));
    }
}


int GetRandomNumber(int maxnumber)
{
    int output = 0 + (rand() % (int) (maxnumber - 0 + 1));
    return output;
}


int main(int argc, char **argv)
{
    // debugging string for OSX
    // this is needed for viewing string content with Xcode !!
    wxString myTest = _T("Test debugging");
    myTest.ToUTF8().data();
    myTest.Len();

    wxApp::CheckBuildOptions(WX_BUILD_OPTIONS_SIGNATURE, "program");
    wxInitializer initializer;
    if (!initializer) {
        fprintf(stderr, "Failed to initialize the wxWidgets library, aborting.");
        return -1;
    }
    wxInitAllImageHandlers();

    wxString myLogoTxt = _T(
            "*\n* cmdLineTest \n* Testing wxVersion plugin \n* (c) Copyright 2020 Terranum. All Rights Reserved. \n*\n");
    wxCmdLineParser parser(cmdLineDesc, argc, argv);
    parser.SetLogo(myLogoTxt);
    if (parser.Parse() != 0) {
        return 0;
    }

    wxPrintf(myLogoTxt);
    wxPrintf(wxHgVersion::GetAllSoftwareInfo() + _T("\n"));
    wxPrintf(wxHgVersion::GetAllModuleInfo() + _T("\n"));

    return 0;
}
