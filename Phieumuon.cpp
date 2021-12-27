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
    Tensach = new string[1000];
    Tentacgia = new string[1000];
    Sosach = new int[1000];
}
Phieumuon::~Phieumuon()
{
    delete [] Tensach;
    delete [] Tentacgia;
    delete [] Sosach;
}
istream& operator >>(istream &in,Phieumuon &pm)
{
    Book *book = new Book[1000];
    int n = book->getInfo(book);
    bool found = false;
    ifstream file("D:/Workspace/PBL2/Book/Booklist.txt");
    if(!file){
        cout << "Khong mo duoc file!" << endl;
        return in;
    }
    Input: 
    {
        cout << "                                         Nhap ten sach: ";
        fflush(stdin);
        getline(in,pm.Tensach[tongsach]);
        cout << "                                         Nhap ten tac gia: ";
        fflush(stdin);
        getline(in,pm.Tentacgia[tongsach]);
        cout << "                                         Nhap so luong sach muon: ";
        char sl_temp[100];
        //đếm số trong sl_temp
        SO:
        {
            in.getline(sl_temp,100);
            int so=0;
            for(int i=0; i < strlen(sl_temp); i++)
            {
                if(isdigit(sl_temp[i]))
                    so++;
            }
            while(so != strlen(sl_temp) || atoi(sl_temp) <= 0)
            {
                textcolor(12); cout << "                                         So luong sach khong hop le! Nhap lai: "; textcolor(7);
                goto SO;
            }
        }
        pm.Sosach[tongsach] = atoi(sl_temp); //gán khi chuỗi chỉ toàn số hợp lệ
        //CHECK
        for(int i=0; i<n; i++)
        {
            if(book[i].getTensach() == pm.Tensach[tongsach] && book[i].getTentacgia() == pm.Tentacgia[tongsach])
            {
                    found = true;
                    break;
            }
        }
        if(!found)
        {
            textcolor(12); cout << "                                         Thong tin khong hop le! Hay nhap lai... " << endl; textcolor(7);
            goto Input;
        }
    }
    for(int i = 0; i < n; i++)
    {
        if(book[i].getTensach() == pm.Tensach[tongsach] && book[i].getTentacgia() == pm.Tentacgia[tongsach])
        {
            //thông tin hợp lệ
            textcolor(10); cout << "                                         Muon sach thanh cong!" << endl; textcolor(7);
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
    out << setw(30) << left << "Ten sach" << setw(30) << left << "Ten tac gia" << setw(30) << left << "So luong" << endl;
    for(int i = 0; i < tongsach; i++){
        out << setw(30) << left << pm.Tensach[i] << setw(30) << left << pm.Tentacgia[i] << setw(30) << left << pm.Sosach[i] << endl;
    }
    return out;
}

bool Phieumuon::checkMamuon(string &mamuon)
{
    string temp="D:/Workspace/PBL2/Phieumuon/"+mamuon+".txt";
    ifstream fileout(temp.c_str());
    if(fileout) //đã tồn tại
    {
        fileout.close();
        return true;
    }
    else
    {
        fileout.close();
        return false;
    }
}
void Phieumuon::Muonsach(Phieumuon &pm)
{
    int i=3; string temp;
    textcolor(6); Goto(41,i); cout << "************ MUON SACH ************" << endl; textcolor(7);i++;
    Goto(41,++i); cout<<"Nhap ma phieu muon: ";
    fflush(stdin);
    getline(cin,temp);
    //check mã phiếu mượn
    while(checkMamuon(temp)) //đã tồn tại
    {
        textcolor(12); Goto(41,++i); cout << "Ma phieu muon da ton tai! Hay nhap lai: "; textcolor(7);
        fflush(stdin);
        getline(cin,temp);
    }
    pm.Mamuon = temp;
    //mã sv và thời gian được nhập tự động
    cin >> pm; //nhập thông tin sách
    //mượn thêm sách khác
    Muonthem:
    {
        cout << "                                         Muon them sach khac? (Y/N): ";
        string c;
        fflush(stdin);
        getline(cin,c);
        if(strcmp(c.c_str(),"Y")==0 || strcmp(c.c_str(),"y")==0)
        {
            cin >> pm;
            goto Muonthem;
        }
        else if(strcmp(c.c_str(),"N")==0 || strcmp(c.c_str(),"n")==0)
        {
            textcolor(10);cout << "                                         Ket thuc muon sach!" << endl;textcolor(7);
        }
        else
        {
            textcolor(12);cout << "                                         Lua chon khong hop le! Hay nhap lai..." << endl; textcolor(7);
            goto Muonthem;
        }
    }
    // in phiếu mượn 
    temp="D:/Workspace/PBL2/Phieumuon/"+pm.Mamuon+".txt";
    ofstream fileout(temp.c_str(),ios::app);
    fileout << pm;
    fileout.close();
    //xóa lỗi trong phiếu mươn
    ifstream pm_cu(temp.c_str(),ios::app);
    ofstream pm_moi("D:/Workspace/PBL2/Phieumuon/temp.txt",ios::trunc);
    string tam;
    while(getline(pm_cu,tam))
    {
        if (tam.find("-1163005939") != std::string::npos)
        {
            continue;
        }
        else{
            pm_moi << tam << endl;
        }
    }
    pm_moi.close();
    pm_cu.close();
    remove(temp.c_str());
    rename("D:/Workspace/PBL2/Phieumuon/temp.txt",temp.c_str());
    // in mã phiếu mượn vào ds phiếu
    ofstream List("D:/Workspace/PBL2/Phieumuon/Phieumuon_list.txt",ios::app);
    List << pm.Mamuon << endl;
    List.close();
    //in mã sinh viên vào msv_list
    ofstream msv_list("D:/Workspace/PBL2/Phieumuon/msv_list.txt",ios::app);
    msv_list << pm.Masv << endl;
    msv_list.close();
}

bool Phieumuon::check_msv(string &msv)
{
    ifstream filein("D:/Workspace/PBL2/Phieumuon/msv_list.txt");
    string line;
    while(getline(filein,line))
    {
        if(line == msv)
        {
            filein.close();
            return true;
        }
    }
    filein.close();
    return false;
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
    int i=3;
    textcolor(6);Goto(40,i);
    cout << "************ TRA SACH ************" << endl;textcolor(7);i++;
    if(!check_msv(pm.Masv)) //sv hiện tại k có phiếu mượn 
    {
        textcolor(12);Goto(40,++i);cout << "Ban khong co phieu muon!" << endl;textcolor(7);
        return;
    }
    else // sv hiện tại có phiếu mượn 
    {
        Goto(40,++i);cout << "Nhap ma phieu muon: ";
        string mapm;
        fflush(stdin);
        getline(cin,mapm);
        string temp="D:/Workspace/PBL2/Phieumuon/"+mapm+".txt";
        ifstream filein(temp.c_str());
        if(!filein)
        {
            textcolor(12);cout << "                                        Phieu muon khong ton tai!" << endl;textcolor(7);
            filein.close();
            return;
        }
        char mamuon_temp[100], masinhvien_temp[100];
        filein.getline(mamuon_temp,100);
        filein.getline(masinhvien_temp,100);
        if(masinhvien_temp != "Ma sinh vien: " + pm.Masv) //không phải phiếu mượn của sinh viên 
        {
            textcolor(12); cout<<"                                        Ma muon nay khong phai cua ban! Hay nhap lai...";textcolor(7);
            filein.close();
            getch();
            system("cls");
            Trasach(pm);
        }
        else //đúng phiếu mượn
        {
            string line;
            while (getline(filein,line))
            {
                Goto(40,++i); cout << line << endl;
            }
            filein.close();
            Ask:
            {
                cout << "\n                                         Ban co chac chan muon tra sach?" << endl;
                cout << "                                         1.Co" << endl;
                cout << "                                         2.Khong" << endl;
                cout << "                                         Nhap lua chon cua ban: ";
                string choice;
                fflush(stdin);
                getline(cin,choice);
                if(choice.length() == 1)
                {
                    cout << endl;
                    char c = choice[0];
                    switch (c)
                    {
                        case '1':
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
                            textcolor(10);cout << "                                      Tra sach thanh cong!" << endl; textcolor(7);
                            //xóa 1 msv trùng khớp trong msv_list (không phải toàn bộ)
                            ifstream msv_list("D:/Workspace/PBL2/Phieumuon/msv_list.txt");
                            ofstream msv_list_temp("D:/Workspace/PBL2/Phieumuon/msv_list_temp.txt",ios::app);
                            string line_msv, newlist[10000];
                            int i = 0, x;
                            bool found = false;
                            while(getline(msv_list,line))
                            {
                                if(line ==pm.Masv && found == false)
                                {
                                    found = true;
                                    x = i;
                                }
                                newlist[i] = line;
                                i++;
                            }
                            for(int j = 0; j < i; j++)
                            {
                                if(j != x)
                                {
                                    msv_list_temp << newlist[j] << endl;
                                }
                            }
                            msv_list_temp.close();
                            msv_list.close();
                            remove("D:/Workspace/PBL2/Phieumuon/msv_list.txt");
                            rename("D:/Workspace/PBL2/Phieumuon/msv_list_temp.txt","D:/Workspace/PBL2/Phieumuon/msv_list.txt");
                            break;
                        }
                        case '2':
                        {
                            textcolor(10);cout << "                                        Ket thuc tra sach!" << endl;textcolor(7);
                            filein.close();
                            break;
                        }
                        default:
                        {
                            textcolor(12);cout << "                                      Lua chon khong hop le! Hay nhap lai..." << endl;textcolor(7);
                            goto Ask;
                            break;
                        }
                    }
                }
                else
                {
                    textcolor(12);cout << "                                      Lua chon khong hop le! Hay nhap lai..." << endl;textcolor(7);
                    goto Ask;
                }
            }
        }
        }
}
void Phieumuon::xem_phieumuon()
{
    textcolor(6); Goto(34,4); cout << "************* XEM PHIEU MUON *************" << endl;textcolor(7);
    ifstream in("D:/Workspace/PBL2/Phieumuon/Phieumuon_list.txt");
    if(in.peek() == std::ifstream::traits_type::eof()) //nếu list rỗng
    {
        Goto(40,5); textcolor(12); cout << "Khong co phieu muon nao!" << endl; textcolor(7);
        in.close();
    }
    else //list có phiếu mượn
    {
        Goto(40,5); cout << "-DANH SACH PHIEU MUON-";
        string line;
        int i=6;
        while (getline(in,line))
        {
            Goto(40,i);
            cout << line << endl;
            i++;
        }
        in.close();
        i=i++;
        Goto(40,++i);cout << "Nhap ma phieu muon: ";
        string mapm;
        fflush(stdin);
        getline(cin,mapm);
        string temp="D:/Workspace/PBL2/Phieumuon/"+mapm+".txt";
        ifstream filein(temp.c_str());
        if(!filein)
        {
            textcolor(12);Goto(40,++i);cout << "Phieu muon khong ton tai! Hay nhap lai..." << endl;textcolor(7);
            filein.close();
            getch();
            system("cls");
            xem_phieumuon();
        }
        else{
            cout << endl;
            string line;
            while (getline(filein,line))
            {
                Goto(35,++i); cout << line << endl;
            }
            filein.close();
        }
    }
}