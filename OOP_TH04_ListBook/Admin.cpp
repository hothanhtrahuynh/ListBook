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
	return 1;
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
		if (type == "User")
		{
			Account* ac = new User;
			ac->setPassAccount(pass);
			ac->setUsernameAccount(username);
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
		f << dstk[i]->nameclass() << "\t" << dstk[i]->getUsernameAccount() << "\t" << dstk[i]->getPassAccount() << "\n";
	}
	f.close();
}

int Admin::printMenu()
{
	int lenh;
	cout << "1. Them tai khoan." << endl;
	cout << "2. Them sach." << endl;
	cout << "3. Khoa quyen tac gia." << endl;
	cout << "4. Khoa quyen nha xuat ban." << endl;
	cout << "5. Xem danh sach tai khoan." << endl;
	cout << "6. Xem danh sach sach." << endl;
	cout << "7. Xoa tai khoan." << endl;
	cout << "8. Xoa sach." << endl;
	cout << "0. Dang xuat (Thoat)" << endl;
	cout << "Ban chon lenh nao: ";
	cin >> lenh;
	return lenh;
}

void Admin::funRunMenu(ListBook& lb)
{
	//lb.loadfromFile();
	getData();
	int lenh;
	do
	{
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
		default:
			lenh = 0;
			break;
		}
	} while (lenh!=0);

	writeDownAccountToFile();

}

string Admin::nameclass()
{
	return "Admin";
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
	vector<Account*>::iterator it;
	for (it = dstk.begin(); it != dstk.end(); ++it)
	{
		(*it)->print();
		cout << endl;
	}
	cout << endl;
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
