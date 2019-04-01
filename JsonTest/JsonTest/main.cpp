#include <iostream>
#include <fstream>
#include <string>
#include "head.h"
#include "include/json/json.h"

using namespace std;

MyClass::MyClass()
{
	m_iCount = 0;

}

MyClass::~MyClass()
{
}

void MyClass::Start()
{
	m_iCount++;
	writeFile("first.txt");
	m_iCount++;
	writeFile("second.txt");
}

void MyClass::writeFile(string str)
{
	Json::StyledWriter styleWriter;

	//cout << m_iCount << endl;

	int index = m_iCount - 1;
	m_value["item"][index] = str;

	ofstream ofs("jsonTest.json", ios::out);
	if (ofs)
	{
		ofs << styleWriter.write(m_value);
		ofs.close();
	}
	else
	{
		cout << "Open File Error" << endl;
	}
}

void MyClass::readFile()
{
	Json::Reader reader;
	Json::Value vData;
	//Json::Value vArr;
	ifstream ifs("jsonTest.json", ios::in);
	if (ifs)
	{
		reader.parse(ifs, vData);
		//cout << vData["item"].size() << endl;
		//cout << vData["item"][0]["first"] << endl;
		//cout << vData["item"][1]["second"] << endl;

		for (int i = 0; i < vData["item"].size(); i++)
		{
			string sDelStr = vData["item"][i].asString();
			cout << sDelStr << endl;
			remove(sDelStr.c_str());
		}
		ifs.close();
		//remove("jsonTest.json");
	}
	else
	{
		cout << "Open File Error" << endl;
	}
	
}

int main()
{
	MyClass obj;
	obj.Start();
	obj.readFile();

	system("pause");
	return 0;
}
