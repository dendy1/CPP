
// Task4Dlg.cpp: файл реализации
//

#include "pch.h"
#include "framework.h"
#include "Task4.h"
#include "Task4Dlg.h"
#include "afxdialogex.h"
#include <stdlib.h>

#ifdef _DEBUG
#define new DEBUG_NEW
#endif
#include <sstream>


// Диалоговое окно CAboutDlg используется для описания сведений о приложении

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// Данные диалогового окна
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ABOUTBOX };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // поддержка DDX/DDV

// Реализация
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialogEx(IDD_ABOUTBOX)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
END_MESSAGE_MAP()


// Диалоговое окно CTask4Dlg



CTask4Dlg::CTask4Dlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_TASK4_DIALOG, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CTask4Dlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_MFCEDITBROWSE1, browser);
	DDX_Control(pDX, IDC_LIST1, listbox);
	DDX_Control(pDX, IDC_LIST2, listbox2);
	DDX_Control(pDX, IDC_COMBO2, combobox);
	DDX_Control(pDX, IDC_BUTTON2, layerButton);
}

BEGIN_MESSAGE_MAP(CTask4Dlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
//	ON_BN_CLICKED(IDCANCEL, &CTask4Dlg::OnBnClickedCancel)
//	ON_BN_CLICKED(IDOK, &CTask4Dlg::OnBnClickedOk)
//	ON_EN_CHANGE(IDC_MFCEDITBROWSE1, &CTask4Dlg::OnEnChangeMfceditbrowse1)
ON_EN_CHANGE(IDC_MFCEDITBROWSE1, &CTask4Dlg::OnEnChangeMfceditbrowse1)
ON_BN_CLICKED(IDC_BUTTON1, &CTask4Dlg::OnBnClickedButton1)
ON_BN_CLICKED(IDC_BUTTON2, &CTask4Dlg::OnBnClickedButton2)
ON_CBN_SELCHANGE(IDC_COMBO2, &CTask4Dlg::OnCbnSelchangeCombo2)
END_MESSAGE_MAP()


// Обработчики сообщений CTask4Dlg

BOOL CTask4Dlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// Добавление пункта "О программе..." в системное меню.

	// IDM_ABOUTBOX должен быть в пределах системной команды.
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != nullptr)
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

	// Задает значок для этого диалогового окна.  Среда делает это автоматически,
	//  если главное окно приложения не является диалоговым
	SetIcon(m_hIcon, TRUE);			// Крупный значок
	SetIcon(m_hIcon, FALSE);		// Мелкий значок

	// TODO: добавьте дополнительную инициализацию

	browser.EnableFileBrowseButton(_T("TXT"), _T("Text files|*.txt||"));
	return TRUE;  // возврат значения TRUE, если фокус не передан элементу управления
}

void CTask4Dlg::OnSysCommand(UINT nID, LPARAM lParam)
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

// При добавлении кнопки свертывания в диалоговое окно нужно воспользоваться приведенным ниже кодом,
//  чтобы нарисовать значок.  Для приложений MFC, использующих модель документов или представлений,
//  это автоматически выполняется рабочей областью.

void CTask4Dlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // контекст устройства для рисования

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// Выравнивание значка по центру клиентского прямоугольника
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// Нарисуйте значок
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

// Система вызывает эту функцию для получения отображения курсора при перемещении
//  свернутого окна.
HCURSOR CTask4Dlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}

void CTask4Dlg::OnEnChangeMfceditbrowse1()
{
	// TODO:  Если это элемент управления RICHEDIT, то элемент управления не будет
	// send this notification unless you override the CDialogEx::OnInitDialog()
	// функция и вызов CRichEditCtrl().SetEventMask()
	// with the ENM_CHANGE flag ORed into the mask.

	// TODO:  Добавьте код элемента управления

	CString filename;
    browser.GetWindowTextW(filename);

	CStringArray strArr;
	CString strLine;
	TRY
	{
		CStdioFile file(filename, CFile::modeRead);
		while (file.ReadString(strLine))
		{
			strArr.Add(strLine);
		}
	}
	CATCH_ALL(e)
	{
		e->ReportError(); // shows what's going wrong 
	}
	END_CATCH_ALL

	

	int count = _ttoi(strArr[0]);
	int nTokenPos;
	CStringA strToken, strNeighbors;
	std::vector<Vertex<const char*>*> vertices;
	for (int i = 1; i < strArr.GetCount(); i++)
	{
		nTokenPos = 0;
		strToken = strArr[i].Tokenize(_T("|"), nTokenPos);
		const size_t newsizea = (strToken.GetLength() + 1);
		char* nstringa = new char[newsizea];
		strcpy_s(nstringa, newsizea, strToken);
		vertices.push_back(new Vertex<const char*>(nstringa));
	}

	for (int i = 1; i < strArr.GetCount(); i++)
	{
		auto currentVertex = vertices[i - 1];

		nTokenPos = 1;
		strNeighbors = strArr[i].Tokenize(_T("|"), nTokenPos);

		nTokenPos = 0;
		strToken = strNeighbors.Tokenize(",", nTokenPos);
		while (!strToken.IsEmpty())
		{
			const char* s = (const char*)strToken.GetBuffer();
			auto neighbour = std::find_if(vertices.begin(), vertices.end(), [&s](const Vertex<const char*>* obj) -> bool { return std::strcmp(obj->value, s) == 0; });


			if (neighbour != vertices.end() && currentVertex != *neighbour)
			{
				currentVertex->neighbors.push_back(*neighbour);
			}

			strToken.ReleaseBuffer();
			strToken = strNeighbors.Tokenize(",", nTokenPos);
		}
	}

	graph.vertices = vertices;

	listbox.ResetContent();
	combobox.ResetContent();

	for (auto vertex : graph.vertices)
	{
		listbox.AddString((vertex->ToString()).c_str());
		combobox.AddString((vertex->ToString()).c_str());
	}
	combobox.SetCurSel(0);

	layerButton.ShowWindow(SW_SHOW);
	combobox.ShowWindow(SW_SHOW);
}

void CTask4Dlg::OnBnClickedButton1()
{
	// TODO: добавьте свой код обработчика уведомлений
	this->OnCancel();
}


void CTask4Dlg::OnBnClickedButton2()
{
	listbox2.ResetContent();
	graph.MarkNeighbors(vertexIndex);
	for (auto vertex : graph.vertices)
	{
		listbox2.AddString((vertex->ToStringWithLayer()).c_str());
	}
}


void CTask4Dlg::OnCbnSelchangeCombo2()
{
	vertexIndex = combobox.GetCurSel();
}
