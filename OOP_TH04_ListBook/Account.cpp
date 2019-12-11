#include"Admin.h"
Account::~Account()
{
}

void Account::setTuoi(int tuoi)
{
	mTuoi = tuoi;
}

int Account::getTuoi()
{
	return mTuoi;
}

void Account::getAccount()
{
	//cin.ignore();
	cout << "Nhap vao ten tai khoan: ";
	getline(cin, mTen);
	cout << "Nhap vao mat khau:";
	getline(cin, mPass);
	do
	{
		string pascmp;
		//cin.ignore();
		cout << "Xac nhan mat khau: ";
		getline(cin, pascmp);
		if (pascmp == mPass)
		{
			break;
		}
		else
		{
			cout << "Xac nhan mat khau sai. Nhap lai." << endl;
		}
	} while (true);
	
}

void Account::setUsernameAccount(string ten)
{
	mTen = ten;
}

void Account::setPassAccount(string pass)
{
	mPass = pass;
}

string Account::getUsernameAccount()
{
	return string(mTen);
}

string Account::getPassAccount()
{
	return string(mPass);
}



void Account::setTypeofLognIn(bool a)
{
	logned = a;
}

void Account::getInfor_Message(string& name_account, string& text)
{
	cin.ignore();
	cout << "Nhap vao ten tai khoan muon gui tin nhan: ";
	getline(cin, name_account);
	cout << "Noi dung tin nhan ban muon gui: ";
	getline(cin, text);
}

void Account::fwriteMessage(string& name_account, string& text)
{
	string tenfile = name_account + "_Message.txt";
	fstream f(tenfile, ios::app);
	if (f.fail())
	{
		cout << "Khong tim thay file de gui tin nhan cho user." << endl;
		return;
	}
	f <<this->nameclass()<<"\t"<< this->mTen << "\t" << text << endl;
}

int Account::freadMessage(string tenfile)
{
	fstream f(tenfile);
	if (f.fail()) { cout << "Khong mo duoc file de doc tin nhan." << endl; return-1; }
	while (!f.eof())
	{
		string name_account, text;
		char a[501];
		f.getline(a, 500);
		string check(a);
		if (check == "") break;
		char* p = NULL;
		p = strtok(a, "\t");
		string type_account(p);
		for (int i = 1; i < 3; i++)
		{
			p = strtok(NULL, "\t");
			if (p == NULL) continue;
			if (i == 1) {
				string temp_name_account(p); name_account = temp_name_account;
			}
			if (i == 2) {
				string temp_text(p); text = temp_text;
			}

		}
		Message temp(name_account, text, type_account);
		dstn.push_back(temp);
	}
	return 1 ;
}

int Account::readMessage()
{
	string tenfile = mTen + "_Message.txt";
	
	freadMessage(tenfile);

	for (int i = 0; i < dstn.size(); i++)
	{
		cout << dstn[i];
	}

	return dstn.size();
}

void Account::funReadMessage()
{
	cout << endl << "Tin nhan ban nhan duoc:" << endl;
	int check = readMessage();
	if (check == -1) return;
	if (check == 0)
	{
		cout << "Ban chua nhan duoc tin nhan nao" << endl;
		return;
	}
	cout << "=================" << endl;
	cout << "Ban co muon tra loi tin nhan? " << endl;
	int choice;
	cout << "Tra loi(1) - De xem sau(0)." << endl;
	cout << "Ban chon: "; cin >> choice;
	if (choice == 1)
	{
		sendMessage();
	}
}

void Account::print()
{
	cout  << mTen <<setw(30)<< mPass;
}

