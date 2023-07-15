#pragma once

#define _CRT_SECURE_NO_WARNINGS 1

#define LINE 3

#define COLUMN 3

#include<stdio.h>

#include<stdlib.h>

#include<string.h>

#include<time.h>

// 初始化棋盘
void InitBoard(char Board[LINE][COLUMN], int line, int column);

//打印棋盘
void DisplayBoard(char Board[LINE][COLUMN], int line, int column);

//玩家下棋
void PlayerMove(char Board[LINE][COLUMN],int line,int column );

//电脑下棋
void ComputerMove(char Board[LINE][COLUMN], int line, int column);



