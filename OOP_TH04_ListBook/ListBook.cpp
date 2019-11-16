#include "ListBook.h"

void ListBook::taoDanhSachSach()
{
	cout << "KHOI TAO DANH SACH SACH" << endl;
	cout << "=========" << endl;
	int n;
	do
	{
		cout << "So luong sach can khoi tao: ";
		cin >> n;
		if (n > 0) break;
	} while (true);
	
	for (int i = 0; i < n; i++)
	{
		Sach a;
		cin >> a;
		this->lb.push_back(a);
		cout << endl;
	}
	do
	{
		int lenh;
		cout << "Ban co muon nhap them sach." << endl;
		cout << "Tiep tuc (1) - Dung lai (0)" << endl;
		cin >> lenh;
		if (lenh == 0) break;
		Sach a;
		cin >> a;
		this->lb.push_back(a);
	} while (true);

}

void ListBook::xuatDanhSachSach()
{
	cout << endl << "DANH SACH SACH DA NHAP" << endl;
	int i = 0;
	while (i < lb.size())
	{
		cout << lb[i++] << endl;
	}
}


int ListBook::timSachTheoTen(string& name)
{
	Sach temp;
	int i = 0;
	while (i< lb.size())
	{
		if (lb[i].getTenSach() == name)
		{
			return i;
		}
	}
	return -1;
}
int ListBook::timSachTheoTacGia(string& tg)
{
	int i = 0;
	while (i<lb.size())
	{
		if (lb[i++].getTacGia() == tg) return i;
	}
	return -1;
}
Sach* ListBook::timSach_Ten(string& name)
{
	
	int i = 0;
	while (i < lb.size())
	{
		if (lb[i].getTenSach() == name)
		{
			return &lb[i];
		}
		i++;
	}
	return NULL;
}

Sach** ListBook::timSach(string searchstring,int type)
{
	switch (type)
	{
	case 1://tìm và trả về mảng con trỏ Sách với tên Tác Giả được truyền vào.
	{
		int dem = this->demSach(searchstring, 1);
		Sach** mangSach = new Sach * [dem];
		int i = 0, pos = 0;
		while (i < lb.size())
		{
			if (lb[i].getTacGia() == searchstring)
			{
				mangSach[pos++] = &lb[i];
			}
			i++;
		}
		return mangSach;
	}break;
	case 2://tìm và trả về mảng các con trỏ Sách với tên NXB được truyền vào
	{
		int dem = this->demSach(searchstring, 2);
		Sach** mangSach = new Sach * [dem];
		int i = 0, pos = 0;
		while (i < lb.size())
		{
			if (lb[i].getNXB() == searchstring)
			{
				mangSach[pos++] = &lb[i];
			}
			i++;
		}
		return mangSach;
	}break;
	default:
		break;
	}

}

int ListBook::demSach(string searchstring,int type)
{
	int i = 0, dem = 0;
	switch (type)
	{
		//đếm số sách theo têm Tác giả được truyền vào
		case 1:
		{
			while (i < lb.size())
			{
				if (lb[i].getTacGia() == searchstring)
				{
					dem++;
				}
				i++;
			}
			return dem;
		}break;
		//đém số sách theo NXB với tên được truyền
		case 2:
		{
			while (i < lb.size())
			{
				if (lb[i].getNXB() == searchstring)
				{
					dem++;
				}
				i++;
			}
			return dem;
		}break;
	}
	
}



void ListBook::capNhatGiaSach()
{
	cout << endl << "CAP NHAT GIA SACH" << endl;
	cout << "Nhap vao ma sach can can cap nhat gia :";
	int ms;
	cin >> ms;
	float giamoi;
	cout << "Nhap vao gia sach moi: ";
	cin >> giamoi;
	Sach temp;
	int i = 0;
	while (i<lb.size())
	{
		if (lb[i].getMaSach() == ms)
		{
			lb[i].setGia(giamoi);
			return;
		}
		i++;
	}
	cout << "Khong tim thay sach voi ma vua nhap" << endl;
	/*if (temp.getGiaSach() == this->timSachTheoMaSach(ms).getGiaSach())
	{
		cout << "Khong co sach voi ma vua nhap" << endl;
		return;
	}*/

}

void ListBook::xoaSach()
{
	int ms;
	cout << "Ma sach can xoa la: ";
	cin >> ms;
	int pos = 0;
	pos = timSachTheoMaSach(ms);
	if (pos = -1)
	{
		cout << "Sach can xoa khong ton tai." << endl; return;
	}
	lb.erase(lb.begin()+pos);
}

int ListBook::checkExistBook(Sach& a)
{
	vector<Sach>::iterator it;
	for (it = lb.begin(); it != lb.end(); ++it)
	{
		if (a.getTenSach() == (it)->getTenSach()&&a.getNXB()==it->getNXB()&&a.getTacGia()==it->getTacGia()) return 1;
	}
	return 0;
}

int ListBook::timSachTheoMaSach(int a)
{
	Sach temp;
	int i = 0;
	while (i<lb.size())
	{
		if (lb[i].getMaSach() == a) return i;
		i++;
	}
	return -1;
}

int ListBook::loadfromFile()
{
	ifstream f("ListBookData.txt");
	if (f.fail()) { cout << "Khong mo duoc file." << endl; return -1; }
	char a[256];
	f.getline(a, 255);
	while (!f.eof())
	{
		Sach temp;
		f.getline(a, 255);//lấy ra từng dòng
		temp.filetoSach(a);
		this->lb.push_back(temp);
	}
	/*int dem = 0;
	while (!f.eof())
	{
		dem++;
		if (dem > 10) break;
		Sach temp;
		int ms; string tenSach, tenTacgia, tenNXB; float gia;
		f >> ms; f >> tenSach; f >> tenTacgia; f >> tenNXB;f >> gia;

		temp.setMaSach(ms);
		temp.setTenSach(tenSach);
		temp.setTacGia(tenTacgia);
		temp.setNXB(tenNXB);
		temp.setGia(gia);
		this->lb.push_back(temp);
	}*/
}

//thêm sách vào trong list sách.
void ListBook::themSach()
{
	Sach temp;
	temp.Nhap();
	lb.push_back(temp);
}