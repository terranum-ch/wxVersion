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
 * Portions Copyright 2013 Pascal Horton, University of Lausanne.
 */

#include "wxversion_core.h"

wxString wxHgVersion::GetSoftName()
{
    wxString myName = wxEmptyString;
#ifdef WXGITVERSION_SOFT_NAME
    myName = WXGITVERSION_SOFT_NAME;
#endif
    return myName;
}


wxString wxHgVersion::GetSoftVersion()
{
    wxString myVersion = wxEmptyString;
#ifdef WXGITVERSION_SOFT_TEXT
    myVersion = WXGITVERSION_SOFT_TEXT;
#endif
    return myVersion;
}


wxString wxHgVersion::GetSoftBranch()
{
    wxString myBranch = wxEmptyString;
#ifdef WXGITVERSION_SOFT_BRANCH
    myBranch = WXGITVERSION_SOFT_BRANCH;
#endif
    return myBranch;
}


wxString wxHgVersion::GetSoftNumber()
{
    wxString myNum = wxEmptyString;
#ifdef WXGITVERSION_SOFT_NUMBER
    myNum = WXGITVERSION_SOFT_NUMBER;
#endif
    return myNum;
}


wxString wxHgVersion::GetVersionName()
{
    wxString myTxt = wxEmptyString;
#ifdef WXGITVERSION_NAME
    myTxt = WXGITVERSION_NAME;
#endif
    return myTxt;
}


wxString wxHgVersion::GetVersionVersion()
{
    wxString myTxt = wxEmptyString;
#ifdef WXGITVERSION_TEXT
    myTxt = WXGITVERSION_TEXT;
#endif
    return myTxt;
}


wxString wxHgVersion::GetVersionBranch()
{
    wxString myTxt = wxEmptyString;
#ifdef WXGITVERSION_BRANCH
    myTxt = WXGITVERSION_BRANCH;
#endif
    return myTxt;
}


wxString wxHgVersion::GetVersionNumber()
{
    wxString myTxt = wxEmptyString;
#ifdef WXGITVERSION_NUMBER
    myTxt = WXGITVERSION_NUMBER;
#endif
    return myTxt;
}


wxString wxHgVersion::GetvroomGISVersion()
{
    wxString myTxt = wxEmptyString;
#ifdef VROOMGIS_TEXT
    myTxt = VROOMGIS_TEXT;
#endif
    return myTxt;
}


wxString wxHgVersion::GetvroomGISBranch()
{
    wxString myTxt = wxEmptyString;
#ifdef VROOMGIS_BRANCH
    myTxt = VROOMGIS_BRANCH;
#endif
    return myTxt;
}


wxString wxHgVersion::GetvroomGISNumber()
{
    wxString myTxt = wxEmptyString;
#ifdef VROOMGIS_NUMBER
    myTxt = VROOMGIS_NUMBER;
#endif
    return myTxt;
}


wxString wxHgVersion::GetwxWidgetsNumber()
{
    wxString mywxVersion = wxString::Format("%d.%d.%d", wxMAJOR_VERSION, wxMINOR_VERSION, wxRELEASE_NUMBER);
    if (wxSUBRELEASE_NUMBER != 0) {
        mywxVersion.Append(wxString::Format(".%d", wxSUBRELEASE_NUMBER));
    }
    return mywxVersion;
}


wxString wxHgVersion::GetwxWidgetsSVN()
{
    wxString mySVN = wxEmptyString;
#ifdef WXGITVERSION_WXWIDGETS_SVN
    mySVN = WXGITVERSION_WXWIDGETS_SVN;
#endif
    return mySVN;
}


wxString wxHgVersion::GetGDALNumber()
{
    wxString myGDAL = wxEmptyString;
#ifdef GDAL_INCLUDE_DIR
    myGDAL = GDAL_RELEASE_NAME;
#endif
    return myGDAL;
}


wxString wxHgVersion::GetGEOSNumber()
{
    wxString myGEOS = wxEmptyString;
#ifdef GEOS_INCLUDE_DIR
    myGEOS = GEOS_VERSION;
#endif
    return myGEOS;
}


wxString wxHgVersion::GetCurlNumber()
{
    wxString myTxt = wxEmptyString;
#ifdef CURL_INCLUDE_DIR
    myTxt = wxString(LIBCURL_VERSION);
#endif
    return myTxt;
}


wxString wxHgVersion::GetSQLiteNumber()
{
    wxString mySQlite = wxEmptyString;
#ifdef SQLITE_LIBRARIES
    mySQlite  = wxString(sqlite3_libversion());
#endif
    return mySQlite;
}


wxString wxHgVersion::GetMySQLNumber()
{
    wxString myMySQL = wxEmptyString;
#ifdef MYSQL_INCLUDE_DIR
    myMySQL = wxString(mysql_get_client_info(), wxConvUTF8);
#endif
    return myMySQL;
}


wxString wxHgVersion::GetNetCDFNumber()
{
    wxString ncVers = wxEmptyString;
#ifdef NetCDF_LIBRARIES
    ncVers = wxString(nc_inq_libvers());
#endif
    return ncVers;
}


wxString wxHgVersion::GetProjNumber()
{
    wxString myProj = wxEmptyString;
#ifdef PROJ_LIBRARY
    myProj = wxString::Format("%d", PJ_VERSION);
#elif defined PROJ4_INCLUDE_DIR
    myProj = wxString::Format("%d", PJ_VERSION);
#endif
    // Adding points
    if (!myProj.IsEmpty()) {
        wxString myProjDots = wxEmptyString;
        for (unsigned int i = 0; i < myProj.Length(); i++) {
            if (i != myProj.Length() - 1) {
                myProjDots.Append(myProj.Mid(i, 1) + ".");
            } else {
                myProjDots.Append(myProj.Mid(i, 1));
            }
        }
        myProj = myProjDots;
    }

    return myProj;
}


wxString wxHgVersion::GetEigenNumber()
{
    wxString myTxt = wxEmptyString;
#ifdef EIGEN3_INCLUDE_DIR
    myTxt = wxString::Format("%d.%d.%d", EIGEN_WORLD_VERSION, EIGEN_MAJOR_VERSION, EIGEN_MINOR_VERSION);
#endif
    return myTxt;
}


wxString wxHgVersion::GetAllSoftwareInfo(bool useBranch)
{
    wxString myText = GetSoftName() + _T("\n");
    myText.Append(wxString::Format(_("version: %s (%s)"), GetSoftNumber(), GetSoftVersion()));
    if (useBranch == true) {
        myText.Append(wxString::Format(_("\nbranch: '%s'"), GetSoftBranch()));
    }
    return myText;
}


wxString wxHgVersion::GetAllModuleInfo(bool showChangesetID)
{
    wxString myModules = wxEmptyString;
    if (showChangesetID) {
        myModules = wxString::Format(_T("%s: %s (%s)\n"), GetVersionName(), GetVersionNumber(), GetVersionVersion());
    } else {
        myModules = wxString::Format(_T("%s: %s\n"), GetVersionName(), GetVersionNumber());
    }

    if (GetvroomGISNumber() != wxEmptyString) {
        if (showChangesetID) {
            myModules.Append(wxString::Format(_T("vroomGIS: %s (%s)\n"), GetvroomGISNumber(), GetvroomGISVersion()));
        } else {
            myModules.Append(wxString::Format(_T("vroomGIS: %s\n"), GetvroomGISNumber()));
        }
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

    if (GetNetCDFNumber() != wxEmptyString) {
        myModules.Append(_T("NetCDF: ") + GetNetCDFNumber().BeforeFirst(' ') + _T("\n"));
    }

    if (GetProjNumber() != wxEmptyString) {
        myModules.Append(_T("Proj4: ") + GetProjNumber() + _T("\n"));
    }

    if (GetEigenNumber() != wxEmptyString) {
        myModules.Append(_T("Eigen: ") + GetEigenNumber() + _T("\n"));
    }

    myModules.Append(_T("wxWidgets: ") + GetwxWidgetsNumber());
    if (GetwxWidgetsSVN().IsEmpty() == false) {
        myModules.Append(wxString::Format(" (%s)", GetwxWidgetsSVN()));
    }
    return myModules;
}

