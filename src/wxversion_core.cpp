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

wxString wxVersion::GetSoftName()
{
    wxString myName = wxEmptyString;
#ifdef WXVERSION_SOFT_NAME
    myName = WXVERSION_SOFT_NAME;
#endif
    return myName;
}


wxString wxVersion::GetSoftVersion()
{
    wxString myVersion = wxEmptyString;
#ifdef WXVERSION_SOFT_TEXT
    myVersion = WXVERSION_SOFT_TEXT;
#endif
    return myVersion;
}


wxString wxVersion::GetSoftBranch()
{
    wxString myBranch = wxEmptyString;
#ifdef WXVERSION_SOFT_BRANCH
    myBranch = WXVERSION_SOFT_BRANCH;
#endif
    return myBranch;
}


wxString wxVersion::GetSoftNumber()
{
    wxString myNum = wxEmptyString;
#ifdef WXVERSION_SOFT_NUMBER
    myNum = WXVERSION_SOFT_NUMBER;
#endif
    return myNum;
}


wxString wxVersion::GetVersionName()
{
    wxString myTxt = wxEmptyString;
#ifdef WXVERSION_NAME
    myTxt = WXVERSION_NAME;
#endif
    return myTxt;
}


wxString wxVersion::GetVersionVersion()
{
    wxString myTxt = wxEmptyString;
#ifdef WXVERSION_TEXT
    myTxt = WXVERSION_TEXT;
#endif
    return myTxt;
}


wxString wxVersion::GetVersionBranch()
{
    wxString myTxt = wxEmptyString;
#ifdef WXVERSION_BRANCH
    myTxt = WXVERSION_BRANCH;
#endif
    return myTxt;
}


wxString wxVersion::GetVersionNumber()
{
    wxString myTxt = wxEmptyString;
#ifdef WXVERSION_NUMBER
    myTxt = WXVERSION_NUMBER;
#endif
    return myTxt;
}


wxString wxVersion::GetvroomGISVersion()
{
    wxString myTxt = wxEmptyString;
#ifdef VROOMGIS_TEXT
    myTxt = VROOMGIS_TEXT;
#endif
    return myTxt;
}


wxString wxVersion::GetvroomGISBranch()
{
    wxString myTxt = wxEmptyString;
#ifdef VROOMGIS_BRANCH
    myTxt = VROOMGIS_BRANCH;
#endif
    return myTxt;
}


wxString wxVersion::GetvroomGISNumber()
{
    wxString myTxt = wxEmptyString;
#ifdef VROOMGIS_NUMBER
    myTxt = VROOMGIS_NUMBER;
#endif
    return myTxt;
}


wxString wxVersion::GetwxWidgetsNumber()
{
    wxString mywxVersion = wxString::Format("%d.%d.%d", wxMAJOR_VERSION, wxMINOR_VERSION, wxRELEASE_NUMBER);
    if (wxSUBRELEASE_NUMBER != 0) {
        mywxVersion.Append(wxString::Format(".%d", wxSUBRELEASE_NUMBER));
    }
    return mywxVersion;
}


wxString wxVersion::GetGDALNumber()
{
    wxString myGDAL = wxEmptyString;
#ifdef GDAL_INCLUDE_DIR
    myGDAL = GDAL_RELEASE_NAME;
#endif
    return myGDAL;
}


wxString wxVersion::GetGEOSNumber()
{
    wxString myGEOS = wxEmptyString;
#ifdef GEOS_INCLUDE_DIR
    myGEOS = GEOS_VERSION;
#endif
    return myGEOS;
}


wxString wxVersion::GetCurlNumber()
{
    wxString myTxt = wxEmptyString;
#ifdef CURL_INCLUDE_DIR
    myTxt = wxString(LIBCURL_VERSION);
#endif
    return myTxt;
}


wxString wxVersion::GetSQLiteNumber()
{
    wxString mySQlite = wxEmptyString;
#ifdef SQLITE_LIBRARIES
    mySQlite  = wxString(sqlite3_libversion());
#endif
    return mySQlite;
}


wxString wxVersion::GetMySQLNumber()
{
    wxString myMySQL = wxEmptyString;
#ifdef MYSQL_INCLUDE_DIR
    myMySQL = wxString(mysql_get_client_info(), wxConvUTF8);
#endif
    return myMySQL;
}


wxString wxVersion::GetNetCDFNumber()
{
    wxString ncVers = wxEmptyString;
#ifdef NetCDF_LIBRARIES
    ncVers = wxString(nc_inq_libvers());
#endif
    return ncVers;
}


wxString wxVersion::GetProjNumber()
{
    wxString myProj = wxEmptyString;
#ifdef PROJ_INCLUDE_DIR
#ifdef PJ_VERSION
    myProj = wxString::Format("%d", PJ_VERSION);
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
#endif
#ifdef PROJ_VERSION_MAJOR
    myProj = wxString::Format("%d.%d.%d", PROJ_VERSION_MAJOR,
                              PROJ_VERSION_MINOR, PROJ_VERSION_PATCH);
#endif
#endif

    return myProj;
}


wxString wxVersion::GetEigenNumber()
{
    wxString myTxt = wxEmptyString;
#ifdef EIGEN_VERSION
    myTxt = wxString::Format("%d.%d.%d", EIGEN_WORLD_VERSION, EIGEN_MAJOR_VERSION, EIGEN_MINOR_VERSION);
#endif
    return myTxt;
}


wxString wxVersion::GetPNGNumber()
{
    wxString myTxt = wxEmptyString;
#ifdef PNG_INCLUDE_DIRS
    myTxt = wxString(PNG_LIBPNG_VER_STRING);
#endif
    return myTxt;
}


wxString wxVersion::GetJpegNumber()
{
    wxString myTxt = wxEmptyString;
#ifdef JPEG_INCLUDE_DIR
#ifdef JPEG_LIB_VERSION
    myTxt = wxString::Format("%d", JPEG_LIB_VERSION);
    // Adding points
    if (!myTxt.IsEmpty()) {
        wxString myTxtDots = wxEmptyString;
        for (unsigned int i = 0; i < myTxt.Length(); i++) {
            if (i != myTxt.Length() - 1) {
                myTxtDots.Append(myTxt.Mid(i, 1) + ".");
            } else {
                myTxtDots.Append(myTxt.Mid(i, 1));
            }
        }
        myTxt = myTxtDots;
    }
#endif
#ifdef JPEG_LIB_VERSION_MAJOR
    myTxt =
            wxString::Format("%d.%d", JPEG_LIB_VERSION_MAJOR, JPEG_LIB_VERSION_MINOR);
#endif
#endif
    return myTxt;
}


wxString wxVersion::GetJasperNumber() {
    wxString myTxt = wxEmptyString;
#ifdef JASPER_INCLUDE_DIR
    myTxt = wxString(JAS_VERSION);
#endif
    return myTxt;
}


wxString wxVersion::GetEcCodesNumber()
{
    wxString myTxt = wxEmptyString;
#ifdef ECCODES_LIBRARIES
    myTxt = wxString(ECCODES_VERSION_STR);
#endif
    return myTxt;
}


wxString wxVersion::GetAllSoftwareInfo(bool useBranch)
{
    wxString myText = GetSoftName() + _T("\n");
    myText.Append(wxString::Format(_("version: %s (%s)"), GetSoftNumber(), GetSoftVersion()));
    if (useBranch == true) {
        myText.Append(wxString::Format(_("\nbranch: '%s'"), GetSoftBranch()));
    }
    return myText;
}


wxString wxVersion::GetAllModuleInfo(bool showChangesetID)
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

    if (GetPNGNumber() != wxEmptyString) {
        myModules.Append("PNG: " + GetPNGNumber() + "\n");
    }

    if (GetJpegNumber() != wxEmptyString) {
        myModules.Append("JPEG: " + GetJpegNumber() + "\n");
    }

    if (GetJasperNumber() != wxEmptyString) {
        myModules.Append("Jasper: " + GetJasperNumber() + "\n");
    }

    if (GetEcCodesNumber() != wxEmptyString) {
        myModules.Append("ecCodes: " + GetEcCodesNumber() + "\n");
    }

    myModules.Append(_T("wxWidgets: ") + GetwxWidgetsNumber() + "\n");

    return myModules;
}

