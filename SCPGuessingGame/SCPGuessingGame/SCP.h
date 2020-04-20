#pragma once
#include<string>

using namespace std;

class SCP {
public:
	SCP();
	SCP(string code, string name);

	void setCode(string code);
	string getCode();
	void setName(string name);
	string getName();
private:
	string CODE;
	string NAME;
};

class User : public SCP {
public:
	User(string code, string name);
private:
};