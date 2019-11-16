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
	
	Sach *a;
	do
	{
		cin.ignore();
		cout << "Ten sach can tim la: "; getline(cin, ten);
		a = l.timSach_Ten(ten);
		if (a == NULL)
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
	
	cout << *a << endl;;
}


