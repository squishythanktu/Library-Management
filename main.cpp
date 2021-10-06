#include<iostream>
#include<stdio.h>
#include<stdlib.h>
#include<fstream>
#include<string.h>
#include<conio.h>
#include<Windows.h>
using namespace std;
#define max 50
class Library {
private:
	char id[max], tensach[max], tentacgia[max], nhaxuatban[max];
	int gia, soluong, B;
public:
	Library() //hàm khởi tạo
	{
		strcpy(id, "Khong co ID sach");
		strcpy(tensach, "Khong co ten sach");
		strcpy(tentacgia, "Khong co ten tac gia");
		strcpy(nhaxuatban, "Khong co nha xuat ban");
		gia = 0;
		soluong = 0;
		B = 0;
	}
	void Sinhvien(){}
	void Nguoiquanly(){}
	void GoTo(SHORT posX, SHORT posY) //hàm di chuyển chuột tới tọa độ (x,y)
	{
		HANDLE hStdout = GetStdHandle(STD_OUTPUT_HANDLE);
		COORD Position;
		Position.X = posX;
		Position.Y = posY;

		SetConsoleCursorPosition(hStdout, Position);
	}
	void menu() {
		int i;
		GoTo(25, 2); cout << char(201);
		for (int i = 0; i < 38; i++) {
			cout << char(205);
		}
		cout << char(187);
		GoTo(25, 3); cout << char(186) << "\t HE THONG QUAN LY THU VIEN\t" << char(186);
		GoTo(25, 4); cout << char(200);
		for (int i = 0; i < 38; i++) {
			cout << char(205);
		}
		cout << char(188) << endl;
		GoTo(25, 6); cout << "Vui long chon tu cach dang nhap: ";
		GoTo(25, 8); cout<< "1.Sinh vien";
		GoTo(25, 10); cout<< "2.Nguoi quan ly";
		GoTo(25, 12); cout<< "3.Dong";
		GoTo(25, 14); cout<< "Nhap lua chon: ";
		cin >> i;
		switch (i)
		{
		case 1:
			Sinhvien();
			break;
		case 2:
			Nguoiquanly();
			break;
		case 3:
			exit(0);
			break;
		default:
			GoTo(25, 16); cout<<"Hay chon tu cach dang nhap dung!";
            getch();
            system("CLS");
           	menu();
			break;
		}
	}
};
int main(){
    Library a;
    a.menu();
	system("pause");
    return 0;
}