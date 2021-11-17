#include "Book.cpp"
#include "Phieumuon.cpp"
#include "Phieumuon.h"
#include<iostream>
using namespace std;
Sinhvien::Sinhvien(){
    a = new Book[100];
    this->Msv = "";
    this->Mk = "";
}
Sinhvien::~Sinhvien(){
    delete [] a;
}
string Sinhvien::convert_pass(string &pass)
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
void Sinhvien::DangXuat()
{
    cout << "************ SINH VIEN DANG XUAT ************" << endl;
    cout << "Ban chac chan muon dang xuat? " << endl;
    cout << "1. Co" << endl;
    cout << "2. Khong" << endl;
    cout << "Nhap lua chon cua ban: ";
    string n;
    cin >> n;
    if(n.length()>1)
    {
        cout<<"Lua chon khong hop le. Hay nhap lai...";
        getch();
        system("cls");
        DangXuat();
    }
    char i=n[0];
    switch (i)
    {
        case '1':
        {
            textcolor(2);
            cout << "Ban da dang xuat thanh cong!" << endl;
            getch();
            system("cls");
            textcolor(7);
            Menu a;
            a.menu();
            break;
        }
        case '2':
        {
            system("cls");
            back_sv();
            break;
        }
        default:
        {
            system("cls");
            textcolor(4);
            cout << "Lua chon khong hop le. Hay nhap lai...";
            getch();
            system("cls");
            textcolor(7);
            DangXuat();
        }
    }
}
void Sinhvien::menu_sv()
{
    fflush(stdin);
    system("cls");
    Goto(34, 3);
    textcolor(6);
    cout << "                      -MENU SINH VIEN-           ";
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
    cout<<"\t            3. Muon sach             \t";
    Goto(93,11);cout<<"*";
    Goto(34,12); cout <<"*";
    Goto(93,12);cout<<"*";
    Goto(34,13);cout<<"*";
    cout<<"\t            4. Tra sach             \t";
    Goto(93,13);cout<<"*";
    Goto(34,14); cout <<"*";
    Goto(93,14);cout<<"*";
    Goto(34,15);cout<<"*";
    cout<<"\t            5. Thay doi mat khau             \t";
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
    Goto(56,23);cin >> n;
    textcolor(12);Goto(34,25);
    if(n.length()>1)
    {
        cout<<"Lua chon khong hop le. Hay nhap lai...";
        getch();
        system("cls");
        menu_sv();
    }
    char i=n[0];
    switch (i)
    {
        case '1':
        {
            textcolor(7);
            system("cls");
            this->a->XemSach(a);
            getch();
            system("cls");
            back_sv();
            break;
        }
        case '2':
        {   
            textcolor(7);
            system("cls");
            menu_timsach();
            getch();
            system("cls");
            back_sv();
            break;
        }
        case '3':
        {
            textcolor(7);
            system("cls");
            Phieumuon pm(Msv);
            pm.Muonsach(pm);
            getch();
            system("cls");
            back_sv();
            break;
        }
        case '4':
        {
            textcolor(7);
            system("cls");
            Phieumuon pm(Msv);
            pm.Trasach(pm);
            getch();
            system("cls");
            back_sv();
            break;
        }
        case '5':
        {
            textcolor(7);
            system("cls");
            ThayDoiMatKhau();
            getch();
            system("cls");
            back_sv();
            break;
        }
        case '6':
        {
            textcolor(7);
            system("cls");
            DangXuat();
            getch();
            system("cls");
            back_sv();
            break;
        }
        case '7':
        {
            exit(0);
            break;
        }
        default:
        {
            textcolor(12);cout << "Lua chon khong hop le. Hay nhap lai...";textcolor(7); 
            getch();
            system("cls");
            menu_sv();
            break;
        }
    }
}
void Sinhvien::pass_sv()
{
    string line = " ";
    ifstream readFile("D:/Workspace/PBL2/pass/pass_sv.txt");
    string _UserName, _Password;
    Goto(34, 3);
    textcolor(6);
    cout << "\t        -SINH VIEN DANG NHAP-     \t"<<endl;
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
    Goto(41,6);cout << "Ma sinh vien: ";
    Goto(56,6);cin >> this->Msv;
    Goto(41,8);cout << "Mat khau: ";
    convert_pass(this->Mk); //nhập mật khẩu và chuyển thành dãy ***
    bool found = false;
    while (getline(readFile,line))
    {
        stringstream in(line);
        in >> _UserName >> _Password;
        if (this->Msv == _UserName && this->Mk == _Password) { //Dang nhap thanh cong
            textcolor(10);Goto(41,11);cout << "Dang nhap thanh cong!" << endl;textcolor(7);
            getch();
            system("cls");
            menu_sv();
            found = true;
            break;
        }
    }
    if (!found) { //Dang nhap that bai
        textcolor(12);Goto(41,11);cout << "Ma sinh vien hoac mat khau khong dung. Hay thu lai....."<< endl;textcolor(7);
        getch();
        system("cls");
        pass_sv();
    }
    readFile.close();
}
void Sinhvien::back_sv()
{
    int a;
    Goto(34, 3);
    cout << "\n\t----------Ban muon lam gi?----------------";
	cout << "\n\t1.Quay lai menu sv ";
	cout << "\n\t2.Dong ung dung";
    cout << "\n\t------------------------------------------";
    cout << "\n\tNhap lua chon cua ban: "; 
    cin >> a;
    switch (a)
    {
    case 1:
        system("cls");
        menu_sv();
        break;
    case 2:
        exit(0);
        break;
    default:
        textcolor(12);cout << "Hay nhap lua chon dung!";textcolor(7);
        getch();
        system("cls");
        back_sv();
        break;
    }
}
void Sinhvien::menu_timsach()
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
    Goto(56,15);cin >> n; 
    textcolor(12);
    if(n.length()>1)
    {
        cout<<"Lua chon khong hop le. Hay nhap lai...";
        getch();
        system("cls");
        menu_timsach();
    }
    textcolor(7);
    char m=n[0]; 
    switch (m)
    {
    case '1':
        {
            system("cls");
            this->a->Timsach_ID(a);
            getch();
            system("cls");
            back_sv();
            break;
        }
        
    case '2':
        {
            system("cls");
            this->a->Timsach_Tensach(a);
            getch();
            system("cls");
            back_sv();
            break;
        }
    case '3':
        {
            system("cls");
            back_sv();
            break;
        }
    default:
        {
            cout << "Lua chon khong hop le! Hay nhap lai...";
            getch();
            system("cls");
            menu_timsach();
            break;
        }
    }
}
void Sinhvien::ThayDoiMatKhau()
{
    string mk_hientai, mk_moi, mk_nhaplai, _Password, _Username, user[100], pass[100];
    int n=0;
    Goto(0, 3);
    textcolor(6);
    cout << "\t-----------THAY DOI MAT KHAU SINH VIEN---------\t" << endl;textcolor(7);
    Goto(0, 5);cout << "Nhap mat khau hien tai: ";
    convert_pass(mk_hientai);
    if (mk_hientai==this->Mk){
            cout<<"\nNhap mat khau moi: ";
            convert_pass(mk_moi);
             cout<<"\nNhap lai mat khau moi: ";
            convert_pass(mk_nhaplai);
            if (mk_moi==mk_nhaplai){
                ifstream in("D:/Workspace/PBL2/pass/pass_sv.txt");
                while(in >> _Username >> _Password){
                    if (_Username == this->Msv){
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
                ofstream out("D:/Workspace/PBL2/pass/pass_sv.txt", ios::out | ios::trunc);
                for (int i=0; i<n; i++){
                    out << user[i] << " " << pass[i] << endl;
                }
                out.close();
                textcolor(10);cout << "\nThay doi mat khau thanh cong! Moi ban dang xuat va dang nhap lai"; textcolor(7);
                
            }
            else{
                textcolor(12);cout<<"\nMat khau nhap lai khong dung. Hay nhap lai...";textcolor(7);
                getch();
                system("cls");
                ThayDoiMatKhau();
            }
    }
    else{
        textcolor(12);cout<<"\nMat khau hien tai khong dung. Hay nhap lai...";textcolor(7);
        getch();
        system("cls");
        ThayDoiMatKhau();      
    }
}