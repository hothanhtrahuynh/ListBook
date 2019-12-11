#define _CRT_SECURE_NO_WARNINGS
#define _CRT_SECURE_NO_WARNINGS
#include<conio.h>
#include"Admin.h"



Admin::Admin()
{

}


Admin::~Admin()
{
}

int Admin::addAccount()
{
	string type;
	cin.ignore();
	cout << "Nhap vao loai tai khoan muon tao: ";
	getline(cin, type);
	if (type == "User")
	{
		Account* ac = new User;
		ac->getAccount();
		int tuoi;
		cout << "Nhap vao so tuoi: "; cin >> tuoi;
		ac->setTuoi(tuoi);
		dstk.push_back(ac);
	}
	else if (type == "Tac Gia")
	{
		Account* ac = new TacGia;
		ac->getAccount();
		dstk.push_back(ac);
	}
	else if (type == "NXB")
	{
		Account* ac = new NXB;
		ac->getAccount();
		dstk.push_back(ac);
	}
	else
	{
		Account* ac = new Admin;
		ac->getAccount();
		dstk.push_back(ac);
	}
	
	cout << endl << "|Tao tai khoan thanh cong.|" << endl;
	return 1;
}

void Admin::addUuDai(ListBook& lb, vector<UuDai*>& dsuudai, DS_UuDai& dsud)
{
	string type;
	int uudai;
	cout << "Nhap vao loai uu dai muon khoi tao: ";
	cin >> type;
	if (type=="UuDai_Sach"||type=="Sach")
	{
		string tensach;
		cin.ignore();
		cout << "Nhap vao ten sach can them vao muc uu dai: ";
		getline(cin, tensach);
		Sach* a = lb.timSach_Ten(tensach);
		if (a == NULL)
		{
			cout << "Sach can them khong co trong thu vien sach." << endl;
			return;
		}
		cout << "Muc uu dai la: "; cin >> uudai;
		UuDai* ud = new UuDai_Sach(a,uudai);
		dsud.push_UuDai(ud);
	}
	if (type == "UuDai_Tuoi"||type=="Tuoi")
	{
		int tuoi;
		cout << "Tuoi duoc nhan uu dai la: ";
		cin >> tuoi;
		cout << "Muc uu dai: ";
		cin >> uudai;
		UuDai* ud = new UuDai_Tuoi(tuoi, uudai);
		dsud.push_UuDai(ud);
	}
	cout << "Them uu dai thanh cong." << endl;
}

int Admin::getData()
{
	fstream f("Account.txt");
	if (f.fail())
	{
		cout << "Khong mo duoc file account." << endl;
		return -1;
	}
	char a[256];
	while (!f.eof())
	{
		
		f.getline(a, 255);
		char c[5] = "\t";
		char* p = NULL;
		p = strtok(a, c);
		if (p == NULL) continue;
		string type(p);
		string username, pass;
		int tuoi;
		for (int i = 0; i <= 2; i++)
		{

			p = strtok(NULL, c);
			if (p == NULL) continue;
			switch (i)
			{
			case 0:
			{
				string temp(p);
				username = temp;

			}break;
			case 1:
			{
				string temp(p);
				pass = temp;
			}break;
			case 2:
			{
				string temp(p);
				tuoi = stoi(temp);

			}break;
			}
		}
		if (type == "User")
		{
			Account* ac = new User;
			ac->setPassAccount(pass);
			ac->setUsernameAccount(username);
			ac->setTuoi(tuoi);
			dstk.push_back(ac);
		}
		else if (type == "Tac Gia")
		{
			Account* ac = new TacGia;
			ac->setPassAccount(pass);
			ac->setUsernameAccount(username);
			dstk.push_back(ac);
		}
		else if (type == "NXB")
		{
			Account* ac = new NXB;
			ac->setPassAccount(pass);
			ac->setUsernameAccount(username);
			dstk.push_back(ac);
		}
		else if(type=="Admin")
		{
			Account* ac = new Admin;
			ac->setPassAccount(pass);
			ac->setUsernameAccount(username);
			dstk.push_back(ac);
		}
	}
	f.close();
	return 1;
}

void Admin::loadDSHoaDon()
{
	for (int i = 0; i < dstk.size(); i++)
	{
		if (dstk[i]->nameclass() == "User")
		{
			User* user = new User(dstk[i]->getUsernameAccount(), dstk[i]->getPassAccount(), dstk[i]->getTuoi());
			user->freadFromFile();
			DS_HoaDon  User_DSHD = user->getDanhSachHoaDon();
			if (!User_DSHD.checkEmpty())
			{
				mang_DSHoaDon.push_back(User_DSHD);
			}
		}
	}
}


void Admin::writeDownAccountToFile()
{
	fstream f("Account.txt");
	if (f.fail())
	{
		cout << "Khong mo duoc file account." << endl;
		return;
	}
	for (int i = 0; i < dstk.size(); i++)
	{
		
		if (dstk[i]->nameclass() == "User")
		{
			f << dstk[i]->nameclass() << "\t" << dstk[i]->getUsernameAccount() << "\t" << dstk[i]->getPassAccount()<<"\t"<<dstk[i]->getTuoi() << "\n";
		}
		else
		{
			f << dstk[i]->nameclass() << "\t" << dstk[i]->getUsernameAccount() << "\t" << dstk[i]->getPassAccount() << "\n";
		}
	}
	f.close();
}



int Admin::printMenu()
{
	int lenh;
	cout << "=================" << endl;
	cout << "||   ADMIN   ||" << endl;
	cout << "=================" << endl;
	cout << "1. Them tai khoan." << endl;
	cout << "2. Them sach." << endl;
	cout << "3. Khoa quyen tac gia." << endl;
	cout << "4. Khoa quyen nha xuat ban." << endl;
	cout << "5. Xem danh sach tai khoan." << endl;
	cout << "6. Xem danh sach sach." << endl;
	cout << "7. Xoa tai khoan." << endl;
	cout << "8. Xoa sach." << endl;
	cout << "9. Gui tin nhan." << endl;
	cout << "10. Doc tin nhan." << endl;
	cout << "11. Uu Dai." << endl;
	cout << "12. Thong ke." << endl;
	cout << "13. Xem danh sach hoa don trong he thong." << endl;
	cout << "0. Dang xuat (Thoat)" << endl;
	cout << "Ban chon lenh nao: ";
	cin >> lenh;
	return lenh;
}

int Admin::printMenu_Message()
{
	int lenh;
	cout << "=====================" << endl;
	cout << "||   GUI TIN NHAN   ||" << endl;
	cout << "=====================" << endl;
	cout << "1. Gui dong loat cho USER." << endl;
	cout << "2. Gui dong loat cho Tac Gia." << endl;
	cout << "3. Gui dong loat cho NXB." << endl;
	cout << "4. Gui dong loat cho tat ca tai khoan." << endl;
	cout << "5. Gui cho mot tai khoan cu the: " << endl;
	cout << "0. Thoat." << endl;
	cout << "Ban chon lenh: ";
	cin >> lenh;
	return lenh;
}

int Admin::printMenu_Thongke()
{
	int lenh;
	cout << "=================" << endl;
	cout << "||   THONG KE   ||" << endl;
	cout << "=================" << endl;
	cout << "1. So sach da ban." << endl;
	cout << "2. Sach ban chay nhat." << endl;
	cout << "3. Hoa don co tong tien thanh toan dac nhat." << endl;
	cout << "0. Thoat" << endl;
	cout << "Ban chon lenh: ";
	cin >> lenh;
	return lenh;
}

int Admin::printMenu_UuDai()
{
	int lenh;
	cout << "================" << endl;
	cout << "||   UU DAI   ||" << endl;
	cout << "================" << endl;
	cout << "1. Xem nhung uu dai hien co." << endl;
	cout << "2. Them uu dai." << endl;
	cout << "3. Xoa uu dai." << endl;
	cout << "0. Thoat." << endl;
	cout << "Ban chon lenh: ";
	cin >> lenh;
	return lenh;
}

void Admin::sendPublicMessage(string type_Account)
{
	string text;
	cin.ignore();
	cout << "Noi dung tin nhan ban muon gui: ";
	getline(cin, text);
	text = "Admin: " + text;
	fstream f("Account.txt");
	if (f.fail())
	{
		cout << "Khong mo duoc file account." << endl;
		return ;
	}
	char a[256];
	while (!f.eof())
	{

		f.getline(a, 255);
		char c[5] = "\t";
		char* p = NULL;
		p = strtok(a, c);
		if (p == NULL) continue;
		string type(p);
		string username, pass;
		for (int i = 0; i <= 1; i++)
		{

			p = strtok(NULL, c);
			switch (i)
			{
			case 0:
			{
				string temp(p);
				username = temp;

			}break;
			case 1:
			{
				string temp(p);
				pass = temp;
			}break;
			}
		}
		if (type_Account == type)
		{
			fwriteMessage(username, text);
		}
	}
	f.close();
}

void Admin::runThonngKefunction(ListBook& lb, DS_UuDai& dsud)
{
	int lenh10;
	do
	{
		system("cls");
		lenh10 = printMenu_Thongke();
		switch (lenh10)
		{
		case 1:
		{
			cout << "====================================" << endl;
			cout << "So sach ban duoc: " << lb.soSachDaban() << endl;
			cout << "====================================" << endl;
		}break;
		case 2://sách bán chạy nhất.
		{
			vector<Sach> ds;
			lb.bestSellerBook(ds);
			cout << "=========================" << endl;
			cout << "| SACH BAN CHAY NHAT LA |" << endl;
			cout << "=========================" << endl;
			for (int i = 0; i < ds.size(); i++)
			{
				cout << ds[i] << endl;
			}
			cout << endl;
		}break;
		case 3:
		{
			cout << "=======================================================" << endl;
			cout << "|       HOA DON CO TONG TIEN THANH TOAN LON NHAT      |" << endl;
			cout << "=======================================================" << endl;
			timHaoDonDacNhat();
		}break;
		case 4:
		{

		}break;
		case 5:
		{

		}break;
		default:
			lenh10 = 0;
			break;
		}
		system("pause>nul");
	} while (lenh10 != 0);
}

void Admin::runUuDaiFunction(ListBook& lb, DS_UuDai& dsud)
{
	int lenh;
	do
	{
		lenh = printMenu_UuDai();
		switch (lenh)
		{
		case 1:
		{
			//Xem nhung uu dai hien co
			dsud.xemDanhSachUudai();
		}break;
		case 2:
		{
			//Them uu dai moi
			dsud.addUuDai(lb);
		}break;
		case 3:
		{
			//Xoa uu dai
			dsud.xoaUuDai();
		}break;
		default:
			lenh = 0;
			break;
		}
		cout << endl;
	} while (lenh!=0);
}

void Admin::funRunMenu(ListBook& lb, DS_UuDai& dsud)
{
	
	getData();
	loadDSHoaDon();
	ds_tn.freadMessageFromFile(mTen + "_Message.txt");
	int lenh;
	do
	{
		system("cls");
		lenh = printMenu();
		switch (lenh)
		{
			//thêm tài khoản (user, tác giả, nhà xuất bản, admin)
			case 1:
			{
				addAccount();
				cout << endl;
			}break;
			//thêm sách vào trong danh sách sách.
			case 2:
			{
				lb.themSach();
				cout << endl;
			}break;
			//khóa quyền chỉnh sửa của tác giả
			case 3:
			{
				khoaTacGia(lb);
				cout << endl;
			}break;
			//khóa quyền chỉnh sửa của nhà xuất bản
			case 4:
			{
				khoaNXB(lb);
				cout << endl;
			}break;
			case 5:
			{
				cout << "Username\tPass" << endl;
				xemDanhSachTaiKhoan();
				cout << endl;
			}break;
			case 6:
			{
				lb.xuatDanhSachSach();
				cout << endl;
			}break;
			case 7:
			{
				if (xoaTaiKhoan() == 0)
				{
					cout << "Tai khoan ban vua nhap chua chinh xac." << endl;
				}
				else cout << "Xoa thanh cong." << endl;
				cout << endl;
			}break;
			case 8:
			{
				lb.xoaSach();
				cout << endl;
			}break;
			case 9:
			{
				sendMessage();
			}break;
			case 10:
			{
				//funReadMessage();
				ds_tn.xuatDsTinNhan();
			}break;
			case 11:
			{
				runUuDaiFunction(lb,dsud);
			}break;		
			case 12 :
			{
				runThonngKefunction(lb,dsud);
			}break;
			case 13:
			{
				cout << "===============================================" << endl;
				cout << "|       DANH SACH HOA DON TRONG HE THONG      |" << endl;
				cout << "===============================================" << endl;
				xemDanhSachHoaDon();
			}break;
		default:
			lenh = 0;
			break;
		}
		_getch();
	} while (lenh!=0);
	//lưu danh sách tài khoản trở lại file.
	writeDownAccountToFile();
}

string Admin::nameclass()
{
	return "Admin";
}

void Admin::sendMessage()
{
	int lenh;
	do
	{
		lenh = printMenu_Message();
		switch (lenh)
		{
		case 1:
		{
			sendPublicMessage("User");
		}break;
		case 2:
		{
			sendPublicMessage("Tac Gia");
		}break;
		case 3:
		{
			sendPublicMessage("NXB");
		}break;
		case 4:
		{
			sendPublicMessage("User");
			sendPublicMessage("Tac Gia");
			sendPublicMessage("NXB");
		}break;
		case 5:
		{
			string name_user, text;
			getInfor_Message(name_user, text);
			if (checkExistAccount(name_user) == 0)
			{
				cout << "Khong tim thay tai khoan nao voi ten vua nhap." << endl;
				cout << "Vui long thu lai." << endl;
				return;
			}
			fwriteMessage(name_user, text);
		}break;
		default:
		{
			lenh = 0;
		}break;
		}
		
	} while (lenh!=0);

}



void Admin::khoaTacGia(ListBook& lb)
{
	string tensach;
	cin.ignore();
	cout << "Nhap vao ten sach can khoa tac gia: ";
	getline(cin, tensach);
	Sach *temp=lb.timSach_Ten(tensach);
	if (temp == NULL)
	{
		cout << "Khong co sach voi ten vua nhap trong danh sach." << endl;
		return;
	}
	temp->setAnTacGia(true);
	cout << "Khoa thanh cong" << endl;
}

void Admin::khoaNXB(ListBook& lb)
{
	string tensach;
	cin.ignore();
	cout << "Nhap vao ten sach can KHOA NHA XUAT BAN: ";
	getline(cin, tensach);
	Sach* temp = lb.timSach_Ten(tensach);
	if (temp == NULL)
	{
		cout << "Khong co sach voi ten vua nhap trong danh sach." << endl;
		return;
	}
	temp->setAnNXB(true);
	cout << "Khoa thanh cong" << endl;
}


void Admin::xemDanhSachTaiKhoan()
{
	cout << "DANH SACH TAI KHOAN" << endl;
	cout << "Ten tai khoan" << setw(30) << "Mat khau" << endl;
	vector<Account*>::iterator it;
	for (it = dstk.begin(); it != dstk.end(); ++it)
	{
		(*it)->print();
		cout << endl;
	}
	cout << endl;
}

void Admin::xemDanhSachHoaDon()
{
	for (int i = 0; i < mang_DSHoaDon.size(); i++)
	{
		mang_DSHoaDon[i].xuatDSHoaDon();
	}
}

void Admin::timHaoDonDacNhat()
{
	if (mang_DSHoaDon.size() == 0) return;
	int max = mang_DSHoaDon[0].tongTienHoaDon();
	for (int i = 1; i < mang_DSHoaDon.size(); i++)
	{
		if (max < mang_DSHoaDon[i].tongTienHoaDon())
		{
			max = mang_DSHoaDon[i].tongTienHoaDon();
		}
	}
	for (int i = 0; i < mang_DSHoaDon.size(); i++)
	{
		if (max == mang_DSHoaDon[i].tongTienHoaDon())
		{
			mang_DSHoaDon[i].xuatDSHoaDon();
		}
	}
	cout << "======================================" << endl;
	cout << "| Tong tien hoa don la: " << max << "          |"<<endl;
	cout << "======================================" << endl;
}

int Admin::xoaTaiKhoan()
{
	string username, pass;
	cin.ignore();
	cout << "Nhap vao ten tai khoan muon xoa: " ;
	getline(cin, username);
	cout << "Nhap vao mat khau tai khoan muon xoa: ";
	getline(cin, pass);

	vector<Account*>::iterator it;
	for (it=dstk.begin();it!=dstk.end();++it)
	{
		if ((*it)->getPassAccount() == pass && (*it)->getUsernameAccount() == username)
		{
			dstk.erase(it); 
			cout << "Xoa tai khoan " << username << " thanh cong." << endl;
			return 1;
		}
	}
	return 0;
}

int Admin::xoaUuDai(vector<UuDai*>& dsuudai)
{

	int stt;
	cout << "Nhap vao thu tu uu dai muon xoa trong danh sach tren: ";
	cin >> stt;
	for (int i = 0; i < dsuudai.size(); i++)
	{
		if (stt == i + 1)
		{
			dsuudai.erase(dsuudai.begin() + i);
			cout << "Xoa thanh cong." << endl;
			return 1;
		}
	}
	cout << "Xoa that bai." << endl;
	return 0;
}

int Admin::checkExistAccount(string name_account)
{
	fstream f("Account.txt");
	if (f.fail())
	{
		cout << "Khong mo duoc file account." << endl;
		return -1;
	}
	char a[256];

	while (!f.eof())
	{

		f.getline(a, 255);
		char c[5] = "\t";
		char* p = NULL;
		p = strtok(a, c);
		if (p == NULL) continue;
		string type(p);
		string username, pass;
		for (int i = 0; i <= 1; i++)
		{

			p = strtok(NULL, c);
			switch (i)
			{
			case 0:
			{
				string temp(p);
				username = temp;

			}break;
			case 1:
			{
				string temp(p);
				pass = temp;
			}break;
			}
		}
		if (type == "Admin")
		{
			if (username == name_account) return 1;
		}
	}
	f.close();
	return 0;
}
