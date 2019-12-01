#define _CRT_SECURE_NO_WARNINGS
#define _CRT_SECURE_NO_WARNINGS
#ifndef _ADMIN_H_
#define _ADMIN_H
#include"Account.h"
#include"User.h"
#include"TacGia.h"
#include"NXB.h"
#include<vector>

class Admin:public Account
{
	vector<Account*> dstk;
public:
	Admin();
	Admin(string ten, string pass)
	{
		mTen = ten;
		mPass = pass;
	}
	~Admin();
	int addAccount();

	//Đọc từ file lên danh sách tài khoản
	int getData();

	//in danh sách tài khoản đã cập nhật vào file
	void writeDownAccountToFile();


	int printMenu();
	virtual void funRunMenu(ListBook& lb) ;
	virtual string nameclass();
	
	void khoaTacGia(ListBook& lb);
	void khoaNXB(ListBook& lb);
	void xemDanhSachTaiKhoan();
	int xoaTaiKhoan();
};

#endif