#ifndef SINHVIEN_H
#define SINHVIEN_H
#include<iostream>
#include <sstream>
#include<stdio.h>
#include<stdlib.h>
#include<fstream>
#include<string>
#include<conio.h>
using namespace std;
class Sinhvien{
        private:
                string msv;
        public:
                Sinhvien(){}
                void menu_sv();
                void pass_sv();
                ~Sinhvien(){}
};

#endif