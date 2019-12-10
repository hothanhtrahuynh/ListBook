#define _CRT_SECURE_NO_WARNINGS
#define _CRT_SECURE_NO_WARNINGS
#ifndef _UUDAI_H_
#define _UUDAI_H_

//#include<iostream>
//#include<string>
//#include<fstream>
//using namespace std;
#include"ListBook.h"

class UuDai
{
protected:
	int mucUuDai;
public:
	UuDai() { mucUuDai = 0; };
	UuDai(int sale) { mucUuDai = sale; }
	void setMucUuDai(int sale);
	int getMucUuDai();


	virtual int getTuoiUuDai() = 0;
	virtual Sach* getSachUuDai() = 0;
	virtual string nameclass() = 0;
	virtual void getData_UuDai(ListBook& lb)=0;
	virtual void print() = 0;
	virtual void fwriteDownFile(fstream& f) = 0;
	~UuDai();
};

#endif // !_UUDAI_H_



