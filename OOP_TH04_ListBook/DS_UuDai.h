#ifndef _DS_UUDAI_H_
#define _DS_UUDAI_H_
#include"UuDai_Sach.h"
#include"UuDai_Tuoi.h"

class DS_UuDai
{
private:
	vector<UuDai*> dsuudai;
public:
	DS_UuDai(){}
	~DS_UuDai(){}

	void xemDanhSachUudai();
	int getUuDai(ListBook&lb);

	void addUuDai(ListBook& lb);

	void writeDownUuDaiToFile();

	void push_UuDai(UuDai* ud);

	int xoaUuDai();


	UuDai* timUUDaiTheoSach(string name);
};

#endif