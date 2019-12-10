#define _CRT_SECURE_NO_WARNINGS
#define _CRT_SECURE_NO_WARNINGS	

#include "Sach.h"

Sach::Sach()
{
	tensach = "noname";
	masach = 0;
	gia = -1;
	tacGia = "noname";
	NXB = "noname";
	anTacGia = anNXB = false;
	anSach_TacGia = anSach_NXB = false;
	sl_Daban = 0;
}

Sach::Sach(string a, int b, float c)
{
	tensach = a;
	masach = b;
	gia = c;
	anTacGia = anNXB = false;
	sl_Daban = 0;
}


Sach::Sach(const Sach& a)
{
	tensach = a.tensach;
	masach = a.masach;
	gia = a.gia;
	tacGia = a.tacGia;
	this->NXB = a.NXB;
	anTacGia = a.anTacGia;
	anNXB = a.anNXB;
	anSach_TacGia = a.anSach_TacGia;
	anSach_NXB = a.anSach_NXB;
	sl_Daban = a.sl_Daban;
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

void Sach::setAnTacGia(bool a)
{
	anTacGia = a;
}

void Sach::setAnNXB(bool a)
{
	anNXB = a;
}

void Sach::setAnSachTacGia(bool a)
{
	anSach_TacGia = a;
}

void Sach::setAnSachNXb(bool a)
{
	anSach_NXB = a;
}

void Sach::setSLDaban(int sl)
{
	sl_Daban += sl;
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

bool Sach::getAnTacGia()
{
	return anTacGia;
}

bool Sach::getAnNXB()
{
	return anNXB;
}

bool Sach::getAnSachTacGia()
{
	return anSach_TacGia;
}

bool Sach::getAnSachNXB()
{
	return anSach_NXB;
}

int Sach::getSLDaban()
{
	return sl_Daban;
}

Sach* Sach::getBook()
{
	this->Nhap();
	return this;
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

Sach& Sach::operator=(Sach a)
{
	this->tensach = a.tensach;
	masach = a.masach;
	NXB = a.NXB;
	tacGia = a.tacGia;
	gia = a.gia;
	anTacGia = a.anTacGia;
	anNXB = a.anNXB;
	sl_Daban = a.sl_Daban;
	return *this;
	// TODO: insert return statement here
}

void Sach::filetoSach(char *a)
{
	
	char c[5] = "\t";
	char* p = NULL;
	p = strtok(a, c);
	if (p == NULL) return;
	int ms;
	ms = atoi(p);
	setMaSach(ms);
	for (int i = 0; i <= 8; i++)
	{
		p = strtok(NULL, c);
		if (p == NULL) continue;
		switch (i)
		{
			case 0://set tên Sách
				setTenSach(p);
				break;
			case 1://set tên Tác giả
				setTacGia(p);
				break;
			case 2://set tên Nhà Xuất Bản
				setNXB(p);
			break;
			case 3://set giá sách
			{
				float gia = float(atof(p));
				setGia(gia);
			}break;
			case 4:
			{
				int sl;
				sl = atoi(p);
				this->sl_Daban = sl;
			}break;
			case 5:
			{
				anTacGia = atoi(p);
			}break;
			case 6:
			{
				anNXB = atoi(p);
			}break;
			case 7:
			{
				anSach_TacGia = atoi(p);
			}break;
			case 8:
			{
				anSach_NXB = atoi(p);
			}break;
		}
	}

}


Sach::~Sach()
{

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
	ODev << a.masach << "	";
	ODev<<setw(35) << a.tensach << "	";
	cout <<setw(20)<< a.tacGia << "	";
	cout << setw(30) << a.NXB << "	";
	cout <<setw(10)<< a.gia << "	" << a.getSLDaban();
	return ODev;
	// TODO: insert return statement here
}
