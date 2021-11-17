#ifndef BOOK_H
#define BOOK_H
#include "Nguoiquanly.h"
#include "Sinhvien.h"
#include "Phieumuon.h"
#include<iostream>
#include<stdio.h>
#include<stdlib.h>
#include<fstream>
#include<sstream>
#include<string.h>
#include<conio.h>
#include<iomanip>
#include <cctype>
using namespace std;
class Book{
	private:
	    string ID;
		string Tensach;
		string Tentacgia;
		string Nhaxuatban;
		int Giatien;
	public:
        Book();
        ~Book();
		string getID();
		string getTensach();
		string getTentacgia();
		string getNhaxuatban();
		int getGiatien();
		int getInfo(Book *);
		void display();
        void XemSach(Book *);
		void Timsach_ID(Book *);
		void Timsach_Tensach(Book *);
		void Themsach(Book *);
    	void Xoasach_ID(Book *);
		void Xoasach_Tensach(Book *);
		bool Checktontai(Book *);
		void Sapxep(Book *);
		friend istream& operator >>(istream &in,Book &a);
		friend ostream& operator <<(ostream &out,const Book &a);


};
#endif