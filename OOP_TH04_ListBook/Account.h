﻿#ifndef _ACCOUNT_H_
#define _ACCOUNT_H_
#include"ListBook.h"
#include"DS_UuDai.h"
#include"DS_Message.h"
//class Account
//{
//protected:
//	string mTen;//username
//	string mPass;//mật khẩu
//	bool logned;
//	string nameclass;
//public:
//	Account() {};
//	~Account();
//	void getAccount();
//	void setUsernameAccount(string ten);
//	void setPassAccount(string pass);
//	string getUsernameAccount();
//	string getPassAccount();
//
//	void setTypeofLognIn(bool a);
//	virtual void funRunMenu(ListBook& lb) = 0;
//}
class Account
{
protected:
	string mTen, mPass;
	int mTuoi;
	bool logned;
	vector<Message> dstn;
	DS_Message ds_tn;
public:
	Account() {
		logned = false;
		mTuoi = 0;
	}
	Account(string name, string pass, int tuoi)
	{
		mTen = name;
		mPass = pass;
		mTuoi = tuoi;
	}
	~Account();
	void setTuoi(int tuoi);
	int getTuoi();
	void getAccount();
	void setPassAccount(string pass);
	void setUsernameAccount(string ten);
	string getUsernameAccount();
	string getPassAccount();
	void setTypeofLognIn(bool a);

	void getInfor_Message(string& name_account, string& text);

	virtual int checkExistAccount(string name_account) = 0;

	void fwriteMessage(string& name_account, string& text);

	virtual void funRunMenu(ListBook& lb ,DS_UuDai& dsud) = 0;
	virtual string nameclass() = 0;


	virtual void sendMessage() = 0;

	//đọc tin nhắn từ file
	int freadMessage(string tenfile);
	int readMessage();
	void funReadMessage();


	void print();
};
#endif
