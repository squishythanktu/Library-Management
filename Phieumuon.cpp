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
// bool isNumber(const string& str) //hàm check một chuỗi có phải số không
// {
//     int i=0;
//     for (char c=str[0]; c!='\0'; c=str[++i]) {
//         if (isdigit(c) == 0) return false;
//     }
//     return true;
// }
istream& operator >>(istream &in,Phieumuon &pm)
{
    Book *book = new Book[100];
    int n = book->getInfo(book);
    bool found = false;
    ifstream file("D:/Workspace/PBL2/Book/Booklist.txt");
    if(!file){
        cout << "Khong mo duoc file" << endl;
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
                //tìm đc sách -> kiểm tra số lượng sách
                if(book[i].getSoluong() >= pm.Sosach[tongsach] && pm.Sosach[tongsach] > 0)
                {
                    found = true;
                    break;
                }
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
                book[i].setSoluong(book[i].getSoluong() - pm.Sosach[tongsach]); //cập nhật số lượng sách trong thư viện
                break;
            }
    }
    //cập nhật lại file
    ofstream temp("D:/Workspace/PBL2/Book/Booklist_temp.txt");
    if(!temp){
        cout << "Khong mo duoc file" << endl;
        return in;
    }
    for(int i = 0; i < n-1; i++)
    {
        temp << book[i];
    }
    temp.close();
    file.close();
    delete [] book;
    remove("D:/Workspace/PBL2/Book/Booklist.txt");
    rename("D:/Workspace/PBL2/Book/Booklist_temp.txt", "D:/Workspace/PBL2/Book/Booklist.txt");
    tongsach++;
    return in;
}
ostream& operator <<(ostream &out,const Phieumuon &pm){
    out << "Ma muon: " << pm.Mamuon << endl;
    out << "Ma sinh vien: " << pm.Masv << endl;
    out << "Ngay muon sach: " << pm.Ngaymuon << endl;
    out << setw(30) << left << "Ten sach" << setw(30) << left << "So luong" << endl;
    for(int i=0;i<tongsach;i++){
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
        return false;
        fileout.close();
    }
    else
    {
        return true;
        fileout.close();
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
