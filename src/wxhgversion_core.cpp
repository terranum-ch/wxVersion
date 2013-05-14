/***************************************************************************
 wxhgversion_core.cpp
 -------------------
 copyright            : (C) 2013 Lucien Schreiber
 email                : lucien.schreiber at gmail dot com
 ***************************************************************************/
#include "wxhgversion_core.h"

wxString wxHgVersion::GetSoftName(){
	wxString myName = wxEmptyString;
#ifdef WXHGVERSION_SOFT_NAME
	myName = WXHGVERSION_SOFT_NAME;
#endif
	return myName;
}



wxString wxHgVersion::GetSoftVersion(){
    wxString myVersion = wxEmptyString;
#ifdef WXHGVERSION_TEXT
	myVersion = WXHGVERSION_TEXT;
#endif
	return myVersion;
}



wxString wxHgVersion::GetSoftBranch(){
    wxString myBranch = wxEmptyString;
#ifdef WXHGVERSION_BRANCH
	myBranch = WXHGVERSION_BRANCH;
#endif
	return myBranch;
}



wxString wxHgVersion::GetSoftNumber(){
    wxString myNum = wxEmptyString;
#ifdef WXHGVERSION_NUMBER
	myNum = WXHGVERSION_NUMBER;
#endif
	return myNum;
}



wxString wxHgVersion::GetwxWidgetsNumber(){
	wxString mywxVersion = wxString::Format("%d.%d.%d", wxMAJOR_VERSION, wxMINOR_VERSION, wxRELEASE_NUMBER);
	if (wxSUBRELEASE_NUMBER != 0) {
		mywxVersion.Append(wxString::Format(".%d",wxSUBRELEASE_NUMBER));
	}
	return mywxVersion;
}



wxString wxHgVersion::GetwxWidgetsSVN(){
	wxString mySVN = wxEmptyString;
#ifdef WXHGVERSION_WXWIDGETS_SVN
	mySVN = WXHGVERSION_WXWIDGETS_SVN;
#endif
	return mySVN;
}

wxString wxHgVersion::GetAllSoftwareInfo(bool useBranch){
    wxString myText = GetSoftName();
    myText.Append(wxString::Format(_("version: %s (%s)"), GetSoftNumber(), GetSoftVersion()));
    if (useBranch == true) {
        myText.Append(wxString::Format(_("\nbranch: '%s'"), GetSoftBranch()));
    }
    return myText;
}


wxString wxHgVersion::GetAllModuleInfo(){
    wxString myModules = _T("wxWidgets: ") + GetwxWidgetsNumber();
    if (GetwxWidgetsSVN().IsEmpty() == false) {
        myModules.Append(wxString::Format(" (%s)", GetwxWidgetsSVN()));
    }
	myModules.Append(_T("\n"));
    myModules.Append(wxGetOsDescription());
    return myModules;
}

