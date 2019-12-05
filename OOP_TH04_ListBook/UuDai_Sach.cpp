#include "UuDai_Sach.h"

void UuDai_Sach::setSachUuDai(string tensach)
{
	this->tensach = tensach;
}

void UuDai_Sach::getData_UuDai_Sach(ListBook& lb)
{
	this->sach = lb.timSach_Ten(tensach);
}

void UuDai_Sach::getData_UuDai(ListBook& lb)
{
	this->sach = lb.timSach_Ten(tensach);
}

void UuDai_Sach::print()
{
	cout << sach->getTenSach()<< " giam " << mucUuDai << " %";
}

string UuDai_Sach::nameclass()
{
	return "UuDai_Sach";
}

void UuDai_Sach::fwriteDownFile(fstream& f)
{
	f << this->nameclass()<<"\t"<<sach->getTenSach() << "\t" << mucUuDai << "\n";
}

string UuDai_Sach::getTenSachUuDai()
{
	return tensach;
}

UuDai_Sach::~UuDai_Sach()
{
}
