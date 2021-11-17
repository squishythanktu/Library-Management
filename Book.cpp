#include "Book.h"
#include<iostream>
using namespace std;
Book temp;
Book::Book()
{
    ID="";
    Tensach="";
    Tentacgia="";
    Nhaxuatban="";
    Giatien=0;
}
Book::~Book()
{
    //dtor
}
string Book::getID()
{
    return ID;
}
string Book::getTensach()
{
    return Tensach;
}
string Book::getTentacgia()
{
    return Tentacgia;
}
string Book::getNhaxuatban()
{
    return Nhaxuatban;
}
int Book::getGiatien()
{
    return Giatien;
}
istream& operator >>(istream &in,Book &a){
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
    cout<<"Nhap gia tien: ";
    in >> a.Giatien;
    return in;
}
ostream& operator <<(ostream &out,const Book &a){
    out<<a.ID<<endl;
    out<<a.Tensach<<endl;
    out<<a.Tentacgia<<endl;
    out<<a.Nhaxuatban<<endl;
    out<<a.Giatien<<endl;
    return out;
}

int Book::getInfo(Book *a){
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
        n++;
        continue;
    }
    Book.close();
    return n;
}
void Book::display(){
    cout<<setw(10)<<left<<ID;
    cout<<setw(30)<<left<<Tensach;
    cout<<setw(30)<<left<<Tentacgia;
    cout<<setw(23)<<left<<Nhaxuatban;
    cout<<setw(16)<<left<<Giatien<<endl;
}
void Book::Timsach_ID(Book *a)
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
                cout<<setw(16)<<left<<"Giatien"<<endl;
                title=1;
            }        
            a[i].display();
            found = true;
        }
    }
    textcolor(12);
    if (!found)
        cout << "Khong tim thay sach!";textcolor(7);
}
void Book::Timsach_Tensach(Book *a)
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
                cout<<setw(16)<<left<<"Giatien"<<endl;
                title=1;
            }        
            a[i].display();
            found = true;
        }
    }
    textcolor(12);
    if (!found)
        cout << "Khong tim thay sach!" << endl;textcolor(7);
}
void Book::XemSach(Book *a){
    int n=getInfo(a);
    cout<<setw(10)<<left<<"ID";
    cout<<setw(30)<<left<<"Tensach";
    cout<<setw(30)<<left<<"Tentacgia";
    cout<<setw(23)<<left<<"Nhaxuatban";
    cout<<setw(16)<<left<<"Giatien"<<endl;
    for (int i=0;i<n-1;i++){
    cout<<setw(10)<<left<<a[i].ID;
    cout<<setw(30)<<left<<a[i].Tensach;
    cout<<setw(30)<<left<<a[i].Tentacgia;
    cout<<setw(23)<<left<<a[i].Nhaxuatban;
    cout<<setw(16)<<left<<a[i].Giatien<<endl;
    }
    cout<<endl;
}

bool Book::Checktontai(Book *a)
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
void Book::Sapxep(Book *a)
{
    ofstream Book("D:/Workspace/PBL2/Book/demo.txt",ofstream::out); 
    int n=getInfo(a);
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
void Book::Themsach(Book *a)
{
    textcolor(7);
    Book x;
    ofstream Book("D:/Workspace/PBL2/Book/Booklist.txt",ios::app);
    Goto(34, 4);
    if (Book.fail()) return;
    cout<<"*****************Them sach*****************\n";
    cin>>x;
    while(x.Checktontai(a)) //neu ton tai
    {
        textcolor(12);cout<<"ID hoac ten sach da ton tai, vui long nhap lai!";textcolor(7);
        getch();
        system("cls");
        Goto(34, 4);cout<<"*****************Them sach*****************\n";
        cin>>x;
    }
    Book<<x;
    textcolor(10);cout << "Them sach thanh cong!" << endl;textcolor(7);
    getInfo(a);
    Book.close();
    Sapxep(a);
}

void Book::Xoasach_ID(Book *a)
{
    textcolor(7);
    string x;
    int n = getInfo(a), i, j;
    Goto(34, 4);cout<<"***************XOA SACH THEO ID *******************\n";
    ifstream Xoa("D:/Workspace/PBL2/Book/Booklist.txt");// doc file booklist
    ofstream Book("D:/Workspace/PBL2/Book/demo.txt",ofstream::out); // mo file temp
    bool found=false;
    cout<<"\nNhap ID sach ban muon xoa: "; cin>>x;
    while(!found)
    {
        for(i=0;i<n-1;i++)
        {
            if(x==a[i].ID)
            {
                found = true;
                textcolor(10);cout << "Xoa sach thanh cong!";textcolor(7);
                break;
            }
        }
        if(!found)
        {
            textcolor(12);cout << "Khong tim thay ID sach ban muon xoa! Hay nhap lai...";textcolor(7);
            getch();
            system("cls");
            Goto(34, 4);cout<<"***************XOA SACH THEO ID*******************\n";
            cout<<"\nNhap ID sach ban muon xoa: "; cin>>x;
        }
    }
    for(j=0;j<n-1;j++)
    {
        if(j!=i)
        {
            Book<<a[j];
        }
    }
    Book.close();
    Xoa.close();
    remove("D:/Workspace/PBL2/Book/Booklist.txt"); // Xoá file Booklist cũ
    rename("D:/Workspace/PBL2/Book/demo.txt","D:/Workspace/PBL2/Book/Booklist.txt"); // Đổi tên demo thành Booklist
}
void Book::Xoasach_Tensach(Book *a)
{
    textcolor(7);
    string x;
    int n = getInfo(a), i, j;
    Goto(34, 4);cout<<"***************XOA SACH THEO TEN*******************\n";
    ifstream Xoa("D:/Workspace/PBL2/Book/Booklist.txt");// doc file booklist
    ofstream Book("D:/Workspace/PBL2/Book/demo.txt",ofstream::out); // mo file temp
    bool found=false;
    cout<<"\nNhap ten sach ban muon xoa: ";
    fflush(stdin);
    getline(cin,x);
    while(!found)
    {
        for(i=0;i<n-1;i++)
        {
            if(x==a[i].Tensach)
            {
                found = true;
                textcolor(10);cout << "Xoa sach thanh cong!";textcolor(7);
                break;
            }
        }
        if(!found)
        {
            textcolor(12);cout << "Khong tim thay ten sach ban muon xoa! Hay nhap lai...";textcolor(7);
            getch();
            system("cls");
            Goto(34, 4);cout<<"***************XOA SACH THEO TEN *******************\n";
            cout<<"\nNhap ten sach ban muon xoa: "; cin>>x;
        }
    }
    for(j=0;j<n-1;j++)
    {
        if(j!=i)
        {
            Book<<a[j];
        }
    }
    Book.close();
    Xoa.close();
    remove("D:/Workspace/PBL2/Book/Booklist.txt"); // Xoá file Booklist cũ
    rename("D:/Workspace/PBL2/Book/demo.txt","D:/Workspace/PBL2/Book/Booklist.txt"); // Đổi tên demo thành Booklist
}
