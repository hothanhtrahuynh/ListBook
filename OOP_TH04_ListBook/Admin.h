#define _CRT_SECURE_NO_WARNINGS
#define _CRT_SECURE_NO_WARNINGS
#ifndef _ADMIN_H_
#define _ADMIN_H
#include"Account.h"
#include"User.h"
#include"TacGia.h"
#include"NXB.h"
#include"UuDai.h"
#include"UuDai_Sach.h"
#include"UuDai_Tuoi.h"
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
	void addUuDai(ListBook& lb,vector<UuDai*> &dsuudai, DS_UuDai& dsud);

	//Đọc từ file lên danh sách tài khoản
	int getData();


	//in danh sách tài khoản đã cập nhật vào file
	void writeDownAccountToFile();


	int printMenu();
	int printMenu_Message();
	int printMenu_Thongke();
	int printMenu_UuDai();


	void sendPublicMessage(string type_Account);

	void runThonngKefunction(ListBook& lb, DS_UuDai& dsud);
	void runUuDaiFunction(ListBook &lb, DS_UuDai& dsud);
	virtual void funRunMenu(ListBook& lb, DS_UuDai& dsud) ;
	virtual string nameclass();
	virtual void sendMessage();

	void khoaTacGia(ListBook& lb);
	void khoaNXB(ListBook& lb);


	void xemDanhSachTaiKhoan();

	int xoaTaiKhoan();
	int xoaUuDai(vector<UuDai*>& dsuudai);
	
	virtual int checkExistAccount(string name_account);
};

#endif