#include<string>
#include "SCP.h"

using namespace std;

SCP::SCP() {
	setCode("D-Class");
	setName("D-Boi");
}
SCP::SCP(string code, string name) {
	setCode(code);
	setName(name);
}
User::User(string code, string name) {
	setCode(code);
	setName(name);
}

void SCP::setCode(string code) {
	CODE = code;
}
string SCP::getCode() {
	return CODE;
}
void SCP::setName(string name) {
	NAME = name;
}
string SCP::getName() {
	return NAME;
}