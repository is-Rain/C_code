#pragma once

#define _CRT_SECURE_NO_WARNINGS 1

#define LINE 3

#define COLUMN 3

#include<stdio.h>

#include<stdlib.h>

#include<string.h>

#include<time.h>

// ��ʼ������
void InitBoard(char Board[LINE][COLUMN], int line, int column);

//��ӡ����
void DisplayBoard(char Board[LINE][COLUMN], int line, int column);

//�������
void PlayerMove(char Board[LINE][COLUMN],int line,int column );

//��������
void ComputerMove(char Board[LINE][COLUMN], int line, int column);



