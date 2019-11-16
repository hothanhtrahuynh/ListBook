#ifndef _ACCOUNT_H_
#define _ACCOUNT_H_
#include"ListBook.h"

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
	string mTen, mPass,nameclass;
	bool logned;
public:
	Account() {
		logned = false;
	}
	~Account();
	void getAccount();
	void setPassAccount(string pass);
	void setUsernameAccount(string ten);
	string getUsernameAccount();
	string getPassAccount();
	void setTypeofLognIn(bool a);
	virtual void funRunMenu(ListBook& lb)=0;
	void print();
};
#endif
