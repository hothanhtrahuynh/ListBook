#define _CRT_SECURE_NO_WARNINGS
#define _CRT_SECURE_NO_WARNINGS
#ifndef DS_MESSAGE_H_
#define DS_MESSAGE_H_

#include<vector>
#include<fstream>
#include"Message.h"
class DS_Message
{
private:
	vector<Message> dstn;
public:
	DS_Message()
	{

	}
	~DS_Message()
	{

	}
	int freadMessageFromFile(string tenfile);
	void xuatDsTinNhan();
	vector<Message> getDsTinNhan();

};
#endif // !DS_MESSAGE_H_



