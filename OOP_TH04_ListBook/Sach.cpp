
#include "Sach.h"

Sach::Sach()
{
	tensach = "noname";
	masach = 0;
	gia = -1;
	tacGia = "noname";
	NXB = "noname";
}

Sach::Sach(string a, int b, float c)
{
	tensach = a;
	masach = b;
	gia = c;
}

Sach::Sach(const Sach& a)
{
	tensach = a.tensach;
	masach = a.masach;
	gia = a.gia;
	tacGia = a.tacGia;
	NXB = a.NXB;
}

void Sach::setGia(float a)
{
	gia = a;
}

void Sach::setMaSach(int id)
{
	masach = id;
}

void Sach::setTenSach(string name)
{
	tensach = name;
}

void Sach::setTacGia(string tacgia)
{
	tacGia = tacgia;
}

void Sach::setNXB(string nxb)
{
	this->NXB = nxb;
}

int Sach::getMaSach()
{
	return masach;
}

string Sach::getTenSach()
{
	return string(tensach);
}

float Sach::getGiaSach()
{
	return gia;
}

string Sach::getTacGia()
{
	return string(this->tacGia);
}

string Sach::getNXB()
{
	return string(NXB);
}

void Sach::Nhap()
{
	cout << "Nhap vao ma sach: ";
	cin >> this->masach;
	cin.ignore();
	cout << "Nhap vao ten sach: ";
	getline(cin, this->tensach);
	cout << "Nhap vao tac gia:";
	getline(cin, tacGia);
	cout << "Nha xuat ban: ";
	getline(cin, NXB);
	cout << "Nhap vao gia sach: ";
	cin >> this->gia;
	

}

void Sach::Xuat()
{
	cout << masach << " - " << tensach << " - " << tacGia << " - " << NXB << " - " << gia <<"dong"<< endl;

}



/*Sach& Sach::operator=(Sach& a)
{
	tensach = a.tensach;
	gia = a.gia;
	masach = a.masach;
	return *this;
	// TODO: insert return statement here
}*/

//void Sach::filetoSach(char *a)
//{
//	
//	char c[5] = "\t";
//	char* p = NULL;
//	p = strtok(a, c);
//	if (p == NULL) return;
//	int ms;
//	ms = atoi(p);
//	setMaSach(ms);
//	for (int i = 0; i <= 3; i++)
//	{
//		p = strtok(NULL, c);
//		switch (i)
//		{
//			case 0://set tên Sách
//				setTenSach(p);
//				break;
//			case 1://set tên Tác giả
//				setTacGia(p);
//				break;
//			case 2://set tên Nhà Xuất Bản
//				setNXB(p);
//			break;
//			case 3://set giá sách
//			{
//				float gia = float(atof(p));
//				setGia(gia);
//			}break;
//		}
//	}
//
//}

Sach::~Sach()
{
	gia = 0;
	masach = -1;
	tensach = "\0";
}

istream& operator>>(istream& IDev, Sach& a)
{
	cout << "Nhap vao ma sach: ";
	IDev >> a.masach;
	cout << "Nhap vao ten sach: ";
	IDev >> a.tensach;
	cout << "Nhap vao tac gia: ";
	IDev >> a.tacGia;
	cout << "Nhap vao NXB: ";
	IDev >> a.NXB;
	cout << "Nhap vao gia sach: ";
	IDev >> a.gia;
	return IDev;
	// TODO: insert return statement here
}

ostream& operator<<(ostream& ODev, Sach& a)
{
	ODev  << a.masach << "	";
	ODev << a.tensach << "	";
	cout << a.tacGia << "	";
	cout << a.NXB << "	";
	cout << a.gia;
	return ODev;
	// TODO: insert return statement here
}
