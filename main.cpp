#include "Sinhvien.cpp"
#include "Nguoiquanly.cpp"
#include<iostream>
#include <sstream>
#include<stdio.h>
#include<stdlib.h>
#include<fstream>
#include<string>
#include<conio.h>
#include<Windows.h>
using namespace std;
const int MAX = 100;
void gotoxy(int x, int y)
{
  static HANDLE h = NULL;  
  if(!h)
    h = GetStdHandle(STD_OUTPUT_HANDLE);
  COORD c = { x, y };  
  SetConsoleCursorPosition(h,c);
}
void menu() 
{
    Menu:
        gotoxy(25, 2); cout << char(201);
        for (int i = 0; i < 38; i++) {
            cout << char(205);
        }
        cout << char(187);
        gotoxy(25, 3); cout << char(186) << "\t HE THONG QUAN LY THU VIEN\t" << char(186);
        gotoxy(25, 4); cout << char(200);
        for (int i = 0; i < 38; i++) {
            cout << char(205);
        }
        cout << char(188) << endl;
        gotoxy(25, 6); cout << "Vui long chon tu cach dang nhap: ";
        gotoxy(25, 8); cout<< "1.Sinh vien";
        gotoxy(25, 10); cout<< "2.Nguoi quan ly";
        gotoxy(25, 12); cout<< "3.Dong";
        gotoxy(25, 14); cout<< "Nhap lua chon: ";
        int j;
        cin >> j;
        switch (j)
        {
            case 1:
                {
                    pass_sv:
                        string line = " ";
                        ifstream readFile("D:/Workspace/PBL2/pass/pass_sv.txt");
                        string UserName, _UserName, _Password;
                        gotoxy(25, 16); cout << "Ma sinh vien: ";
                        cin >> UserName;
                        gotoxy(25, 18); cout << "Mat khau: ";
                        int k=0;
                        char ch,st[MAX];
                        while(1)
                        {
                            ch=getch();
                            if(ch==13) //enter
                            {
                                st[k]='\0';
                                break;
                            }
                            else if(ch==8 && k>0) //backspace
                            {
                                k--;
                                cout<<"\b \b"; // xoa ky tu truoc con tro
                            }
                            else
                            {
                                cout<<"*";
                                st[k]=ch;
                                k++;
                            }
                        }
                        string Password = string(st);
                        bool found = false;
                        while (getline(readFile,line)) {
                            stringstream in(line);
                            in >> _UserName >> _Password;
                            if (UserName == _UserName && Password == _Password) { //Dang nhap thanh cong
                                menu_sv:
                                    int i;
                                    system("cls");
                                    gotoxy(25, 2); cout << "************ MENU QUAN LY ************";
                                    gotoxy(25, 4); cout << "Nhap lua chon: ";
                                    gotoxy(25, 6); cout << "1. Xem sach";
                                    gotoxy(25, 8); cout << "2. Tim sach";
                                    gotoxy(25, 10); cout << "3. Muon sach";
                                    gotoxy(25, 12); cout << "4. Tra sach";
                                    gotoxy(25, 14); cout << "5. Tro ve menu";
                                    gotoxy(25, 16); cout << "6.Dong";
                                    gotoxy(25, 18); cout << "Nhap lua chon cua ban: ";  
                                    cin >> i;
                                    switch (i)
                                    {
                                    case 1:
                                        // see(); // Xem sach
                                        break;
                                    case 2:
                                        // search(); // Tim sach
                                        break;
                                    case 3:
                                        // muonsach(); // Muon sach
                                        break;
                                    case 4:
                                        // trasach(); // Tra sach
                                        break;
                                    case 5:
                                        system("cls");
                                        menu();
                                    case 6:
                                        exit(0);
                                        break;
                                    default:
                                        gotoxy(25,20); cout << "Hay nhap lua chon dung!";
                                        getch();
                                        system("cls");
                                        goto menu_sv;
                                        break;
                                    }
                                found = true;
                                break;
                            }
                        }
                        if (!found) { //Dang nhap that bai
                            gotoxy(25,20); cout << "Ma sinh vien hoac mat khau khong dung. Hay thu lai.....";
                            getch();
                            system("cls");
                            goto Menu;
                        }
                    break;
                }    
            case 2:
                {
                    pass_ql:
                        int k=0;
                        char ch,st[MAX],ch1[MAX];
                        gotoxy(25, 16); cout<<"Mat khau: ";
                        while(1)
                        {
                            ch=getch();
                            if(ch==13) //enter
                            {
                                st[k]='\0';
                                break;
                            }
                            else if(ch==8 && k>0) //backspace
                            {
                                k--;
                                cout<<"\b \b"; // xoa ky tu truoc con tro
                            }
                            else
                            {
                                cout<<"*";
                                st[k]=ch;
                                k++;
                            }
                        }
                        ifstream inf("D:/Workspace/PBL2/pass/pass_ql.txt");
                        inf>>ch1; //đọc nội dung file password.txt gán vào biến ch1
                        inf.close();
                        if(strcmp(st,ch1)==0) //Dang nhap thanh cong
                        {
                            system("cls");
                            menu_ql:
                                gotoxy(25, 2); cout << "************ MENU QUAN LY ************";
                                gotoxy(25, 4); cout << "Nhap lua chon: ";
                                gotoxy(25, 6); cout << "1. Xem sach";
                                gotoxy(25, 8); cout << "2. Tim sach";
                                gotoxy(25, 10); cout << "3. Dieu chinh sach";
                                gotoxy(25, 12); cout << "4. Tro ve menu";
                                gotoxy(25, 14); cout << "5. Dong";
                                gotoxy(25, 16); cout << "Nhap lua chon cua ban: "; 
                                int m;
                                cin>>m;
                                switch(m) 
                                {
                                    case 1: //booklist();
                                            break;
                                    case 2: //see(2);
                                            break;
                                    case 3: //modify();
                                            break;
                                    case 4: system("cls");
                                            menu();
                                            break;
                                    case 5: 
                                            exit(0);
                                    default: gotoxy(25, 18); cout<<"Hay nhap lua chon dung";
                                            getch();
                                            system("cls");
                                            goto menu_ql;
                                }
                        }
                        else //Dang nhap that bai
                        {
                            gotoxy(25, 18); cout<<"Mat khau khong dung. Hay thu lai.....";
                            getch();
                            system("cls");
                            menu();
                        } 
                    break;
                }
            case 3:
                exit(0);
                break;
            default:
                gotoxy(25, 16); cout<<"Hay chon tu cach dang nhap dung!";
                getch();
                system("cls");
                goto Menu;
                break;
        }
}
int main(){
    menu();
	system("pause");
    return 0;
}
// int branch() //danh mục các loại sách
//     {
//          int i;
//             GoTo(25,2); cout<<"Danh sach the loai sach:\n";
//             GoTo(25,4); cout<<"1.Khoa hoc";
//             GoTo(25,6); cout<<"2.Toan";
//             GoTo(25,8); cout<<"3.Van hoc";
//             GoTo(25,10); cout<<"4.Giao an";
//             GoTo(25,12); cout<<"5.Lich su";
//             GoTo(25,14); cout<<"6.Huong nghiep";
//             GoTo(25,16); cout<<"7.Tro ve menu";
//             GoTo(25,18); cout<<"Nhap lua chon cua ban: ";
//             cin>>i;
//         switch(i)
//         {
//             case 1: return 1;
//                     break;
//             case 2: return 2;
//                     break;
//             case 3: return 3;
//                     break;
//             case 4: return 4;
//                     break;
//             case 5: return 5;
//                     break;
//             case 6: return 6;
//                     break;
//             case 7: exit(0);
// 		            break;
//             default: 
// 					GoTo(25,20); cout<<"Hay chon dung danh muc sach!";
//                     getch();
//                     system("CLS");
//                     branch();
// 		}  
// 	}
