#ifndef _UUDAITUOI_H_
#define _UUDAITUOI_H_

#include "UuDai.h"
class UuDai_Tuoi :
	public UuDai
{
private:
	int soTuoi;
public:
	UuDai_Tuoi() { soTuoi = 0; }
	UuDai_Tuoi(int tuoi) { soTuoi = tuoi; }
	UuDai_Tuoi(int tuoi, int sale)
	{
		soTuoi = tuoi;
		mucUuDai = sale;
	}

	virtual void getData_UuDai(ListBook& lb);
	virtual void print();
	virtual string nameclass();
	virtual void fwriteDownFile(fstream& f);
	~UuDai_Tuoi() {}

};
#endif
