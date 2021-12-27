#include "Menu.h"
using namespace std;

void Menu::menu()
{ 
    fflush(stdin);
     int i;
    Goto(51, 3);
    textcolor(6);
    cout << "-HE THONG QUAN LY THU VIEN-";
    textcolor(7);
    Goto(34,5);cout<<"*";
    for(int i=0;i<58;i++)
    {
        cout<<"*";
    }
    cout <<"*";
    Goto(34, 6); cout << "*";
    Goto(93,6);cout<<"*";
    Goto(34,7);cout << "*";
    cout<<"\t            1. Sinh vien             \t";
    Goto(93,7);cout<<"*";
    Goto(34,8); cout << "*";
    Goto(93,8);cout<<"*";
    Goto(34,9);cout << "*";
    cout<<"\t            2. Quan ly             \t";
    Goto(93,9);cout<<"*";
    Goto(34,10); cout << "*";
    Goto(93,10);cout<<"*";
    Goto(34,11);cout << "*";
    cout<<"\t            3. Dong             \t";
    Goto(93,11);cout<<"*";
    Goto(34,12); cout <<"*";
    Goto(93,12);cout<<"*";
    Goto(34,13);cout<<"*";
    for (int i = 0; i < 58; i++) {
        cout << "*";
    }
    cout << "*";
    Goto(34,16);
    cout<<"Vui long chon phuong thuc dang nhap:           \t";
    string n;
    Goto(71,16);
    cin>>n;
    if(n.length()>1)
    {
        textcolor(4);
        Goto(34,17);
        cout<<"Lua chon khong hop le. Hay nhap lai...";
        getch();
        system("cls");
        menu();
    }
    char m=n[0];
    switch (m)
    {
        case '1':
        {
            system("cls");
            Sinhvien a;
            a.pass_sv();
            break;
        }    
        case '2':
        {
            system("cls");
            Nguoiquanly ql;
            ql.pass_ql();
            break;
        }
        case '3':
        {
            exit(0);
            break;
        }
        default:
        {
            textcolor(4);
            Goto(34,17);cout<<"Hay chon tu cach dang nhap dung!";
            getch();
            getch();
            system("cls");
            textcolor(7);
            menu();
            break;
        }
    }
}