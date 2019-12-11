#include "User.h"



User::User()
{

}


DS_HoaDon User::muaSach(ListBook& l)
{
	do
	{
			int lenh;
			//gọi hàm thêm hóa đơn vào danh sách háo đơn
			hd_user.themHoaDon(l);
			cout << "Tiep tuc them hoa don: Tiep tuc(1) - Ngung nhap(0) "; cin >> lenh;
			//nếu người dùng không mua nữa = ngừng thêm sách vào hóa đơn--> thoát khỏi vòng lập
			if (lenh == 0) break;
	} while (true);
	//trả về danh sách hóa đơn mà người dùng đã chọn mua (gồm các hóa đơn đã thêm vào)
	return hd_user;
}

void User::upDateHoaDon(ListBook& lb)
{
	hd_user.xuatDSHoaDon();
	int stt, nSl;
	cout << "Nhap vao so thu tu hoa don can cap nhat: "; cin >>stt;
	cout << "Nhap vao so luong sach can cap nhat cho hoa don do: "; cin >> nSl;
	hd_user.upDateHoaDonThu(stt, nSl,lb);
}

void User::xoaHoaDon_DSHD()
{
	this->hd_user.xoaHoaDon();
}

DS_HoaDon User::getDanhSachHoaDon()
{
	return DS_HoaDon(hd_user);
}



int User::printMenu()
{
	int lenh;
	cout << "==============" << endl;
	cout << "||   USER   ||" << endl;
	cout << "==============" << endl;
	cout << "1. Xem danh sach sach." << endl;
	cout << "2. Tim sach." << endl;
	cout << "3. Mua sach." << endl;
	cout << "4. Xem Danh sach hoa don." << endl;
	cout << "5. Chinh sua hoa don." << endl;
	cout << "6. Xoa bot hoa don." << endl;
	cout << "7. Tong tien ban da mua." << endl;
	cout << "8. Gui tin nhan." << endl;
	cout << "9. Doc tin nhan." << endl;
	cout << "10. Xem danh sach uu (cua rieng minh)." << endl;
	cout << "0. Dang xuat." << endl;
	cout << "Ban chon lenh nao: ";
	cin >> lenh;
	return lenh;
}

void User::funRunMenu(ListBook& lb, DS_UuDai& dsud)
{
	freadFromFile();
	loadfromTotalUuDai(dsud);
	ds_tn.freadMessageFromFile(mTen + "_Message.txt");
	int lenh;
	do
	{
		system("cls");
		lenh = printMenu();
		switch (lenh)
		{
		case 1:
		{
			lb.xuatdanhsach_KhongAn();
		}break;
		case 2:
		{
			/*string name;
			cin.ignore();
			cout << "Nhap vao ten sach can tim: ";
			getline(cin, name);
			Sach* a = lb.timSach_Ten(name);
			if (a == NULL) cout << "Khong co sach can tim." << endl;
			else if (a->getAnSachTacGia() || a->getAnSachNXB())
			{
				cout << "Sach ban vua tim da duoc vi mot ly do nao do da bi Tac gia hoac Nha Xuat Ban an di." << endl;
				cout << "Ban vui long tim sach khac." << endl;
				break;
			}
			else
			{
				cout << "Sach can tim la: " << endl;
				cout << (*a) << endl;
			}*/
			timSach(lb);
			
		}break;
		case 3:
		{
			DS_HoaDon User_DSHD = muaSach(lb);
			cout << endl;
		}break;
		case 4:
		{
			cout << endl << "DANH SACH HOA DON " << endl;
			DS_HoaDon  User_DSHD = getDanhSachHoaDon();
			User_DSHD.xuatDSHoaDon();
			cout << endl;
		}break;
		case 5:
		{
			upDateHoaDon(lb);
			cout << endl;
		}break;
		case 6:
		{
			xoaHoaDon_DSHD();
			cout << endl;
		}break;
		case 7:
		{
			DS_HoaDon  User_DSHD = getDanhSachHoaDon();
			cout << "Tong tien ma ban da mua la: " << User_DSHD.tongTienHoaDon() << endl;
			cout << endl;
		}break;
		case 8:
		{
			sendMessage();
		}break;
		case 9:
		{
			
			
			ds_tn.xuatDsTinNhan();
		}break;
		case 10:
		{
			ud_user.xemDanhSachUudai();

		}break;
		default:
			lenh = 0;
			break;
		}
		system("pause>nul");
	} while (lenh!=0);

	fwriteToFile();
}

string User::nameclass()
{
	return "User";
}

void User::sendMessage()
{
	string name_user, text;
	getInfor_Message(name_user, text);
	
	if (checkExistAccount(name_user) == 0)
	{
		cout << "Khong tim thay tai khoan nao voi ten vua nhap. Hoac tai khoan khong nam trong pham vi cho phep gui tin nhan"<<endl;
		cout << "Vui long thu lai." << endl;
		return;
	}

	fwriteMessage(name_user, text);

}

int User::checkExistAccount(string name_account)
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
			if (username == name_account) return 1;
		}
	}
	f.close();
	return 0;
}

void User::fwriteToFile()
{
	string tenfile = mTen + ".txt";
	fstream f(tenfile, ios::out);
	if (f.fail())
	{
		cout << "Khong mo duoc file" << endl;
		return;
	}
	
	this->hd_user.fwriteToFile(f);
	f.close();
}

void User::freadFromFile()
{
	string tenfile = mTen + ".txt";
	fstream f(tenfile);
	if (f.fail())
	{
		cout << "Khong mo duoc file" << endl;
		return;
	}
	hd_user.freadFromFile(f);
	f.close();
}

void User::loadfromTotalUuDai(DS_UuDai& dsuudai)
{
	vector<HoaDon> dshd;
	dshd = hd_user.getDSHoaDon();
	for (int i = 0; i < dshd.size(); i++)
	{
		string name=dshd[i].getSachTrongHoaDon().getTenSach();
		UuDai* temp = dsuudai.timUUDaiTheoSach(name);
		
		if (temp != NULL)
			ud_user.push_UuDai(temp);
	}
	
}
