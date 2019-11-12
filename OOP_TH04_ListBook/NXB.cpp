#include "NXB.h"

NXB::NXB()
{
	mTen = "";
	this->mPass = "";
}

NXB::~NXB()
{
}

void NXB::addBook()
{
	Sach* temp = new Sach;
	int ms; string tensach, tenTacGia; float gia;
	cout << "Ma so sach: "; cin >> ms;
	cout << "Ten sach: "; cin >> tensach;
	cout << "Tac gia: "; cin >> tenTacGia;
	cout << "Gia sach: "; cin >> gia;
	temp->setMaSach(ms);
	temp->setTenSach(tensach);
	temp->setTacGia(tenTacGia);
	temp->setNXB(mTen);
	temp->setGia(gia);
	dsSach.push_back(temp);
}

void NXB::getData(ListBook& l)
{
	int sl = l.demSach(mTen,2);
	Sach** p = l.timSach(this->mTen,2);
	if (p != NULL) 
	{
		for (int i = 0; i < sl; i++)
		{
			dsSach.push_back(p[i]);
		}
	}
}

void NXB::printNXBListBook()
{
	cout << "NHA XUAT BAN " << mTen << endl;
	vector<Sach*>::iterator it;
	for (it = dsSach.begin(); it != dsSach.end(); ++it)
	{
		cout << *(*it) << endl;
	}
}

Sach* NXB::findSachfromNXBList(string tensach)
{
	vector<Sach*>::iterator it;
	for (it = dsSach.begin(); it != dsSach.end(); ++it)
	{
		if ((*it)->getTenSach() == tensach) return *it;
	}
	return NULL;
}

int NXB::updatePrice(string tenSach,float gia)
{
	Sach* p = findSachfromNXBList(tenSach);
	if (p == NULL) { cout << "Khong tim duoc sach trong so sach cua NXB." << endl; return -1; }
	p->setGia(gia);
	return 1;
}

void NXB::funRunUpdatePrice()
{
	int gia; string tensach;
	do
	{
		cout << "Nhap vao ten sach can cap nhat lai gia: "; cin >> tensach;
		cout << "Gia sach moi: "; cin >> gia;
		if (updatePrice(tensach, gia) == 1) break;
		cout << "Vui long thu lai." << endl;
		int lenh;
		cout << "Tiep tuc chinh sua: Tiep tuc(1) - Ngung (0) "; cin >> lenh;
		if (lenh == 0) break;
	} while (true);
	
}

int NXB::deleBook(string tensach)
{
	Sach* temp = findSachfromNXBList(tensach);
	if (temp == NULL) { 
		cout << "Sach ban can xoa khong co trong danh sach." << endl; 
		return-1;
	}
	else
	{
		temp->setNXB("");
	}
	vector <Sach*>::iterator it;
	NXB nxb_temp;
	for (it = dsSach.begin(); it != dsSach.end(); ++it)
	{
		if ((*it)->getTenSach() != tensach)
		{
			nxb_temp.dsSach.push_back((*it));
		}
	}
	*this = nxb_temp;
	return 1;
}

void NXB::funRundeleBook()
{
	string tensach;
	do
	{
		cout << "Nhap ten sach muon xoa khỏi danh sach cua NXB: "; cin >> tensach;
		if (deleBook(tensach) == 1) break;
		cout << "Vui long nhap lai.";
	} while (true);
}


