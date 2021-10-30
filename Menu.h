#ifndef MENU_H
#define MENU_H
#include "Nguoiquanly.cpp"
#include "Sinhvien.cpp"
#include<iostream>
#include <sstream>
#include<stdio.h>
#include<stdlib.h>
#include<fstream>
#include<string>
#include<conio.h>
using namespace std;
const int MAX = 100;

class Menu: public Nguoiquanly, public Sinhvien{
    public:
        Menu(){}
        void menu();
        ~Menu(){}
};

#endif