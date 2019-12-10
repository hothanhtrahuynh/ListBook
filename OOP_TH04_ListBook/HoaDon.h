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
	bool payed, applied_promotion;
public:
	HoaDon();
	HoaDon(const HoaDon& hd);
	HoaDon(Sach& a, int sl, int tien,bool pay, bool b) {
		sach = a;
		this->sl = sl;
		payed = pay;
		applied_promotion = b;
		tongTien = tien;
	}
	~HoaDon();
	int taoHoaDon(ListBook& a);
	void xuatHoaDon();
	friend ostream& operator<<(ostream& out, HoaDon& b);

	void setSoLuongSach(int n);
	void setTongTien(int tien);
	void setPayed(bool a);
	void setApplied_Promotion(bool a);

	Sach getSachTrongHoaDon();
	int getTienHoaDon();
	int getSoLuong();
	bool getPayed();
	bool getAppliedPromotion();
};

#endif