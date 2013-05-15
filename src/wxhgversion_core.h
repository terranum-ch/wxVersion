/***************************************************************************
 wxhgversion_core.h
 -------------------
 copyright            : (C) 2010 CREALP Lucien Schreiber
 email                : lucien.schreiber at crealp dot vs dot ch
 ***************************************************************************/

#ifndef _WXHGVERSION_CORE_H_
#define _WXHGVERSION_CORE_H_
#include "wx/wxprec.h"
#ifndef WX_PRECOMP
#include <wx/wx.h>
#endif
#include "wxhgversion_param.h"


class wxHgVersion {
public:
    static wxString GetSoftName();
    static wxString GetSoftVersion();
    static wxString GetSoftBranch();
    static wxString GetSoftNumber();
    
    static wxString GetVersionName();
    static wxString GetVersionVersion();
    static wxString GetVersionBranch();
    static wxString GetVersionNumber();
    
    static wxString GetwxWidgetsNumber();
    static wxString GetwxWidgetsSVN();
    static wxString GetAllSoftwareInfo(bool useBranch = true);
    static wxString GetAllModuleInfo();
};
#endif

