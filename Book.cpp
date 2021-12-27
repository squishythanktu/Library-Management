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
int Book::getSoluong()
{
    return Soluong;
}
void Book::setSoluong(int a)
{
    Soluong=a;
}
istream& operator >>(istream &in,Book &a){
    Goto(34, 6);cout<<"Nhap ID sach: "; 
    fflush(stdin);
    getline(in,a.ID);
    Goto(34, 7);cout<<"Nhap ten sach: "; 
    fflush(stdin);
    getline(in,a.Tensach);
    Goto(34, 8);cout<<"Nhap ten tac gia: "; 
    fflush(stdin);
    getline(in,a.Tentacgia);
    Goto(34, 9);cout<<"Nhap nha xuat ban: "; 
    fflush(stdin);
    getline(in,a.Nhaxuatban);
    Goto(34, 10);cout<<"Nhap gia tien: ";
    char temp[100];
    GIA:
    {
        in.getline(temp,100);
        int so=0;
        for(int i=0; i < strlen(temp); i++)
        {
            if(isdigit(temp[i]))
                so++;
        }
        while(so != strlen(temp) || atoi(temp) <= 0)
        {
            Goto(34,11); textcolor(12); cout << "Gia tien khong hop le! Nhap lai: "; textcolor(7);
            goto GIA;
        }
    }
    //gán khi chuỗi chỉ toàn số hợp lệ
    a.Giatien=atoi(temp);
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
    cout<<setw(30)<<left<<Nhaxuatban;
    cout<<setw(16)<<left<<Giatien<<endl;
}
void Book::Timsach_ID(Book *a)
{
    int n=getInfo(a), title=0;
    string line;
    bool found = false;
    Goto(30, 4); textcolor(6); cout << "*************** TIM SACH THEO ID ***************" << endl; textcolor(7);
    Goto(30, 6); cout<<"Nhap ID sach ban muon coi: "; 
    fflush(stdin);
    cin >> line;
    cout << endl << endl;
    for (int i=0;i<n-1;i++){
        if (line==a[i].ID)
        {
            if(title==0)
            {
                cout<<setw(10)<<left<<"ID";
                cout<<setw(30)<<left<<"Tensach";
                cout<<setw(30)<<left<<"Tentacgia";
                cout<<setw(30)<<left<<"Nhaxuatban";
                cout<<setw(16)<<left<<"Giatien" << endl << endl;
                title=1;
            }        
            a[i].display();
            found = true;
        }
    }
    if (!found)
    {
        Goto(30, 8); textcolor(12); cout << "Khong tim thay sach!";textcolor(7);
    }
}
void Book::Timsach_Tensach(Book *a)
{
    int n=getInfo(a), title=0;
    string line;
    bool found = false;
    Goto(30, 4); textcolor(6); cout << "*************** TIM SACH THEO TEN ***************" << endl; textcolor(7);
    Goto(30, 6); cout<<"Nhap ten sach ban muon coi: "; 
    fflush(stdin);
    getline(cin, line);
    cout << endl << endl;
    for (int i=0;i<n-1;i++){
        if (line==a[i].Tensach || a[i].Tensach.find(line) != string::npos){
            if(title==0)
            {
                cout<<setw(10)<<left<<"ID";
                cout<<setw(30)<<left<<"Tensach";
                cout<<setw(30)<<left<<"Tentacgia";
                cout<<setw(30)<<left<<"Nhaxuatban";
                cout<<setw(16)<<left<<"Giatien"<< endl << endl;
                title=1;
            }        
            a[i].display();
            found = true;
        }
    }
    if (!found)
    {
        Goto(30, 8); textcolor(12); cout << "Khong tim thay sach!";textcolor(7);
    }
}
void Book::XemSach(Book *a){
    int n=getInfo(a);
    cout<<setw(10)<<left<<"ID";
    cout<<setw(30)<<left<<"Tensach";
    cout<<setw(30)<<left<<"Tentacgia";
    cout<<setw(30)<<left<<"Nhaxuatban";
    cout<<setw(16)<<left<<"Giatien"<<endl;
    for (int i=0;i<n-1;i++){
    cout<<setw(10)<<left<<a[i].ID;
    cout<<setw(30)<<left<<a[i].Tensach;
    cout<<setw(30)<<left<<a[i].Tentacgia;
    cout<<setw(30)<<left<<a[i].Nhaxuatban;
    cout<<setw(16)<<left<<a[i].Giatien<<endl;
    }
    cout<<endl;
}

bool Book::Checktontai(Book *a)
{
    int n = getInfo(a);
    for(int i=0;i<n-1;i++)
    {
        if(ID==a[i].ID || (Tensach==a[i].Tensach && Tentacgia==a[i].Tentacgia))
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
    textcolor(6);Goto(34, 4);
    if (Book.fail()) return;
    cout<<"*****************Them sach*****************\n";textcolor(7);
    cin>>x;
    while(x.Checktontai(a)) //neu ton tai
    {
        textcolor(12); Goto(34, 12); cout<<" ID hoac ten sach da ton tai, vui long nhap lai!"; textcolor(7);
        getch();
        system("cls");
        textcolor(6); Goto(34, 4); cout<<"*****************Them sach*****************\n"; textcolor(7);
        cin >> x;
    }
    Book<<x;
    Goto(34,12);textcolor(10);cout << "Them sach thanh cong!" << endl; textcolor(7);
    getInfo(a);
    Book.close();
    Sapxep(a);
}

void Book::Xoasach(Book *a)
{
    textcolor(7);
    string id,ten;
    int n = getInfo(a), i, j;
    Goto(34, 4); textcolor(6); cout<<"*************** XOA SACH ***************\n"; textcolor(7);
    ifstream Xoa("D:/Workspace/PBL2/Book/Booklist.txt");// doc file booklist
    ofstream Book("D:/Workspace/PBL2/Book/demo.txt",ofstream::out); // mo file temp
    bool found=false;
    Goto(34, 5);cout<<"Nhap ID sach can xoa: ";
    fflush(stdin);
    getline(cin, id);
    Goto(34,6); cout << "Nhap ten sach ban muon xoa: ";
    fflush(stdin);
    getline(cin,ten);
    while(!found)
    {
        for(i=0; i < n-1; i++)
        {
            if(ten==a[i].Tensach && id == a[i].ID)
            {
                found = true;
                Goto(34,7); textcolor(10); cout << "Xoa sach thanh cong!"; textcolor(7);
                break;
            }
        }
        if(!found)
        {
            Goto(34,7); textcolor(12); cout << "Khong tim thay sach ban muon xoa! Hay nhap lai..."; textcolor(7);
            getch();
            system("cls");
            Goto(34, 4); textcolor(6); cout<<"*************** XOA SACH ***************\n"; textcolor(7);
            Goto(34, 5);cout<<"Nhap ID sach can xoa: ";
            fflush(stdin);
            getline(cin, id);
            Goto(34,6); cout << "Nhap ten sach ban muon xoa: ";
            fflush(stdin);
            getline(cin,ten);
        }
    }
    for(j=0; j < n-1; j++)
    {
        if(j != i)
        {
            Book << a[j];
        }
    }
    Book.close();
    Xoa.close();
    remove("D:/Workspace/PBL2/Book/Booklist.txt"); // Xoá file Booklist cũ
    rename("D:/Workspace/PBL2/Book/demo.txt","D:/Workspace/PBL2/Book/Booklist.txt"); // Đổi tên demo thành Booklist
}
