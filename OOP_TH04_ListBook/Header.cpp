#include "Header.h"
#include<conio.h>

int Manager::printMenu()
{
	int lenh;
	cout << "==========================" << endl;
	cout << "|| WELCOME TO MY SYSTEM ||" << endl;
	cout << "==========================" << endl;
	cout << "1. Dang nhap." << endl;
	cout << "2. Xem sach." << endl;
	cout << "3. Tim sach" << endl;
	cout << "4. Dang ky tai khoan." << endl;
	cout << "5. Xem danh sach uu dai hien co." << endl;
	cout << "6. Huong dan su dung." << endl;
	cout << "0. Thoat." << endl;
	cout << "Ban chon lenh nao: ";
	cin >> lenh;
	return lenh;
}

int Manager::getUuDai()
{

	fstream f("UuDai.txt");
	if (f.fail())
	{
		cout << "Khong mo duoc file Uudai." << endl;
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
		string tensach;
		int tuoi, mucuudai;
		for (int i = 0; i <= 1; i++)
		{

			p = strtok(NULL, c);
			if (p == NULL) continue;
			switch (i)
			{
			case 0:
			{
				if (type == "UuDai_Sach")
				{
					string temp(p);
					tensach = temp;
				}
				else
				{
					string temp(p);
					tuoi = stoi(temp);
				}

			}break;
			case 1:
			{
				string temp(p);
				mucuudai = stoi(temp);
			}break;
			}
			
		}
		if (type == "UuDai_Sach")
		{
			UuDai* ud = new UuDai_Sach(tensach,mucuudai);
			ud->getData_UuDai(lb);
			dsud.push_UuDai(ud);
		}
		if (type == "UuDai_Tuoi")
		{
			UuDai* ud = new UuDai_Tuoi(tuoi, mucuudai);
			dsud.push_UuDai(ud);
		}
	}

	return 1;
}




void getAccount(string& ten, string& pass)
{
	cin.ignore();
	cout << "Enter your name: "; getline(cin , ten);
	cout << "Enter your password: "; getline(cin , pass);
}
string Manager::lognIn(string& ten, string& matkhau,int &tuoi)
{

	getAccount(ten, matkhau);
	fstream f("Account.txt");
	if (f.fail()) {
		cout << "Khong mo duoc file account" << endl;
		return "";
	}
	char a[256];
	
	while (!f.eof())
	{
		
		f.getline(a, 255);//lấy ra từng dòng
		
		char c[5] = "\t";
		char* p = NULL;
		p = strtok(a, c);
		if (p == NULL) continue;
		string type (p);
		string username, pass;
		for (int i = 0; i <= 2; i++)
		{
			
			p = strtok(NULL, c);
			if (p == NULL) continue;
			switch (i)
			{
				case 0:
				{
					string temp(p);
					username=temp;

				}break;
				case 1:
				{
					string temp(p);
					pass = temp;
				}break;
				case 2:
				{
					string temp(p);
					tuoi = stoi(temp);
				}break;
			}
		}
		if (username == ten && pass == matkhau)
		{
			f.close();
			return type;
		}
	}
	f.close();
	return "";
}
void Manager::funRun()
{
	lb.loadfromFile();//đọc danh sách sách từ file lên
	dsud.getUuDai(lb);
	int lenh;
	do
	{
		system("cls");
		lenh = printMenu();
		switch (lenh)
		{
		case 1:
		{
			string type,ten, pass;
			int tuoi=0;
			do
			{
				
				type= lognIn(ten, pass,tuoi);
				if (type=="")
				{
					cout << "Dang nhap khong thanh cong." << endl;
					int choice;
					cout << "Tiep tuc(1) - Ngung (0) "; cin >> choice;
						if (choice == 0)
						{
							cout << "Cam on quy khach da su dung dich vu" << endl;
							break;
						}
				}
			} while (type==""); 
			cout << "Dang nhap thanh cong." << endl;
			if (type == "User")
			{
				//thực hiện các thao tác của User.
				User user(ten, pass,tuoi);
				user.setTypeofLognIn(true);
				user.funRunMenu(lb,dsud);	
				

			}
			else if (type == "NXB")
			{
				//thực hiện các thao tác của NXB.
				NXB nxb(ten, pass);
				nxb.setTypeofLognIn(true);
				nxb.funRunMenu(lb, dsud);

			}
			else if (type == "Tac Gia")
			{
				//thực hiện các thao tác của Tac Gia.
				TacGia tacgia(ten, pass);
				tacgia.setTypeofLognIn(true);
				tacgia.funRunMenu(lb, dsud);
				
			}
			else if (type == "Admin")
			{
				//thực hiện các thao tác của Admin
				Admin ad(ten, pass);
				ad.setTypeofLognIn(true);
				ad.funRunMenu(lb, dsud);

			}
			
		}break;
		case 2:
		{

			lb.xuatDanhSachSach();
			cout << endl;

		}break;
		case 3:
		{
			Guest guest;
			guest.timSach(lb);
		}break;
		case 4:
		{
			string ten, pass;
			int tuoi;
			cin.ignore();
			cout << "Ten dang nhap: "; getline(cin, ten);
			cout << "Mat khau: "; getline(cin, pass);
			cout << "Tuoi cua ban la: ";
			cin >> tuoi;
			Account* new_user=new User(ten, pass,tuoi);
			writeDownNewAccount(new_user);

			cout <<endl<< "Dang ki thanh cong." << endl;
			//ghi tai khoan nay vao file.
		}break;
		case 5:
		{
			dsud.xemDanhSachUudai();
		}break;
		case 6:
		{
			freadUserManual();
		}break;
		default:
			lenh = 0;
			cout << "=========================================" << endl;
			cout << "|| CAM ON QUY KHACH DA SU DUNG DICH VU ||" << endl;
			cout << "=========================================" << endl;
			break;
		}
		system("pause");
	} while (lenh!=0);
	lb.writeDownToFile();//viết danh sách đã được cập nhật xuống file.

	//viết danh sách uu đãi ngược trở lại file.
	dsud.writeDownUuDaiToFile();
}

void Manager::freadUserManual()
{
	fstream f("UserManual.txt");
	if (f.fail())
	{
		cout << "Khong mo duoc file Huong dan su dung." << endl;
		return;
	}
	while (!f.eof())
	{
		char a[501];
		f.getline(a, 500);
		string text(a);
		cout << text << endl;
	}
}

void Manager::writeDownNewAccount(Account* p)
{
	fstream f("Account.txt",ios::app);
	if (f.fail())
	{
		cout << "Khong mo duoc file" << endl;
		return;
	}
	
	f << p->nameclass() << "\t" << p->getUsernameAccount() << "\t" << p->getPassAccount();
	
}

