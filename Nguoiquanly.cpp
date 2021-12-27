#include "Nguoiquanly.h"
#include<iostream>
using namespace std;

Nguoiquanly::Nguoiquanly(){
    a = new Book[100];
    this->admin = "";
    this->pass = "";
}
Nguoiquanly::~Nguoiquanly(){
    delete[] a;
}
void Nguoiquanly:: menu_ql()
{
    fflush(stdin);
    system("cls");
    Goto(34, 3);
    textcolor(6);
    cout << "                      -MENU QUAN LY-           ";
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
    cout<<"\t            1. Xem sach             \t";
    Goto(93,7);cout<<"*";
    Goto(34,8); cout << "*";
    Goto(93,8);cout<<"*";
    Goto(34,9);cout << "*";
    cout<<"\t            2. Tim sach             \t";
    Goto(93,9);cout<<"*";
    Goto(34,10); cout << "*";
    Goto(93,10);cout<<"*";
    Goto(34,11);cout << "*";
    cout<<"\t            3. Dieu chinh sach             \t";
    Goto(93,11);cout<<"*";
    Goto(34,12); cout <<"*";
    Goto(93,12);cout<<"*";
    Goto(34,13);cout<<"*";
    cout<<"\t            4. Xem danh sach phieu muon             \t";
    Goto(93,13);cout<<"*";
    Goto(34,14); cout <<"*";
    Goto(93,14);cout<<"*";
    Goto(34,15);cout<<"*";
    cout<<"\t            5. Doi mat khau quan ly         \t";
    Goto(93,15);cout<<"*";
    Goto(34,16); cout <<"*";
    Goto(93,16);cout<<"*";
    Goto(34,17);cout<<"*";
    cout<<"\t            6. Dang xuat             \t";
    Goto(93,17);cout<<"*";
    Goto(34,18); cout <<"*";
    Goto(93,18);cout<<"*";
    Goto(34,19);cout<<"*";
    cout<<"\t            7. Dong             \t";
    Goto(93,19);cout<<"*";
    Goto(34,20); cout <<"*";
    Goto(93,20);cout<<"*";
    Goto(34,21);cout<<"*";
    for (int i = 0; i < 58; i++) {
        cout << "*";
    }
    cout << "*";
    Goto(34,23);
    cout<<"Nhap lua chon cua ban:           \t";
    string n; 
    Goto(57,23);cin >> n;
    textcolor(12);Goto(34,25);
    if(n.length()>1)
    {
        cout<<"Lua chon khong hop le. Hay nhap lai...";
        getch();
        system("cls");
        menu_ql();
    }
    char m=n[0];
    switch(m) 
    {
        case '1': 
        {
            textcolor(7);
            system("cls");
            a->XemSach(a);
            getch();
            system("cls");
            back_ql();
            break;
        }
            
        case '2': 
        {   
            textcolor(7);
            system("cls");
            menu_timsach();
            getch();
            system("cls");
            back_ql();
            break;
        }
        case '3': 
        {
            textcolor(7);
            system("cls");
            menu_dieuchinh();
            getch();
            system("cls");
            back_ql();
            break;
        }
        case '4':
        {
            textcolor(7);
            system("cls");
            Phieumuon temp;
            temp.xem_phieumuon();
            getch();
            system("cls");
            back_ql();
            break;
        }
        case '5':
        {
            textcolor(7);
            system("cls");
            ThayDoiMatKhau();
            getch();
            system("cls");
            Menu temp;
            temp.menu();
            break;
        }
        case '6':
        { 
            textcolor(7);
            system("cls");
            DangXuat();
            getch();
            system("cls");
            back_ql();
            break;
        }
        case '7': 
        {
            exit(0);
        }
        default: 
        {
            cout<<"Lua chon khong hop le. Hay nhap lai...";
            getch();
            system("cls");
            menu_ql();
        }
    }
}
void Nguoiquanly::DangXuat()
{
    Goto(41,3);textcolor(6);  cout << "************ QUAN LY DANG XUAT ************" << endl;textcolor(7);
    Goto(45,4);cout << "Ban chac chan muon dang xuat? " << endl;
    Goto(45,5);cout << "1. Co" << endl;
    Goto(45,6);cout << "2. Khong" << endl;
    Goto(45,7);cout << "Nhap lua chon cua ban: ";
    string n;
    cin >> n;
    if(n.length()>1)
    {
        textcolor(12); cout<<"Lua chon khong hop le. Hay nhap lai..."; textcolor(7);
        getch();
        system("cls");
        DangXuat();
    }
    char i=n[0];
    switch (i)
    {
        case '1':
        {
            textcolor(10); Goto(41,8);cout << "Ban da dang xuat thanh cong!" << endl;textcolor(7);
            getch();
            system("cls");
            Menu a;
            a.menu();
            break;
        }
        case '2':
        {
            system("cls");
            menu_ql();
            break;
        }
        default:
        {
            Goto(45,8);textcolor(12); cout << "Lua chon khong hop le. Hay nhap lai..."; textcolor(7);
            getch();
            system("cls");
            DangXuat();
        }
    }
}
string Nguoiquanly::convert_pass(string &pass)
{
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
    pass = string(st);
    return pass;
}
void Nguoiquanly::pass_ql()
{
    string line = " ";
    ifstream readFile("D:/Workspace/PBL2/pass/pass_ql.txt");
    string _UserName, _Password;
    Goto(53, 3);
    textcolor(6);
    cout << "-QUAN LY DANG NHAP-"<<endl;
    textcolor(7);
    Goto(34,5);cout<<"*";
    for(int i=0;i<58;i++)
    {
        cout<<"*";
    }
    cout <<"*";
    Goto(34, 6); cout << "*";
    Goto(93,6);cout<<"*";
    Goto(34,6);cout << "*";
    Goto(93,7);cout<<"*";
    Goto(34,7);cout << "*";
    Goto(93,8);cout<<"*";
    Goto(34,8);cout << "*";
    Goto(93,9);cout<<"*";
    Goto(34,9);cout << "*";
    Goto(34,10);cout<<"*";
    for(int i=0;i<58;i++)
    {
        cout<<"*";
    }
    cout<<"*";
    Goto(41,6);cout << "Ten dang nhap: ";
    Goto(56,6);cin >> this->admin;
    Goto(41,8);cout << "Mat khau: ";
    convert_pass(this->pass); //nhập mật khẩu và chuyển thành dãy ***
    bool found = false;
    while (getline(readFile,line))
    {
        stringstream in(line);
        in >> _UserName >> _Password;
        if (this->admin == _UserName && this->pass == _Password) { //Dang nhap thanh cong
            textcolor(10);Goto(41,11);cout << "Dang nhap thanh cong!" << endl;textcolor(7);
            getch();
            system("cls");
            menu_ql();
            found = true;
            break;
        }
    }
    if (!found) { //Dang nhap that bai
        textcolor(12);Goto(41,11);cout << "Ten dang nhap hoac mat khau khong dung. Hay thu lai...";textcolor(7);
        getch();
        system("cls");
        pass_ql();
    }
    readFile.close();
}
void Nguoiquanly::ThayDoiMatKhau()
{
    string mk_hientai, mk_moi, mk_nhaplai, _Password, _Username, user[100], pass[100];
    int n=0;
    Goto(40, 3); textcolor(6); cout << "\t-------THAY DOI MAT KHAU QUAN LY-------\t" << endl; textcolor(7);
    Goto(40, 5);cout << "Nhap mat khau hien tai: ";
    convert_pass(mk_hientai);
    if (mk_hientai==this->pass){
            Goto(40, 6);cout<<"Nhap mat khau moi: ";
            convert_pass(mk_moi);
            Goto(40, 7);cout<<"Nhap lai mat khau moi: ";
            convert_pass(mk_nhaplai);
            if (mk_moi==mk_nhaplai){
                ifstream in("D:/Workspace/PBL2/pass/pass_ql.txt");
                while(in >> _Username >> _Password){
                    if (_Username == this->admin){
                        user[n]=_Username;
                        pass[n]=mk_moi;
                        n++;
                    }
                    else{
                        user[n]=_Username;
                        pass[n]=_Password;
                        n++;
                    }
                }
                in.close();
                ofstream out("D:/Workspace/PBL2/pass/pass_ql.txt", ios::out | ios::trunc);
                for (int i=0; i<n; i++){
                    out << user[i] << " " << pass[i] << endl;
                }
                out.close();
                textcolor(10);cout << "\n                                        Thay doi mat khau thanh cong! Moi ban dang xuat va dang nhap lai"; textcolor(7);
                
            }
            else{
                textcolor(12);cout<<"\n                                        Mat khau nhap lai khong dung. Hay nhap lai...";textcolor(7);
                getch();
                system("cls");
                ThayDoiMatKhau();
            }
    }
    else{
        textcolor(12);cout<<"\n                                        Mat khau hien tai khong dung. Hay nhap lai...";textcolor(7);
        getch();
        system("cls");
        ThayDoiMatKhau();      
    }
}
void Nguoiquanly::back_ql()
{
    string a;
    Goto(41,5);
    cout << "----------Ban muon lam gi?----------";
	Goto(45,6);cout << "1.Quay lai menu quan ly";
	Goto(45,7);cout << "2.Dong ung dung";
    Goto(41,8);cout << "------------------------------------";
    Goto(45,9);cout << "Nhap lua chon cua ban: "; 
    fflush(stdin);
    getline(cin,a);
    if(strcmp(a.c_str(),"1")==0){
        system("cls");
        menu_ql();
    }
    else if(strcmp(a.c_str(),"2")==0){
        exit(0);
    }
    else{
        textcolor(12);Goto(45,10);cout << "Hay nhap lua chon dung!";textcolor(7);
        getch();
        system("cls");
        back_ql();
    }
}
void Nguoiquanly::menu_timsach()
{
    Goto(34, 4);
    textcolor(6);
    cout << "                    -MENU TIM SACH-           ";
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
    cout<<"\t            1. Tim sach theo ID             \t";
    Goto(93,7);cout<<"*";
    Goto(34,8); cout << "*";
    Goto(93,8);cout<<"*";
    Goto(34,9);cout << "*";
    cout<<"\t            2. Tim sach theo ten            \t";
    Goto(93,9);cout<<"*";
    Goto(34,10); cout << "*";
    Goto(93,10);cout<<"*";
    Goto(34,11);cout << "*";
    cout<<"\t            3. Tro ve menu truoc          \t";
    Goto(93,11);cout<<"*";
    Goto(34,12); cout <<"*";
    Goto(93,12);cout<<"*";
    Goto(34,13);cout<<"*";
    for (int i = 0; i < 58; i++) {
        cout << "*";
    }
    cout << "*";
    Goto(34,15);
    cout<<"Nhap lua chon cua ban:           \t";
    string n; 
    Goto(57,15);cin >> n; 
    textcolor(12);
    if(n.length()>1)
    {
        cout<<"Lua chon khong hop le. Hay nhap lai...";
        getch();
        system("cls");
        menu_timsach();
    }
    char m=n[0]; 
    switch (m)
    {
    case '1':
        {
            textcolor(7);
            system("cls");
            this->a->Timsach_ID(a);
            getch();
            system("cls");
            back_ql();
            break;
        }
        
    case '2':
        {
            textcolor(7);
            system("cls");
            this->a->Timsach_Tensach(a);
            getch();
            system("cls");
            back_ql();
            break;
        }
    case '3':
        {
            textcolor(7);
            system("cls");
            menu_ql();
            break;
        }
    default:
        {
            Goto(34,16);cout << "Lua chon khong hop le! Hay nhap lai...";
            getch();
            system("cls");
            menu_timsach();
            break;
        }
    }
}
void Nguoiquanly::menu_dieuchinh()
{
    Goto(34, 4);
    textcolor(6);
    cout << "                    -MENU DIEU CHINH-           ";
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
    cout<<"\t            1. Them sach             \t";
    Goto(93,7);cout<<"*";
    Goto(34,8); cout << "*";
    Goto(93,8);cout<<"*";
    Goto(34,9);cout << "*";
    cout<<"\t            2. Xoa sach            \t";
    Goto(93,9);cout<<"*";
    Goto(34,10); cout << "*";
    Goto(93,10);cout<<"*";
    Goto(34,11);cout << "*";
    cout<<"\t            3. Tro ve menu truoc          \t";
    Goto(93,11);cout<<"*";
    Goto(34,12); cout <<"*";
    Goto(93,12);cout<<"*";
    Goto(34,13);cout<<"*";
    for (int i = 0; i < 58; i++) {
        cout << "*";
    }
    cout << "*";
    Goto(34,15);
    cout<<"Nhap lua chon cua ban:           \t";
    string n; 
    Goto(57,15);cin >> n;
    textcolor(12);
    if(n.length()>1)
    {
        cout<<"Lua chon khong hop le. Hay nhap lai...";
        getch();
        system("cls");
        menu_dieuchinh();
    }
    char m=n[0];
    switch (m)
    {
        case '1':
            {   
                system("cls");
                this->a->Themsach(a);
                getch();
                system("cls");
                back_ql();
                break;
            }
            
        case '2':
            {
                system("cls");
                this->a->Xoasach(a);
                getch();
                system("cls");
                back_ql();
                break;
            }
        case '3':
            {
                textcolor(7);
                system("cls");
                menu_ql();
                break;
            }
        default:
            {
                Goto(34,16);cout << "Lua chon khong hop le! Hay nhap lai...";
                getch();
                system("cls");
                menu_dieuchinh();
                break;
            }
    }
}