#include "Guest.h"



Guest::Guest()
{
}


Guest::~Guest()
{
}

void Guest::timSach(ListBook& l)
{
	string ten;
	cout << "Ten sach can tim la: "; cin >> ten;
	Sach a;
	do
	{
		a = *l.timSach_Ten(ten);
		if (a.getGiaSach() == -1)
		{
			cout << "Khong co sach voi ten vua nhap." << endl;
			cout << "Tiep tuc tim sach." << endl;
			cout << "Tiep tuc(1) - Ngung (0)." << endl;
			int lenh;
			cin >> lenh;
			if (lenh != 1) return;
		}
		else break;
	} while (true);
	
	cout << a << endl;;
}


