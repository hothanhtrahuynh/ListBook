#ifndef _UUDAISACH_H_
#define _UUDAISACH_H_
#include "UuDai.h"
class UuDai_Sach :
	public UuDai
{
private:
	string tensach;
	Sach* sach;
public:
	UuDai_Sach() {};
	UuDai_Sach(string tensach, int uudai)
	{
		this->tensach = tensach;
		mucUuDai = uudai;
	}
	UuDai_Sach(Sach* a,int uudai)
	{
		sach = a;
		tensach = a->getTenSach();
		mucUuDai = uudai;
	}
	UuDai_Sach(const UuDai_Sach& a)
	{
		sach = a.sach;
	}
	void setSachUuDai(string tensach);

	void getData_UuDai_Sach(ListBook&lb);

	virtual int getTuoiUuDai();
	virtual Sach* getSachUuDai();
	virtual void getData_UuDai(ListBook& lb);
	virtual void print();
	virtual string nameclass();
	virtual void fwriteDownFile(fstream& f);


	string getTenSachUuDai();
	~UuDai_Sach();
};

#endif