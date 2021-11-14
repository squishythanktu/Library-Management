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
    cout << "************ MENU QUAN LY ************" << endl;
    cout << "Nhap lua chon: " << endl;
    cout << "1. Xem sach" << endl;
    cout << "2. Tim sach" << endl;
    cout << "3. Dieu chinh sach" << endl;
    cout << "4. Xem danh sach phieu muon"<<endl;
    cout << "5. Thay doi mat khau"<<endl;
    cout << "6. Dang xuat" << endl;
    cout << "7. Dong" << endl;
    cout << "Nhap lua chon cua ban: "; 
    string n; 
    cin >> n;
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
            system("cls");
            a->XemSach(a);
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
            system("cls");
            //xem_phieumuon(a);
            getch();
            system("cls");
            back_ql();
            break;
        }
        case '5':
        {
            system("cls");
            ThayDoiMatKhau();
            getch();
            system("cls");
            back_ql();
            break;
        }
        case '6':
        {
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
    cout << "************ QUAN LY DANG XUAT ************" << endl;
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
            cout << "Ban da dang xuat thanh cong!" << endl;
            getch();
            system("cls");
            Menu a;
            a.menu();
            break;
        }
        case '2':
        {
            system("cls");
            back_ql();
            break;
        }
        default:
        {
            system("cls");
            cout << "Lua chon khong hop le. Hay nhap lai...";
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
    cout << "QUAN LY DANG NHAP!" << endl;
    cout << "Ten dang nhap: ";
    cin >> this->admin;
    cout << "Mat khau: ";
    convert_pass(this->pass); //nhập mật khẩu và chuyển thành dãy ***
    bool found = false;
    while (getline(readFile,line))
    {
        stringstream in(line);
        in >> _UserName >> _Password;
        if (this->admin == _UserName && this->pass == _Password) { //Dang nhap thanh cong
            cout << "\nDang nhap thanh cong!" << endl;
            getch();
            system("cls");
            menu_ql();
            found = true;
            break;
        }
    }
    if (!found) { //Dang nhap that bai
        cout << "\nTen dang nhap hoac mat khau khong dung. Hay thu lai.....";
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
    cout << "************ THAY DOI MAT KHAU QUAN LY ************" << endl;
    cout << "Nhap mat khau hien tai: ";
    convert_pass(mk_hientai);
    if (mk_hientai==this->pass){
            cout<<"\nNhap mat khau moi: ";
            convert_pass(mk_moi);
            cout<<"\nNhap lai mat khau moi: ";
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
                cout << "\nThay doi mat khau thanh cong!";
                
            }
            else{
                cout<<"\nMat khau nhap lai khong dung. Hay nhap lai...";
                getch();
                system("cls");
                ThayDoiMatKhau();
            }
    }
    else{
        cout<<"\nMat khau hien tai khong dung. Hay nhap lai...";
        getch();
        system("cls");
        ThayDoiMatKhau();      
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
        {
            system("cls");
            menu_ql();
            break;
        }
            
        case 2:
        {
            exit(0);
            break;
        }
        default:
        {
            cout << "Hay nhap lua chon dung!";
            getch();
            system("cls");
            back_ql();
            break;
        }
    }
}
void Nguoiquanly::menu_timsach()
{
    cout << "************ MENU TIM SACH ************" << endl;
    cout << "1. Tim sach theo ID" << endl;
    cout << "2. Tim sach theo ten" << endl;
    cout << "3. Tro ve menu truoc" << endl;
    cout << "Nhap lua chon cua ban: "; 
    string n; 
    cin >> n;
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
            system("cls");
            this->a->Timsach_ID(a);
            getch();
            system("cls");
            back_ql();
            break;
        }
        
    case '2':
        {
            system("cls");
            this->a->Timsach_Tensach(a);
            getch();
            system("cls");
            back_ql();
            break;
        }
    case '3':
        {
            system("cls");
            back_ql();
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
void Nguoiquanly::menu_dieuchinh()
{
    cout << "************ MENU DIEU CHINH ************" << endl;
    cout << "1. Them sach" << endl;
    cout << "2. Xoa sach" << endl;
    cout << "3. Tro ve menu truoc" << endl;
    cout << "Nhap lua chon cua ban: ";
    string n; 
    cin >> n;
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
                menu_xoasach();
                getch();
                system("cls");
                back_ql();
                break;
            }
        case '3':
            {
                system("cls");
                back_ql();
                break;
            }
        default:
            {
                cout << "Lua chon khong hop le! Hay nhap lai...";
                getch();
                system("cls");
                menu_dieuchinh();
                break;
            }
    }
}
void Nguoiquanly::menu_xoasach()
{
    cout << "************ MENU XOA SACH ************" << endl;
    cout << "1. Xoa sach theo ID" << endl;
    cout << "2. Xoa sach theo ten" << endl;
    cout << "3. Tro ve menu truoc" << endl;
    cout << "Nhap lua chon cua ban: "; 
    string n; 
    cin >> n;
    if(n.length()>1)
    {
        cout<<"Lua chon khong hop le. Hay nhap lai...";
        getch();
        system("cls");
        menu_xoasach();
    }
    char m=n[0];
    switch (m)
    {
        case '1':
        {
            system("cls");
            this->a->Xoasach_ID(a);
            getch();
            system("cls");
            back_ql();
            break;
        } 
        case '2':
        {
            system("cls");
            this->a->Xoasach_Tensach(a);
            getch();
            system("cls");
            back_ql();
            break;
        }
        case '3':
        {
            system("cls");
            back_ql();
            break;
        }
        default:
        {   
            cout << "Lua chon khong hop le! Hay nhap lai...";
            getch();
            system("cls");
            menu_xoasach();
            break;
        }
    }
}