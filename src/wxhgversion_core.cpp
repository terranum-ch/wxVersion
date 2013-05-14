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
	myName = wxhgversion_SOFT_NAME;
#endif
	return myName;
}



wxString wxHgVersion::GetSoftSVN()
{
	wxString mySVN = wxEmptyString;
#ifdef wxhgversion_SOFT_VERSION
	mySVN = wxhgversion_SOFT_VERSION;
#endif
	return mySVN;
}


wxString wxHgVersion:GetSoftVersion(){
    wxString myVersion = wxEmptyString;
#ifdef WXHGVERSION_TEXT
	myVersion = WXHGVERSION_TEXT;
#endif
	return myVersion;
}



wxString wxHgVersion:GetSoftBranch(){
    wxString myBranch = wxEmptyString;
#ifdef WXHGVERSION_BRANCH
	myBranch = WXHGVERSION_BRANCH;
#endif
	return myBranch;
}



wxString wxHgVersion:GetSoftNumber(){
    wxString myNum = wxEmptyString;
#ifdef WXHGVERSION_NUMBER
	myBranch = WXHGVERSION_NUMBER;
#endif
	return myNumber;
}


wxString wxHgVersion::GetwxWidgetsNumber(){
	wxString mywxVersion = wxString::Format("%d.%d.%d", wxMAJOR_VERSION, wxMINOR_VERSION, wxRELEASE_NUMBER);
	if (wxSUBRELEASE_NUMBER != 0) {
		mywxVersion.Append(wxString::Format(".%d",wxSUBRELEASE_NUMBER));
	}
	return mywxVersion;
}


wxString wxHgVersion::GetwxWidgetsSVN()
{
	wxString mySVN = wxEmptyString;
#ifdef WXHGVERSION_WXWIDGETS_SVN
	mySVN = WXHGVERSION_WXWIDGETS_SVN;
#endif
	return mySVN;
}


wxString wxHgVersion::GetAll()
{
    
	wxString myModules = _T("wxWidgets: ") + GetwxWidgetsNumber();
    
    if (GetwxWidgetsSVN().IsEmpty() == false) {
        myModules.Append(wxString::Format(" (%s)", GetwxWidgetsSVN()));
    }
	myModules.Append(_T("\n"));
    
    if (GetVroomGISNumber().IsEmpty() == false) {
        myModules.Append(_T("vroomGIS: ") + GetVroomGISNumber() + _T("\n"));
    }
	
	if (GetMySQLNumber().IsEmpty() == false){
		myModules.Append(_T("MySQL: ") + GetMySQLNumber() + _T("\n"));
	}
	
    if (GetSQLiteNumber().IsEmpty() == false) {
        myModules.Append(_T("SQLite: ") + GetSQLiteNumber() + _T("\n"));
    }
    
    if (GetGDALNumber().IsEmpty() == false) {
        myModules.Append(_T("GDAL: ") + GetGDALNumber() + _T("\n"));
    }
    
    if (GetGEOSNumber().IsEmpty() == false) {
        myModules.Append(_T("GEOS: ") + GetGEOSNumber() + _T("\n"));
    }
    
    if (GetCurlNumber().IsEmpty() == false ) {
        myModules.Append(_T("libCURL: ") + GetCurlNumber() + _T("\n"));
    }
    
	myModules.Append(wxGetOsDescription());
	return myModules;
}

