
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

// 增
CStu CStuMg::addAStu(std::map<int, CStu>& m1, CStu& stu) {
	// 先假设id可以重复了
	m1.insert(make_pair(stu.getId(),stu));  //insert插入学生信息到map

	return stu;
}

// 删（按id删除）
bool CStuMg::deleteStuById(std::map<int, CStu>& m1, const int& id) {

	bool b= false;

	map<int, CStu> ::iterator iter;
	iter = m1.find(id); 
	if (iter != m1.end())  //找到了对应id的元素
	{
		m1.erase(iter);
		b = true; // 删除成功
	}

	return b;
}

// 改
CStu CStuMg::updateStu(std::map<int, CStu>& m1, const CStu& cStu) {

	CStu stu;
	int id = cStu.getId();

	map<int, CStu> ::iterator iter;
	iter = m1.find(id);
	if (iter != m1.end())
	{
		// 修改
		iter->second = cStu;
		stu = cStu; // 把修改后的对象，赋值，再返回上层
	}

	return stu;

}

// 查 by id
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

	//fstream ofs(pathName,ios::out+ios::binary); // 为什么不是以binary保存？
	fstream ofs(pathName, ios::out);
	if (ofs) {
		stringstream ss;

		cout << "文件打开" << endl;

		CStu stu;
		for (auto p = m1.begin(); p != m1.end(); p++)
		{
			stu = p->second;
			ss << stu << endl;
		}

		ofs << ss.str(); // 注意，输出一定是 ss.str();

		ofs.close();
	}
	else
	{
		cout << "文件打开失败" << endl;
		b = false;
	}

	return b;

}
// read from file
bool CStuMg::readFromFile(std::map<int, CStu>& m1, std::string path) {
	
	bool b = true;
	m1.clear(); // 清掉原来的

	fstream ifs(path, ios::in);
	if (ifs) {
		cout << "文件打开" << endl;
		string s;
		stringstream ss;
		while (getline(ifs, s)) // 怎么一行行地读取？
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
		cout << "文件打开失败" << endl;
		b = false;
	}

	return b;

}
