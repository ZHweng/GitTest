/*JsonCpp�����÷�*/
#include <iostream>
#include <fstream>
#include <string>
#include "json/json.h"

using namespace std;

int main()
{
	const char* age = 0;		//ע���ʼ��
	Json::Value root;
	Json::FastWriter fast_writer;
	Json::StyledWriter style_writer;
	Json::StyledStreamWriter stream_writer;
	Json::Reader reader;
	Json::Value json_object;

	root["null"] = NULL;			// ע��˴����������ʾΪ0������null
	root["message"] = "OK";
	root["age"] = 52;
	root["array"].append("arr");	// �½�һ��keyΪarray������Ϊ���飬�Ե�һ��Ԫ�ظ�ֵΪ�ַ�����arr��
	root["array"].append(123);		// Ϊ���� key_array ��ֵ���Եڶ���Ԫ�ظ�ֵΪ��1234

	Json::ValueType type = root.type();				//root������

	cout << root.toStyledString() << endl;			//��ʽ�����
	cout << "root_type��" <<type << endl;			//����Ϊ7����Ϊ����Ϊ����

	/*д�������ļ�*/
	cout << "���������" << endl;
	string str = fast_writer.write(root);
	cout << str << endl;		//�������,������
	ofstream ofs("fast_writer.json");
	ofs << str;
	ofs.close();

	cout << "��ʽ�������" << endl;
	str = style_writer.write(root);
	cout << str << endl;		//��ʽ��������Ű���
	ofs.open("style_writer.json");
	ofs << str;
	ofs.close();

	/*���ַ�������*/
	//const char* json_document = "{\"age\" : 12, \"name\" : \"weng\"}";
	string json_document = "{\"age\" : 123, \"name\" : \"weng\"}";
	if (!reader.parse(json_document, json_object)){
		cout << "error" << endl;
		return 0;
	}
	else{
		cout <<"age:" <<json_object["age"] << " name" << json_object["name"] << endl;
	}
	
	/*���ļ�����*/
	ifstream ifs("E:\\demo\\JsonTest\\JsonTest\\example.json", ios::binary);
	if (!reader.parse(ifs, json_object)){
		cout << "open error" << endl;
		ifs.close();
	}else{
		cout << "�ļ������" << endl;
		cout << "encoding:" << json_object["encoding"].asString() << endl;
		cout << "age:" <<json_object["age"].asInt() << endl;
		int num = json_object["plug"].size();
		for (int i = 0; i < num; i++){
			cout << json_object["plug"][i].asString() << " ";
		}
		cout<< endl << "null:" << json_object["null"] << " ";
		ifs.close();
		cout << endl;
	}

	/*�ж�key�Ƿ����*/
	bool is_age =  root.isMember("age");
	cout << "�Ƿ����key��" << endl;
	cout << "isMember:" <<is_age << endl;

	/*�ж��Ƿ�Ϊnull*/
	cout << "�Ƿ�Ϊnull��" << endl;
	bool is_null = root["null"].isNull();			// ע��˴�����ֵΪ0������null
	cout << "is_null:" << is_null << endl;
	bool isNull = json_object["null"].isNull();
	cout << "isNull:" << isNull << endl;

	/*�õ����е�key*/
	for (auto elem : root.getMemberNames()){
		cout << elem << " ";
	}
	cout << endl;

	/*ɾ����Ա*/
	cout << "remove_age:" << root.removeMember("age") << endl;

	system("pause");
	return 0;
}