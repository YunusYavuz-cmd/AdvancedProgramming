
// yunusyavuz_yavuz_yunus_hw8Dlg.cpp : implementation file
//

#include "stdafx.h"
#include "yunusyavuz_yavuz_yunus_hw8.h"
#include "yunusyavuz_yavuz_yunus_hw8Dlg.h"
#include "afxdialogex.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CAboutDlg dialog used for App About

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// Dialog Data
	enum { IDD = IDD_ABOUTBOX };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

// Implementation
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialogEx(CAboutDlg::IDD)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
END_MESSAGE_MAP()


// Cyunusyavuz_yavuz_yunus_hw8Dlg dialog



Cyunusyavuz_yavuz_yunus_hw8Dlg::Cyunusyavuz_yavuz_yunus_hw8Dlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(Cyunusyavuz_yavuz_yunus_hw8Dlg::IDD, pParent)
	, and1(0)
	, OR1(0)
	, XOR1(0)
	, radioSelect(0)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void Cyunusyavuz_yavuz_yunus_hw8Dlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);

	DDX_Control(pDX, IDC_LIST1, ansResult);
	DDX_Control(pDX, IDC_EDIT2, input1);
	DDX_Control(pDX, IDC_EDIT3, input2);
	DDX_Control(pDX, IDC_CHECK1, shift1);
	DDX_Control(pDX, IDC_COMBO1, advanceCombo);
	DDX_Control(pDX, IDC_EDIT1, inpLas);
	DDX_Radio(pDX, IDC_RADIO1, radioSelect);
}

BEGIN_MESSAGE_MAP(Cyunusyavuz_yavuz_yunus_hw8Dlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_RADIO1, &Cyunusyavuz_yavuz_yunus_hw8Dlg::OnBnClickedRadio1)
	ON_BN_CLICKED(IDC_RADIO2, &Cyunusyavuz_yavuz_yunus_hw8Dlg::OnBnClickedRadio2)
	ON_BN_CLICKED(IDC_RADIO3, &Cyunusyavuz_yavuz_yunus_hw8Dlg::OnBnClickedRadio3)
	ON_BN_CLICKED(IDC_BUTTON1, &Cyunusyavuz_yavuz_yunus_hw8Dlg::OnBnClickedButton1)
	ON_BN_CLICKED(IDC_CHECK1, &Cyunusyavuz_yavuz_yunus_hw8Dlg::OnBnClickedCheck1)
END_MESSAGE_MAP()


// Cyunusyavuz_yavuz_yunus_hw8Dlg message handlers

BOOL Cyunusyavuz_yavuz_yunus_hw8Dlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// Add "About..." menu item to system menu.

	// IDM_ABOUTBOX must be in the system command range.
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != NULL)
	{
		BOOL bNameValid;
		CString strAboutMenu;
		bNameValid = strAboutMenu.LoadString(IDS_ABOUTBOX);
		ASSERT(bNameValid);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// Set the icon for this dialog.  The framework does this automatically
	//  when the application's main window is not a dialog
	SetIcon(m_hIcon, TRUE);			// Set big icon
	SetIcon(m_hIcon, FALSE);		// Set small icon

	// TODO: Add extra initialization here

	return TRUE;  // return TRUE  unless you set the focus to a control
}

void Cyunusyavuz_yavuz_yunus_hw8Dlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialogEx::OnSysCommand(nID, lParam);
	}
}

// If you add a minimize button to your dialog, you will need the code below
//  to draw the icon.  For MFC applications using the document/view model,
//  this is automatically done for you by the framework.

void Cyunusyavuz_yavuz_yunus_hw8Dlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // device context for painting

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// Center icon in client rectangle
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// Draw the icon
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

// The system calls this function to obtain the cursor to display while the user drags
//  the minimized window.
HCURSOR Cyunusyavuz_yavuz_yunus_hw8Dlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}


bool isOperatorPressed = false;
CString operatorPressed;
void Cyunusyavuz_yavuz_yunus_hw8Dlg::OnBnClickedRadio1()
{
	// TODO: Add your control notification handler code here
	CString result;
	double result_d;
	ansResult.GetWindowTextW(result);
	result_d = _ttof(result);
	radioSelect=0;
	result.Format(_T("%.2f"), result_d);


	ansResult.SetWindowTextW(result);
}


void Cyunusyavuz_yavuz_yunus_hw8Dlg::OnBnClickedRadio2()
{
	// TODO: Add your control notification handler code here
	CString result;
	double result_d;
	ansResult.GetWindowTextW(result);
	result_d = _ttof(result);
	radioSelect=1;
	result.Format(_T("%.3f"), result_d);
	ansResult.SetWindowTextW(result);
}


void Cyunusyavuz_yavuz_yunus_hw8Dlg::OnBnClickedRadio3()
{
	// TODO: Add your control notification handler code here
	CString result;
	double result_d;
	ansResult.GetWindowTextW(result);
	result_d = _ttof(result);
	radioSelect=2;
	result.Format(_T("%.5f"), result_d);
	ansResult.SetWindowTextW(result);
}

int maxSize=0;
void Cyunusyavuz_yavuz_yunus_hw8Dlg::OnBnClickedButton1()
{
	// TODO: Add your control notification handler code here
	CString inpstr1,inpstr2,result,comboText,lastAns,last1,last2;
	CString inplast;
	unsigned int firstInp,secondInp,lastInp,lastly;
	CSize cz;
	CDC *pDC= GetDC();
	bool checkShift=false;
	input1.GetWindowTextW(inpstr1);
	input2.GetWindowTextW(inpstr2);
	inpLas.GetWindowTextW(inplast);
	if(inpstr1.GetLength()<=0||inpstr2.GetLength()<=0) //if missing input
	{
		result+=_T("At least one operand was not entered.");
	}
	else if(shift1.GetCheck()==1) //if shift selected
	{
		int selectedIndx=advanceCombo.GetCurSel();
		advanceCombo.GetLBText(selectedIndx, comboText);
		if(inplast.GetLength()<=0)
		{
			result=_T("Specify how many bits you want to shift");
		}
		else
		{
			firstInp= _tcstoul(inpstr1,nullptr,10);
			secondInp= _tcstoul(inpstr2,nullptr,10);
			lastInp= _tcstoul(inplast,nullptr,10);
			int a=comboText.GetLength();
			if(a==4)//if selected is left(couldnt find any other way since it gives a different text type so i looked length)
			{
				firstInp=firstInp<<lastInp;
				secondInp=secondInp<<lastInp;
				last1.Format(_T("%u"), firstInp);
				result+=last1;
			}
			else
			{
				firstInp=firstInp>>lastInp;
				secondInp=secondInp>>lastInp;
				last1.Format(_T("%u"), firstInp);
				result+=last1;
			}
			if(radioSelect==0) //if and 
			{
				lastly=firstInp&secondInp;
				last2.Format(_T("%u"), secondInp);
				lastAns.Format(_T("%u"), lastly);
				result+=_T(" AND ")+last2+_T(" = ")+lastAns;
			}
			else if(radioSelect==1)//if or
			{
				lastly=firstInp|secondInp;
				last2.Format(_T("%u"), secondInp);
				lastAns.Format(_T("%u"), lastly);
				result+=_T(" OR ")+last2+_T(" = ")+lastAns;
			}
			else if(radioSelect==2)//if xor
			{
				lastly=firstInp^secondInp;
				last2.Format(_T("%u"), secondInp);
				lastAns.Format(_T("%u"), lastly);
				result+=_T(" XOR ")+last2+_T(" = ")+lastAns;
			}
		}
	}
	else  //if shift not selected
	{
		firstInp= _tcstoul(inpstr1,nullptr,10);
		secondInp= _tcstoul(inpstr2,nullptr,10);
		lastInp= _tcstoul(inplast,nullptr,10);
		if(radioSelect==0)//and 
			{
				lastly=firstInp&secondInp;
				lastAns.Format(_T("%u"), lastly);
			last1.Format(_T("%u"), firstInp);
			last2.Format(_T("%u"), secondInp);
			result+=last1+_T(" AND ")+last2+_T(" = ")+lastAns;
			}
			else if(radioSelect==1)//or
			{
				lastly=firstInp|secondInp;
				lastAns.Format(_T("%u"), lastly);
				last1.Format(_T("%u"), firstInp);
				last2.Format(_T("%u"), secondInp);
				result+=last1+_T(" OR ")+last2+_T(" = ")+lastAns;
			}
			else if(radioSelect==2)//xor
			{
				lastly=firstInp^secondInp;
				lastAns.Format(_T("%u"), lastly);
				last1.Format(_T("%u"), firstInp);
				last2.Format(_T("%u"), secondInp);
				result+=last1+_T(" XOR ")+last2+_T(" = ")+lastAns;
			}
			

	}

	ansResult.AddString(result);
	cz=pDC->GetTextExtent(result);
	if(cz.cx>maxSize)
		maxSize=cz.cx;
	ansResult.SetHorizontalExtent(maxSize);
		
}


void Cyunusyavuz_yavuz_yunus_hw8Dlg::OnBnClickedCheck1()
{
	// TODO: Add your control notification handler code here
	if(shift1.GetCheck()==1)//if shift selected it makes combotext avaible
	{
		advanceCombo.EnableWindow(TRUE);
	}
	else
	{
		advanceCombo.EnableWindow(FALSE);
	}


}
