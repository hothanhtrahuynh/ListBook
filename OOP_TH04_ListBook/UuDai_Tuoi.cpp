#include "UuDai_Tuoi.h"

int UuDai_Tuoi::getTuoiUuDai()
{
	return soTuoi;
}

Sach* UuDai_Tuoi::getSachUuDai()
{
	return nullptr;
}

void UuDai_Tuoi::getData_UuDai(ListBook& lb)
{
}

void UuDai_Tuoi::print()
{
	cout << soTuoi << " tuoi --> giam " << mucUuDai << " %";
}

string UuDai_Tuoi::nameclass()
{
	return "UuDai_Tuoi";
}

void UuDai_Tuoi::fwriteDownFile(fstream& f)
{
	f << this->nameclass() << "\t" << this->soTuoi << "\t" << mucUuDai << "\n";
}
