#include"TacGia.h"

TacGia::TacGia()
{
	mTen = "";
	mPass = "";
}

TacGia::TacGia(string ten, string pass)
{
	mTen = ten;
	mPass = pass;

}

void  TacGia::addBook(Sach *a)
{
	if (a != NULL);
	this->dsSach.push_back(a);

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
//tìm và trả về con trỏ trỏ đến sách trong ListBook có tên được truyền vào trong số Sách của Tác Giả
{
	vector<Sach*>::iterator it;
	for (it = dsSach.begin(); it != dsSach.end(); ++it)
	{
		if ((*it)->getTenSach() == tensach) return *it;
	}
	return NULL;
}

int TacGia::updateTenSach(string tensach )
{
	Sach* p = findSachfromTacGiaList(tensach);
	if (p == NULL) { cout << "Khong tim duoc sach trong so sach cua NXB." << endl; return -1; }
	
	if (p->getAnTacGia() == true) 
	{ 
		cout << "Tac gia khong duoc cap quyen de chinh sua tren sach nay." << endl; 
		cout << "Vui long chon lai sach khac." << endl;
		return 0;
	}

	string tensachmoi;
	cin.ignore();
	cout << "Ten sach moi: "; getline(cin, tensachmoi);
	p->setTenSach(tensachmoi);
	return 1;
}

void TacGia::funRunUpdateNameBook()
{
	string tensach, tensachmoi;
	do
	{
		cin.ignore();
		cout << "Nhap vao ten sach can cap nhat lai ten: "; getline(cin, tensach);
		int check = updateTenSach(tensach);
		if ( check== 1) break;
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
	else if (temp->getAnTacGia() == true)
	{
		cout << "Tac gia khong duoc cap quyen de chinh sua hay xoa doi voi sach nay." << endl;
		cout << "Vui long chon sach khac." << endl;
		return 0;
	}
	else
	{
		temp->setTacGia("");
	}
	vector <Sach*>::iterator it;
	TacGia* tacgia_temp = new TacGia;
	for (it = dsSach.begin(); it != dsSach.end(); ++it)
	{
		if ((*it)->getTenSach() != tensach)
		{
			tacgia_temp->dsSach.push_back((*it));
		}
	}
	*this = *tacgia_temp;
	return 1;	
}

void TacGia::funRundeleBook()
{
	string tensach;
	do
	{
		cout << "Nhap ten sach muon xoa khỏi danh sach cua NXB: "; getline(cin , tensach);
		int check = deleBook(tensach);
		if ( check== 1) break;
		cout << "Vui long nhap lai.";
	} while (true);
}

int TacGia::printMenu()
{
	int lenh;
	cout << "1. Xem danh sach sach." << endl;
	cout << "2. Them sach vao danh sach. " << endl; //(indivitual list book)
	cout << "3. Cap nhat lai ten sach." << endl;
	cout << "4. Xoa sach." << endl;
	cout << "0. Dang xuat (Thoat)." << endl;
	cout << "Ban chon lenh nao: ";
	cin >> lenh;
	return lenh;
}

void TacGia::funRunMenu(ListBook& lb)
{
	getData(lb);
	int lenh;
	do
	{
		lenh = printMenu();
		switch (lenh)
		{
		case 1:
		{
			printTacGiaListBook();
			cout << endl;
		}break;
		case 2:
		{
			Sach* temp = new Sach;
			temp->Nhap();
			if (lb.checkExistBook(*temp) ==1 )
			{
				cout << "Sach vua nhap da ton tai trong he thong." << endl;
				cout << "Vui long thu lai." << endl;
			}
			addBook(temp);
			cout << endl;
		}break;
		case 3:
		{
			funRunUpdateNameBook();
			cout << endl;
		}break;
		case 4:
		{
			funRundeleBook();
			cout << endl;
		}break;
		default:
			lenh = 0;
			cout << "Cam on ban da su dung sich vu vua chung toi." << endl;
			break;
		}

	} while (lenh!=0);
}

string TacGia::nameclass()
{
	return "Tac Gia";
}
