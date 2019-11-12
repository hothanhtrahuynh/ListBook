#include "User.h"



User::User()
{
}


User::~User()
{
}

void User::setTenUser(string ten)
{
	mTen = ten;
}

void User::setTuoiUser(int t)
{
	mTuoi = t;
}

void User::setPassUser(string pass)
{
	mPass = pass;
}

string User::getTenUser()
{
	return string(mTen);
}

int User::getTuoiUser()
{
	return mTuoi;
}

string User::getPassUser()
{
	return string(mPass);
}

DS_HoaDon User::muaSach(ListBook& l)
{
	DS_HoaDon dshoadon;
	
	do
	{
			int lenh;
			//gọi hàm thêm hóa đơn vào danh sách háo đơn
			dshoadon.themHoaDon(l);
				cout << "Tiep tuc them hoa don: Tiep tuc(1) - Ngung nhap(0) "; cin >> lenh;
				//nếu người dùng không mua nữa = ngừng thêm sách vào hóa đơn--> thoát khỏi vòng lập
				if (lenh == 0) break;
	} while (true);
	//trả về danh sách hóa đơn mà người dùng đã chọn mua (gồm các hóa đơn đã thêm vào)
	return dshoadon;
}

void User::upDateHoaDon(DS_HoaDon&a)
{
	a.xuatDSHoaDon();
	int stt, nSl;
	cout << "Nhap vao so thu tu hoa don can cap nhat: "; cin >>stt;
	cout << "Nhap vao so luong sach can cap nhat cho hoa don do: "; cin >> nSl;
	a.upDateHoaDonThu(stt, nSl);
}
