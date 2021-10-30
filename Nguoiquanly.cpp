#include "Nguoiquanly.h"
#include<iostream>
#include<stdio.h>
#include<stdlib.h>
#include<fstream>
#include <sstream>
#include<string>
#include<string>
#include<conio.h>
#include<Windows.h>
using namespace std;
istream& operator >>(istream &in,Nguoiquanly &a){
    cout<<"Nhap ID sach: "; 
    fflush(stdin);
    getline(in,a.ID);
    cout<<"Nhap ten sach: "; 
    fflush(stdin);
    getline(in,a.Tensach);
    cout<<"Nhap ten tac gia: "; 
    fflush(stdin);
    getline(in,a.Tentacgia);
    cout<<"Nhap nha xuat ban: "; 
    fflush(stdin);
    getline(in,a.Nhaxuatban);
    cout<<"Nhap gia tien: ";in >> a.Giatien;
    cout<<"Nhap so luong: ";in >> a.Soluong;
    return in;
}
ostream& operator <<(ostream &out,const Nguoiquanly &a){
    out<<a.ID<<endl;
    out<<a.Tensach<<endl;
    out<<a.Tentacgia<<endl;
    out<<a.Nhaxuatban<<endl;
    out<<a.Giatien<<endl;
    out<<a.Soluong<<endl;
    return out;
}
void Nguoiquanly::menu_ql()
{
    fflush(stdin);
    cout << "************ MENU QUAN LY ************" << endl;
    cout << "Nhap lua chon: " << endl;
    cout << "1. Xem sach" << endl;
    cout << "2. Tim sach" << endl;
    cout << "3. Dieu chinh sach" << endl;
    cout << "4. Dong" << endl;
    cout << "Nhap lua chon cua ban: "; 
    char m;
    cin>>m;
    switch(m) 
    {
        case '1': 
            {
                system("cls");
                Nguoiquanly *a = new Nguoiquanly[100];
                XemSach(a);
                getch();
                system("cls");
                back_ql();
                break;
            }
                
        case '2': 
            {
                system("cls");
                menu_timsach();
                getch();
                system("cls");
                back_ql();
                break;
            }
        case '3': 
            {
                system("cls");
                menu_dieuchinh();
                getch();
                system("cls");
                back_ql();
                break;
            }
        case '4': 
            {
                exit(0);
            }
        default: 
            {
                cout<<"Hay nhap lua chon dung!";
                getch();
                system("cls");
                menu_ql();
            }
    }
}
void Nguoiquanly::pass_ql()
{
    int k=0;
    char ch,st[100],ch1[100];
    cout << "QUAN LY DANG NHAP!" << endl;
    cout<<"Mat khau: ";
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
        menu_ql();
    }
    else //Dang nhap that bai
    {
        cout<<"\nMat khau khong dung. Hay thu lai.....";
        getch();
        system("cls");
        pass_ql();
    } 
}
void Nguoiquanly::back_ql()
{
    int a;
    cout << "Quay lai menu quan ly" << endl;
    cout << "1. Co" << endl;
    cout << "2. Khong" << endl;
    cout << "Nhap lua chon cua ban: "; 
    cin >> a;
    switch (a)
    {
    case 1:
        system("cls");
        menu_ql();
        break;
    case 2:
        exit(0);
        break;
    default:
        cout << "Hay nhap lua chon dung!";
        getch();
        system("cls");
        back_ql();
        break;
    }

}

int Nguoiquanly::getInfo(Nguoiquanly *a){
    ifstream Book("D:/Workspace/PBL2/Book/Booklist.txt");
    if (Book.fail()){
        cout<<"Loi doc file";
        system("exit");
    }
    int n=0;
    string line;
    while (!Book.eof()){ //Khi chưa đọc hết file
        getline(Book,a[n].ID);
        getline(Book,a[n].Tensach);
        getline(Book,a[n].Tentacgia);
        getline(Book,a[n].Nhaxuatban);
        getline(Book,line); 
        stringstream getlint(line); //chuyển kiểu string sang int
        getlint >> a[n].Giatien;
        getline(Book,line);
        stringstream getint(line);
        getint >> a[n].Soluong;
        n++;
        continue;
    }
    return n;
}
void Nguoiquanly::display(){
    cout<<setw(10)<<left<<ID;
    cout<<setw(30)<<left<<Tensach;
    cout<<setw(30)<<left<<Tentacgia;
    cout<<setw(23)<<left<<Nhaxuatban;
    cout<<setw(16)<<left<<Giatien;
    cout<<setw(15)<<left<<Soluong<<endl;
}
void Nguoiquanly::Timsach_ID(Nguoiquanly *a)
{
    int n=getInfo(a), title=0;
    string line;
    bool found = false;
    cout<<"Nhap ID sach ban muon coi: "; cin >> line;
    for (int i=0;i<n-1;i++){
        if (line==a[i].ID){
            if(title==0)
            {
                cout<<setw(10)<<left<<"ID";
                cout<<setw(30)<<left<<"Tensach";
                cout<<setw(30)<<left<<"Tentacgia";
                cout<<setw(23)<<left<<"Nhaxuatban";
                cout<<setw(16)<<left<<"Giatien";
                cout<<setw(15)<<left<<"Soluong"<<endl;
                title=1;
            }        
            a[i].display();
            found = true;
        }
    }
    if (!found)
        cout << "Khong tim thay sach!";
}
void Nguoiquanly::Timsach_Tensach(Nguoiquanly *a)
{
    int n=getInfo(a), title=0;
    string line;
    bool found = false;
    cout<<"Nhap ten sach ban muon coi: "; 
    fflush(stdin);
    getline(cin, line);
    for (int i=0;i<n-1;i++){
        if (line==a[i].Tensach || a[i].Tensach.find(line) != string::npos){
            if(title==0)
            {
                cout<<setw(10)<<left<<"ID";
                cout<<setw(30)<<left<<"Tensach";
                cout<<setw(30)<<left<<"Tentacgia";
                cout<<setw(23)<<left<<"Nhaxuatban";
                cout<<setw(16)<<left<<"Giatien";
                cout<<setw(15)<<left<<"Soluong"<<endl;
                title=1;
            }        
            a[i].display();
            found = true;
        }
    }
    if (!found)
        cout << "Khong tim thay sach!" << endl;
}
void Nguoiquanly::XemSach(Nguoiquanly *a){
    int n=getInfo(a);
    cout<<setw(10)<<left<<"ID";
    cout<<setw(30)<<left<<"Tensach";
    cout<<setw(30)<<left<<"Tentacgia";
    cout<<setw(23)<<left<<"Nhaxuatban";
    cout<<setw(16)<<left<<"Giatien";
    cout<<setw(15)<<left<<"Soluong"<<endl;
    for (int i=0;i<n-1;i++){
    cout<<setw(10)<<left<<a[i].ID;
    cout<<setw(30)<<left<<a[i].Tensach;
    cout<<setw(30)<<left<<a[i].Tentacgia;
    cout<<setw(23)<<left<<a[i].Nhaxuatban;
    cout<<setw(16)<<left<<a[i].Giatien;
    cout<<setw(15)<<left<<a[i].Soluong<<endl;
    }
    cout<<endl;
}
void Nguoiquanly::menu_timsach()
{
    cout << "************ MENU TIM SACH ************" << endl;
    cout << "1. Tim sach theo ID" << endl;
    cout << "2. Tim sach theo ten" << endl;
    cout << "3. Tro ve menu truoc" << endl;
    cout << "Nhap lua chon cua ban: "; 
    int m;
    cin >> m;
    switch (m)
    {
    case 1:
        {
            system("cls");
            Nguoiquanly *a = new Nguoiquanly[100];
            Timsach_ID(a);
            getch();
            system("cls");
            back_ql();
            break;
        }
        
    case 2:
        {
            system("cls");
            Nguoiquanly *b = new Nguoiquanly[100];
            Timsach_Tensach(b);
            getch();
            system("cls");
            back_ql();
            break;
        }
    case 3:
        {
            system("cls");
            back_ql();
            break;
        }
    default:
        {
            break;

        }
    }
}
void Nguoiquanly::menu_dieuchinh()
{
    cout << "************ MENU DIEU CHINH ************" << endl;
    cout << "1. Them sach" << endl;
    cout << "2. Xoa sach" << endl;
    cout << "3. Tro ve menu truoc" << endl;
    cout << "Nhap lua chon cua ban: ";
    int m;
    cin >> m;
    getchar();
    switch (m)
    {
    case 1:
        {   
            system("cls");
            Nguoiquanly *a=new Nguoiquanly[100];
            Nguoiquanly::Themsach(a);
            getch();
            system("cls");
            back_ql();
            break;
        }
        
    case 2:
        {
            system("cls");
            Nguoiquanly *a=new Nguoiquanly[100];
            Nguoiquanly::Xoasach(a);
            getch();
            system("cls");
            back_ql();
            break;
        }
    case 3:
        {
            system("cls");
            back_ql();
            break;
        }
    default:
        {
            break;
        }
    }
}
bool Nguoiquanly::Checktontai(Nguoiquanly *a)
{
    int n = getInfo(a);
    for(int i=0;i<n-1;i++)
    {
        if(ID==a[i].ID || Tensach==a[i].Tensach)
        {
            return true;
        }
    }
    return false;
}
void Nguoiquanly::Sapxep(Nguoiquanly *a)
{
    ofstream Book("D:/Workspace/PBL2/Book/demo.txt",ofstream::out); // ::out là mo file temp de ghi
    int n=getInfo(a);
    Nguoiquanly temp;
    for(int i=0;i<n;i++)
    {
        for(int j=i+1;j<n;j++)
        {
            if(atoi(a[i].ID.c_str()) > atoi(a[j].ID.c_str()))
            {
                temp=a[i];
                a[i]=a[j];
                a[j]=temp;
            }
        }
        
    }
    for(int i=1; i<n; i++)
    {
            Book<<a[i];
    }
    Book.close();
    remove("D:/Workspace/PBL2/Book/Booklist.txt"); // Xoá file Booklist cũ
    rename("D:/Workspace/PBL2/Book/demo.txt","D:/Workspace/PBL2/Book/Booklist.txt"); // Đổi tên demo thành Booklist
}
void Nguoiquanly::Themsach(Nguoiquanly *a)
{
    Nguoiquanly x;
    ofstream Book("D:/Workspace/PBL2/Book/Booklist.txt",ios::app);
    if (Book.fail()) return;
    cout<<"*****************Them sach*****************\n";
    cin>>x;
    while(x.Checktontai(a)) //neu ton tai
    {
        cout<<"ID hoac ten sach da ton tai, vui long nhap lai!";
        getch();
        system("cls");
        cout<<"*****************Them sach*****************\n";
        cin>>x;
    }
    Book<<x;
    cout << "Them sach thanh cong!" << endl;
    getInfo(a);
    Book.close();
    Sapxep(a);
}
void Nguoiquanly::Xoasach(Nguoiquanly *a)
{
    string x;
    cout<<"***************Xoa sach*******************\n";
    cout<<"\nNhap ID sach ban muon xoa: "; cin>>x;
    ifstream Xoa("D:/Workspace/PBL2/Book/Booklist.txt");// doc file booklist
    ofstream Book("D:/Workspace/PBL2/Book/demo.txt",ofstream::out); // mo file temp
    int n = getInfo(a);
    int i;
    int j;
    for(i=0;i<n-1;i++){
        if(x==a[i].ID) break;
    }
    for(j=0;j<n-1;j++){
        if(j!=i){
            Book<<a[j];
        }
    }
    Book.close();
    Xoa.close();
    remove("D:/Workspace/PBL2/Book/Booklist.txt"); // Xoá file Booklist cũ
    rename("D:/Workspace/PBL2/Book/demo.txt","D:/Workspace/PBL2/Book/Booklist.txt"); // Đổi tên demo thành Booklist
    cout << "Xoa sach thanh cong!";
}
