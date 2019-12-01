#define _CRT_SECURE_NO_WARNINGS
#define _CRT_SECURE_NO_WARNINGS
#include "User.h"



User::User()
{
}


void User::setTuoiUser(int t)
{
	mTuoi = t;
}

int User::getTuoiUser()
{
	return mTuoi;
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

void User::upDateHoaDon()
{
	hd_user.xuatDSHoaDon();
	int stt, nSl;
	cout << "Nhap vao so thu tu hoa don can cap nhat: "; cin >>stt;
	cout << "Nhap vao so luong sach can cap nhat cho hoa don do: "; cin >> nSl;
	hd_user.upDateHoaDonThu(stt, nSl);
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
	cout << "1. Mua sach." << endl;
	cout << "2.Xem Danh sach hoa don." << endl;
	cout << "3. Chinh sua hoa don." << endl;
	cout << "4. Xoa bot hoa don." << endl;
	cout << "5. Tong tien ban da mua." << endl;
	cout << "0. Dang xuat." << endl;
	cout << "Ban chon lenh nao: ";
	cin >> lenh;
	return lenh;
}

void User::funRunMenu(ListBook& lb)
{
	lb.xuatDanhSachSach();
	cout << endl;

	freadFromFile();
	int lenh;
	do
	{
		lenh = printMenu();
		switch (lenh)
		{
		case 1:
		{
			DS_HoaDon User_DSHD = muaSach(lb);
			cout << endl;
		}break;
		case 2:
		{
			DS_HoaDon  User_DSHD = getDanhSachHoaDon();
			User_DSHD.xuatDSHoaDon();
			cout << endl;
		}break;
		case 3:
		{
			upDateHoaDon();
			cout << endl;
		}break;
		case 4:
		{
			xoaHoaDon_DSHD();
			cout << endl;
		}break;
		case 5:
		{
			DS_HoaDon  User_DSHD = getDanhSachHoaDon();
			cout << "Tong tien ma ban da mua la: " << User_DSHD.tongTienHoaDon() << endl;
			cout << endl;
		}break;
		default:
			lenh = 0;
			break;
		}
	} while (lenh!=0);

	fwriteToFile();
}

string User::nameclass()
{
	return "User";
}

void User::fwriteToFile()
{
	string tenfile = mTen + ".dat";
	/*char* c = new char[tenfile.size()];
	copy(tenfile.begin(), tenfile.end(), c);
	c[tenfile.size()] = '\0';
	FILE* f = fopen(c, "ab");
	if (f==NULL) { cout << "Khong mo duoc file." << endl; return; }*/
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
	string tenfile = mTen + ".dat";
	/*char* c = new char[tenfile.size()];
	copy(tenfile.begin(), tenfile.end(), c);
	c[tenfile.size()] = '\0';
	FILE* f=fopen(c,"rb");
	if (f==NULL)
	{
		return;
	}*/
	fstream f(tenfile, ios::in);
	if (f.fail())
	{
		cout << "Khong mo duoc file" << endl;
		return;
	}
	hd_user.freadFromFile(f);
	f.close();
}
