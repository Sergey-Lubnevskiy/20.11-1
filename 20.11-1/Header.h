#pragma once
#include <windows.h>
#include <tchar.h>
#include <time.h>
#include "resource.h"
#include <windowsX.h>
#include <commctrl.h>

#pragma comment(lib,"comctl32")


HWND hbutton;
HWND hedit1, hedit2;
HWND hcombo1, hcombo2;
HWND hcheck1, hcheck2, hcheck3, hcheck4;
HWND hprogress;
HWND hradio1, hradio2, hradio3, hradio4, hradio5, hradio6, hradio7, hradio8, hradio9, hradio10;
HWND hspin1, hspin2;

int score = 0;
int ed1 = 24;

void Close(HWND hwnd)
{
	EndDialog(hwnd, 0);
}

BOOL InitDialog(HWND hwnd, HWND hwndFocus, LPARAM lParam)
{
	hbutton = GetDlgItem(hwnd, IDC_BUTTON1);

	hedit1 = GetDlgItem(hwnd, IDC_EDIT1);
	hedit2 = GetDlgItem(hwnd, IDC_EDIT2);

	hspin1 = GetDlgItem(hwnd, IDC_SPIN1);
	hspin2 = GetDlgItem(hwnd, IDC_SPIN2);

	hcombo1 = GetDlgItem(hwnd, IDC_COMBO1);
	hcombo2 = GetDlgItem(hwnd, IDC_COMBO2);

	hprogress = GetDlgItem(hwnd, IDC_PROGRESS1);

	hcheck1 = GetDlgItem(hwnd, IDC_CHECK1);
	hcheck2 = GetDlgItem(hwnd, IDC_CHECK2);
	hcheck3 = GetDlgItem(hwnd, IDC_CHECK3);
	hcheck4 = GetDlgItem(hwnd, IDC_CHECK4);

	hradio1 = GetDlgItem(hwnd, IDC_RADIO2);
	hradio2 = GetDlgItem(hwnd, IDC_RADIO5);
	hradio3 = GetDlgItem(hwnd, IDC_RADIO7);
	hradio4 = GetDlgItem(hwnd, IDC_RADIO12);
	hradio5 = GetDlgItem(hwnd, IDC_RADIO14);
	hradio6 = GetDlgItem(hwnd, IDC_RADIO17);
	hradio7 = GetDlgItem(hwnd, IDC_RADIO19);
	hradio8 = GetDlgItem(hwnd, IDC_RADIO23);

	SendMessage(hspin1, UDM_SETRANGE32, 1, 50);
	SendMessage(hspin2, UDM_SETRANGE32, 1, 50);

	UDACCEL pAcceleration[1] = { {1,1} };
	SendMessage(hspin1, UDM_SETACCEL, 1, LPARAM(pAcceleration));

	SendMessage(hspin1, UDM_SETBUDDY, WPARAM(hedit1), 0);
	SendMessage(hspin2, UDM_SETBUDDY, WPARAM(hedit2), 0);

	

	SetWindowText(hedit1, TEXT("1"));
	SetWindowText(hedit2, TEXT("1"));

	

	return TRUE;
}

void Command(HWND hwnd, UINT message, HWND hwndCtl, UINT codeNotify)
{
	switch (message)
	{
	case IDC_BUTTON1:
	{
		TCHAR buf[10];

		LRESULT res1 = SendDlgItemMessage(hwnd, IDC_RADIO2, BM_GETCHECK, 0, 0);
		LRESULT res2 = SendDlgItemMessage(hwnd, IDC_RADIO5, BM_GETCHECK, 0, 0);
		LRESULT res3 = SendDlgItemMessage(hwnd, IDC_RADIO7, BM_GETCHECK, 0, 0);
		LRESULT res4 = SendDlgItemMessage(hwnd, IDC_RADIO12, BM_GETCHECK, 0, 0);
		LRESULT res5 = SendDlgItemMessage(hwnd, IDC_RADIO14, BM_GETCHECK, 0, 0);
		LRESULT res6 = SendDlgItemMessage(hwnd, IDC_RADIO17, BM_GETCHECK, 0, 0);
		LRESULT res7 = SendDlgItemMessage(hwnd, IDC_RADIO19, BM_GETCHECK, 0, 0);
		LRESULT res8 = SendDlgItemMessage(hwnd, IDC_RADIO23, BM_GETCHECK, 0, 0);

		LRESULT res9 = SendDlgItemMessage(hwnd, IDC_CHECK1, BM_GETCHECK, 0, 0);
		LRESULT res10 = SendDlgItemMessage(hwnd, IDC_CHECK3, BM_GETCHECK, 0, 0);
		LRESULT res11 = SendDlgItemMessage(hwnd, IDC_CHECK2, BM_GETCHECK, 0, 0);
		LRESULT res12 = SendDlgItemMessage(hwnd, IDC_CHECK4, BM_GETCHECK, 0, 0);

		if (res1 == BST_CHECKED)
		{
			score++;
		}
		if (res2 == BST_CHECKED)
		{
			score++;
		}
		if (res3 == BST_CHECKED)
		{
			score++;
		}
		if (res4 == BST_CHECKED)
		{
			score++;
		}
		if (res5 == BST_CHECKED)
		{
			score++;
		}
		if (res6 == BST_CHECKED)
		{
			score++;
		}
		if (res7 == BST_CHECKED)
		{
			score++;
		}
		if (res8 == BST_CHECKED)
		{
			score++;
		}
		if (res9 == BST_CHECKED && res10 == BST_CHECKED && res11 == BST_UNCHECKED && res12 == BST_UNCHECKED)
		{
			score++;
		}
		int nTime = SendMessage(hspin1, UDM_GETPOS32, 0, 0);
		if (nTime == ed1)
		{
			score++;
		}

		wsprintf(buf, TEXT("%d"), score);
		int rez = MessageBox(hwnd, buf, TEXT("Результат"), MB_OK | MB_ICONINFORMATION);
		if(rez == IDOK)
		{
			DestroyWindow(hwnd);
		}
	}
	}
}

BOOL CALLBACK DlgProc(HWND hwnd, UINT message, WPARAM wParam, LPARAM lParam)
{
	switch (message)
	{
		HANDLE_MSG(hwnd, WM_CLOSE, Close);
		HANDLE_MSG(hwnd, WM_INITDIALOG, InitDialog);
		HANDLE_MSG(hwnd, WM_COMMAND, Command);
	}
	return FALSE;
}