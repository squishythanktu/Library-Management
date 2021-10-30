#ifndef NGUOIQUANLY_H
#define NGUOIQUANLY_H
#include<iostream>
#include<stdio.h>
#include<stdlib.h>
#include<fstream>
#include<sstream>
#include<string>
#include<string>
#include<conio.h>
#include<Windows.h>
#include<iomanip>
using namespace std;
class Nguoiquanly{
	private:
	    string ID;
		string Tensach;
		string Tentacgia;
		string Nhaxuatban;
		int Giatien;
		int Soluong;
	public:
		void menu_ql();
		void pass_ql();
		void back_ql();
		int getInfo(Nguoiquanly *);
        void XemSach(Nguoiquanly *);
		void menu_timsach();
		void Timsach_ID(Nguoiquanly *);
		void Timsach_Tensach(Nguoiquanly *);
		void display();
		void menu_dieuchinh();
		void Themsach(Nguoiquanly *);
    	void Xoasach(Nguoiquanly *);
		bool Checktontai(Nguoiquanly *);
		void Sapxep(Nguoiquanly *);
		friend istream& operator >>(istream &in,Nguoiquanly &a);
		friend ostream& operator <<(ostream &out,const Nguoiquanly &a);

		~Nguoiquanly(){}
};
#endif