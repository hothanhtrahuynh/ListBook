#include "HoaDon.h"



HoaDon::HoaDon()
{
	this->sl = -1;
}

HoaDon::HoaDon(const HoaDon& hd)
{
	sach = hd.sach;
	this->sl = hd.sl;
	this->tongTien = hd.tongTien;
}


HoaDon::~HoaDon()
{
}

int HoaDon::taoHoaDon(ListBook& a)
{
	int n;
	cin.ignore();
	string name;
	cout << "Nhap vao ten sach can tao hoa don: ";
	getline(cin,name);//tên sách cần tìm
	Sach temp,*b=a.timSach_Ten(name);//tìm sách trong DS sách với tên đã nhập rồi gán cho biến b
	if (temp.getGiaSach() == b->getGiaSach())
	{
		cout << "Sach vua nhap khong co trong danh sach" << endl;
		return-1;
	}
	this->sach = *b;
	cout << "Nhap vao so luong sach: "; cin >> n;
	this->sl = n;
	b->setSLDaban(n);
	this->tongTien = n *b->getGiaSach();
	return 1;
}

void HoaDon::xuatHoaDon()
{
	cout << sach.getTenSach() << " : " << sl << "*" << tongTien / sl << " = " << tongTien << endl;
}

void HoaDon::setSoLuongSach(int n)
{
	if (n < 0)return;
	sl = n;
	tongTien = sl * sach.getGiaSach();
}

Sach HoaDon::getSachTrongHoaDon()
{
	return sach;
}

int HoaDon::getTienHoaDon()
{
	return tongTien;
}

int HoaDon::getSoLuong()
{
	return sl;
}

ostream& operator<<(ostream& out, HoaDon& b)
{
	out << b.sach << "	" << b.sl << "*" << b.tongTien / b.sl << " = " << b.tongTien << endl;
	return out;
	// TODO: insert return statement here
}
