#ifndef SINHVIEN_H
#define SINHVIEN_H
#include "Book.h"
#include "Menu.h"
#include "Phieumuon.h"
#include<iostream>
#include <sstream>
#include<stdio.h>
#include<stdlib.h>
#include<fstream>
#include<sstream>
#include<string.h>
#include<conio.h>
#include<iomanip>
#include <cctype>
using namespace std;
class Book;
class Sinhvien{
    private:
        Book *a;
        string Msv;
        string Mk;
    public:
        Sinhvien();
        ~Sinhvien();
        void menu_sv();
        void pass_sv();
        void back_sv();
        void menu_timsach();
        void ThayDoiMatKhau();
        void DangXuat();
        string convert_pass(string &pass);
};
#endif