#ifndef _USER_H_
#define _USER_H_
#include"Account.h"
#include"DS_HoaDon.h"
class User :public Account
{
private:
	int mTuoi;
	DS_HoaDon hd_user;

public:
	User();
	User(string ten, string matkhau)
	{
		mTen = ten;
		mPass = matkhau;
		nameclass = "User";
	}
	~User() {};
	
	void setTuoiUser(int t);
	int getTuoiUser();
	DS_HoaDon muaSach(ListBook& l);
	void upDateHoaDon();
	void xoaHoaDon_DSHD();

	DS_HoaDon getDanhSachHoaDon();
	int printMenu();
	void funRunMenu(ListBook& lb);
};


#endif // !_USER_H_


