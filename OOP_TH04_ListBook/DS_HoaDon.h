#pragma once
#ifndef _DSHOADON_H_
#define _DSHOADON_H_
#include"HoaDon.h"
class DS_HoaDon
{
private:
	vector <HoaDon> dshd;
public:
	void themHoaDon(ListBook &a);
	void xuatDSHoaDon();
	void xoaHoaDon();
	void upDateHoaDonThu(int pos, int soLuongMoi);
	int tongTienHoaDon();
};

#endif