// WinItextDlg.h : header file
//

#if !defined(AFX_WINITEXTDLG_H__072123BE_061E_4873_8F9A_CDD91AEE2D21__INCLUDED_)
#define AFX_WINITEXTDLG_H__072123BE_061E_4873_8F9A_CDD91AEE2D21__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "bitmapdialog.h"
#include "stv5730.h"

/////////////////////////////////////////////////////////////////////////////
// CWinItextDlg dialog

class CWinItextDlg : public CBitmapDialog
{
// Construction
public:
	CWinItextDlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	//{{AFX_DATA(CWinItextDlg)
	enum { IDD = IDD_WINITEXT_DIALOG };
	CSTV5730	m_ctrMonitor;
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CWinItextDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CWinItextDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_WINITEXTDLG_H__072123BE_061E_4873_8F9A_CDD91AEE2D21__INCLUDED_)
