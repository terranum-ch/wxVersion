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
#ifdef WXHGVERSION_SOFT_TEXT
	myVersion = WXHGVERSION_SOFT_TEXT;
#endif
	return myVersion;
}



wxString wxHgVersion::GetSoftBranch(){
    wxString myBranch = wxEmptyString;
#ifdef WXHGVERSION_SOFT_BRANCH
	myBranch = WXHGVERSION_SOFT_BRANCH;
#endif
	return myBranch;
}



wxString wxHgVersion::GetSoftNumber(){
    wxString myNum = wxEmptyString;
#ifdef WXHGVERSION_SOFT_NUMBER
	myNum = WXHGVERSION_SOFT_NUMBER;
#endif
	return myNum;
}



wxString wxHgVersion::GetVersionName(){
    wxString myTxt = wxEmptyString;
#ifdef WXHGVERSION_NAME
    myTxt = WXHGVERSION_NAME;
#endif
    return myTxt;
}



wxString wxHgVersion::GetVersionVersion(){
    wxString myTxt = wxEmptyString;
#ifdef WXHGVERSION_TEXT
    myTxt = WXHGVERSION_TEXT;
#endif
    return myTxt;
}



wxString wxHgVersion::GetVersionBranch(){
    wxString myTxt = wxEmptyString;
#ifdef WXHGVERSION_BRANCH
    myTxt = WXHGVERSION_BRANCH;
#endif
    return myTxt;
}



wxString wxHgVersion::GetVersionNumber(){
    wxString myTxt = wxEmptyString;
#ifdef WXHGVERSION_NUMBER
    myTxt = WXHGVERSION_NUMBER;
#endif
    return myTxt;
}



wxString wxHgVersion::GetvroomGISVersion(){
    wxString myTxt = wxEmptyString;
#ifdef VROOMGIS_TEXT
    myTxt = VROOMGIS_TEXT;
#endif
    return myTxt;
}



wxString wxHgVersion::GetvroomGISBranch(){
    wxString myTxt = wxEmptyString;
#ifdef VROOMGIS_BRANCH
    myTxt = VROOMGIS_BRANCH;
#endif
    return myTxt;
}



wxString wxHgVersion::GetvroomGISNumber(){
    wxString myTxt = wxEmptyString;
#ifdef VROOMGIS_NUMBER
    myTxt = VROOMGIS_NUMBER;
#endif
    return myTxt;
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



wxString wxHgVersion::GetGDALNumber(){
	wxString myGDAL = wxEmptyString;
#ifdef GDAL_INCLUDE_DIR
	myGDAL = GDAL_RELEASE_NAME;
#endif
	return myGDAL;
}


wxString wxHgVersion::GetGEOSNumber(){
	wxString myGEOS = wxEmptyString;
#ifdef GEOS_INCLUDE_DIR
	myGEOS = GEOS_VERSION;
#endif
	return myGEOS;
}


wxString wxHgVersion::GetCurlNumber(){
    wxString myTxt = wxEmptyString;
#ifdef SEARCH_CURL
    myTxt = wxString(LIBCURL_VERSION);
#endif
    return myTxt;
}


wxString wxHgVersion::GetSQLiteNumber(){
    wxString mySQlite = wxEmptyString;
#ifdef SQLITE_LIBRARIES
    mySQlite  = wxString(sqlite3_libversion());
#endif
    return mySQlite;
}


wxString wxHgVersion::GetMySQLNumber(){
	wxString myMySQL = wxEmptyString;
#ifdef MYSQL_INCLUDE_DIR
	myMySQL = wxString(mysql_get_client_info(), wxConvUTF8);
#endif
	return myMySQL;
}



wxString wxHgVersion::GetAllSoftwareInfo(bool useBranch){
    wxString myText = GetSoftName() + _T("\n");
    myText.Append(wxString::Format(_("version: %s (%s)"), GetSoftNumber(), GetSoftVersion()));
    if (useBranch == true) {
        myText.Append(wxString::Format(_("\nbranch: '%s'"), GetSoftBranch()));
    }
    return myText;
}


wxString wxHgVersion::GetAllModuleInfo(){
    wxString myModules = wxString::Format(_T("%s: %s (%s)\n"), GetVersionName(), GetVersionNumber(), GetVersionVersion());
    
    if (GetvroomGISNumber() != wxEmptyString) {
        myModules.Append(wxString::Format(_T("vroomGIS: %s (%s)\n"), GetvroomGISNumber(), GetVersionVersion()));
    }
    
    if (GetGDALNumber() != wxEmptyString) {
        myModules.Append(_T("GDAL: ") + GetGDALNumber() + _T("\n"));
    }
    
    if (GetGEOSNumber() != wxEmptyString) {
        myModules.Append(_T("GEOS: ") + GetGEOSNumber() + _T("\n"));
    }
    
    if (GetCurlNumber() != wxEmptyString) {
        myModules.Append(_T("libCurl: ") + GetCurlNumber() + _T("\n"));
    }
    
    if (GetSQLiteNumber() != wxEmptyString) {
        myModules.Append(_T("SQLite: ") + GetSQLiteNumber() + _T("\n"));
    }
    
    if (GetMySQLNumber() != wxEmptyString) {
        myModules.Append(_T("MySQL: ") + GetMySQLNumber() + _T("\n"));
    }
                         
    myModules.Append(_T("wxWidgets: ") + GetwxWidgetsNumber());
    if (GetwxWidgetsSVN().IsEmpty() == false) {
        myModules.Append(wxString::Format(" (%s)", GetwxWidgetsSVN()));
    }
	myModules.Append(_T("\n"));
    myModules.Append(wxGetOsDescription());
    return myModules;
}

