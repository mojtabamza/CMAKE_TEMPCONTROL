#pragma once

#include <iostream>
#include <string>
using std::string;
using std::cout;
using std::endl;

class GUI { //this class can be defined as a singleton class as we need just one onject of that
public:
	GUI() {}
	inline void printData(string data) { cout << data << endl; } //print data in consule, LCD, put that on serial buffer
	inline char scanKeypad(void) {}
	inline bool checkNewData(void) {}

};


