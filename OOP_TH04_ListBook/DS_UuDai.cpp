#include "DS_UuDai.h"

void DS_UuDai::xemDanhSachUudai()
{
	cout << "======================" << endl;
	cout << "|| DANH SACH UU DAI ||" << endl;
	cout << "======================" << endl;
	for (int i = 0; i < dsuudai.size(); i++)
	{
		cout << "1.";
		dsuudai[i]->print();
		cout << endl;
	}
	cout << "======================" << endl;
}

int DS_UuDai::getUuDai(ListBook& lb)
{

	fstream f("UuDai.txt");
	if (f.fail())
	{
		cout << "Khong mo duoc file Uudai." << endl;
		return -1;
	}
	char a[256];
	while (!f.eof())
	{

		f.getline(a, 255);
		char c[5] = "\t";
		char* p = NULL;
		p = strtok(a, c);
		if (p == NULL) continue;
		string type(p);
		string tensach;
		int tuoi, mucuudai;
		for (int i = 0; i <= 1; i++)
		{

			p = strtok(NULL, c);
			if (p == NULL) continue;
			switch (i)
			{
			case 0:
			{
				if (type == "UuDai_Sach")
				{
					string temp(p);
					tensach = temp;
				}
				else
				{
					string temp(p);
					tuoi = stoi(temp);
				}

			}break;
			case 1:
			{
				string temp(p);
				mucuudai = stoi(temp);
			}break;
			}

		}
		if (type == "UuDai_Sach")
		{
			UuDai* ud = new UuDai_Sach(tensach, mucuudai);
			ud->getData_UuDai(lb);
			dsuudai.push_back(ud);
		}
		if (type == "UuDai_Tuoi")
		{
			UuDai* ud = new UuDai_Tuoi(tuoi, mucuudai);
			dsuudai.push_back(ud);
		}
	}

	return 1;
}

void DS_UuDai::addUuDai(ListBook& lb)
{
	string type;
	int uudai;
	cout << "Nhap vao loai uu dai muon khoi tao: ";
	cin >> type;
	if (type == "UuDai_Sach" || type == "Sach")
	{
		string tensach;
		cin.ignore();
		cout << "Nhap vao ten sach can them vao muc uu dai: ";
		getline(cin, tensach);
		Sach* a = lb.timSach_Ten(tensach);
		if (a == NULL)
		{
			cout << "Sach can them khong co trong thu vien sach." << endl;
			return;
		}
		cout << "Muc uu dai la: "; cin >> uudai;
		UuDai* ud = new UuDai_Sach(a, uudai);
		dsuudai.push_back(ud);
	}
	if (type == "UuDai_Tuoi" || type == "Tuoi")
	{
		int tuoi;
		cout << "Tuoi duoc nhan uu dai la: ";
		cin >> tuoi;
		cout << "Muc uu dai: ";
		cin >> uudai;
		UuDai* ud = new UuDai_Tuoi(tuoi, uudai);
		dsuudai.push_back(ud);
	}
	cout << "Them uu dai thanh cong." << endl;
}

void DS_UuDai::writeDownUuDaiToFile()
{
	fstream f("UuDai.txt");
	if (f.fail())
	{
		cout << "Khong mo duoc file Uudai." << endl;
		return;
	}
	for (int i = 0; i < dsuudai.size(); i++)
	{
		dsuudai[i]->fwriteDownFile(f);
	}
}

void DS_UuDai::push_UuDai(UuDai* ud)
{
	if (ud != NULL)
	dsuudai.push_back(ud);

}

int DS_UuDai::xoaUuDai()
{
	xemDanhSachUudai();
	int stt;
	cout << "Nhap vao thu tu uu dai muon xoa trong danh sach tren: ";
	cin >> stt;
	for (int i = 0; i < dsuudai.size(); i++)
	{
		if (stt == i + 1)
		{
			dsuudai.erase(dsuudai.begin() + i);
			cout << "Xoa thanh cong." << endl;
			return 1;
		}
	}
	cout << "Xoa that bai." << endl;
	return 0;
}
