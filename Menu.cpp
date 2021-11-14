#include "Menu.h"
using namespace std;

void Menu::menu()
{ 
    fflush(stdin);
    cout << "\t HE THONG QUAN LY THU VIEN\t" << endl;
    cout << "Vui long chon tu cach dang nhap: " << endl;
    cout<< "1.Sinh vien" << endl;
    cout<< "2.Nguoi quan ly" << endl;
    cout<< "3.Dong" << endl;
    cout<< "Nhap lua chon: ";
    string n; 
    cin >> n;
    if(n.length()>1)
    {
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
            cout<<"Hay chon tu cach dang nhap dung!";
            getch();
            system("cls");
            menu();
            break;
        }
    }
}