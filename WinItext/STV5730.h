#if !defined(AFX_STV5730_H__C0777959_E186_4224_A323_7A6C0ED0F6EE__INCLUDED_)
#define AFX_STV5730_H__C0777959_E186_4224_A323_7A6C0ED0F6EE__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// STV5730.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CSTV5730 window

class CSTV5730 : public CRichEditCtrl
{
// Construction
public:
	CSTV5730();

// Attributes
protected:
	int m_nLine;
	int m_nRow;

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CSTV5730)
	public:
	virtual BOOL Create(LPCTSTR lpszClassName, LPCTSTR lpszWindowName, DWORD dwStyle, const RECT& rect, CWnd* pParentWnd, UINT nID, CCreateContext* pContext = NULL);
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CSTV5730();

	// Generated message map functions
protected:
	//{{AFX_MSG(CSTV5730)
	afx_msg void OnChar(UINT nChar, UINT nRepCnt, UINT nFlags);
	//}}AFX_MSG

	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_STV5730_H__C0777959_E186_4224_A323_7A6C0ED0F6EE__INCLUDED_)
