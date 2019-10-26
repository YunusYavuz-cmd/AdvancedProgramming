
// yunusyavuz_yavuz_yunus_hw8Dlg.h : header file
//

#pragma once
#include "afxwin.h"


// Cyunusyavuz_yavuz_yunus_hw8Dlg dialog
class Cyunusyavuz_yavuz_yunus_hw8Dlg : public CDialogEx
{
// Construction
public:
	Cyunusyavuz_yavuz_yunus_hw8Dlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	enum { IDD = IDD_YUNUSYAVUZ_YAVUZ_YUNUS_HW8_DIALOG };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support


// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedRadio1();
	afx_msg void OnBnClickedRadio2();
	afx_msg void OnBnClickedRadio3();
	CListBox ansResult;
	CEdit input1;
	CEdit input2;
	int and1;
	int OR1;
	int XOR1;
	afx_msg void OnBnClickedButton1();
	CButton shift1;
	CComboBox advanceCombo;
	afx_msg void OnBnClickedCheck1();
	CEdit inpLas;
	int radioSelect;
};
