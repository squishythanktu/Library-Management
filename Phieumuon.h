#ifndef PHIEUMUON_H
#define PHIEUMUON_H
#include "Nguoiquanly.h"
#include "Sinhvien.h"
#include "Book.h"
#include<iostream>
#include<stdio.h>
#include<stdlib.h>
#include<fstream>
#include<sstream>
#include<string.h>
#include<conio.h>
#include<iomanip>
#include <cctype>
#include <time.h>
#include <algorithm>

using namespace std;
class Book;
class Phieumuon
{
    private:
            string Mamuon;
            string Masv;
            string Ngaymuon;
            string *Tensach; //mảng chứa tên sách
            int *Sosach; //mảng chứa số lượng sách
    public:
            Phieumuon(string);
            ~Phieumuon();
            bool CheckSach();
            void Timphieusv(Phieumuon *);
            void Muonsach(Phieumuon&);
            void Trasach(Phieumuon *);
            bool checkMamuon();
            bool checkSoluong();
            friend istream& operator >>(istream &in,Phieumuon &a);
            friend ostream& operator <<(ostream &out,const Phieumuon &a);
};
#endif