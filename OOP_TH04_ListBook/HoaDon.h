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
	HoaDon(const HoaDon& hd);
	HoaDon(Sach& a, int sl, int tien) {
		sach = a;
		this->sl = sl;
		tongTien = tien;
	}
	~HoaDon();
	int taoHoaDon(ListBook& a);
	void xuatHoaDon();
	friend ostream& operator<<(ostream& out, HoaDon& b);
	void setSoLuongSach(int n);
	Sach getSachTrongHoaDon();
	int getTienHoaDon();
	int getSoLuong();
	
};

#endif