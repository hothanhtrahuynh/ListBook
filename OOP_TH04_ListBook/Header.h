#define _CRT_SECURE_NO_WARNINGS
#define _CRT_SECURE_NO_WARNINGS
#ifndef _HEADER_H_
#define _HEADER_H_

#include<string>
#include<iostream>
using namespace std;
#include"ListBook.h"
#include"NXB.h"
#include"TacGia.h"
#include"Admin.h"
#include"User.h"
#include"Guest.h"
#include"DS_UuDai.h"

class Manager
{
private:
	ListBook lb;
	DS_UuDai dsud;
public:
	Manager() {};
	~Manager() {};
	int printMenu();
	//Đọc danh sách ưu đãi từ file.
	int getUuDai();
	

	string lognIn(string& ten, string& pass, int& tuoi);
	void funRun();



	void freadUserManual();
	void writeDownNewAccount(Account* p);


};

void getAccount(string& ten, string& pass);


#endif
