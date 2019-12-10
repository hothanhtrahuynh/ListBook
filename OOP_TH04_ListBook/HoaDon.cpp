#include "HoaDon.h"



HoaDon::HoaDon()
{
	this->sl = -1;
	applied_promotion = payed = false;
}

HoaDon::HoaDon(const HoaDon& hd)
{
	sach = hd.sach;
	this->sl = hd.sl;
	this->tongTien = hd.tongTien;
	applied_promotion = hd.applied_promotion;
	payed = hd.payed;
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
	if (b==NULL)
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

void HoaDon::setTongTien(int tien)
{
	tongTien = tien;
}

void HoaDon::setPayed(bool a)
{
	payed = a;
}

void HoaDon::setApplied_Promotion(bool a)
{
	applied_promotion = a;
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

bool HoaDon::getPayed()
{
	return payed;
}

bool HoaDon::getAppliedPromotion()
{
	return applied_promotion;
}

ostream& operator<<(ostream& out, HoaDon& b)
{
	out << b.sach << "	" << b.sl << "*" << b.tongTien / b.sl << " = " << b.tongTien << endl;
	return out;
	// TODO: insert return statement here
}
