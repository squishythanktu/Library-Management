#include "Book.cpp"
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
            back_sv();
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
    cout << "5. Thay doi mat khau" << endl;
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
        menu_sv();
    }
    char i=n[0];
    switch (i)
    {
        case '1':
        {
            system("cls");
            this->a->XemSach(a);
            getch();
            system("cls");
            back_sv();
            break;
        }
        case '2':
        {  
            system("cls");
            menu_timsach();
            getch();
            system("cls");
            back_sv();
            break;
        }
        case '3':
        {
            system("cls");
            Phieumuon pm(Msv);
            pm.Muonsach(pm);
            getch();
            system("cls");
            back_sv();
            break;
        }
        case '4':
            // trasach(); // Tra sach
            break;
        case '5':
        {
            system("cls");
            ThayDoiMatKhau();
            getch();
            system("cls");
            back_sv();
            break;
        }
        case '6':
        {
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
            cout << "Lua chon khong hop le. Hay nhap lai..."; 
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
    cout << "SINH VIEN DANG NHAP!" << endl;
    cout << "Ma sinh vien: ";
    cin >> this->Msv;
    cout << "Mat khau: ";
    convert_pass(this->Mk); //nhập mật khẩu và chuyển thành dãy ***
    bool found = false;
    while (getline(readFile,line))
    {
        stringstream in(line);
        in >> _UserName >> _Password;
        if (this->Msv == _UserName && this->Mk == _Password) { //Dang nhap thanh cong
            cout << "\nDang nhap thanh cong!" << endl;
            getch();
            system("cls");
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
    readFile.close();
}
void Sinhvien::back_sv()
{
    int a;
    cout << "Quay lai menu sinh vien" << endl;
    cout << "1. Co" << endl;
    cout << "2. Khong" << endl;
    cout << "Nhap lua chon cua ban: "; 
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
        cout << "Hay nhap lua chon dung!";
        getch();
        system("cls");
        back_sv();
        break;
    }
}
void Sinhvien::menu_timsach()
{
    cout << "************ MENU TIM SACH ************" << endl;
    cout << "1. Tim sach theo ID" << endl;
    cout << "2. Tim sach theo ten" << endl;
    cout << "3. Tro ve menu truoc" << endl;
    cout << "Nhap lua chon cua ban: "; 
    string n; 
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
    cout << "************ THAY DOI MAT KHAU SINH VIEN ************" << endl;
    cout << "Nhap mat khau hien tai: ";
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