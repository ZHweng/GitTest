#include <iostream>
#include <string>
#include "include/json/json.h"

using namespace std;

class MyClass
{
public:
	MyClass();
	~MyClass();
	void Start();
	void writeFile(string str);
	void readFile();

private:
	Json::Value m_value;
	int m_iCount;
};

