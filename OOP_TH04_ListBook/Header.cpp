﻿#include "Header.h"
#include<conio.h>

int printMenu()
{
	int lenh;
	cout << "WELCOME TO MY SYSTEM" << endl;
	cout << "1.Dang nhap." << endl;
	cout << "2.  Xem sach." << endl;
	cout << "3. Tim sach" << endl;
	cout << "4. Dang ky tai khoan." << endl;
	cout << "0. Thoat." << endl;
	cout << "Ban chon lenh nao: ";
	cin >> lenh;
	return lenh;
}

void getAccount(string& ten, string& pass)
{
	cin.ignore();
	cout << "Enter your name: "; getline(cin , ten);
	cout << "Enter your password: "; getline(cin , pass);
}

string lognIn(string& ten, string& matkhau)
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
		for (int i = 0; i <= 1; i++)
		{
			
			p = strtok(NULL, c);
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
void funRun(ListBook& lb)//truyền vào list sách đã được cập nhật thông tin từ file
{
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
			do
			{
				
				type= lognIn(ten, pass);
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
				User user(ten, pass);
				user.setTypeofLognIn(true);
				user.funRunMenu(lb);
				

			}
			else if (type == "NXB")
			{
				//thực hiện các thao tác của NXB.
				NXB nxb(ten, pass);
				nxb.setTypeofLognIn(true);
				nxb.funRunMenu(lb);

			}
			else if (type == "Tac Gia")
			{
				//thực hiện các thao tác của Tac Gia.
				TacGia tacgia(ten, pass);
				tacgia.setTypeofLognIn(true);
				tacgia.funRunMenu(lb);
				
			}
			else if (type == "Admin")
			{
				//thực hiện các thao tác của Admin
				Admin ad(ten, pass);
				ad.setTypeofLognIn(true);
				ad.funRunMenu(lb);

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

			Account* new_user=new User(ten, pass);
			writeDownNewAccount(new_user);

			cout <<endl<< "Dang ki thanh cong." << endl;
			//ghi tai khoan nay vao file.
		}break;
		default:
			lenh = 0;
			break;
		}
		_getch();
	} while (lenh!=0);

	// lưu danh sách sách mói vàgo file

	//lưu danh sách tài khoản trở lại file.
}

void writeDownNewAccount(Account* p)
{
	fstream f("Account.txt",ios::app);
	if (f.fail())
	{
		cout << "Khong mo duoc file" << endl;
		return;
	}
	
	f << p->nameclass() << "\t" << p->getUsernameAccount() << "\t" << p->getPassAccount();
	
}
