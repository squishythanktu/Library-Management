#include "Sinhvien.h"

void Sinhvien::menu_sv()
{
    fflush(stdin);
    system("cls");
    cout << "************ MENU SINH VIEN ************" << endl;
    cout << "Nhap lua chon: " << endl;
    cout << "1. Xem sach" << endl;
    cout << "2. Tim sach" << endl;
    cout << "3. Muon sach" << endl;
    cout << "4. Tra sach" << endl;
    cout << "5.Dong" << endl;
    cout << "Nhap lua chon cua ban: ";  
    char i;
    cin >> i;
    switch (i)
    {
    case '1':
    
        break;
    case '2':
        // search(); // Tim sach
        break;
    case '3':
        // muonsach(); // Muon sach
        break;
    case '4':
        // trasach(); // Tra sach
        break;
    case '5':
        exit(0);
        break;
    default:
        cout << "Hay nhap lua chon dung!";
        getch();
        system("cls");
        menu_sv();
        break;
    }
}
void Sinhvien::pass_sv()
{
    string line = " ";
    ifstream readFile("D:/Workspace/PBL2/pass/pass_sv.txt");
    string UserName, _UserName, _Password;
    cout << "SINH VIEN DANG NHAP!" << endl;
    cout << "Ma sinh vien: ";
    cin >> UserName;
    cout << "Mat khau: ";
    int k=0;
    char ch,st[100];
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
            menu_sv();
            found = true;
            break;
        }
    }
    if (!found) { //Dang nhap that bai
        cout << "\nMa sinh vien hoac mat khau khong dung. Hay thu lai.....";
        getch();
        system("cls");
        pass_sv();
    }
}