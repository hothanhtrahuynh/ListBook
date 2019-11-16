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

int printMenu();
void getAccount(string& ten, string& pass);
string lognIn(string &ten, string& pass);
void funRun(ListBook& lb);


#endif
