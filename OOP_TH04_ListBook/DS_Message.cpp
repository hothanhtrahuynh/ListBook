#include "DS_Message.h"

int DS_Message::freadMessageFromFile(string tenfile)
{
	fstream f(tenfile);
	if (f.fail()) { cout << "Khong mo duoc file de doc tin nhan." << endl; return-1; }
	while (!f.eof())
	{
		string name_account, text;
		char a[501];
		f.getline(a, 500);
		string check(a);
		if (check == "") break;
		char* p = NULL;
		p = strtok(a, "\t");
		string type_account(p);
		for (int i = 1; i < 3; i++)
		{
			p = strtok(NULL, "\t");
			if (p == NULL) continue;
			if (i == 1) {
				string temp_name_account(p); name_account = temp_name_account;
			}
			if (i == 2) {
				string temp_text(p); text = temp_text;
			}

		}
		Message temp(name_account, text, type_account);
		dstn.push_back(temp);
	}
	f.close();
	return 1;
}

void DS_Message::xuatDsTinNhan()
{
	for (int i = 0; i < dstn.size(); i++)
	{
		cout << dstn[i];
	}
}

vector<Message> DS_Message::getDsTinNhan()
{
	return dstn;
}
