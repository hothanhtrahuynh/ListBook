﻿#include "DS_HoaDon.h"

bool DS_HoaDon::checkEmpty()
{
	if(dshd.empty())
	return true;
	return false;
}

void DS_HoaDon::themHoaDon(ListBook& a)
{
	HoaDon b;
	cout << "THEM HOA DON" << endl;
	//thêm sach vào hóa đơn-->tạo hóa đơn
	b.taoHoaDon(a);
	//thêm hóa đơn vào ds hóa đơn
	if (b.getSoLuong() == -1) return;
		this->dshd.push_back(b);

}

void DS_HoaDon::xuatDSHoaDon()
{
	int i = 0;
	while (i<dshd.size())
	{
		dshd[i].xuatHoaDon();
		cout << endl;
		i++;
	}
}

void DS_HoaDon::xoaHoaDon()
{
	int stt;
	cout << "Nhap vao thu tu hoa don muon xoa: ";
	cin >> stt;
	for (int i = 0; i < dshd.size(); i++)
	{
		if (i==stt-1)
		{
			dshd.erase(dshd.begin() + i);
		}
	}
}

void DS_HoaDon::upDateHoaDonThu(int pos, int soLuongMoi)
{
	if (pos<0 || pos>dshd.size()) return;
	for (int i = 0; i < dshd.size(); i++)
	{
		if (i == pos - 1)
		{
			dshd[i].setSoLuongSach(soLuongMoi);
		}
	}
}

int DS_HoaDon::tongTienHoaDon()
{
	int tong = 0;
	for (int i = 0; i < dshd.size(); i++)
	{
		tong += dshd[i].getTienHoaDon();
	}
	return tong;
}

int DS_HoaDon::fwriteToFile(fstream& f)
{
	for (int i = 0; i < dshd.size(); i++)
	{
		f.write(reinterpret_cast<const char*>(&dshd[i]), sizeof(HoaDon));
	}
	
	return 1;
}

int DS_HoaDon::freadFromFile(fstream& f)
{
	while (!f.eof())
	{
		HoaDon* temp = new HoaDon;
		f.read(reinterpret_cast<char*>(temp), sizeof(HoaDon));
		if(temp->getSachTrongHoaDon().getGiaSach()!=-1)
			this->dshd.push_back(*temp);
	}
	
	return 1;
}

