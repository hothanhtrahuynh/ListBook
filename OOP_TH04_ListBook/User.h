#ifndef _USER_H_
#define _USER_H_
#include"Guest.h"

class User:public Guest
{
private:
	int mTuoi;
	DS_HoaDon hd_user;
protected:
	string mTen;
	string mPass;
public:
	User();
	~User();
	void setTenUser(string ten);
	void setTuoiUser(int t);
	void setPassUser(string pass);
	string getTenUser();
	int getTuoiUser();
	string getPassUser();
	DS_HoaDon muaSach(ListBook& l);
	void upDateHoaDon(DS_HoaDon& a);
};


#endif // !_USER_H_


