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
	cout << "================================" << endl;
	cout << "|             TAC GIA          |" << endl;
	cout << "================================" << endl;
	cout << "1. Xem danh sach sach." << endl;
	cout << "2. Them sach vao danh sach. " << endl; //(indivitual list book)
	cout << "3. Cap nhat lai ten sach." << endl;
	cout << "4. Xoa sach." << endl;
	cout << "5. Gui tin nhan." << endl;
	cout << "6. Doc tin nhan." << endl;
	cout << "7. Thong ke sach da ban." << endl;
	cout << "8. Khoa/Mo sach." << endl;
	cout << "9. Sach co luot mua cao nhat." << endl;
	cout << "0. Dang xuat (Thoat)." << endl;
	cout << "Ban chon lenh nao: ";
	cin >> lenh;
	return lenh;
}

int TacGia::countSoldBook()
{
	int tong = 0;
	for (int i = 0; i <dsSach.size(); i++)
	{
		tong += dsSach[i]->getSLDaban();
	}
	return tong;
}

void TacGia::bestSoldBook()
{
	cout << "========================================" << endl;
	cout << "|     DANH SACH BAN CHAY CUA TAC GIA    |" << endl;
	cout << "========================================" << endl;
	int max = dsSach[0]->getSLDaban();
	for (int i = 1; i < dsSach.size(); i++)
	{
		if (max < dsSach[i]->getSLDaban())
		{
			max = dsSach[i]->getSLDaban();
		}
	}

	vector<Sach*>::iterator it;
	for (it = dsSach.begin(); it != dsSach.end(); ++it)
	{
		if(max==(*it)->getSLDaban())
			cout << *(*it) << endl;
	}
}

void TacGia::LOckedOrUnlocked()
{
	string name;
	cin.ignore();
	cout << "Nhap vao ten sach can Khoa/Mo: ";
	getline(cin, name);
	Sach* temp = findSachfromTacGiaList(name);
	if (temp == NULL) return;
	cout << "Sach tim duoc la:" << endl;
	cout << *temp << endl;
	if (temp->getAnSachTacGia() == true)
	{
		cout << "Sach vua tim duoc da khoa." << endl;
		int lenh;
		cout << "Ban co muon mo khoa khong?" << endl;
		cout << "(1) - Mo            (2) - Khoa" << endl;
		cout << "Ban chon lenh nao: "; cin >> lenh;
		if (lenh != 2)
		{
			temp->setAnSachTacGia(false);
		}
		cout << "BAN DA MO KHOA SACH THANH CONG." << endl;
	}
	else
	{
		cout << "Sach vua tim duoc chua khoa." << endl;
		int lenh;
		cout << "Ban co muon khoa no khong?" << endl;
		cout << "(1) - Mo            (2) - Khoa" << endl;
		cout << "Ban chon lenh nao: "; cin >> lenh;
		if (lenh != 1)
		{
			temp->setAnSachTacGia(true);
		}
		cout << "BAN DA KHAO SACH THANH CONG." << endl;
	}
}

void TacGia::funRunMenu(ListBook& lb, DS_UuDai& dsud)
{
	getData(lb);
	int lenh;
	do
	{
		system("cls");
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
		case 5:
		{
			sendMessage();
		}break;
		case 6:
		{
			funReadMessage();
		}break;
		case 7:
		{
			cout << "So sach cua tac gia da ban duoc tai quay sach la: " << countSoldBook() << endl;
		}break;
		case 8:
		{
			LOckedOrUnlocked();
		}break;
		case 9:
		{
			bestSoldBook();
		}break;
		default:
			lenh = 0;
			cout << "Cam on ban da su dung sich vu vua chung toi." << endl;
			break;
		}
		system("pause>nul");
	} while (lenh!=0);
}

string TacGia::nameclass()
{
	return "Tac Gia";
}

void TacGia::sendMessage()
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

int TacGia::checkExistAccount(string name_account)
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
		if (type == "Tac Gia")
		{
			if (username == name_account) return 1;
		}
	}
	f.close();
	return 0;
}
