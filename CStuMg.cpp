
#include <iostream>
#include <fstream>
#include <string>
#include <map>
#include <sstream>
#include "CStu.h"
#include "CStuMg.h"


using namespace std;

CStuMg::CStuMg() {}
CStuMg::~CStuMg() {}

// ��
CStu CStuMg::addAStu(std::map<int, CStu>& m1, CStu& stu) {
	// �ȼ���id�����ظ���
	m1.insert(make_pair(stu.getId(),stu));  //insert����ѧ����Ϣ��map

	return stu;
}

// ɾ����idɾ����
bool CStuMg::deleteStuById(std::map<int, CStu>& m1, const int& id) {

	bool b= false;

	map<int, CStu> ::iterator iter;
	iter = m1.find(id); 
	if (iter != m1.end())  //�ҵ��˶�Ӧid��Ԫ��
	{
		m1.erase(iter);
		b = true; // ɾ���ɹ�
	}

	return b;
}

// ��
CStu CStuMg::updateStu(std::map<int, CStu>& m1, const CStu& cStu) {

	CStu stu;
	int id = cStu.getId();

	map<int, CStu> ::iterator iter;
	iter = m1.find(id);
	if (iter != m1.end())
	{
		// �޸�
		iter->second = cStu;
		stu = cStu; // ���޸ĺ�Ķ��󣬸�ֵ���ٷ����ϲ�
	}

	return stu;

}

// �� by id
CStu CStuMg::findById(const std::map<int, CStu>& m1, const int& id) const {

	CStu stu;

	map<int, CStu> ::const_iterator iter;
	iter = m1.find(id);
	if (iter != m1.end())
	{
		stu = iter->second;
	}

	return stu;

}

// showAll
void CStuMg::showAll(const std::map<int, CStu>& m1) const {

	for (auto p : m1)
	{
		cout << p.second << endl;
	}
		
}

// save to file
bool CStuMg::saveToFile(const std::map <int, CStu>& m1, const std::string& pathName) const {


	bool b = true;

	//fstream ofs(pathName,ios::out+ios::binary); // Ϊʲô������binary���棿
	fstream ofs(pathName, ios::out);
	if (ofs) {
		stringstream ss;

		cout << "�ļ���" << endl;

		CStu stu;
		for (auto p = m1.begin(); p != m1.end(); p++)
		{
			stu = p->second;
			ss << stu << endl;
		}

		ofs << ss.str(); // ע�⣬���һ���� ss.str();

		ofs.close();
	}
	else
	{
		cout << "�ļ���ʧ��" << endl;
		b = false;
	}

	return b;

}
// read from file
bool CStuMg::readFromFile(std::map<int, CStu>& m1, std::string path) {
	
	bool b = true;
	m1.clear(); // ���ԭ����

	fstream ifs(path, ios::in);
	if (ifs) {
		cout << "�ļ���" << endl;
		string s;
		stringstream ss;
		while (getline(ifs, s)) // ��ôһ���еض�ȡ��
		{
			CStu cStu;
			ss << s;
			// cout<<ss.str();
			ss >> cStu;
			ss.clear();

			m1.insert(make_pair(cStu.getId(), cStu));

		}

		ifs.close();

	}
	else {
		cout << "�ļ���ʧ��" << endl;
		b = false;
	}

	return b;

}
