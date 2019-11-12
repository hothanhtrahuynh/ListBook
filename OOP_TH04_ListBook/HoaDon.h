#pragma once
#ifndef _HOADON_H_
#define _HOADON_H_
#include"ListBook.h"
class HoaDon
{
private:
	Sach sach;
	int tongTien;
	int sl;
public:
	HoaDon();
	~HoaDon();
	int taoHoaDon(ListBook& a);
	void xuatHoaDon();
	friend ostream& operator<<(ostream& out, HoaDon& b);
	void setSoLuongSach(int n);
	Sach getSachTrongHoaDon();
	int getTienHoaDon();
};

#endif