#include "DS_HoaDon.h"

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

void DS_HoaDon::upDateHoaDonThu(int pos, int soLuongMoi, ListBook& lb)
{
	if (pos<0 || pos>dshd.size()) return;
	for (int i = 0; i < dshd.size(); i++)
	{
		if (i == pos - 1)
		{
			dshd[i].setSoLuongSach(soLuongMoi);
			Sach* a = lb.timSach_Ten(dshd[i].getSachTrongHoaDon().getTenSach());
			a->setSLDaban(soLuongMoi - a->getSLDaban());
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
		f << dshd[i].getSachTrongHoaDon().getMaSach() << "\t" << dshd[i].getSachTrongHoaDon().getTenSach() << "\t" << dshd[i].getSachTrongHoaDon().getTacGia() << "\t" << dshd[i].getSachTrongHoaDon().getNXB() << "\t" << dshd[i].getSachTrongHoaDon().getGiaSach() << "\t" << dshd[i].getSachTrongHoaDon().getSLDaban() << "\t" << dshd[i].getSachTrongHoaDon().getAnTacGia() << "\t" << dshd[i].getSachTrongHoaDon().getAnNXB() << "\n";
		f << dshd[i].getSoLuong()<<" " << dshd[i].getTienHoaDon() << "\n";
	}
	
	return 1;
}

int DS_HoaDon::freadFromFile(fstream& f)
{
	while (!f.eof())
	{
		char a[501];
		f.getline(a, 500);
		Sach temp;
		string check(a);
		if (check == "") continue;
		temp.filetoSach(a);
		int sl, tien;
		f >> sl >> tien;	
		HoaDon* temp_hd = new HoaDon(temp, sl, tien);
		dshd.push_back(*temp_hd);
		delete temp_hd;
	}
	
	return 1;
}

