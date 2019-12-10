#define _CRT_SECURE_NO_WARNINGS
#define _CRT_SECURE_NO_WARNINGS
#ifndef _USER_H_
#define _USER_H_
#include"Guest.h"
#include"Account.h"
#include"DS_HoaDon.h"
class User :public Account, public Guest
{
private:
	DS_HoaDon hd_user;
	DS_UuDai ud_user;
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

	virtual void funRunMenu(ListBook& lb, DS_UuDai& dsud);
	string nameclass();
	virtual void sendMessage();
	virtual int checkExistAccount(string name_account);

	void fwriteToFile();
	void freadFromFile();
	
	void loadfromTotalUuDai(DS_UuDai& dsuudai);
};


#endif // !_USER_H_


