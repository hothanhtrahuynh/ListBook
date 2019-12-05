﻿
#include"NXB.h"
NXB::NXB()
{
	mTen = "";
	this->mPass = "";
}

NXB::~NXB()
{
}

void NXB::addBook(Sach *a)
{
	if (a != NULL);
	dsSach.push_back(a);
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

int NXB::updatePrice(string tenSach)
{
	Sach* p = findSachfromNXBList(tenSach);
	if (p == NULL) { cout << "Khong tim duoc sach trong so sach cua NXB." << endl; return -1; }
	if (p->getAnNXB() == true) { cout << "Nha xuat ban khong duoc cap quyen de chinh sua tren sach nay." << endl; return 0; }
	
	float gia=-1;
	cout << "Gia sach moi: "; 
	cin >> gia;
	p->setGia(gia);
	return 1;
}

void NXB::funRunUpdatePrice()
{
	int gia; string tensach;
	do
	{
		cout << "Nhap vao ten sach can cap nhat lai gia: "; cin >> tensach;
		
		int check = updatePrice(tensach);
		if ( check== 1) break;
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
	else if (temp->getAnNXB() == true)
	{
		cout << "Nha xuat ban khogn duoc cap quyen thaot ac tren sach nay." << endl;
		cout << "VUi long chon lai sach khac." << endl;
		return 0;
	}
	else
	{
		temp->setNXB("");
	}
	vector <Sach*>::iterator it;
	NXB* nxb_temp = new NXB;
	for (it = dsSach.begin(); it != dsSach.end(); ++it)
	{
		if ((*it)->getTenSach() != tensach)
		{
			nxb_temp->dsSach.push_back((*it));
		}
	}
	*this = *nxb_temp;
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

int NXB::printMenu()
{
	int lenh;
	cout << "1. Xem danh sach sach." << endl;
	cout << "2. Them sach vao danh sach. " << endl; //(indivitual list book)
	cout << "3. Cap nhat lai gia sach." << endl;
	cout << "4. Xoa sach." << endl;
	cout << "5. Gui tin nhan." << endl;
	cout << "0. Dang xuat (Thoat)." << endl;
	cout << "Ban chon lenh nao: ";
	cin >> lenh;
	return lenh;
}

void NXB::funRunMenu(ListBook& lb, DS_UuDai& dsud)
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
			printNXBListBook();
			cout << endl;
		}break;
		case 2:
		{
			Sach* temp = new Sach;
			temp->Nhap();
			if (lb.checkExistBook(*temp) == 1)
			{
				cout << "Sach vua nhap da ton tai trong he thong." << endl;
				cout << "Vui long thu lai." << endl;
			}
			cout << endl;
		}break;
		case 3:
		{
			funRunUpdatePrice();
			cout << endl;
		}break;
		case 4:
		{
			funRundeleBook();
			cout << endl;
		}break;
		case 5:
		{
			sendMessage();
		}break;
		default:
			lenh = 0;
			cout << "Cam on ban da su dung sich vu vua chung toi." << endl;
			break;
			cout << endl;
		}

	} while (lenh!=0);
}

string NXB::nameclass()
{
	return "NXB";
}

void NXB::sendMessage()
{
	string name_user, text;
	getInfor_Message(name_user, text);
	if (checkExistAccount(name_user) == 0)
	{
		cout << "Khong tim thay tai khoan nao voi ten vua nhap." << endl;
		cout << "Vui long thu lai." << endl;
		return;
	}
	fwriteMessage(name_user, text);
}

int NXB::checkExistAccount(string name_account)
{
	fstream f("Account.txt");
	if (f.fail())
	{
		cout << "Khong mo duoc file account." << endl;
		return -1;
	}
	char a[256];

	while (!f.eof())
	{

		f.getline(a, 255);
		char c[5] = "\t";
		char* p = NULL;
		p = strtok(a, c);
		if (p == NULL) continue;
		string type(p);
		string username, pass;
		for (int i = 0; i <= 1; i++)
		{

			p = strtok(NULL, c);
			switch (i)
			{
			case 0:
			{
				string temp(p);
				username = temp;

			}break;
			case 1:
			{
				string temp(p);
				pass = temp;
			}break;
			}
		}
		if (type == "NXB")
		{
			if (username == name_account) return 1;
		}
	}
	f.close();
	return 0;
}


