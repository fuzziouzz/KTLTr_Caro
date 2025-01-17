﻿
#include "Algorithm.h"
#include "global.h"
#include "Graphics.h"
#include "Manage.h"

void moveEffect(int s) {
	if (s % 2 == 0)
		PlaySound(TEXT("map_move.wav"), NULL, SND_ASYNC);
	if (_TURN) {
		GotoXY(_X, _Y);
		TextColor(240);
		printf("x");
	}
	else {
		GotoXY(_X, _Y);
		TextColor(240);
		printf("o");
	}
	GotoXY(_X, _Y);
}
void _moveEffect() {
	for (int i = 0; i < _BOARD_SIZE; i++) {
		for (int j = 0; j < _BOARD_SIZE; j++) {
			if (_A[i][j].x == _X && _A[i][j].y == _Y && _A[i][j].c == 0)
			{
				TextColor(240);
				printf(" ");
				GotoXY(_X, _Y);
			}
		}
	}
	for (int i = 0; i < _BOARD_SIZE; i++) {
		for (int j = 0; j < _BOARD_SIZE; j++) {
			if (_A[i][j].x == _X && _A[i][j].y == _Y && _A[i][j].c != 0)
			{
				if (_A[i][j].x != LastMove.x || _A[i][j].y != LastMove.y)
				{
					if (_A[i][j].c == 1)
					{
						TextColor(241);
						printf("O");
					}
					else {
						TextColor(244);
						printf("X");
					}
				}
				else if (_A[i][j].x == LastMove.x && _A[i][j].y == LastMove.y)
				{
					if (_A[i][j].c == 1)
					{
						TextColor(177);
						printf("O");
					}
					else {
						TextColor(180);
						printf("X");
					}
				}
				GotoXY(_X, _Y);
			}
		}
	}


}

void DrawBoard(int n) {

	HieuUngBanCo();

	GotoXY(_LEFT, _TOP);
	printf("%c%c%c%c", trentrai, ngang, ngang, ngang);
	for (int i = 0; i < n - 1; i++)
		printf("%c%c%c%c", trenngang, ngang, ngang, ngang);
	printf("%c", trenphai);

	for (int i = 0; i < n * 2; i += 2)
	{
		GotoXY(_LEFT, _TOP + i + 1);
		printf("%c", doc);
		for (int j = 0; j < n; j++) { printf("   "); printf("%c", doc); };
	}

	for (int i = 0; i < n - 1; i++) { GotoXY(_LEFT, 2 + _TOP + 2 * i); printf("%c%c%c%c", doctrai, ngang, ngang, ngang); for (int j = 0; j < n - 1; j++) printf("%c%c%c%c", docngang, ngang, ngang, ngang); printf("%c", docphai); }

	GotoXY(_LEFT, _TOP + (n * 2));
	printf("%c%c%c%c", duoitrai, ngang, ngang, ngang); for (int i = 0; i < n - 1; i++) printf("%c%c%c%c", duoingnang, ngang, ngang, ngang); printf("%c\n", duoiphai);
}


void DRAW_animate() {//DRAW
	/*
	## = BLUE
	@@ = BLACK
	!! = RED
	$$ = PURPLE
	*/
	SetConsoleTextAttribute(hConsoleColor, 0);
	cout << "==";
	SetConsoleTextAttribute(hConsoleColor, 221);
	cout << "==================================================================================================================";
	SetConsoleTextAttribute(hConsoleColor, 0);
	cout << "==" << endl;
	cout << "==";
	SetConsoleTextAttribute(hConsoleColor, 221);
	cout << "==";
	SetConsoleTextAttribute(hConsoleColor, 255);
	cout << "                                                                                                              ";
	SetConsoleTextAttribute(hConsoleColor, 221);
	cout << "==";
	SetConsoleTextAttribute(hConsoleColor, 0);
	cout << "==" << endl;

	SetConsoleTextAttribute(hConsoleColor, 0);
	cout << "==";
	SetConsoleTextAttribute(hConsoleColor, 221);
	cout << "==";
	SetConsoleTextAttribute(hConsoleColor, 255);
	cout << "                   ";
	SetConsoleTextAttribute(hConsoleColor, 0);
	cout << "@@";
	SetConsoleTextAttribute(hConsoleColor, 51);
	cout << "######";
	SetConsoleTextAttribute(hConsoleColor, 255);
	cout << "        ";
	SetConsoleTextAttribute(hConsoleColor, 0);
	cout << "@@";
	SetConsoleTextAttribute(hConsoleColor, 221);
	cout << "$$$$$$$$";
	SetConsoleTextAttribute(hConsoleColor, 255);
	cout << "        ";
	SetConsoleTextAttribute(hConsoleColor, 0);
	cout << "@@";
	SetConsoleTextAttribute(hConsoleColor, 68);
	cout << "!!!!!!";
	SetConsoleTextAttribute(hConsoleColor, 255);
	cout << "      ";
	SetConsoleTextAttribute(hConsoleColor, 0);
	cout << "@@";
	SetConsoleTextAttribute(hConsoleColor, 68);
	cout << "!!";
	SetConsoleTextAttribute(hConsoleColor, 255);
	cout << "            ";
	SetConsoleTextAttribute(hConsoleColor, 0);
	cout << "@@";
	SetConsoleTextAttribute(hConsoleColor, 68);
	cout << "!!";
	SetConsoleTextAttribute(hConsoleColor, 255);
	cout << "                       ";
	SetConsoleTextAttribute(hConsoleColor, 221);
	cout << "==";
	SetConsoleTextAttribute(hConsoleColor, 0);
	cout << "==" << endl;

	SetConsoleTextAttribute(hConsoleColor, 0);
	cout << "==";
	SetConsoleTextAttribute(hConsoleColor, 221);
	cout << "==";
	SetConsoleTextAttribute(hConsoleColor, 255);
	cout << "                   ";
	SetConsoleTextAttribute(hConsoleColor, 0);
	cout << "@@";
	SetConsoleTextAttribute(hConsoleColor, 51);
	cout << "##";
	SetConsoleTextAttribute(hConsoleColor, 255);
	cout << "  ";
	SetConsoleTextAttribute(hConsoleColor, 0);
	cout << "@@";
	SetConsoleTextAttribute(hConsoleColor, 51);
	cout << "##";
	SetConsoleTextAttribute(hConsoleColor, 255);
	cout << "      ";
	SetConsoleTextAttribute(hConsoleColor, 0);
	cout << "@@";
	SetConsoleTextAttribute(hConsoleColor, 221);
	cout << "$$";
	SetConsoleTextAttribute(hConsoleColor, 255);
	cout << "    ";
	SetConsoleTextAttribute(hConsoleColor, 0);
	cout << "@@";
	SetConsoleTextAttribute(hConsoleColor, 221);
	cout << "$$";
	SetConsoleTextAttribute(hConsoleColor, 255);
	cout << "    ";
	SetConsoleTextAttribute(hConsoleColor, 0);
	cout << "@@";
	SetConsoleTextAttribute(hConsoleColor, 221);
	cout << "$$";
	SetConsoleTextAttribute(hConsoleColor, 255);
	cout << "    ";
	SetConsoleTextAttribute(hConsoleColor, 0);
	cout << "@@";
	SetConsoleTextAttribute(hConsoleColor, 68);
	cout << "!!";
	SetConsoleTextAttribute(hConsoleColor, 255);
	cout << "    ";
	SetConsoleTextAttribute(hConsoleColor, 0);
	cout << "@@";
	SetConsoleTextAttribute(hConsoleColor, 68);
	cout << "!!";
	SetConsoleTextAttribute(hConsoleColor, 255);
	cout << "            ";
	SetConsoleTextAttribute(hConsoleColor, 0);
	cout << "@@";
	SetConsoleTextAttribute(hConsoleColor, 68);
	cout << "!!";
	SetConsoleTextAttribute(hConsoleColor, 255);
	cout << "                       ";
	SetConsoleTextAttribute(hConsoleColor, 221);
	cout << "==";
	SetConsoleTextAttribute(hConsoleColor, 0);
	cout << "==" << endl;

	SetConsoleTextAttribute(hConsoleColor, 0);
	cout << "==";
	SetConsoleTextAttribute(hConsoleColor, 221);
	cout << "==";
	SetConsoleTextAttribute(hConsoleColor, 255);
	cout << "                   ";
	SetConsoleTextAttribute(hConsoleColor, 0);
	cout << "@@";
	SetConsoleTextAttribute(hConsoleColor, 51);
	cout << "##";
	SetConsoleTextAttribute(hConsoleColor, 255);
	cout << "    ";
	SetConsoleTextAttribute(hConsoleColor, 0);
	cout << "@@";
	SetConsoleTextAttribute(hConsoleColor, 51);
	cout << "##";
	SetConsoleTextAttribute(hConsoleColor, 255);
	cout << "    ";
	SetConsoleTextAttribute(hConsoleColor, 0);
	cout << "@@";
	SetConsoleTextAttribute(hConsoleColor, 51);
	cout << "##";
	SetConsoleTextAttribute(hConsoleColor, 255);
	cout << "    ";
	SetConsoleTextAttribute(hConsoleColor, 0);
	cout << "@@";
	SetConsoleTextAttribute(hConsoleColor, 221);
	cout << "$$";
	SetConsoleTextAttribute(hConsoleColor, 255);
	cout << "    ";
	SetConsoleTextAttribute(hConsoleColor, 0);
	cout << "@@";
	SetConsoleTextAttribute(hConsoleColor, 221);
	cout << "$$";
	SetConsoleTextAttribute(hConsoleColor, 255);
	cout << "    ";
	SetConsoleTextAttribute(hConsoleColor, 0);
	cout << "@@";
	SetConsoleTextAttribute(hConsoleColor, 68);
	cout << "!!";
	SetConsoleTextAttribute(hConsoleColor, 255);
	cout << "    ";
	SetConsoleTextAttribute(hConsoleColor, 0);
	cout << "@@";
	SetConsoleTextAttribute(hConsoleColor, 68);
	cout << "!!";
	SetConsoleTextAttribute(hConsoleColor, 255);
	cout << "    ";
	SetConsoleTextAttribute(hConsoleColor, 0);
	cout << "@@";
	SetConsoleTextAttribute(hConsoleColor, 68);
	cout << "!!";
	SetConsoleTextAttribute(hConsoleColor, 255);
	cout << "    ";
	SetConsoleTextAttribute(hConsoleColor, 0);
	cout << "@@";
	SetConsoleTextAttribute(hConsoleColor, 68);
	cout << "!!";
	SetConsoleTextAttribute(hConsoleColor, 255);
	cout << "                       ";
	SetConsoleTextAttribute(hConsoleColor, 221);
	cout << "==";
	SetConsoleTextAttribute(hConsoleColor, 0);
	cout << "==" << endl;

	SetConsoleTextAttribute(hConsoleColor, 0);
	cout << "==";
	SetConsoleTextAttribute(hConsoleColor, 221);
	cout << "==";
	SetConsoleTextAttribute(hConsoleColor, 255);
	cout << "                   ";
	SetConsoleTextAttribute(hConsoleColor, 0);
	cout << "@@";
	SetConsoleTextAttribute(hConsoleColor, 51);
	cout << "##";
	SetConsoleTextAttribute(hConsoleColor, 255);
	cout << "    ";
	SetConsoleTextAttribute(hConsoleColor, 0);
	cout << "@@";
	SetConsoleTextAttribute(hConsoleColor, 51);
	cout << "##";
	SetConsoleTextAttribute(hConsoleColor, 255);
	cout << "    ";
	SetConsoleTextAttribute(hConsoleColor, 0);
	cout << "@@";
	SetConsoleTextAttribute(hConsoleColor, 51);
	cout << "####";
	SetConsoleTextAttribute(hConsoleColor, 221);
	cout << "$$$$";
	SetConsoleTextAttribute(hConsoleColor, 255);
	cout << "      ";
	SetConsoleTextAttribute(hConsoleColor, 0);
	cout << "@@";
	SetConsoleTextAttribute(hConsoleColor, 221);
	cout << "$$$$$$";
	SetConsoleTextAttribute(hConsoleColor, 68);
	cout << "!!!!";
	SetConsoleTextAttribute(hConsoleColor, 255);
	cout << "      ";
	SetConsoleTextAttribute(hConsoleColor, 0);
	cout << "@@";
	SetConsoleTextAttribute(hConsoleColor, 68);
	cout << "!!";
	SetConsoleTextAttribute(hConsoleColor, 255);
	cout << "  ";
	SetConsoleTextAttribute(hConsoleColor, 0);
	cout << "@@";
	SetConsoleTextAttribute(hConsoleColor, 68);
	cout << "!!";
	SetConsoleTextAttribute(hConsoleColor, 255);
	cout << "  ";
	SetConsoleTextAttribute(hConsoleColor, 0);
	cout << "@@";
	SetConsoleTextAttribute(hConsoleColor, 68);
	cout << "!!";
	SetConsoleTextAttribute(hConsoleColor, 255);
	cout << "                         ";
	SetConsoleTextAttribute(hConsoleColor, 221);
	cout << "==";
	SetConsoleTextAttribute(hConsoleColor, 0);
	cout << "==" << endl;

	SetConsoleTextAttribute(hConsoleColor, 0);
	cout << "==";
	SetConsoleTextAttribute(hConsoleColor, 221);
	cout << "==";
	SetConsoleTextAttribute(hConsoleColor, 255);
	cout << "                   ";
	SetConsoleTextAttribute(hConsoleColor, 0);
	cout << "@@";
	SetConsoleTextAttribute(hConsoleColor, 51);
	cout << "##";
	SetConsoleTextAttribute(hConsoleColor, 255);
	cout << "    ";
	SetConsoleTextAttribute(hConsoleColor, 0);
	cout << "@@";
	SetConsoleTextAttribute(hConsoleColor, 51);
	cout << "##";
	SetConsoleTextAttribute(hConsoleColor, 255);
	cout << "    ";
	SetConsoleTextAttribute(hConsoleColor, 0);
	cout << "@@";
	SetConsoleTextAttribute(hConsoleColor, 51);
	cout << "##";
	SetConsoleTextAttribute(hConsoleColor, 0);
	cout << "@@";
	SetConsoleTextAttribute(hConsoleColor, 51);
	cout << "##";
	SetConsoleTextAttribute(hConsoleColor, 255);
	cout << "        ";
	SetConsoleTextAttribute(hConsoleColor, 0);
	cout << "@@";
	SetConsoleTextAttribute(hConsoleColor, 221);
	cout << "$$";
	SetConsoleTextAttribute(hConsoleColor, 255);
	cout << "    ";
	SetConsoleTextAttribute(hConsoleColor, 0);
	cout << "@@";
	SetConsoleTextAttribute(hConsoleColor, 68);
	cout << "!!";
	SetConsoleTextAttribute(hConsoleColor, 255);
	cout << "      ";
	SetConsoleTextAttribute(hConsoleColor, 0);
	cout << "@@";
	SetConsoleTextAttribute(hConsoleColor, 68);
	cout << "!!";
	SetConsoleTextAttribute(hConsoleColor, 0);
	cout << "@@";
	SetConsoleTextAttribute(hConsoleColor, 68);
	cout << "!!";
	SetConsoleTextAttribute(hConsoleColor, 0);
	cout << "@@";
	SetConsoleTextAttribute(hConsoleColor, 68);
	cout << "!!";
	SetConsoleTextAttribute(hConsoleColor, 0);
	cout << "@@";
	SetConsoleTextAttribute(hConsoleColor, 68);
	cout << "!!";
	SetConsoleTextAttribute(hConsoleColor, 255);
	cout << "                         ";
	SetConsoleTextAttribute(hConsoleColor, 221);
	cout << "==";
	SetConsoleTextAttribute(hConsoleColor, 0);
	cout << "==" << endl;

	SetConsoleTextAttribute(hConsoleColor, 0);
	cout << "==";
	SetConsoleTextAttribute(hConsoleColor, 221);
	cout << "==";
	SetConsoleTextAttribute(hConsoleColor, 255);
	cout << "                   ";
	SetConsoleTextAttribute(hConsoleColor, 0);
	cout << "@@";
	SetConsoleTextAttribute(hConsoleColor, 51);
	cout << "##";
	SetConsoleTextAttribute(hConsoleColor, 255);
	cout << "  ";
	SetConsoleTextAttribute(hConsoleColor, 0);
	cout << "@@";
	SetConsoleTextAttribute(hConsoleColor, 51);
	cout << "##";
	SetConsoleTextAttribute(hConsoleColor, 0);
	cout << "@@";
	SetConsoleTextAttribute(hConsoleColor, 255);
	cout << "    ";
	SetConsoleTextAttribute(hConsoleColor, 0);
	cout << "@@";
	SetConsoleTextAttribute(hConsoleColor, 51);
	cout << "##";
	SetConsoleTextAttribute(hConsoleColor, 255);
	cout << "  ";
	SetConsoleTextAttribute(hConsoleColor, 0);
	cout << "@@";
	SetConsoleTextAttribute(hConsoleColor, 51);
	cout << "##";
	SetConsoleTextAttribute(hConsoleColor, 255);
	cout << "      ";
	SetConsoleTextAttribute(hConsoleColor, 0);
	cout << "@@";
	SetConsoleTextAttribute(hConsoleColor, 221);
	cout << "$$";
	SetConsoleTextAttribute(hConsoleColor, 255);
	cout << "    ";
	SetConsoleTextAttribute(hConsoleColor, 0);
	cout << "@@";
	SetConsoleTextAttribute(hConsoleColor, 68);
	cout << "!!";
	SetConsoleTextAttribute(hConsoleColor, 255);
	cout << "      ";
	SetConsoleTextAttribute(hConsoleColor, 0);
	cout << "@@";
	SetConsoleTextAttribute(hConsoleColor, 68);
	cout << "!!";
	SetConsoleTextAttribute(hConsoleColor, 0);
	cout << "@@";
	SetConsoleTextAttribute(hConsoleColor, 68);
	cout << "!!";
	SetConsoleTextAttribute(hConsoleColor, 0);
	cout << "@@";
	SetConsoleTextAttribute(hConsoleColor, 68);
	cout << "!!";
	SetConsoleTextAttribute(hConsoleColor, 0);
	cout << "@@";
	SetConsoleTextAttribute(hConsoleColor, 68);
	cout << "!!";
	SetConsoleTextAttribute(hConsoleColor, 255);
	cout << "                         ";
	SetConsoleTextAttribute(hConsoleColor, 221);
	cout << "==";
	SetConsoleTextAttribute(hConsoleColor, 0);
	cout << "==" << endl;

	SetConsoleTextAttribute(hConsoleColor, 0);
	cout << "==";
	SetConsoleTextAttribute(hConsoleColor, 221);
	cout << "==";
	SetConsoleTextAttribute(hConsoleColor, 255);
	cout << "                   ";
	SetConsoleTextAttribute(hConsoleColor, 0);
	cout << "@@";
	SetConsoleTextAttribute(hConsoleColor, 51);
	cout << "######";
	SetConsoleTextAttribute(hConsoleColor, 0);
	cout << "@@";
	SetConsoleTextAttribute(hConsoleColor, 255);
	cout << "      ";
	SetConsoleTextAttribute(hConsoleColor, 0);
	cout << "@@";
	SetConsoleTextAttribute(hConsoleColor, 51);
	cout << "##";
	SetConsoleTextAttribute(hConsoleColor, 255);
	cout << "    ";
	SetConsoleTextAttribute(hConsoleColor, 0);
	cout << "@@";
	SetConsoleTextAttribute(hConsoleColor, 51);
	cout << "##";
	SetConsoleTextAttribute(hConsoleColor, 255);
	cout << "    ";
	SetConsoleTextAttribute(hConsoleColor, 0);
	cout << "@@";
	SetConsoleTextAttribute(hConsoleColor, 221);
	cout << "$$";
	SetConsoleTextAttribute(hConsoleColor, 255);
	cout << "    ";
	SetConsoleTextAttribute(hConsoleColor, 0);
	cout << "@@";
	SetConsoleTextAttribute(hConsoleColor, 68);
	cout << "!!";
	SetConsoleTextAttribute(hConsoleColor, 255);
	cout << "        ";
	SetConsoleTextAttribute(hConsoleColor, 0);
	cout << "@@";
	SetConsoleTextAttribute(hConsoleColor, 68);
	cout << "!!";
	SetConsoleTextAttribute(hConsoleColor, 255);
	cout << "    ";
	SetConsoleTextAttribute(hConsoleColor, 0);
	cout << "@@";
	SetConsoleTextAttribute(hConsoleColor, 68);
	cout << "!!";
	SetConsoleTextAttribute(hConsoleColor, 255);
	cout << "                           ";
	SetConsoleTextAttribute(hConsoleColor, 221);
	cout << "==";
	SetConsoleTextAttribute(hConsoleColor, 0);
	cout << "==" << endl;

	SetConsoleTextAttribute(hConsoleColor, 0);
	cout << "==";
	SetConsoleTextAttribute(hConsoleColor, 221);
	cout << "==";
	SetConsoleTextAttribute(hConsoleColor, 255);
	cout << "                   ";
	SetConsoleTextAttribute(hConsoleColor, 0);
	cout << "@@@@@@@@";
	SetConsoleTextAttribute(hConsoleColor, 255);
	cout << "        ";
	SetConsoleTextAttribute(hConsoleColor, 0);
	cout << "@@@@";
	SetConsoleTextAttribute(hConsoleColor, 255);
	cout << "      ";
	SetConsoleTextAttribute(hConsoleColor, 0);
	cout << "@@";
	SetConsoleTextAttribute(hConsoleColor, 255);
	cout << "    ";
	SetConsoleTextAttribute(hConsoleColor, 0);
	cout << "@@@@";
	SetConsoleTextAttribute(hConsoleColor, 255);
	cout << "    ";
	SetConsoleTextAttribute(hConsoleColor, 0);
	cout << "@@@@";
	SetConsoleTextAttribute(hConsoleColor, 255);
	cout << "        ";
	SetConsoleTextAttribute(hConsoleColor, 0);
	cout << "@@@@";
	SetConsoleTextAttribute(hConsoleColor, 255);
	cout << "    ";
	SetConsoleTextAttribute(hConsoleColor, 0);
	cout << "@@@@";
	SetConsoleTextAttribute(hConsoleColor, 255);
	cout << "                           ";
	SetConsoleTextAttribute(hConsoleColor, 221);
	cout << "==";
	SetConsoleTextAttribute(hConsoleColor, 0);
	cout << "==" << endl;
	SetConsoleTextAttribute(hConsoleColor, 0);
	cout << "==";
	SetConsoleTextAttribute(hConsoleColor, 221);
	cout << "==";
	SetConsoleTextAttribute(hConsoleColor, 255);
	cout << "                                                                                                              ";
	SetConsoleTextAttribute(hConsoleColor, 221);
	cout << "==";
	SetConsoleTextAttribute(hConsoleColor, 0);
	cout << "==" << endl;
	SetConsoleTextAttribute(hConsoleColor, 0);
	cout << "==";
	SetConsoleTextAttribute(hConsoleColor, 221);
	cout << "==================================================================================================================";
	SetConsoleTextAttribute(hConsoleColor, 0);
	cout << "==" << endl;
}

void HieuUngBanCo() {
	GotoXY(_LEFT, _TOP);
	printf("%c", 218);
	for (int i = 0; i < _BOARD_SIZE * 4; i++)
	{
		printf("%c", 196);
	}
	GotoXY(_LEFT + _BOARD_SIZE * 4, _TOP); printf("%c", 191);


	for (int i = 1; i < _BOARD_SIZE * 2; i++)
	{
		GotoXY(_LEFT + _BOARD_SIZE * 4, i + _TOP);
		printf("%c", 179);
		
	}
	GotoXY(_LEFT + _BOARD_SIZE * 4, _BOARD_SIZE * 2 + _TOP); printf("%c", 217);

	for (int i = _BOARD_SIZE * 4 + _LEFT - 1; i >= _LEFT; i--)
	{
		GotoXY(i, _BOARD_SIZE * 2 + _TOP);
		printf("%c", 196);
		
	}
	GotoXY(_LEFT, _BOARD_SIZE * 2 + _TOP); printf("%c", 192);

	for (int i = _BOARD_SIZE * 2 - 1 + _TOP; i > _TOP; i--)
	{
		GotoXY(_LEFT, i);
		printf("%c", 179);
		
	}
}
void Mainmenu() {
	SetConsoleTextAttribute(hConsoleColor, 255);
	cout << "                                                                                                                       " << endl;
	cout << "                                                                                                                       " << endl;
	cout << "                                                                                                                       " << endl;
	cout << "                                                                                                                       " << endl;
	cout << "                                                                                                                       " << endl;
	cout << "                                                                                                                       " << endl;
	cout << "                                                                                                                       " << endl;
	cout << "                                                                                                                       " << endl;
	cout << "                                                                                                                       " << endl;
	cout << "                                                                                                                       " << endl;
	cout << "                                                                                                                       " << endl;
	cout << "                                                                                                                       " << endl;
	cout << "                                                                                                                       " << endl;
	cout << "                                                                                                                       " << endl;
	cout << "                                                                                                                       " << endl;
	cout << "                                                                                                                       " << endl;
	cout << "                                                                                                                       " << endl;
	cout << "                                                                                                                       " << endl;
	cout << "                                                                                                                       " << endl;
	cout << "                                                                                                                       " << endl;
	cout << "                                                                                                                       " << endl;
	cout << "                                                                                                                       " << endl;
	cout << "                                                                                                                       " << endl;
	cout << "                                                                                                                       " << endl;
	cout << "                                                                                                                       " << endl;
	cout << "                                                                                                                       " << endl;
	cout << "                                                                                                                       " << endl;
	cout << "                                                                                                                       " << endl;
	cout << "                                                                                                                       " << endl;
	cout << "                                                                                                                       " << endl;
}
void X_WIN_animate() {
	SetConsoleTextAttribute(hConsoleColor, 0);
	cout << "  ";
	SetConsoleTextAttribute(hConsoleColor, 68);
	cout << "==================================================================================================================";
	SetConsoleTextAttribute(hConsoleColor, 0);
	cout << "==" << endl;
	SetConsoleTextAttribute(hConsoleColor, 0);
	cout << "  ";
	SetConsoleTextAttribute(hConsoleColor, 68);
	cout << "  ";
	SetConsoleTextAttribute(hConsoleColor, 255);
	cout << "                                                                                                              ";
	SetConsoleTextAttribute(hConsoleColor, 68);
	cout << "  ";
	SetConsoleTextAttribute(hConsoleColor, 0);
	cout << "  " << endl;

	SetConsoleTextAttribute(hConsoleColor, 0);
	cout << "  ";
	SetConsoleTextAttribute(hConsoleColor, 68);
	cout << "  ";
	SetConsoleTextAttribute(hConsoleColor, 255);
	cout << "      ";
	SetConsoleTextAttribute(hConsoleColor, 119);
	cout << "!!";
	SetConsoleTextAttribute(hConsoleColor, 136);
	cout << "%%";
	SetConsoleTextAttribute(hConsoleColor, 0);
	cout << "@@@@";
	SetConsoleTextAttribute(hConsoleColor, 255);
	cout << "  ";
	SetConsoleTextAttribute(hConsoleColor, 119);
	cout << "!!";
	SetConsoleTextAttribute(hConsoleColor, 136);
	cout << "%%";
	SetConsoleTextAttribute(hConsoleColor, 0);
	cout << "@@@@";
	SetConsoleTextAttribute(hConsoleColor, 255);
	cout << "                 ";
	SetConsoleTextAttribute(hConsoleColor, 119);
	cout << "!!";
	SetConsoleTextAttribute(hConsoleColor, 136);
	cout << "%%";
	SetConsoleTextAttribute(hConsoleColor, 0);
	cout << "@@";
	SetConsoleTextAttribute(hConsoleColor, 68);
	cout << "##";
	SetConsoleTextAttribute(hConsoleColor, 255);
	cout << "        ";
	SetConsoleTextAttribute(hConsoleColor, 119);
	cout << "!!";
	SetConsoleTextAttribute(hConsoleColor, 136);
	cout << "%%";
	SetConsoleTextAttribute(hConsoleColor, 0);
	cout << "@@";
	SetConsoleTextAttribute(hConsoleColor, 68);
	cout << "##";
	SetConsoleTextAttribute(hConsoleColor, 119);
	cout << "!!";
	SetConsoleTextAttribute(hConsoleColor, 136);
	cout << "%%";
	SetConsoleTextAttribute(hConsoleColor, 0);
	cout << "@@";
	SetConsoleTextAttribute(hConsoleColor, 68);
	cout << "##########";
	SetConsoleTextAttribute(hConsoleColor, 119);
	cout << "!!";
	SetConsoleTextAttribute(hConsoleColor, 136);
	cout << "%%";
	SetConsoleTextAttribute(hConsoleColor, 0);
	cout << "@@";
	SetConsoleTextAttribute(hConsoleColor, 68);
	cout << "##";
	SetConsoleTextAttribute(hConsoleColor, 255);
	cout << "    ";
	SetConsoleTextAttribute(hConsoleColor, 119);
	cout << "!!";
	SetConsoleTextAttribute(hConsoleColor, 136);
	cout << "%%";
	SetConsoleTextAttribute(hConsoleColor, 0);
	cout << "@@";
	SetConsoleTextAttribute(hConsoleColor, 68);
	cout << "##";
	SetConsoleTextAttribute(hConsoleColor, 255);
	cout << "         ";
	SetConsoleTextAttribute(hConsoleColor, 68);
	cout << "  ";
	SetConsoleTextAttribute(hConsoleColor, 0);
	cout << "  " << endl;
	SetConsoleTextAttribute(hConsoleColor, 0);
	cout << "  ";
	SetConsoleTextAttribute(hConsoleColor, 68);
	cout << "  ";
	SetConsoleTextAttribute(hConsoleColor, 255);
	cout << "      ";
	SetConsoleTextAttribute(hConsoleColor, 119);
	cout << "!!";
	SetConsoleTextAttribute(hConsoleColor, 136);
	cout << "%%";
	SetConsoleTextAttribute(hConsoleColor, 0);
	cout << "@@";
	SetConsoleTextAttribute(hConsoleColor, 68);
	cout << "##";
	SetConsoleTextAttribute(hConsoleColor, 0);
	cout << "@@";
	SetConsoleTextAttribute(hConsoleColor, 136);
	cout << "%%";
	SetConsoleTextAttribute(hConsoleColor, 0);
	cout << "@@";
	SetConsoleTextAttribute(hConsoleColor, 68);
	cout << "##";
	SetConsoleTextAttribute(hConsoleColor, 0);
	cout << "@@";
	SetConsoleTextAttribute(hConsoleColor, 255);
	cout << "                 ";
	SetConsoleTextAttribute(hConsoleColor, 119);
	cout << "!!";
	SetConsoleTextAttribute(hConsoleColor, 136);
	cout << "%%";
	SetConsoleTextAttribute(hConsoleColor, 0);
	cout << "@@";
	SetConsoleTextAttribute(hConsoleColor, 68);
	cout << "##";
	SetConsoleTextAttribute(hConsoleColor, 255);
	cout << "        ";
	SetConsoleTextAttribute(hConsoleColor, 119);
	cout << "!!";
	SetConsoleTextAttribute(hConsoleColor, 136);
	cout << "%%";
	SetConsoleTextAttribute(hConsoleColor, 0);
	cout << "@@";
	SetConsoleTextAttribute(hConsoleColor, 68);
	cout << "##";
	SetConsoleTextAttribute(hConsoleColor, 255);
	cout << "    ";
	SetConsoleTextAttribute(hConsoleColor, 119);
	cout << "!!";
	SetConsoleTextAttribute(hConsoleColor, 136);
	cout << "%%";
	SetConsoleTextAttribute(hConsoleColor, 0);
	cout << "@@";
	SetConsoleTextAttribute(hConsoleColor, 68);
	cout << "##";
	SetConsoleTextAttribute(hConsoleColor, 255);
	cout << "    ";
	SetConsoleTextAttribute(hConsoleColor, 119);
	cout << "!!";
	SetConsoleTextAttribute(hConsoleColor, 136);
	cout << "%%";
	SetConsoleTextAttribute(hConsoleColor, 0);
	cout << "@@";
	SetConsoleTextAttribute(hConsoleColor, 68);
	cout << "####";
	SetConsoleTextAttribute(hConsoleColor, 255);
	cout << "  ";
	SetConsoleTextAttribute(hConsoleColor, 119);
	cout << "!!";
	SetConsoleTextAttribute(hConsoleColor, 136);
	cout << "%%";
	SetConsoleTextAttribute(hConsoleColor, 0);
	cout << "@@";
	SetConsoleTextAttribute(hConsoleColor, 68);
	cout << "##";
	SetConsoleTextAttribute(hConsoleColor, 255);
	cout << "         ";
	SetConsoleTextAttribute(hConsoleColor, 68);
	cout << "  ";
	SetConsoleTextAttribute(hConsoleColor, 0);
	cout << "  " << endl;

	SetConsoleTextAttribute(hConsoleColor, 0);
	cout << "  ";
	SetConsoleTextAttribute(hConsoleColor, 68);
	cout << "  ";
	SetConsoleTextAttribute(hConsoleColor, 255);
	cout << "        ";
	SetConsoleTextAttribute(hConsoleColor, 119);
	cout << "!!";
	SetConsoleTextAttribute(hConsoleColor, 136);
	cout << "%%";
	SetConsoleTextAttribute(hConsoleColor, 0);
	cout << "@@";
	SetConsoleTextAttribute(hConsoleColor, 68);
	cout << "##";
	SetConsoleTextAttribute(hConsoleColor, 0);
	cout << "@@";
	SetConsoleTextAttribute(hConsoleColor, 68);
	cout << "##";
	SetConsoleTextAttribute(hConsoleColor, 0);
	cout << "@@";
	SetConsoleTextAttribute(hConsoleColor, 255);
	cout << "                   ";
	SetConsoleTextAttribute(hConsoleColor, 119);
	cout << "!!";
	SetConsoleTextAttribute(hConsoleColor, 136);
	cout << "%%";
	SetConsoleTextAttribute(hConsoleColor, 0);
	cout << "@@";
	SetConsoleTextAttribute(hConsoleColor, 68);
	cout << "##";
	SetConsoleTextAttribute(hConsoleColor, 119);
	cout << "!!";
	SetConsoleTextAttribute(hConsoleColor, 136);
	cout << "%%";
	SetConsoleTextAttribute(hConsoleColor, 0);
	cout << "@@";
	SetConsoleTextAttribute(hConsoleColor, 68);
	cout << "##";
	SetConsoleTextAttribute(hConsoleColor, 119);
	cout << "!!";
	SetConsoleTextAttribute(hConsoleColor, 136);
	cout << "%%";
	SetConsoleTextAttribute(hConsoleColor, 0);
	cout << "@@";
	SetConsoleTextAttribute(hConsoleColor, 68);
	cout << "##";
	SetConsoleTextAttribute(hConsoleColor, 255);
	cout << "    ";
	SetConsoleTextAttribute(hConsoleColor, 119);
	cout << "!!";
	SetConsoleTextAttribute(hConsoleColor, 136);
	cout << "%%";
	SetConsoleTextAttribute(hConsoleColor, 0);
	cout << "@@";
	SetConsoleTextAttribute(hConsoleColor, 68);
	cout << "##";
	SetConsoleTextAttribute(hConsoleColor, 255);
	cout << "    ";
	SetConsoleTextAttribute(hConsoleColor, 119);
	cout << "!!";
	SetConsoleTextAttribute(hConsoleColor, 136);
	cout << "%%";
	SetConsoleTextAttribute(hConsoleColor, 0);
	cout << "@@";
	SetConsoleTextAttribute(hConsoleColor, 68);
	cout << "##";
	SetConsoleTextAttribute(hConsoleColor, 0);
	cout << "@@";
	SetConsoleTextAttribute(hConsoleColor, 68);
	cout << "##";
	SetConsoleTextAttribute(hConsoleColor, 119);
	cout << "!!";
	SetConsoleTextAttribute(hConsoleColor, 136);
	cout << "%%";
	SetConsoleTextAttribute(hConsoleColor, 0);
	cout << "@@";
	SetConsoleTextAttribute(hConsoleColor, 68);
	cout << "##";
	SetConsoleTextAttribute(hConsoleColor, 255);
	cout << "         ";
	SetConsoleTextAttribute(hConsoleColor, 68);
	cout << "  ";
	SetConsoleTextAttribute(hConsoleColor, 0);
	cout << "  " << endl;

	SetConsoleTextAttribute(hConsoleColor, 0);
	cout << "  ";
	SetConsoleTextAttribute(hConsoleColor, 68);
	cout << "  ";
	SetConsoleTextAttribute(hConsoleColor, 255);
	cout << "          ";
	SetConsoleTextAttribute(hConsoleColor, 119);
	cout << "!!";
	SetConsoleTextAttribute(hConsoleColor, 136);
	cout << "%%";
	SetConsoleTextAttribute(hConsoleColor, 0);
	cout << "@@";
	SetConsoleTextAttribute(hConsoleColor, 68);
	cout << "##";
	SetConsoleTextAttribute(hConsoleColor, 0);
	cout << "@@";
	SetConsoleTextAttribute(hConsoleColor, 255);
	cout << "                       ";
	SetConsoleTextAttribute(hConsoleColor, 119);
	cout << "!!";
	SetConsoleTextAttribute(hConsoleColor, 136);
	cout << "%%";
	SetConsoleTextAttribute(hConsoleColor, 0);
	cout << "@@";
	SetConsoleTextAttribute(hConsoleColor, 68);
	cout << "##";
	SetConsoleTextAttribute(hConsoleColor, 136);
	cout << "%%";
	SetConsoleTextAttribute(hConsoleColor, 0);
	cout << "@@";
	SetConsoleTextAttribute(hConsoleColor, 68);
	cout << "##";
	SetConsoleTextAttribute(hConsoleColor, 136);
	cout << "%%";
	SetConsoleTextAttribute(hConsoleColor, 0);
	cout << "@@";
	SetConsoleTextAttribute(hConsoleColor, 68);
	cout << "##";
	SetConsoleTextAttribute(hConsoleColor, 255);
	cout << "      ";
	SetConsoleTextAttribute(hConsoleColor, 119);
	cout << "!!";
	SetConsoleTextAttribute(hConsoleColor, 136);
	cout << "%%";
	SetConsoleTextAttribute(hConsoleColor, 0);
	cout << "@@";
	SetConsoleTextAttribute(hConsoleColor, 68);
	cout << "##";
	SetConsoleTextAttribute(hConsoleColor, 255);
	cout << "    ";
	SetConsoleTextAttribute(hConsoleColor, 119);
	cout << "!!";
	SetConsoleTextAttribute(hConsoleColor, 136);
	cout << "%%";
	SetConsoleTextAttribute(hConsoleColor, 0);
	cout << "@@";
	SetConsoleTextAttribute(hConsoleColor, 68);
	cout << "##";
	SetConsoleTextAttribute(hConsoleColor, 136);
	cout << "%%";
	SetConsoleTextAttribute(hConsoleColor, 0);
	cout << "@@";
	SetConsoleTextAttribute(hConsoleColor, 68);
	cout << "##";
	SetConsoleTextAttribute(hConsoleColor, 136);
	cout << "%%";
	SetConsoleTextAttribute(hConsoleColor, 0);
	cout << "@@";
	SetConsoleTextAttribute(hConsoleColor, 68);
	cout << "##";
	SetConsoleTextAttribute(hConsoleColor, 255);
	cout << "         ";
	SetConsoleTextAttribute(hConsoleColor, 68);
	cout << "  ";
	SetConsoleTextAttribute(hConsoleColor, 0);
	cout << "  " << endl;

	SetConsoleTextAttribute(hConsoleColor, 0);
	cout << "  ";
	SetConsoleTextAttribute(hConsoleColor, 68);
	cout << "  ";
	SetConsoleTextAttribute(hConsoleColor, 255);
	cout << "        ";
	SetConsoleTextAttribute(hConsoleColor, 119);
	cout << "!!";
	SetConsoleTextAttribute(hConsoleColor, 136);
	cout << "%%";
	SetConsoleTextAttribute(hConsoleColor, 0);
	cout << "@@";
	SetConsoleTextAttribute(hConsoleColor, 68);
	cout << "##";
	SetConsoleTextAttribute(hConsoleColor, 0);
	cout << "@@";
	SetConsoleTextAttribute(hConsoleColor, 68);
	cout << "##";
	SetConsoleTextAttribute(hConsoleColor, 0);
	cout << "@@";
	SetConsoleTextAttribute(hConsoleColor, 255);
	cout << "                     ";
	SetConsoleTextAttribute(hConsoleColor, 119);
	cout << "!!";
	SetConsoleTextAttribute(hConsoleColor, 136);
	cout << "%%";
	SetConsoleTextAttribute(hConsoleColor, 0);
	cout << "@@";
	SetConsoleTextAttribute(hConsoleColor, 68);
	cout << "##";
	SetConsoleTextAttribute(hConsoleColor, 0);
	cout << "@@";
	SetConsoleTextAttribute(hConsoleColor, 68);
	cout << "##";
	SetConsoleTextAttribute(hConsoleColor, 0);
	cout << "@@";
	SetConsoleTextAttribute(hConsoleColor, 68);
	cout << "##";
	SetConsoleTextAttribute(hConsoleColor, 0);
	cout << "@@";
	SetConsoleTextAttribute(hConsoleColor, 68);
	cout << "##";
	SetConsoleTextAttribute(hConsoleColor, 255);
	cout << "      ";
	SetConsoleTextAttribute(hConsoleColor, 119);
	cout << "!!";
	SetConsoleTextAttribute(hConsoleColor, 136);
	cout << "%%";
	SetConsoleTextAttribute(hConsoleColor, 0);
	cout << "@@";
	SetConsoleTextAttribute(hConsoleColor, 68);
	cout << "##";
	SetConsoleTextAttribute(hConsoleColor, 255);
	cout << "    ";
	SetConsoleTextAttribute(hConsoleColor, 119);
	cout << "!!";
	SetConsoleTextAttribute(hConsoleColor, 136);
	cout << "%%";
	SetConsoleTextAttribute(hConsoleColor, 0);
	cout << "@@";
	SetConsoleTextAttribute(hConsoleColor, 68);
	cout << "##";
	SetConsoleTextAttribute(hConsoleColor, 119);
	cout << "!!";
	SetConsoleTextAttribute(hConsoleColor, 136);
	cout << "%%";
	SetConsoleTextAttribute(hConsoleColor, 0);
	cout << "@@";
	SetConsoleTextAttribute(hConsoleColor, 68);
	cout << "##";
	SetConsoleTextAttribute(hConsoleColor, 0);
	cout << "@@";
	SetConsoleTextAttribute(hConsoleColor, 68);
	cout << "##";
	SetConsoleTextAttribute(hConsoleColor, 255);
	cout << "         ";
	SetConsoleTextAttribute(hConsoleColor, 68);
	cout << "  ";
	SetConsoleTextAttribute(hConsoleColor, 0);
	cout << "  " << endl;

	SetConsoleTextAttribute(hConsoleColor, 0);
	cout << "  ";
	SetConsoleTextAttribute(hConsoleColor, 68);
	cout << "  ";
	SetConsoleTextAttribute(hConsoleColor, 255);
	cout << "      ";
	SetConsoleTextAttribute(hConsoleColor, 119);
	cout << "!!";
	SetConsoleTextAttribute(hConsoleColor, 136);
	cout << "%%";
	SetConsoleTextAttribute(hConsoleColor, 0);
	cout << "@@";
	SetConsoleTextAttribute(hConsoleColor, 68);
	cout << "##";
	SetConsoleTextAttribute(hConsoleColor, 0);
	cout << "@@";
	SetConsoleTextAttribute(hConsoleColor, 136);
	cout << "%%";
	SetConsoleTextAttribute(hConsoleColor, 0);
	cout << "@@";
	SetConsoleTextAttribute(hConsoleColor, 68);
	cout << "##";
	SetConsoleTextAttribute(hConsoleColor, 0);
	cout << "@@";
	SetConsoleTextAttribute(hConsoleColor, 255);
	cout << "                   ";
	SetConsoleTextAttribute(hConsoleColor, 119);
	cout << "!!";
	SetConsoleTextAttribute(hConsoleColor, 136);
	cout << "%%";
	SetConsoleTextAttribute(hConsoleColor, 0);
	cout << "@@";
	SetConsoleTextAttribute(hConsoleColor, 68);
	cout << "##";
	SetConsoleTextAttribute(hConsoleColor, 0);
	cout << "@@";
	SetConsoleTextAttribute(hConsoleColor, 68);
	cout << "##";
	SetConsoleTextAttribute(hConsoleColor, 0);
	cout << "@@";
	SetConsoleTextAttribute(hConsoleColor, 68);
	cout << "##";
	SetConsoleTextAttribute(hConsoleColor, 0);
	cout << "@@";
	SetConsoleTextAttribute(hConsoleColor, 68);
	cout << "##";
	SetConsoleTextAttribute(hConsoleColor, 255);
	cout << "      ";
	SetConsoleTextAttribute(hConsoleColor, 119);
	cout << "!!";
	SetConsoleTextAttribute(hConsoleColor, 136);
	cout << "%%";
	SetConsoleTextAttribute(hConsoleColor, 0);
	cout << "@@";
	SetConsoleTextAttribute(hConsoleColor, 68);
	cout << "##";
	SetConsoleTextAttribute(hConsoleColor, 255);
	cout << "    ";
	SetConsoleTextAttribute(hConsoleColor, 119);
	cout << "!!";
	SetConsoleTextAttribute(hConsoleColor, 136);
	cout << "%%";
	SetConsoleTextAttribute(hConsoleColor, 0);
	cout << "@@";
	SetConsoleTextAttribute(hConsoleColor, 68);
	cout << "##";
	SetConsoleTextAttribute(hConsoleColor, 255);
	cout << "  ";
	SetConsoleTextAttribute(hConsoleColor, 119);
	cout << "!!";
	SetConsoleTextAttribute(hConsoleColor, 136);
	cout << "%%";
	SetConsoleTextAttribute(hConsoleColor, 0);
	cout << "@@";
	SetConsoleTextAttribute(hConsoleColor, 68);
	cout << "####";
	SetConsoleTextAttribute(hConsoleColor, 255);
	cout << "         ";
	SetConsoleTextAttribute(hConsoleColor, 68);
	cout << "  ";
	SetConsoleTextAttribute(hConsoleColor, 0);
	cout << "  " << endl;

	SetConsoleTextAttribute(hConsoleColor, 0);
	cout << "  ";
	SetConsoleTextAttribute(hConsoleColor, 68);
	cout << "  ";
	SetConsoleTextAttribute(hConsoleColor, 255);
	cout << "      ";
	SetConsoleTextAttribute(hConsoleColor, 119);
	cout << "!!";
	SetConsoleTextAttribute(hConsoleColor, 136);
	cout << "%%";
	SetConsoleTextAttribute(hConsoleColor, 0);
	cout << "@@@@";
	SetConsoleTextAttribute(hConsoleColor, 255);
	cout << "  ";
	SetConsoleTextAttribute(hConsoleColor, 119);
	cout << "!!";
	SetConsoleTextAttribute(hConsoleColor, 136);
	cout << "%%";
	SetConsoleTextAttribute(hConsoleColor, 0);
	cout << "@@@@";
	SetConsoleTextAttribute(hConsoleColor, 255);
	cout << "                     ";
	SetConsoleTextAttribute(hConsoleColor, 119);
	cout << "!!";
	SetConsoleTextAttribute(hConsoleColor, 136);
	cout << "%%";
	SetConsoleTextAttribute(hConsoleColor, 0);
	cout << "@@";
	SetConsoleTextAttribute(hConsoleColor, 68);
	cout << "##";
	SetConsoleTextAttribute(hConsoleColor, 119);
	cout << "!!";
	SetConsoleTextAttribute(hConsoleColor, 136);
	cout << "%%";
	SetConsoleTextAttribute(hConsoleColor, 0);
	cout << "@@";
	SetConsoleTextAttribute(hConsoleColor, 68);
	cout << "##";
	SetConsoleTextAttribute(hConsoleColor, 255);
	cout << "    ";
	SetConsoleTextAttribute(hConsoleColor, 119);
	cout << "!!";
	SetConsoleTextAttribute(hConsoleColor, 136);
	cout << "%%";
	SetConsoleTextAttribute(hConsoleColor, 0);
	cout << "@@";
	SetConsoleTextAttribute(hConsoleColor, 68);
	cout << "##########";
	SetConsoleTextAttribute(hConsoleColor, 119);
	cout << "!!";
	SetConsoleTextAttribute(hConsoleColor, 136);
	cout << "%%";
	SetConsoleTextAttribute(hConsoleColor, 0);
	cout << "@@";
	SetConsoleTextAttribute(hConsoleColor, 68);
	cout << "##";
	SetConsoleTextAttribute(hConsoleColor, 255);
	cout << "    ";
	SetConsoleTextAttribute(hConsoleColor, 119);
	cout << "!!";
	SetConsoleTextAttribute(hConsoleColor, 136);
	cout << "%%";
	SetConsoleTextAttribute(hConsoleColor, 0);
	cout << "@@";
	SetConsoleTextAttribute(hConsoleColor, 68);
	cout << "##";
	SetConsoleTextAttribute(hConsoleColor, 255);
	cout << "         ";
	SetConsoleTextAttribute(hConsoleColor, 68);
	cout << "  ";
	SetConsoleTextAttribute(hConsoleColor, 0);
	cout << "  " << endl;

	SetConsoleTextAttribute(hConsoleColor, 0);
	cout << "  ";
	SetConsoleTextAttribute(hConsoleColor, 68);
	cout << "  ";
	SetConsoleTextAttribute(hConsoleColor, 240);
	cout << "                                                                                                              ";
	SetConsoleTextAttribute(hConsoleColor, 68);
	cout << "  ";
	SetConsoleTextAttribute(hConsoleColor, 0);
	cout << "  " << endl;
	SetConsoleTextAttribute(hConsoleColor, 0);
	cout << "  ";
	SetConsoleTextAttribute(hConsoleColor, 68);
	cout << "================================================================================================================";
	SetConsoleTextAttribute(hConsoleColor, 68);
	cout << "  ";
	SetConsoleTextAttribute(hConsoleColor, 0);
	cout << "  " << endl;

	SetConsoleTextAttribute(hConsoleColor, 0);
	cout << "======================================================================================================================" << endl;
}
void O_WIN_animate() {//O_win
	SetConsoleTextAttribute(hConsoleColor, 0);
	cout << "==";
	SetConsoleTextAttribute(hConsoleColor, 51);
	cout << "==================================================================================================================";
	SetConsoleTextAttribute(hConsoleColor, 0);
	cout << "==" << endl;

	cout << "  ";
	SetConsoleTextAttribute(hConsoleColor, 51);
	cout << "  ";
	SetConsoleTextAttribute(hConsoleColor, 255);
	cout << "                                                                                                              ";
	SetConsoleTextAttribute(hConsoleColor, 51);
	cout << "  ";
	SetConsoleTextAttribute(hConsoleColor, 0);
	cout << "  " << endl;
	cout << "  ";
	SetConsoleTextAttribute(hConsoleColor, 51);
	cout << "  ";
	SetConsoleTextAttribute(hConsoleColor, 255);
	cout << "          ";
	SetConsoleTextAttribute(hConsoleColor, 119);
	cout << "!!";
	SetConsoleTextAttribute(hConsoleColor, 136);
	cout << "%%";
	SetConsoleTextAttribute(hConsoleColor, 0);
	cout << "@@@@@@";
	SetConsoleTextAttribute(hConsoleColor, 255);
	cout << "                     ";
	SetConsoleTextAttribute(hConsoleColor, 119);
	cout << "!!";
	SetConsoleTextAttribute(hConsoleColor, 136);
	cout << "%%";
	SetConsoleTextAttribute(hConsoleColor, 0);
	cout << "@@";
	SetConsoleTextAttribute(hConsoleColor, 51);
	cout << "##";
	SetConsoleTextAttribute(hConsoleColor, 255);
	cout << "        ";
	SetConsoleTextAttribute(hConsoleColor, 119);
	cout << "!!";
	SetConsoleTextAttribute(hConsoleColor, 136);
	cout << "%%";
	SetConsoleTextAttribute(hConsoleColor, 0);
	cout << "@@";
	SetConsoleTextAttribute(hConsoleColor, 51);
	cout << "##";
	SetConsoleTextAttribute(hConsoleColor, 119);
	cout << "!!";
	SetConsoleTextAttribute(hConsoleColor, 136);
	cout << "%%";
	SetConsoleTextAttribute(hConsoleColor, 0);
	cout << "@@";
	SetConsoleTextAttribute(hConsoleColor, 51);
	cout << "##########";
	SetConsoleTextAttribute(hConsoleColor, 119);
	cout << "!!";
	SetConsoleTextAttribute(hConsoleColor, 136);
	cout << "%%";
	SetConsoleTextAttribute(hConsoleColor, 0);
	cout << "@@";
	SetConsoleTextAttribute(hConsoleColor, 51);
	cout << "##";
	SetConsoleTextAttribute(hConsoleColor, 255);
	cout << "    ";
	SetConsoleTextAttribute(hConsoleColor, 119);
	cout << "!!";
	SetConsoleTextAttribute(hConsoleColor, 136);
	cout << "%%";
	SetConsoleTextAttribute(hConsoleColor, 0);
	cout << "@@";
	SetConsoleTextAttribute(hConsoleColor, 51);
	cout << "##";
	SetConsoleTextAttribute(hConsoleColor, 255);
	cout << "         ";
	SetConsoleTextAttribute(hConsoleColor, 51);
	cout << "  ";
	SetConsoleTextAttribute(hConsoleColor, 0);
	cout << "  " << endl;

	SetConsoleTextAttribute(hConsoleColor, 0);
	cout << "  ";
	SetConsoleTextAttribute(hConsoleColor, 51);
	cout << "  ";
	SetConsoleTextAttribute(hConsoleColor, 255);
	cout << "        ";
	SetConsoleTextAttribute(hConsoleColor, 119);
	cout << "!!";
	SetConsoleTextAttribute(hConsoleColor, 136);
	cout << "%%";
	SetConsoleTextAttribute(hConsoleColor, 0);
	cout << "@@";
	SetConsoleTextAttribute(hConsoleColor, 51);
	cout << "######";
	SetConsoleTextAttribute(hConsoleColor, 0);
	cout << "@@";
	SetConsoleTextAttribute(hConsoleColor, 255);
	cout << "                   ";
	SetConsoleTextAttribute(hConsoleColor, 119);
	cout << "!!";
	SetConsoleTextAttribute(hConsoleColor, 136);
	cout << "%%";
	SetConsoleTextAttribute(hConsoleColor, 0);
	cout << "@@";
	SetConsoleTextAttribute(hConsoleColor, 51);
	cout << "##";
	SetConsoleTextAttribute(hConsoleColor, 255);
	cout << "        ";
	SetConsoleTextAttribute(hConsoleColor, 119);
	cout << "!!";
	SetConsoleTextAttribute(hConsoleColor, 136);
	cout << "%%";
	SetConsoleTextAttribute(hConsoleColor, 0);
	cout << "@@";
	SetConsoleTextAttribute(hConsoleColor, 51);
	cout << "##";
	SetConsoleTextAttribute(hConsoleColor, 255);
	cout << "    ";
	SetConsoleTextAttribute(hConsoleColor, 119);
	cout << "!!";
	SetConsoleTextAttribute(hConsoleColor, 136);
	cout << "%%";
	SetConsoleTextAttribute(hConsoleColor, 0);
	cout << "@@";
	SetConsoleTextAttribute(hConsoleColor, 51);
	cout << "##";
	SetConsoleTextAttribute(hConsoleColor, 255);
	cout << "    ";
	SetConsoleTextAttribute(hConsoleColor, 119);
	cout << "!!";
	SetConsoleTextAttribute(hConsoleColor, 136);
	cout << "%%";
	SetConsoleTextAttribute(hConsoleColor, 0);
	cout << "@@";
	SetConsoleTextAttribute(hConsoleColor, 51);
	cout << "####";
	SetConsoleTextAttribute(hConsoleColor, 255);
	cout << "  ";
	SetConsoleTextAttribute(hConsoleColor, 119);
	cout << "!!";
	SetConsoleTextAttribute(hConsoleColor, 136);
	cout << "%%";
	SetConsoleTextAttribute(hConsoleColor, 0);
	cout << "@@";
	SetConsoleTextAttribute(hConsoleColor, 51);
	cout << "##";
	SetConsoleTextAttribute(hConsoleColor, 255);
	cout << "         ";
	SetConsoleTextAttribute(hConsoleColor, 51);
	cout << "  ";
	SetConsoleTextAttribute(hConsoleColor, 0);
	cout << "  " << endl;


	SetConsoleTextAttribute(hConsoleColor, 0);
	cout << "  ";
	SetConsoleTextAttribute(hConsoleColor, 51);
	cout << "  ";
	SetConsoleTextAttribute(hConsoleColor, 255);
	cout << "      ";
	SetConsoleTextAttribute(hConsoleColor, 119);
	cout << "!!";
	SetConsoleTextAttribute(hConsoleColor, 136);
	cout << "%%";
	SetConsoleTextAttribute(hConsoleColor, 0);
	cout << "@@";
	SetConsoleTextAttribute(hConsoleColor, 51);
	cout << "##";
	SetConsoleTextAttribute(hConsoleColor, 0);
	cout << "@@@@@@";
	SetConsoleTextAttribute(hConsoleColor, 51);
	cout << "##";
	SetConsoleTextAttribute(hConsoleColor, 0);
	cout << "@@";
	SetConsoleTextAttribute(hConsoleColor, 255);
	cout << "                 ";
	SetConsoleTextAttribute(hConsoleColor, 119);
	cout << "!!";
	SetConsoleTextAttribute(hConsoleColor, 136);
	cout << "%%";
	SetConsoleTextAttribute(hConsoleColor, 0);
	cout << "@@";
	SetConsoleTextAttribute(hConsoleColor, 51);
	cout << "##";
	SetConsoleTextAttribute(hConsoleColor, 119);
	cout << "!!";
	SetConsoleTextAttribute(hConsoleColor, 136);
	cout << "%%";
	SetConsoleTextAttribute(hConsoleColor, 0);
	cout << "@@";
	SetConsoleTextAttribute(hConsoleColor, 51);
	cout << "##";
	SetConsoleTextAttribute(hConsoleColor, 119);
	cout << "!!";
	SetConsoleTextAttribute(hConsoleColor, 136);
	cout << "%%";
	SetConsoleTextAttribute(hConsoleColor, 0);
	cout << "@@";
	SetConsoleTextAttribute(hConsoleColor, 51);
	cout << "##";
	SetConsoleTextAttribute(hConsoleColor, 255);
	cout << "    ";
	SetConsoleTextAttribute(hConsoleColor, 119);
	cout << "!!";
	SetConsoleTextAttribute(hConsoleColor, 136);
	cout << "%%";
	SetConsoleTextAttribute(hConsoleColor, 0);
	cout << "@@";
	SetConsoleTextAttribute(hConsoleColor, 51);
	cout << "##";
	SetConsoleTextAttribute(hConsoleColor, 255);
	cout << "    ";
	SetConsoleTextAttribute(hConsoleColor, 119);
	cout << "!!";
	SetConsoleTextAttribute(hConsoleColor, 136);
	cout << "%%";
	SetConsoleTextAttribute(hConsoleColor, 0);
	cout << "@@";
	SetConsoleTextAttribute(hConsoleColor, 51);
	cout << "##";
	SetConsoleTextAttribute(hConsoleColor, 0);
	cout << "@@";
	SetConsoleTextAttribute(hConsoleColor, 51);
	cout << "##";
	SetConsoleTextAttribute(hConsoleColor, 119);
	cout << "!!";
	SetConsoleTextAttribute(hConsoleColor, 136);
	cout << "%%";
	SetConsoleTextAttribute(hConsoleColor, 0);
	cout << "@@";
	SetConsoleTextAttribute(hConsoleColor, 51);
	cout << "##";
	SetConsoleTextAttribute(hConsoleColor, 255);
	cout << "         ";
	SetConsoleTextAttribute(hConsoleColor, 51);
	cout << "  ";
	SetConsoleTextAttribute(hConsoleColor, 0);
	cout << "  " << endl;


	SetConsoleTextAttribute(hConsoleColor, 0);
	cout << "  ";
	SetConsoleTextAttribute(hConsoleColor, 51);
	cout << "  ";
	SetConsoleTextAttribute(hConsoleColor, 255);
	cout << "      ";
	SetConsoleTextAttribute(hConsoleColor, 119);
	cout << "!!";
	SetConsoleTextAttribute(hConsoleColor, 136);
	cout << "%%";
	SetConsoleTextAttribute(hConsoleColor, 0);
	cout << "@@";
	SetConsoleTextAttribute(hConsoleColor, 51);
	cout << "##";
	SetConsoleTextAttribute(hConsoleColor, 0);
	cout << "@@";
	SetConsoleTextAttribute(hConsoleColor, 136);
	cout << "%%";
	SetConsoleTextAttribute(hConsoleColor, 0);
	cout << "@@";
	SetConsoleTextAttribute(hConsoleColor, 51);
	cout << "##";
	SetConsoleTextAttribute(hConsoleColor, 0);
	cout << "@@";
	SetConsoleTextAttribute(hConsoleColor, 255);
	cout << "                   ";
	SetConsoleTextAttribute(hConsoleColor, 119);
	cout << "!!";
	SetConsoleTextAttribute(hConsoleColor, 136);
	cout << "%%";
	SetConsoleTextAttribute(hConsoleColor, 0);
	cout << "@@";
	SetConsoleTextAttribute(hConsoleColor, 51);
	cout << "##";
	SetConsoleTextAttribute(hConsoleColor, 136);
	cout << "%%";
	SetConsoleTextAttribute(hConsoleColor, 0);
	cout << "@@";
	SetConsoleTextAttribute(hConsoleColor, 51);
	cout << "##";
	SetConsoleTextAttribute(hConsoleColor, 136);
	cout << "%%";
	SetConsoleTextAttribute(hConsoleColor, 0);
	cout << "@@";
	SetConsoleTextAttribute(hConsoleColor, 51);
	cout << "##";
	SetConsoleTextAttribute(hConsoleColor, 255);
	cout << "      ";
	SetConsoleTextAttribute(hConsoleColor, 119);
	cout << "!!";
	SetConsoleTextAttribute(hConsoleColor, 136);
	cout << "%%";
	SetConsoleTextAttribute(hConsoleColor, 0);
	cout << "@@";
	SetConsoleTextAttribute(hConsoleColor, 51);
	cout << "##";
	SetConsoleTextAttribute(hConsoleColor, 255);
	cout << "    ";
	SetConsoleTextAttribute(hConsoleColor, 119);
	cout << "!!";
	SetConsoleTextAttribute(hConsoleColor, 136);
	cout << "%%";
	SetConsoleTextAttribute(hConsoleColor, 0);
	cout << "@@";
	SetConsoleTextAttribute(hConsoleColor, 51);
	cout << "##";
	SetConsoleTextAttribute(hConsoleColor, 136);
	cout << "%%";
	SetConsoleTextAttribute(hConsoleColor, 0);
	cout << "@@";
	SetConsoleTextAttribute(hConsoleColor, 51);
	cout << "##";
	SetConsoleTextAttribute(hConsoleColor, 136);
	cout << "%%";
	SetConsoleTextAttribute(hConsoleColor, 0);
	cout << "@@";
	SetConsoleTextAttribute(hConsoleColor, 51);
	cout << "##";
	SetConsoleTextAttribute(hConsoleColor, 255);
	cout << "         ";
	SetConsoleTextAttribute(hConsoleColor, 51);
	cout << "  ";
	SetConsoleTextAttribute(hConsoleColor, 0);
	cout << "  " << endl;

	SetConsoleTextAttribute(hConsoleColor, 0);
	cout << "  ";
	SetConsoleTextAttribute(hConsoleColor, 51);
	cout << "  ";
	SetConsoleTextAttribute(hConsoleColor, 255);
	cout << "      ";
	SetConsoleTextAttribute(hConsoleColor, 119);
	cout << "!!";
	SetConsoleTextAttribute(hConsoleColor, 136);
	cout << "%%";
	SetConsoleTextAttribute(hConsoleColor, 0);
	cout << "@@";
	SetConsoleTextAttribute(hConsoleColor, 51);
	cout << "##";
	SetConsoleTextAttribute(hConsoleColor, 0);
	cout << "@@@@@@";
	SetConsoleTextAttribute(hConsoleColor, 51);
	cout << "##";
	SetConsoleTextAttribute(hConsoleColor, 0);
	cout << "@@";
	SetConsoleTextAttribute(hConsoleColor, 255);
	cout << "                   ";
	SetConsoleTextAttribute(hConsoleColor, 119);
	cout << "!!";
	SetConsoleTextAttribute(hConsoleColor, 136);
	cout << "%%";
	SetConsoleTextAttribute(hConsoleColor, 0);
	cout << "@@";
	SetConsoleTextAttribute(hConsoleColor, 51);
	cout << "##";
	SetConsoleTextAttribute(hConsoleColor, 0);
	cout << "@@";
	SetConsoleTextAttribute(hConsoleColor, 51);
	cout << "##";
	SetConsoleTextAttribute(hConsoleColor, 0);
	cout << "@@";
	SetConsoleTextAttribute(hConsoleColor, 51);
	cout << "##";
	SetConsoleTextAttribute(hConsoleColor, 0);
	cout << "@@";
	SetConsoleTextAttribute(hConsoleColor, 51);
	cout << "##";
	SetConsoleTextAttribute(hConsoleColor, 255);
	cout << "      ";
	SetConsoleTextAttribute(hConsoleColor, 119);
	cout << "!!";
	SetConsoleTextAttribute(hConsoleColor, 136);
	cout << "%%";
	SetConsoleTextAttribute(hConsoleColor, 0);
	cout << "@@";
	SetConsoleTextAttribute(hConsoleColor, 51);
	cout << "##";
	SetConsoleTextAttribute(hConsoleColor, 255);
	cout << "    ";
	SetConsoleTextAttribute(hConsoleColor, 119);
	cout << "!!";
	SetConsoleTextAttribute(hConsoleColor, 136);
	cout << "%%";
	SetConsoleTextAttribute(hConsoleColor, 0);
	cout << "@@";
	SetConsoleTextAttribute(hConsoleColor, 51);
	cout << "##";
	SetConsoleTextAttribute(hConsoleColor, 119);
	cout << "!!";
	SetConsoleTextAttribute(hConsoleColor, 136);
	cout << "%%";
	SetConsoleTextAttribute(hConsoleColor, 0);
	cout << "@@";
	SetConsoleTextAttribute(hConsoleColor, 51);
	cout << "##";
	SetConsoleTextAttribute(hConsoleColor, 0);
	cout << "@@";
	SetConsoleTextAttribute(hConsoleColor, 51);
	cout << "##";
	SetConsoleTextAttribute(hConsoleColor, 255);
	cout << "         ";
	SetConsoleTextAttribute(hConsoleColor, 51);
	cout << "  ";
	SetConsoleTextAttribute(hConsoleColor, 0);
	cout << "  " << endl;


	SetConsoleTextAttribute(hConsoleColor, 0);
	cout << "  ";
	SetConsoleTextAttribute(hConsoleColor, 51);
	cout << "  ";
	SetConsoleTextAttribute(hConsoleColor, 255);
	cout << "        ";
	SetConsoleTextAttribute(hConsoleColor, 119);
	cout << "!!";
	SetConsoleTextAttribute(hConsoleColor, 136);
	cout << "%%";
	SetConsoleTextAttribute(hConsoleColor, 0);
	cout << "@@";
	SetConsoleTextAttribute(hConsoleColor, 51);
	cout << "######";
	SetConsoleTextAttribute(hConsoleColor, 0);
	cout << "@@";
	SetConsoleTextAttribute(hConsoleColor, 255);
	cout << "                     ";
	SetConsoleTextAttribute(hConsoleColor, 119);
	cout << "!!";
	SetConsoleTextAttribute(hConsoleColor, 136);
	cout << "%%";
	SetConsoleTextAttribute(hConsoleColor, 0);
	cout << "@@";
	SetConsoleTextAttribute(hConsoleColor, 51);
	cout << "##";
	SetConsoleTextAttribute(hConsoleColor, 0);
	cout << "@@";
	SetConsoleTextAttribute(hConsoleColor, 51);
	cout << "##";
	SetConsoleTextAttribute(hConsoleColor, 0);
	cout << "@@";
	SetConsoleTextAttribute(hConsoleColor, 51);
	cout << "##";
	SetConsoleTextAttribute(hConsoleColor, 0);
	cout << "@@";
	SetConsoleTextAttribute(hConsoleColor, 51);
	cout << "##";
	SetConsoleTextAttribute(hConsoleColor, 255);
	cout << "      ";
	SetConsoleTextAttribute(hConsoleColor, 119);
	cout << "!!";
	SetConsoleTextAttribute(hConsoleColor, 136);
	cout << "%%";
	SetConsoleTextAttribute(hConsoleColor, 0);
	cout << "@@";
	SetConsoleTextAttribute(hConsoleColor, 51);
	cout << "##";
	SetConsoleTextAttribute(hConsoleColor, 255);
	cout << "    ";
	SetConsoleTextAttribute(hConsoleColor, 119);
	cout << "!!";
	SetConsoleTextAttribute(hConsoleColor, 136);
	cout << "%%";
	SetConsoleTextAttribute(hConsoleColor, 0);
	cout << "@@";
	SetConsoleTextAttribute(hConsoleColor, 51);
	cout << "##";
	SetConsoleTextAttribute(hConsoleColor, 255);
	cout << "  ";
	SetConsoleTextAttribute(hConsoleColor, 119);
	cout << "!!";
	SetConsoleTextAttribute(hConsoleColor, 136);
	cout << "%%";
	SetConsoleTextAttribute(hConsoleColor, 0);
	cout << "@@";
	SetConsoleTextAttribute(hConsoleColor, 51);
	cout << "####";
	SetConsoleTextAttribute(hConsoleColor, 255);
	cout << "         ";
	SetConsoleTextAttribute(hConsoleColor, 51);
	cout << "  ";
	SetConsoleTextAttribute(hConsoleColor, 0);
	cout << "  " << endl;

	SetConsoleTextAttribute(hConsoleColor, 0);
	cout << "  ";
	SetConsoleTextAttribute(hConsoleColor, 51);
	cout << "  ";
	SetConsoleTextAttribute(hConsoleColor, 255);
	cout << "          ";
	SetConsoleTextAttribute(hConsoleColor, 119);
	cout << "!!";
	SetConsoleTextAttribute(hConsoleColor, 136);
	cout << "%%";
	SetConsoleTextAttribute(hConsoleColor, 0);
	cout << "@@@@@@";
	SetConsoleTextAttribute(hConsoleColor, 255);
	cout << "                         ";
	SetConsoleTextAttribute(hConsoleColor, 119);
	cout << "!!";
	SetConsoleTextAttribute(hConsoleColor, 136);
	cout << "%%";
	SetConsoleTextAttribute(hConsoleColor, 0);
	cout << "@@";
	SetConsoleTextAttribute(hConsoleColor, 51);
	cout << "##";
	SetConsoleTextAttribute(hConsoleColor, 119);
	cout << "!!";
	SetConsoleTextAttribute(hConsoleColor, 136);
	cout << "%%";
	SetConsoleTextAttribute(hConsoleColor, 0);
	cout << "@@";
	SetConsoleTextAttribute(hConsoleColor, 51);
	cout << "##";
	SetConsoleTextAttribute(hConsoleColor, 255);
	cout << "    ";
	SetConsoleTextAttribute(hConsoleColor, 119);
	cout << "!!";
	SetConsoleTextAttribute(hConsoleColor, 136);
	cout << "%%";
	SetConsoleTextAttribute(hConsoleColor, 0);
	cout << "@@";
	SetConsoleTextAttribute(hConsoleColor, 51);
	cout << "##########";
	SetConsoleTextAttribute(hConsoleColor, 119);
	cout << "!!";
	SetConsoleTextAttribute(hConsoleColor, 136);
	cout << "%%";
	SetConsoleTextAttribute(hConsoleColor, 0);
	cout << "@@";
	SetConsoleTextAttribute(hConsoleColor, 51);
	cout << "##";
	SetConsoleTextAttribute(hConsoleColor, 255);
	cout << "    ";
	SetConsoleTextAttribute(hConsoleColor, 119);
	cout << "!!";
	SetConsoleTextAttribute(hConsoleColor, 136);
	cout << "%%";
	SetConsoleTextAttribute(hConsoleColor, 0);
	cout << "@@";
	SetConsoleTextAttribute(hConsoleColor, 51);
	cout << "##";
	SetConsoleTextAttribute(hConsoleColor, 255);
	cout << "         ";
	SetConsoleTextAttribute(hConsoleColor, 51);
	cout << "  ";
	SetConsoleTextAttribute(hConsoleColor, 0);
	cout << "  " << endl;

	SetConsoleTextAttribute(hConsoleColor, 0);
	cout << "  ";
	SetConsoleTextAttribute(hConsoleColor, 51);
	cout << "  ";
	SetConsoleTextAttribute(hConsoleColor, 255);
	cout << "                                                                                                              ";
	SetConsoleTextAttribute(hConsoleColor, 51);
	cout << "  ";
	SetConsoleTextAttribute(hConsoleColor, 0);
	cout << "  " << endl;
	SetConsoleTextAttribute(hConsoleColor, 0);
	cout << "==";
	SetConsoleTextAttribute(hConsoleColor, 51);
	cout << "==================================================================================================================";
	SetConsoleTextAttribute(hConsoleColor, 0);
	cout << "==" << endl;
	SetConsoleTextAttribute(hConsoleColor, 0);
	cout << "======================================================================================================================" << endl;
}
void TextColor(int x) //X là mã màu
{
	HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(h, x);
}
void changeColor(int x, int y, int a, int b) //Đổi màu ô x,y sang màu a, sau đó trả về màu b
{
	GotoXY(x, y);
	TextColor(a);
	for (int i = 0; i < _BOARD_SIZE; i++)
		for (int j = 0; j < _BOARD_SIZE; j++)
			if (_A[i][j].x == x && _A[i][j].y == y) {
				if (_A[i][j].c == -1)
					printf("X");
				else if (_A[i][j].c == 1) printf("O");
			}
	TextColor(b);
}
void credits() {
	GotoXY(30,5);
	cout << "          ____   ____  _    _ _______   _    _  _____";
	GotoXY(30,6); 
	cout << "    /\\   |  _ \\ / __ \\| |  | |__   __| | |  | |/ ____|";
	GotoXY(30,7);
	cout << "   /  \\  | |_) | |  | | |  | |  | |    | |  | | (___";
	GotoXY(30,8);  
	cout << "  / /\\ \\ |  _ <| |  | | |  | |  | |    | |  | |\\___ \\";
	GotoXY(30,9); 
	cout << " / ____ \\| |_) | |__| | |__| |  | |    | |__| |____) |";
	GotoXY(30,10);
	cout << "/_/    \\_\\____/ \\____/ \\____/   |_|     \\____/|_____/"; 
                                                       
                                                       

	GotoXY(40, 15);
	cout << "Group 1 - KI THUAT LAP TRINH";
	GotoXY(40, 20);
	cout << "Pham Manh Trung - 22127430";
	GotoXY(40, 21);
	cout << "Thai Huu Tho - 22127400" << endl;
	GotoXY(40, 23);
	cout << "GVHD: Truong Toan Thinh" << endl;
}
void draw_number(int number, int x, int y, int color) {
	_setmode(_fileno(stdout), _O_U16TEXT);
	SetConsoleTextAttribute(hConsoleColor, color);
	switch (number) {
	case 1: {
		gotoxy(x, y);
		wcout << L"  ▄" << endl;
		gotoxy(x, y + 1);
		wcout << L"  █" << endl;
		gotoxy(x, y + 2);
		wcout << L"  █" << endl;
		break;
	}
	case 2: {
		gotoxy(x, y);
		wcout << L"▄▄▄" << endl;
		gotoxy(x, y + 1);
		wcout << L"▄▄█" << endl;
		gotoxy(x, y + 2);
		wcout << L"█▄▄" << endl;
		break;
	}
	case 3: {
		gotoxy(x, y);
		wcout << L"▄▄▄" << endl;
		gotoxy(x, y + 1);
		wcout << L"▄▄█" << endl;
		gotoxy(x, y + 2);
		wcout << L"▄▄█" << endl;
		break;
	}
	case 4: {
		gotoxy(x, y);
		wcout << L"▄ ▄" << endl;
		gotoxy(x, y + 1);
		wcout << L"█▄█" << endl;
		gotoxy(x, y + 2);
		wcout << L"  █" << endl;
		break;
	}
	case 5: {
		gotoxy(x, y);
		wcout << L"▄▄▄" << endl;
		gotoxy(x, y + 1);
		wcout << L"█▄▄" << endl;
		gotoxy(x, y + 2);
		wcout << L"▄▄█" << endl;
		break;
	}
	case 6: {
		gotoxy(x, y);
		wcout << L"▄▄▄" << endl;
		gotoxy(x, y + 1);
		wcout << L"█▄▄" << endl;
		gotoxy(x, y + 2);
		wcout << L"█▄█" << endl;
		break;
	}
	case 7: {
		gotoxy(x, y);
		wcout << L"▄▄▄" << endl;
		gotoxy(x, y + 1);
		wcout << L"  █" << endl;
		gotoxy(x, y + 2);
		wcout << L"  █" << endl;
		break;
	}
	case 8: {
		gotoxy(x, y);
		wcout << L"▄▄▄" << endl;
		gotoxy(x, y + 1);
		wcout << L"█▄█" << endl;
		gotoxy(x, y + 2);
		wcout << L"█▄█" << endl;
		break;
	}
	case 9: {
		gotoxy(x, y);
		wcout << L"▄▄▄" << endl;
		gotoxy(x, y + 1);
		wcout << L"█▄█" << endl;
		gotoxy(x, y + 2);
		wcout << L"▄▄█" << endl;
		break;
	}
	case 0: {
		gotoxy(x, y);
		wcout << L"▄▄▄" << endl;
		gotoxy(x, y + 1);
		wcout << L"█ █" << endl;
		gotoxy(x, y + 2);
		wcout << L"█▄█" << endl;
		break;
	}
	}
	_setmode(_fileno(stdout), _O_TEXT);
}
void drawGameTable(int width, int height, int x, int y) {
	GotoXY(x, y);
	printf("%c", trentrai); for (int i = 0; i < width; i++) printf("%c", ngang); printf("%c", trenphai);

	for (int i = 0; i < height - 1; i++) { GotoXY(x + width + 1, y + i + 1), printf("%c", doc); }

	for (int i = 0; i < height; i++) { GotoXY(x, y + 1 + i); printf("%c", doc); }

	GotoXY(x, y + height); printf("%c", duoitrai);

	for (int i = 0; i < width; i++) { printf("%c", ngang); }
	printf("%c", duoiphai);
}
void drawX() {//77, 14, 104, 14

	gotoxy(77 - 8, 14 + 1);
	cout << "TIME";
	gotoxy(77 - 8, 14 + 2);
	cout << "LEFT";
	gotoxy(104 - 10, 14 + 1);
	cout << "TIME";
	gotoxy(104 - 10, 14 + 2);
	cout << "LEFT";
	_setmode(_fileno(stdout), _O_U16TEXT);
	gotoxy(77 - 2, 14 + 1);
	wcout << L"▀";
	gotoxy(77 - 2, 14 + 2);
	wcout << L"▀";
	gotoxy(104 - 4, 14 + 1);
	wcout << L"▀";
	gotoxy(104 - 4, 14 + 2);
	wcout << L"▀";
	_setmode(_fileno(stdout), _O_TEXT);

 /*
 __   __
 \ \ / /
  \ V / 
   > <  
  / . \ 
 /_/ \_\
        */
        

	//line 1
	GotoXY(69, 6);
	TextColor(17);
	cout << "####";
	TextColor(255);
	cout << "      ";
	TextColor(17);
	cout << "####" << endl;

	//line 2
	GotoXY(69, 7);
	TextColor(17);
	cout << "##";
	TextColor(153);
	cout << "&&";
	TextColor(17);
	cout << "##";
	TextColor(255);
	cout << "  ";
	TextColor(17);
	cout << "##";
	TextColor(153);
	cout << "&&";
	TextColor(17);
	cout << "##" << endl;

	//line 3
	GotoXY(69, 8);
	TextColor(255);
	cout << "  ";
	TextColor(17);
	cout << "##";
	TextColor(153);
	cout << "&&";
	TextColor(17);
	cout << "##";
	TextColor(153);
	cout << "&&";
	TextColor(17);
	cout << "##";
	TextColor(255);
	cout << "  " << endl;

	//line 4
	GotoXY(69, 9);
	TextColor(255);
	cout << "    ";
	TextColor(17);
	cout << "##";
	TextColor(153);
	cout << "&&";
	TextColor(17);
	cout << "##";
	TextColor(255);
	cout << "    " << endl;

	//line 3
	GotoXY(69, 10);
	TextColor(255);
	cout << "  ";
	TextColor(17);
	cout << "##";
	TextColor(153);
	cout << "&&";
	TextColor(17);
	cout << "##";
	TextColor(153);
	cout << "&&";
	TextColor(17);
	cout << "##";
	TextColor(255);
	cout << "  " << endl;

	//line 2
	GotoXY(69, 11);
	TextColor(17);
	cout << "##";
	TextColor(153);
	cout << "&&";
	TextColor(17);
	cout << "##";
	TextColor(255);
	cout << "  ";
	TextColor(17);
	cout << "##";
	TextColor(153);
	cout << "&&";
	TextColor(17);
	cout << "##" << endl;

	//line 1
	GotoXY(69, 12);
	TextColor(17);
	cout << "####";
	TextColor(255);
	cout << "      ";
	TextColor(17);
	cout << "####" << endl;

	TextColor(240);
}

void drawO() {
	//line 1
	GotoXY(94, 6);
	TextColor(255);
	cout << "    ";
	TextColor(68);
	cout << "######";
	TextColor(255);
	cout << "    " << endl;

	//line 2
	GotoXY(94, 7);
	TextColor(255);
	cout << "  ";
	TextColor(68);
	cout << "##";
	TextColor(204);
	cout << "&&";
	TextColor(204);
	cout << "&&";
	TextColor(204);
	cout << "&&";
	TextColor(68);
	cout << "##";
	TextColor(255);
	cout << "  " << endl;

	//line 3
	GotoXY(94, 8);
	TextColor(68);
	cout << "##";
	TextColor(204);
	cout << "&&";
	TextColor(255);
	cout << "  ";
	TextColor(255);
	cout << "  ";
	TextColor(255);
	cout << "  ";
	TextColor(204);
	cout << "&&";
	TextColor(68);
	cout << "##" << endl;

	//line 4
	GotoXY(94, 9);
	TextColor(68);
	cout << "##";
	TextColor(204);
	cout << "&&";
	TextColor(255);
	cout << "  ";
	TextColor(255);
	cout << "  ";
	TextColor(255);
	cout << "  ";
	TextColor(204);
	cout << "&&";
	TextColor(68);
	cout << "##" << endl;

	//line 3
	GotoXY(94, 10);
	TextColor(68);
	cout << "##";
	TextColor(204);
	cout << "&&";
	TextColor(255);
	cout << "  ";
	TextColor(255);
	cout << "  ";
	TextColor(255);
	cout << "  ";
	TextColor(204);
	cout << "&&";
	TextColor(68);
	cout << "##" << endl;

	//line 2
	GotoXY(94, 11);
	TextColor(255);
	cout << "  ";
	TextColor(68);
	cout << "##";
	TextColor(204);
	cout << "&&";
	TextColor(204);
	cout << "&&";
	TextColor(204);
	cout << "&&";
	TextColor(68);
	cout << "##";
	TextColor(255);
	cout << "  " << endl;

	//line 1
	GotoXY(94, 12);
	TextColor(255);
	cout << "    ";
	TextColor(68);
	cout << "######";
	TextColor(255);
	cout << "    " << endl;

	TextColor(240);
}
void drawV() {
	gotoxy(77 - 8, 14 + 1);
	cout << "TIME";
	gotoxy(77 - 8, 14 + 2);
	cout << "LEFT";
	gotoxy(104 - 10, 14 + 1);
	cout << "TIME";
	gotoxy(104 - 10, 14 + 2);
	cout << "LEFT";
	_setmode(_fileno(stdout), _O_U16TEXT);
	gotoxy(77 - 2, 14 + 1);
	wcout << L"▀";
	gotoxy(77 - 2, 14 + 2);
	wcout << L"▀";
	gotoxy(104 - 4, 14 + 1);
	wcout << L"▀";
	gotoxy(104 - 4, 14 + 2);
	wcout << L"▀";
	_setmode(_fileno(stdout), _O_TEXT);
	GotoXY(67, 22);
	SetConsoleTextAttribute(hConsoleColor, 248);
	_setmode(_fileno(stdout), _O_U16TEXT);
	SetConsoleTextAttribute(hConsoleColor, 241);
	wcout << L"▄▄";
	SetConsoleTextAttribute(hConsoleColor, 243);
	wcout << L"▄▄▄▄";
	SetConsoleTextAttribute(hConsoleColor, 49);
	wcout << L"▀";
	SetConsoleTextAttribute(hConsoleColor, 57);
	wcout << L"▀▀";
	SetConsoleTextAttribute(hConsoleColor, 243);
	wcout << L"▄▄▄▄▄▄▄▄▄▄▄▄▄▄" << endl;


	GotoXY(67, 23);
	SetConsoleTextAttribute(hConsoleColor, 17);
	wcout << L"██";
	SetConsoleTextAttribute(hConsoleColor, 51);
	wcout << L"█";
	SetConsoleTextAttribute(hConsoleColor, 0);
	wcout << L"██";
	SetConsoleTextAttribute(hConsoleColor, 176);
	wcout << L"▀";
	SetConsoleTextAttribute(hConsoleColor, 0);
	wcout << L"██";
	SetConsoleTextAttribute(hConsoleColor, 176);
	wcout << L"▀▀▀▀▀";
	SetConsoleTextAttribute(hConsoleColor, 0);
	wcout << L"██████";
	SetConsoleTextAttribute(hConsoleColor, 176);
	wcout << L"▀▀";
	SetConsoleTextAttribute(hConsoleColor, 0);
	wcout << L"█";
	SetConsoleTextAttribute(hConsoleColor, 51);
	wcout << L"█" << endl;

	GotoXY(67, 24);
	SetConsoleTextAttribute(hConsoleColor, 17);
	wcout << L"██";
	SetConsoleTextAttribute(hConsoleColor, 51);
	wcout << L"█";
	SetConsoleTextAttribute(hConsoleColor, 0);
	wcout << L"██";
	SetConsoleTextAttribute(hConsoleColor, 0);
	wcout << L"█";
	SetConsoleTextAttribute(hConsoleColor, 0);
	wcout << L"▀";
	SetConsoleTextAttribute(hConsoleColor, 0);
	wcout << L"█";
	SetConsoleTextAttribute(hConsoleColor, 0);
	wcout << L"▀▀▀";
	SetConsoleTextAttribute(hConsoleColor, 0);
	wcout << L"███";
	SetConsoleTextAttribute(hConsoleColor, 0);
	wcout << L"▀▀▀";
	SetConsoleTextAttribute(hConsoleColor, 0);
	wcout << L"█";
	SetConsoleTextAttribute(hConsoleColor, 0);
	wcout << L"▀▀▀";
	SetConsoleTextAttribute(hConsoleColor, 0);
	wcout << L"█";
	SetConsoleTextAttribute(hConsoleColor, 51);
	wcout << L"█" << endl;

	GotoXY(67, 25);
	SetConsoleTextAttribute(hConsoleColor, 17);
	wcout << L"██";
	SetConsoleTextAttribute(hConsoleColor, 57);
	wcout << L"▄";
	SetConsoleTextAttribute(hConsoleColor, 0);
	wcout << L"██";
	SetConsoleTextAttribute(hConsoleColor, 0);
	wcout << L"▄";
	SetConsoleTextAttribute(hConsoleColor, 0);
	wcout << L" ";
	SetConsoleTextAttribute(hConsoleColor, 0);
	wcout << L"█";
	SetConsoleTextAttribute(hConsoleColor, 0);
	wcout << L" ";
	SetConsoleTextAttribute(hConsoleColor, 0);
	wcout << L"█";
	SetConsoleTextAttribute(hConsoleColor, 0);
	wcout << L" ";
	SetConsoleTextAttribute(hConsoleColor, 0);
	wcout << L"█";
	SetConsoleTextAttribute(hConsoleColor, 176);
	wcout << L"▄";
	SetConsoleTextAttribute(hConsoleColor, 0);
	wcout << L"█";
	SetConsoleTextAttribute(hConsoleColor, 0);
	wcout << L" ";
	SetConsoleTextAttribute(hConsoleColor, 0);
	wcout << L"█";
	SetConsoleTextAttribute(hConsoleColor, 0);
	wcout << L" ";
	SetConsoleTextAttribute(hConsoleColor, 0);
	wcout << L"█";
	SetConsoleTextAttribute(hConsoleColor, 0);
	wcout << L" ";
	SetConsoleTextAttribute(hConsoleColor, 0);
	wcout << L"▀▀";
	SetConsoleTextAttribute(hConsoleColor, 0);
	wcout << L"█";
	SetConsoleTextAttribute(hConsoleColor, 57);
	wcout << L"▄" << endl;

	GotoXY(67, 26);
	SetConsoleTextAttribute(hConsoleColor, 17);
	wcout << L"██";
	SetConsoleTextAttribute(hConsoleColor, 153);
	wcout << L"█";
	SetConsoleTextAttribute(hConsoleColor, 0);
	wcout << L"███";
	SetConsoleTextAttribute(hConsoleColor, 0);
	wcout << L" ";
	SetConsoleTextAttribute(hConsoleColor, 0);
	wcout << L"█";
	SetConsoleTextAttribute(hConsoleColor, 0);
	wcout << L" ";
	SetConsoleTextAttribute(hConsoleColor, 0);
	wcout << L"▀";
	SetConsoleTextAttribute(hConsoleColor, 0);
	wcout << L" ";
	SetConsoleTextAttribute(hConsoleColor, 0);
	wcout << L"█";
	SetConsoleTextAttribute(hConsoleColor, 176);
	wcout << L"▄";
	SetConsoleTextAttribute(hConsoleColor, 0);
	wcout << L"█";
	SetConsoleTextAttribute(hConsoleColor, 0);
	wcout << L" ";
	SetConsoleTextAttribute(hConsoleColor, 0);
	wcout << L"▀";
	SetConsoleTextAttribute(hConsoleColor, 0);
	wcout << L" ";
	SetConsoleTextAttribute(hConsoleColor, 0);
	wcout << L"█";
	SetConsoleTextAttribute(hConsoleColor, 0);
	wcout << L"▀▀";
	SetConsoleTextAttribute(hConsoleColor, 0);
	wcout << L" ";
	SetConsoleTextAttribute(hConsoleColor, 0);
	wcout << L"█";
	SetConsoleTextAttribute(hConsoleColor, 153);
	wcout << L"█" << endl;
	gotoxy(67, 27);
	SetConsoleTextAttribute(hConsoleColor, 17);
	wcout << L"██";
	SetConsoleTextAttribute(hConsoleColor, 153);
	wcout << L"█";
	SetConsoleTextAttribute(hConsoleColor, 144);
	wcout << L"▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀";
	SetConsoleTextAttribute(hConsoleColor, 153);
	wcout << L"█" << endl;

	_setmode(_fileno(stdout), _O_TEXT);
	draw_number(0, 71, 24, 11);
	draw_number(0, 75, 24, 11);
	draw_number(0, 81, 24, 11);
	draw_number(0, 85, 24, 11);
	TextColor(240);
}
void drawPlay() {
	//1
	GotoXY(13, 0);
	TextColor(0);
	cout << "######";
	TextColor(255);
	cout << "    ";
	TextColor(0);
	cout << "##";
	TextColor(255);
	cout << "            ";
	TextColor(0);
	cout << "##";
	TextColor(255);
	cout << "        ";
	TextColor(0);
	cout << "##";
	TextColor(255);
	cout << "      ";
	TextColor(0);
	cout << "##" << endl;

	//2
	GotoXY(13, 1);
	TextColor(0);
	cout << "##";
	TextColor(255);
	cout << "    ";
	TextColor(0);
	cout << "##";
	TextColor(255);
	cout << "  ";
	TextColor(0);
	cout << "##";
	TextColor(255);
	cout << "          ";
	TextColor(0);
	cout << "##";
	TextColor(255);
	cout << "  ";
	TextColor(0);
	cout << "##";
	TextColor(255);
	cout << "        ";
	TextColor(0);
	cout << "##";
	TextColor(255);
	cout << "  ";
	TextColor(0);
	cout << "##";
	TextColor(255);
	cout << "  " << endl;

	//3
	GotoXY(13, 2);
	TextColor(0);
	cout << "######";
	TextColor(255);
	cout << "    ";
	TextColor(0);
	cout << "##";
	TextColor(255);
	cout << "        ";
	TextColor(0);
	cout << "##";
	TextColor(255);
	cout << "  ";
	TextColor(0);
	cout << "##";
	TextColor(255);
	cout << "  ";
	TextColor(0);
	cout << "##";
	TextColor(255);
	cout << "        ";
	TextColor(0);
	cout << "##" << endl;

	//4
	GotoXY(13, 3);
	TextColor(0);
	cout << "##";
	TextColor(255);
	cout << "        ";
	TextColor(0);
	cout << "##";
	TextColor(255);
	cout << "        ";
	TextColor(0);
	cout << "####";
	TextColor(255);
	cout << "  ";
	TextColor(0);
	cout << "####";
	TextColor(255);
	cout << "      ";
	TextColor(0);
	cout << "##" << endl;

	//5 
	GotoXY(13, 4);
	TextColor(0);
	cout << "##";
	TextColor(255);
	cout << "        ";
	TextColor(0);
	cout << "######";
	TextColor(255);
	cout << "    ";
	TextColor(0);
	cout << "##";
	TextColor(255);
	cout << "      ";
	TextColor(0);
	cout << "##";
	TextColor(255);
	cout << "    ";
	TextColor(0);
	cout << "##";

	TextColor(240);
}

int getCommand() { // Nhập lệnh
	return _COMMAND;
}
void gotoxy(int column, int line)

{

	COORD coord;

	coord.X = column;

	coord.Y = line;

	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);

}
void helps() {
	SetConsoleTextAttribute(hConsoleColor, 255);
	cout << "                                                                                                                       ";
	cout << "                                                                                                                       ";
	cout << "                                                                                                                       ";
	cout << "                                                                                                                       ";
	cout << "                                                                                                                       ";
	cout << "                                                                                                                       ";
	cout << "                                                                                                                       ";
	cout << "                                                                                                                       ";
	cout << "                                                                                                                       ";
	cout << "                                                                                                                       ";
	cout << "                                                                                                                       ";
	cout << "                                                                                                                       ";
	cout << "                                                                                                                       ";
	cout << "                                                                                                                       ";
	cout << "                                                                                                                       ";
	cout << "                                                                                                                       ";
	cout << "                                                                                                                       ";
	cout << "                                                                                                                       ";
	cout << "                                                                                                                       ";
	cout << "                                                                                                                       ";
	cout << "                                                                                                                       ";
	cout << "                                                                                                                       ";
	cout << "                                                                                                                       ";
	cout << "                                                                                                                       ";
	cout << "                                                                                                                       ";
	cout << "                                                                                                                       ";
}
int loadGame(const char name[]) {
	vector<int> data;
	TextColor(240);
	system("cls");
	FILE* f = fopen(name, "rb");
	if (f == NULL) {
		GotoXY(30, 10);
		cout << "Khong tim thay ten nguoi choi! Dang tro ve mang hinh chinh...";
		Sleep(1000);
		return 0;
		system("cls");
		//play();
	}
	int j = 0;
	int i = 0;
	int a;
	StartGame();
	fscanf(f, "%d", &_TURN);
	fscanf(f, "\n");
	while (!feof(f)) {
		fscanf(f, "%d", &a);
		data.push_back(a);
	}
	int getdata = 0;
	for (int i = 0; i < _BOARD_SIZE; i++)
	{
		for (int j = 0; j < _BOARD_SIZE; j++)
		{
			int x = _A[i][j].x;
			int y = _A[i][j].y;
			GotoXY(x, y);
			_A[i][j].c = data[getdata];
			if (data[getdata] == -1) {
				TextColor(244);
				cout << "X";
			}
			if (data[getdata] == 1) {
				TextColor(241);
				cout << "O";
			}
			getdata++;
		}
	}
	fclose(f);
	return 1;
}
void loadgame() {
	hConsoleColor = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hConsoleColor, 255);
	cout << "                                                                                                                        ";
	cout << "                                                                                                                        ";
	cout << "                                                                                                                        ";
	cout << "                                                                                                                        ";
	cout << "                                                                                                                        ";
	cout << "                                                                                                                        ";
	cout << "                                                                                                                        ";
	cout << "                                                                                                                        ";
	cout << "                                                                                                                        ";
	cout << "                                                                                                                        ";
	cout << "                                                                                                                        ";
	cout << "                                                                                                                        ";
	cout << "                                                                                                                        ";
	cout << "                                                                                                                        ";
	cout << "                                                                                                                        ";
	cout << "                                                                                                                        ";
	cout << "                                                                                                                        ";
	cout << "                                                                                                                        ";
	cout << "                                                                                                                        ";
	cout << "                                                                                                                        ";
	cout << "                                                                                                                        ";
	cout << "                                                                                                                        ";
	cout << "                                                                                                                        ";
	cout << "                                                                                                                        ";
	cout << "                                                                                                                        ";
	cout << "                                                                                                                        ";
	cout << "                                                                                                                        ";

}
void newgame() {
	SetConsoleTextAttribute(hConsoleColor, 255);
	cout << "                                                                                                                       ";
	cout << "                                                                                                                       ";
	cout << "                                                                                                                       ";
	cout << "                                                                                                                       ";
	cout << "                                                                                                                       ";
	cout << "                                                                                                                       ";
	cout << "                                                                                                                       ";
	cout << "                                                                                                                       ";
	cout << "                                                                                                                       ";
	cout << "                                                                                                                       ";
	cout << "                                                                                                                       ";
	cout << "                                                                                                                       ";
	cout << "                                                                                                                       ";
	cout << "                                                                                                                       ";
	cout << "                                                                                                                       ";
	cout << "                                                                                                                       ";
	cout << "                                                                                                                       ";
	cout << "                                                                                                                       ";
	cout << "                                                                                                                       ";
	cout << "                                                                                                                       ";
	cout << "                                                                                                                       ";
	cout << "                                                                                                                       ";
	cout << "                                                                                                                       ";
	cout << "                                                                                                                       ";
	cout << "                                                                                                                       ";
	cout << "                                                                                                                       ";
}
void settings() {
	SetConsoleTextAttribute(hConsoleColor, 255);
	for (int i = 0; i < 35; i++) {
		cout << "                                                                                                                     " << endl;
	}
}
void redToWhite()//-1:244   1"241
{

	for (int i = 0; i < _BOARD_SIZE; i++)
		for (int j = 0; j < _BOARD_SIZE; j++)
			if (_A[i][j].x == LastMove.x && _A[i][j].y == LastMove.y)
			{
				GotoXY(LastMove.x, LastMove.y);
				if (_A[i][j].c == -1)
				{
					TextColor(244);
					printf("X");
				}
				else if (_A[i][j].c == 1)
				{
					TextColor(241);
					printf("O");
				}
				TextColor(240);
				GotoXY(_X, _Y);
			}
}

void winLine_on()
{
	int i = 1;
	int dong = (_Y - 1 - _TOP) / 2, cot = (_X - 2 - _LEFT) / 4;
	changeColor(_X, _Y, 248, 245);

	if (countCol() >= 5)
	{
		while (_A[dong][cot].c == _A[dong + i][cot].c)
		{
			if (_A[dong + i][cot].c == 0) break;
			changeColor(_A[dong + i][cot].x, _A[dong + i][cot].y, 248, 245);
			i++;
		} i = 1;
		while (_A[dong][cot].c == _A[dong - i][cot].c)
		{
			if (_A[dong - i][cot].c == 0) break;
			changeColor(_A[dong - i][cot].x, _A[dong - i][cot].y, 248, 245);
			i++;
		}
	}
	if (countRow() >= 5)
	{
		while (_A[dong][cot].c == _A[dong][cot + i].c)
		{
			if (_A[dong][cot + i].c == 0) break;
			changeColor(_A[dong][cot + i].x, _A[dong][cot + i].y, 248, 245);
			i++;
		}i = 1;
		while (_A[dong][cot].c == _A[dong][cot - i].c)
		{
			if (_A[dong][cot - i].c == 0) break;
			changeColor(_A[dong][cot - i].x, _A[dong][cot - i].y, 248, 245);
			i++;
		}
	}
	if (countSac() >= 5)
	{
		while (_A[dong][cot].c == _A[dong + i][cot - i].c)
		{
			if (_A[dong + i][cot - i].c == 0) break;
			changeColor(_A[dong + i][cot - i].x, _A[dong + i][cot - i].y, 248, 245);
			i++;
		}i = 1;
		while (_A[dong][cot].c == _A[dong - i][cot + i].c)
		{
			if (_A[dong - i][cot + i].c == 0) break;
			changeColor(_A[dong - i][cot + i].x, _A[dong - i][cot + i].y, 248, 245);
			i++;
		}
	}

	if (countHuyen() >= 5)
	{
		while (_A[dong][cot].c == _A[dong + i][cot + i].c)
		{
			if (_A[dong + i][cot + i].c == 0) break;
			changeColor(_A[dong + i][cot + i].x, _A[dong + i][cot + i].y, 248, 245);
			i++;
		}i = 1;
		while (_A[dong][cot].c == _A[dong - i][cot - i].c)
		{
			if (_A[dong - i][cot - i].c == 0) break;
			changeColor(_A[dong - i][cot - i].x, _A[dong - i][cot - i].y, 248, 245);
			i++;
		}

	}



}
void winLine_off()
{
	int i = 1;
	int dong = (_Y - 1 - _TOP) / 2, cot = (_X - 2 - _LEFT) / 4;

	changeColor(_X, _Y, 245, 245);
	if (countCol() >= 5)
	{
		while (_A[dong][cot].c == _A[dong + i][cot].c)
		{
			if (_A[dong + i][cot].c == 0) break;
			changeColor(_A[dong + i][cot].x, _A[dong + i][cot].y, 245, 245);
			i++;
		} i = 1;
		while (_A[dong][cot].c == _A[dong - i][cot].c)
		{
			if (_A[dong - i][cot].c == 0) break;
			changeColor(_A[dong - i][cot].x, _A[dong - i][cot].y, 245, 245);
			i++;
		}
	}
	if (countRow() >= 5)
	{
		while (_A[dong][cot].c == _A[dong][cot + i].c)
		{
			if (_A[dong][cot + i].c == 0) break;
			changeColor(_A[dong][cot + i].x, _A[dong][cot + i].y, 245, 245);
			i++;
		}i = 1;
		while (_A[dong][cot].c == _A[dong][cot - i].c)
		{
			if (_A[dong][cot - i].c == 0) break;
			changeColor(_A[dong][cot - i].x, _A[dong][cot - i].y, 245, 245);
			i++;
		}
	}

	if (countSac() >= 5)
	{
		while (_A[dong][cot].c == _A[dong + i][cot - i].c)
		{
			if (_A[dong + i][cot - i].c == 0) break;
			changeColor(_A[dong + i][cot - i].x, _A[dong + i][cot - i].y, 245, 245);
			i++;
		}i = 1;
		while (_A[dong][cot].c == _A[dong - i][cot + i].c)
		{
			if (_A[dong - i][cot + i].c == 0) break;
			changeColor(_A[dong - i][cot + i].x, _A[dong - i][cot + i].y, 245, 245);
			i++;
		}
	}

	if (countHuyen() >= 5)
	{
		while (_A[dong][cot].c == _A[dong + i][cot + i].c)
		{
			if (_A[dong + i][cot + i].c == 0) break;
			changeColor(_A[dong + i][cot + i].x, _A[dong + i][cot + i].y, 245, 245);
			i++;
		}i = 1;
		while (_A[dong][cot].c == _A[dong - i][cot - i].c)
		{
			if (_A[dong - i][cot - i].c == 0) break;
			changeColor(_A[dong - i][cot - i].x, _A[dong - i][cot - i].y, 245, 245);
			i++;
		}

	}

}
void winLineBlink()
{
	int i = 0;
	while (i != 5) {
		winLine_on();
		sleep(100);
		winLine_off();
		sleep(100);
		i++;
	}
}
void winEffect()
{
	if (m % 2 == 0)PlaySound(TEXT("joustus_mysterycard_new.wav"),NULL,SND_ASYNC);
	winLineBlink();
}

void timeCountDown(int& temp_time, bool& bufTurn, int x1, int y1, int x2, int y2)
{
	char command;
	
	draw_number(timeCountDownX / 10, x1 + 1, y1, 249);
	draw_number(timeCountDownX % 10, x1 + 5, y1, 249);
	draw_number(timeCountDownO / 10, x2 - 1, y2, 252);
	draw_number(timeCountDownO % 10, x2 + 3, y2, 252);
	GotoXY(_X, _Y);
	clock_t _end = clock();
	TextColor(240);

	if (bufTurn != _TURN)
	{
		if (_TURN)
		{
			timeCountDownO = 30;
			draw_number(timeCountDownX / 10, x1 + 1, y1, 249);
			draw_number(timeCountDownX % 10, x1 + 5, y1, 249);
		}
		else
		{
			timeCountDownX = 30;
			draw_number(timeCountDownO / 10, x2 - 1, y2, 252);
			draw_number(timeCountDownO % 10, x2 + 3, y2, 252);
		}
		bufTurn = _TURN;
	}
	if (((_end - start) / 1000) != temp_time)
	{
		if (_TURN)
		{
			timeCountDownX--;
			draw_number(timeCountDownX / 10, x1 + 1, y1, 249);
			draw_number(timeCountDownX % 10, x1 + 5, y1, 249);
			GotoXY(_X, _Y);
		}
		else
		{
			timeCountDownO--;
			draw_number(timeCountDownO / 10, x2 - 1, y2, 252);
			draw_number(timeCountDownO % 10, x2 + 3, y2, 252);;
			GotoXY(_X, _Y);
		}

	}
	temp_time = (_end - start) / 1000;
}