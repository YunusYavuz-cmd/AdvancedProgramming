
// yunusyavuz_yavuz_yunus_hw8.h : main header file for the PROJECT_NAME application
//

#pragma once

#ifndef __AFXWIN_H__
	#error "include 'stdafx.h' before including this file for PCH"
#endif

#include "resource.h"		// main symbols


// Cyunusyavuz_yavuz_yunus_hw8App:
// See yunusyavuz_yavuz_yunus_hw8.cpp for the implementation of this class
//

class Cyunusyavuz_yavuz_yunus_hw8App : public CWinApp
{
public:
	Cyunusyavuz_yavuz_yunus_hw8App();

// Overrides
public:
	virtual BOOL InitInstance();

// Implementation

	DECLARE_MESSAGE_MAP()
};

extern Cyunusyavuz_yavuz_yunus_hw8App theApp;