#define _CRT_SECURE_NO_WARNINGS
#define _CRT_SECURE_NO_WARNINGS
#ifndef _USER_H_
#define _USER_H_
#include"Account.h"
#include"DS_HoaDon.h"
class User :public Account
{
private:
	DS_HoaDon hd_user;

public:
	User();
	User(string ten, string matkhau, int tuoi)
	{
		mTen = ten;
		mPass = matkhau;
		mTuoi = tuoi;
	}
	~User() {};
	
	DS_HoaDon muaSach(ListBook& l);
	void upDateHoaDon(ListBook& lb);
	void xoaHoaDon_DSHD();

	DS_HoaDon getDanhSachHoaDon();
	int printMenu();

	void funRunMenu(ListBook& lb, DS_UuDai& dsud);
	string nameclass();
	virtual void sendMessage();
	virtual int checkExistAccount(string name_account);

	void fwriteToFile();
	void freadFromFile();
	
};


#endif // !_USER_H_


