#include "Menu.h"
#include "Nguoiquanly.h"
#include "Sinhvien.h"
void Menu::menu()
{ 
        fflush(stdin);
        cout << "\t HE THONG QUAN LY THU VIEN\t" << endl;
        cout << "Vui long chon tu cach dang nhap: " << endl;
        cout<< "1.Sinh vien" << endl;
        cout<< "2.Nguoi quan ly" << endl;
        cout<< "3.Dong" << endl;
        cout<< "Nhap lua chon: ";
        char j;
        cin >> j;
        switch (j)
        {
            case '1':
                {
                    system("cls");
                    pass_sv();
                    break;
                }    
            case '2':
                {
                    system("cls");
                    pass_ql();
                    break;
                }
            case '3':
                exit(0);
                break;
            default:
                cout<<"Hay chon tu cach dang nhap dung!";
                getch();
                system("cls");
                menu();
                break;
        }
}