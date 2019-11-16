#include"Admin.h"
Account::~Account()
{
}

void Account::getAccount()
{
	cin.ignore();
	cout << "Nhap vao ten tai khoan: ";
	getline(cin, mTen);
	cout << "Nhap vao mat khau:";
	string mk;
	getline(cin, mk);
	do
	{
		string pascmp;
		cin.ignore();
		cout << "Xac nhan mat khau: ";
		getline(cin, pascmp);
		if (pascmp == mk)
		{
			mPass = mk;
		}
		else
		{
			cout << "Xac nhan matkhau sai. Nhap lai." << endl;
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

void Account::print()
{
	cout << nameclass << " " << mTen << " " << mPass;
}

