// STV5730.cpp : implementation file
//

#include "stdafx.h"
#include "WinItext.h"
#include "STV5730.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CSTV5730

CSTV5730::CSTV5730()
{
	m_nLine=0;
	m_nRow=0;
}

CSTV5730::~CSTV5730()
{
}


BEGIN_MESSAGE_MAP(CSTV5730, CRichEditCtrl)
	//{{AFX_MSG_MAP(CSTV5730)
	ON_WM_CHAR()
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CSTV5730 message handlers

void CSTV5730::OnChar(UINT nChar, UINT nRepCnt, UINT nFlags) 
{
	// TODO: Add your message handler code here and/or call default
	
	if (GetLineCount()>11)
		return;

	CRichEditCtrl::OnChar(nChar, nRepCnt, nFlags);
}

BOOL CSTV5730::Create(LPCTSTR lpszClassName, LPCTSTR lpszWindowName, DWORD dwStyle, const RECT& rect, CWnd* pParentWnd, UINT nID, CCreateContext* pContext) 
{
	CHARFORMAT cf;

	BOOL ret;	
	ret = CWnd::Create(lpszClassName, lpszWindowName, dwStyle, rect, pParentWnd, nID, pContext);

	SetTargetDevice (NULL,0);
	SetBackgroundColor (FALSE,RGB (0,0,0));
	GetDefaultCharFormat (m_cf);
	cf.crTextColor = RGB (255,255,255);
	cf.dwMask = CFM_COLOR |CFM_FACE |CFM_SIZE;
	cf.cbSize = sizeof (CHARFORMAT);
	cf.dwEffects=NULL;
	cf.yHeight = 330;
	strcpy (m_cf.szFaceName,"STV5730");
	SetDefaultCharFormat (m_cf);

	return ret;
}
