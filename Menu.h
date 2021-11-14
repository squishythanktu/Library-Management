#ifndef MENU_H
#define MENU_H
#include "Nguoiquanly.h"
#include "Sinhvien.h"
#include <iostream>
using namespace std;
class Menu: public Nguoiquanly, public Sinhvien
{
    private:
        /* data */
    public:
        Menu(){}
        ~Menu(){}
        void menu();
};

#endif