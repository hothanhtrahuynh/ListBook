#include "Message.h"

Message::Message(const Message& a)
{
	senderAccount_name = a.senderAccount_name;
	text = a.text;
}

void Message::setname_account(string name)
{
	senderAccount_name = name;
}

void Message::setText(string text)
{
	this->text = text;
}

string Message::getNameAcoount()
{
	return senderAccount_name;
}

string Message::getText()
{
	return text;
}

ostream& operator<<(ostream& out, Message& tn)
{
	out <<tn.nameclass<< tn.senderAccount_name << " : " << tn.text << endl;
	return out;
	// TODO: insert return statement here
}
