#include "Phieumuon.h"
#include <time.h>
static int tongsach = 0;
Phieumuon::Phieumuon(string msv)
{
    Mamuon = "";
    Masv = msv;
    //tự động gán ngày mượn
    time_t now;
    time(&now);
    this->Ngaymuon=ctime(&now);  
    Tensach = new string[100];
    Sosach = new int[100];
}
Phieumuon::~Phieumuon()
{
    delete [] Tensach;
    delete [] Sosach;
}
istream& operator >>(istream &in,Phieumuon &pm)
{
    Book *book = new Book[100];
    int n = book->getInfo(book);
    bool found = false;
    ifstream file("D:/Workspace/PBL2/Book/Booklist.txt");
    if(!file){
        cout << "Khong mo duoc file!" << endl;
        return in;
    }
    Input: 
    {
        cout << "Nhap ten sach: ";
        fflush(stdin);
        getline(in,pm.Tensach[tongsach]);
        cout << "Nhap so luong sach muon: ";
        cin >> pm.Sosach[tongsach];
        //CHECK
        for(int i=0; i<n; i++)
        {
            if(book[i].getTensach() == pm.Tensach[tongsach])
            {
                    found = true;
                    break;
            }
        }
        if(!found)
        {
            cout << "Thong tin khong hop le! Hay nhap lai... " << endl;
            goto Input;
        }
    }
    for(int i = 0; i < n; i++)
    {
            if(book[i].getTensach() == pm.Tensach[tongsach])
            {
                //thông tin hợp lệ
                cout << "Muon sach thanh cong!" << endl;
                break;
            }
    }
    file.close();
    delete [] book;
    tongsach++;
    return in;
}
ostream& operator <<(ostream &out,const Phieumuon &pm){
    out << "Ma muon: " << pm.Mamuon << endl;
    out << "Ma sinh vien: " << pm.Masv << endl;
    out << "Ngay muon sach: " << pm.Ngaymuon << endl;
    out << setw(30) << left << "Ten sach" << setw(30) << left << "So luong" << endl;
    for(int i = 0; i < tongsach; i++){
        out << setw(30) << left << pm.Tensach[i] << setw(30) << left << pm.Sosach[i] << endl;
    }
    return out;
}

bool Phieumuon::checkMamuon()
{
    string temp="Phieumuon/"+this->Mamuon+".txt";
    ifstream fileout(temp.c_str());
    if(fileout) //đã rồn rại
    {
        fileout.close();
        return false;
    }
    else
    {
        fileout.close();
        return true;
    }
}
void Phieumuon::Muonsach(Phieumuon &pm)
{
    cout << "************ MUON SACH ************" << endl;
    cout<<"Nhap ma phieu muon: ";
    cin >> this->Mamuon;
    while(!checkMamuon())
    {
        cout<<"Ma phieu muon da ton tai, vui long nhap lai: ";
        cin >> this->Mamuon;
    }
    //mã sv và thời gian được nhập tự động
    cin >> pm; //nhập thông tin sách
    //mượn thêm sách khác
    Muonthem:
      {
            cout << "Muon them sach khac? (Y/N): ";
            char c;
            cin >> c;
            if(c == 'y' || c=='Y'){
                cin >> pm;
                goto Muonthem;
            }
            else if(c == 'n' || c=='N'){
                cout << "Ket thuc muon sach!" << endl;
            }
            else{
                cout << "Lua chon khong hop le! Hay nhap lai..." << endl;
                goto Muonthem;
            }
      }
    //in phiếu mượn và mã phiếu mượn vào ds phiếu
    string temp="D:/Workspace/PBL2/Phieumuon/"+pm.Mamuon+".txt";
    ofstream fileout(temp.c_str(),ios::app);
    fileout << pm;
    fileout.close();
    ofstream List("D:/Workspace/PBL2/Phieumuon/Phieumuon_list.txt",ios::app);
    List << pm.Mamuon << endl;
    List.close(); 
}
void Phieumuon::print(const string &path)
{
    ifstream in(path.c_str());
    string line;
    while (getline(in,line))
    {
        cout << line << endl;
    }
    in.close();
}
void Phieumuon::Trasach(Phieumuon &pm)
{
    cout << "************ TRA SACH ************" << endl;
    cout << "Nhap ma phieu muon: ";
    string mapm;
    fflush(stdin);
    getline(cin,mapm);
    string temp="D:/Workspace/PBL2/Phieumuon/"+mapm+".txt";
    ifstream filein(temp.c_str());
    if(!filein)
    {
        cout << "Phieu muon khong ton tai! Hay nhap lai..." << endl;
        filein.close();
        getch();
        system("cls");
        Trasach(pm);
    }
    char mamuon_temp[100], masinhvien_temp[100];
    filein.getline(mamuon_temp,100);
    filein.getline(masinhvien_temp,100);
    if(masinhvien_temp == "Ma sinh vien: " + pm.Masv) //đúng phiếu mượn của sinh viên 
    {
        filein.close();
        //in thông tin phiếu mượn
        print(temp);
        Ask:
        {
            cout << "\nBan co chac chan muon tra sach?" << endl;
            cout << "1.Co" << endl;
            cout << "2.Khong" << endl;
            cout << "Nhap lua chon cua ban: ";
            string choice;
            fflush(stdin);
            getline(cin,choice);
            if(choice == "1")
            {   //xóa phiếu mượn và mã phiếu mượn trong list
                remove(temp.c_str());
                ifstream List("D:/Workspace/PBL2/Phieumuon/Phieumuon_list.txt");
                ofstream Temp("D:/Workspace/PBL2/Phieumuon/Phieumuon_list_temp.txt",ios::app);
                string line;
                while(getline(List,line))
                {
                    if(line != mapm)
                    {
                        Temp << line << endl;
                    }
                }
                Temp.close();
                List.close();
                remove("D:/Workspace/PBL2/Phieumuon/Phieumuon_list.txt");
                rename("D:/Workspace/PBL2/Phieumuon/Phieumuon_list_temp.txt","D:/Workspace/PBL2/Phieumuon/Phieumuon_list.txt");
                cout << "Tra sach thanh cong!" << endl;
            }
            else if(choice == "2")
            {
                cout << "Ket thuc tra sach!" << endl;
                filein.close();
                return;
            }
            else
            {
                cout << "Lua chon khong hop le! Hay nhap lai..." << endl;
                goto Ask;
            }
        }
    }
    else
    {
        cout<<"Ma muon nay khong phai cua ban! Hay nhap lai...";
        filein.close();
        getch();
        system("cls");
        Trasach(pm);
    }
}
void Phieumuon::xem_phieumuon()
{
    cout << "************ XEM PHIEU MUON ************" << endl;
    cout << "DANH SACH PHIEU MUON" << endl;
    print("D:/Workspace/PBL2/Phieumuon/Phieumuon_list.txt");
    cout << "Nhap ma phieu muon: ";
    string mapm;
    fflush(stdin);
    getline(cin,mapm);
    string temp="D:/Workspace/PBL2/Phieumuon/"+mapm+".txt";
    ifstream filein(temp.c_str());
    if(!filein)
    {
        cout << "Phieu muon khong ton tai! Hay nhap lai..." << endl;
        filein.close();
        getch();
        system("cls");
        xem_phieumuon();
    }
    else{
        print(temp);
        filein.close();
    }
}