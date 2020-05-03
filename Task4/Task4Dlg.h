
// Task4Dlg.h: файл заголовка
//

#pragma once
#include "Graph.h"

// Диалоговое окно CTask4Dlg
class CTask4Dlg : public CDialogEx
{
// Создание
public:
	CTask4Dlg(CWnd* pParent = nullptr);	// стандартный конструктор

// Данные диалогового окна
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_TASK4_DIALOG };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// поддержка DDX/DDV


// Реализация
protected:
	HICON m_hIcon;

	// Созданные функции схемы сообщений
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnEnChangeMfceditbrowse1();
	CMFCEditBrowseCtrl browser;
	Graph<const char*> graph;
	int vertexIndex;
	CListBox listbox;
	afx_msg void OnBnClickedButton1();
	afx_msg void OnBnClickedButton2();
	CListBox listbox2;
	afx_msg void OnCbnSelchangeCombo2();
	CComboBox combobox;
	CButton layerButton;
};
