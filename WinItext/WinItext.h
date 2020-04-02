// WinItext.h : main header file for the WINITEXT application
//

#if !defined(AFX_WINITEXT_H__77D9FFDB_7637_4C4B_BC9D_DBD272742B09__INCLUDED_)
#define AFX_WINITEXT_H__77D9FFDB_7637_4C4B_BC9D_DBD272742B09__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CWinItextApp:
// See WinItext.cpp for the implementation of this class
//

class CWinItextApp : public CWinApp
{
public:
	CWinItextApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CWinItextApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CWinItextApp)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_WINITEXT_H__77D9FFDB_7637_4C4B_BC9D_DBD272742B09__INCLUDED_)
