#include "TacGia.h"

TacGia::TacGia()
{
	mTen = "";
	mPass = "";
}

TacGia::~TacGia()
{
}

void TacGia::addBook()
{
	Sach* temp = new Sach;
	int ms; string tensach, nxb; float gia;
	cout << "Ma so sach: "; cin >> ms;
	cout << "Ten sach: "; cin >> tensach;
	cout << "NXB: "; cin >> nxb;
	cout << "Gia sach: "; cin >> gia;
	temp->setMaSach(ms);
	temp->setTenSach(tensach);
	temp->setNXB(nxb);
	temp->setTacGia(mTen);
	temp->setGia(gia);
	dsSach.push_back(temp);
}

void TacGia::getData(ListBook& l)
{
	int sl = l.demSach(mTen, 1);
	//do đếm số Sách  theo tên Tác gải nên type=1
	Sach** p = l.timSach(mTen, 1);
	if (p != NULL)
	{
		for (int i = 0; i < sl; i++)
		{
			dsSach.push_back(p[i]);
		}
	}
}

void TacGia::printTacGiaListBook()
{

	cout << "TAC GIA " << mTen << endl;
	vector<Sach*>::iterator it;
	for (it = dsSach.begin(); it != dsSach.end(); ++it)
	{
		cout << *(*it) << endl;
	}
	cout << endl;
}

Sach* TacGia::findSachfromTacGiaList(string tensach)
{
	vector<Sach*>::iterator it;
	for (it = dsSach.begin(); it != dsSach.end(); ++it)
	{
		if ((*it)->getTenSach() == tensach) return *it;
	}
	return NULL;
}

int TacGia::updateTenSach(string tensach, string tensachmoi)
{
	Sach* p = findSachfromTacGiaList(tensach);
	if (p == NULL) { cout << "Khong tim duoc sach trong so sach cua NXB." << endl; return -1; }
	p->setTenSach(tensachmoi);
	return 1;
}

void TacGia::funRunUpdateNameBook()
{
	string tensach, tensachmoi;
	do
	{
		cout << "Nhap vao ten sach can cap nhat lai ten: "; cin >> tensach;
		cout << "Ten sach moi: "; cin >> tensachmoi;
		if (updateTenSach(tensach, tensachmoi) == 1) break;
		cout << "Vui long thu lai." << endl;
		int lenh;
		cout << "Tiep tuc chinh sua: Tiep tuc(1) - Ngung (0) "; cin >> lenh;
		if (lenh == 0) break;
	} while (true);
	
}

int TacGia::deleBook(string tensach)
{
	Sach* temp = findSachfromTacGiaList(tensach);
	if (temp == NULL) {
		cout << "Sach ban can xoa khong co trong danh sach." << endl;
		return-1;
	}
	else
	{
		temp->setTacGia("");
	}
	vector <Sach*>::iterator it;
	TacGia tacgia_temp;
	for (it = dsSach.begin(); it != dsSach.end(); ++it)
	{
		if ((*it)->getTenSach() != tensach)
		{
			tacgia_temp.dsSach.push_back((*it));
		}
	}
	*this = tacgia_temp;
	return 1;	
}

void TacGia::funRundeleBook()
{
	string tensach;
	do
	{
		cout << "Nhap ten sach muon xoa khỏi danh sach cua NXB: "; cin >> tensach;
		if (deleBook(tensach) == 1) break;
		cout << "Vui long nhap lai.";
	} while (true);
}
