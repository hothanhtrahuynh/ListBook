#ifndef _MESSAGE_H_
#define _MESSAGE_H_

#include<iostream>
#include<string>
using namespace std;

class Message
{
private:
	string senderAccount_name;
	string text;
	string nameclass;
public:
	Message() { senderAccount_name = "None"; text = ""; };
	Message(string &name, string &text,string nameclass)
	{
		senderAccount_name = name;
		this->text = text;
		this->nameclass = nameclass;
	}
	Message(const Message& a);

	void setname_account(string name);
	void setText(string text);

	string getNameAcoount();
	string getText();

	friend ostream& operator<<(ostream& out, Message& tn);
	~Message() {};

};


#endif // !_MESSAGE


