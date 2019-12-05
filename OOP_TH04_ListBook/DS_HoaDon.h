#pragma once
#ifndef _DSHOADON_H_
#define _DSHOADON_H_
#include"HoaDon.h"
class DS_HoaDon
{
private:
	vector <HoaDon> dshd;
public:
	bool checkEmpty();
	void themHoaDon(ListBook &a);
	void xuatDSHoaDon();
	void xoaHoaDon();
	void upDateHoaDonThu(int pos, int soLuongMoi,ListBook& lb);
	int tongTienHoaDon();
	int fwriteToFile(fstream& f);
	int freadFromFile(fstream& f);
};

#endif