#ifndef NGUOIQUANLY_H
#define NGUOIQUANLY_H
#include "Book.h"
#include<iostream>
#include<stdio.h>
#include<stdlib.h>
#include<fstream>
#include<sstream>
#include<string.h>
#include<conio.h>
#include<iomanip>
using namespace std;
#include<cctype>
class Book;
class Nguoiquanly{
    private:
        Book *a;
		string admin;
		string pass;
	public:
		Nguoiquanly();
        ~Nguoiquanly();
		void menu_ql();
		void pass_ql();
		void back_ql();
		void menu_timsach();
		void menu_xoasach();
		void menu_dieuchinh();
		void ThayDoiMatKhau();
		void DangXuat();
        string convert_pass(string &pass);
};
#endif