#include <iostream>
#include <windows.h>
#include <conio.h>
#include <mmsystem.h>
#include <vector>
#include <time.h>
#include <string.h>
#include<io.h>
#include<fcntl.h>
#include "control.h"
#include "Algorithm.h"
#include "global.h"
#include "Graphics.h"
#include "Manage.h"

void Nocursortype()
{
	CONSOLE_CURSOR_INFO Info;
	Info.bVisible = FALSE;
	Info.dwSize = 20;
	SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &Info);
}
void SetWindowSize(SHORT width, SHORT height)
{
	HANDLE hStdout = GetStdHandle(STD_OUTPUT_HANDLE);

	SMALL_RECT WindowSize;
	WindowSize.Top = 0;
	WindowSize.Left = 0;
	WindowSize.Right = width;
	WindowSize.Bottom = height;

	SetConsoleWindowInfo(hStdout, 1, &WindowSize);
}
void SetScreenBufferSize(SHORT width, SHORT height)
{
	HANDLE hStdout = GetStdHandle(STD_OUTPUT_HANDLE);

	COORD NewSize;
	NewSize.X = width;
	NewSize.Y = height;

	SetConsoleScreenBufferSize(hStdout, NewSize);
}
void DisableResizeWindow()
{
	HWND hWnd = GetConsoleWindow();
	SetWindowLong(hWnd, GWL_STYLE, GetWindowLong(hWnd, GWL_STYLE) & ~WS_SIZEBOX);
}
void DisableCtrButton(bool Close, bool Min, bool Max)
{
	HWND hWnd = GetConsoleWindow();
	HMENU hMenu = GetSystemMenu(hWnd, false);

	if (Close == 1)
	{
		DeleteMenu(hMenu, SC_CLOSE, MF_BYCOMMAND);
	}
	if (Min == 1)
	{
		DeleteMenu(hMenu, SC_MINIMIZE, MF_BYCOMMAND);
	}
	if (Max == 1)
	{
		DeleteMenu(hMenu, SC_MAXIMIZE, MF_BYCOMMAND);
	}
}
void ShowScrollbar(BOOL Show)
{
	HWND hWnd = GetConsoleWindow();
	ShowScrollBar(hWnd, SB_BOTH, Show);
}

void FixConsoleWindow() {

	HWND consoleWindow = GetConsoleWindow();
	
	LONG style = GetWindowLong(consoleWindow, GWL_STYLE);
	
	style = style & ~(WS_MAXIMIZEBOX) & ~(WS_THICKFRAME);
	
	SetWindowLong(consoleWindow, GWL_STYLE, style);
}

void main()
{
	PlaySound(TEXT("ycg_logo.wav"), NULL, SND_ASYNC);
	m = 2, s = 2;
	SetWindowSize(118, 60);
	SetScreenBufferSize(118, 60);
	DisableResizeWindow();
	DisableCtrButton(1, 1, 1);
	Nocursortype();
	hConsoleColor = GetStdHandle(STD_OUTPUT_HANDLE);
	Menu menu;
	int x;
	int pmode;
	int load;
	int line = 14; //Vị trí dòng của menu
	bool EXIT = false;
	char loadg[5][100];
	menu.printMenu();
	Sleep(300);
	//Vẽ con trỏ ở đầu menu
	SetConsoleTextAttribute(hConsoleColor, 240);
	gotoxy(50, line);
	cout << ">>";
	gotoxy(66, line);
	cout << "<<";
	//Vẽ con trỏ trỏ tới menu
	while (!EXIT) {
		if (m == 100) m = 2;
		if (s == 100) s = 2;
		if (_kbhit()) {
			x = move();
			gotoxy(50, line);
			SetConsoleTextAttribute(hConsoleColor, 255);
			cout << "  ";
			gotoxy(66, line);
			SetConsoleTextAttribute(hConsoleColor, 255);
			cout << "  ";
			SetConsoleTextAttribute(hConsoleColor, 240);
			switch (x) {
			case 1:if (s % 2 == 0)
				PlaySound(TEXT("menu_file_cursor_move.wav"), NULL, SND_ASYNC);
			case 3:
			{if (s % 2 == 0)
				PlaySound(TEXT("menu_file_cursor_move.wav"), NULL, SND_ASYNC);
			line++;
			if (line >= menu.numberOfItem() + 14) line = 14;
			break;
			}
			case 2:if (s % 2 == 0)
				PlaySound(TEXT("menu_file_cursor_move.wav"), NULL, SND_ASYNC);
			case 4:
			{if (s % 2 == 0)
				PlaySound(TEXT("menu_file_cursor_move.wav"), NULL, SND_ASYNC);
			line--;
			if (line < 14) line = menu.numberOfItem() - 1 + 14;
			break;
			}
			case 5:
			{	if (s % 2 == 0)
				PlaySound(TEXT("enter.wav"), NULL, SND_ASYNC);
			if (line == 14) {
				system("cls");
				NewGame(pmode, m, s);
				if (pmode == 6) {
					StartGame();
					singleplay_PVC(s, m);
				};
				if (pmode == 11) {
					StartGame();
					multiplay();
				}
				system("cls");
				menu.printMenu();
			}
			if (line == 15) {
				system("cls");
				GotoXY(0, 0);
				LOADGAME(s, load, loadg);

				if (load != 26) {
					system("cls");
					playAfterLoad(loadg, load);
				}

				system("cls");
				menu.printMenu();
			}
			if (line == 16) {
				system("cls");
				SETTINGS(m, s);
				system("cls");
				menu.printMenu();
			}
			if (line == 17) {
				system("cls");
				CREDITS(s);
				system("cls");
				menu.printMenu();
			}
			if (line == 18) {
				system("cls");
				HELPS(s);
				system("cls");
				menu.printMenu();
			}
			if (line == 19) EXIT = true;
			break;
			}
			}
			SetConsoleTextAttribute(hConsoleColor, 240);
			gotoxy(50, line);
			cout << ">>";
			gotoxy(66, line);
			cout << "<<";

		}
	}
	menu.deleteMenu();
	gotoxy(30, 5);
	cout << "  _____                 _ _                  _";
	gotoxy(30, 6);
	cout << " / ____|               | | |                | |";
	gotoxy(30, 7);
	cout << "| |  __  ___   ___   __| | |__  _   _  ___  | |";
	gotoxy(30, 8);
	cout << "| | |_ |/ _ \\ / _ \\ / _` | '_ \\| | | |/ _ \\ | |";
	gotoxy(30, 9);
	cout << "| |__| | (_) | (_) | (_| | |_) | |_| |  __/ |_|";
	gotoxy(30, 10);
	cout << " \\_____|\\___/ \\___/ \\__,_|_.__/ \\__, |\\___| (_)";
	gotoxy(30, 11);
	cout << "                                 __/ |         ";
	gotoxy(30, 12);
	cout << "                                |___/          ";
	Sleep(1500);
	return;
}






