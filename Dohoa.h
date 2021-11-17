#include <iostream>
#include <conio.h>
#include <Windows.h>
using namespace std;

//Hàm tô màu chữ
void textcolor(int x)
{
    HANDLE mau;
    mau=GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(mau,x);
}
// Hàm goto
void Goto(SHORT posX, SHORT posY) //hàm  bạn di chuyển chuột tới tọa độ (x,y)
{
	HANDLE hStdout = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD Position;
	Position.X = posX;
	Position.Y = posY;
	SetConsoleCursorPosition(hStdout, Position);
}
