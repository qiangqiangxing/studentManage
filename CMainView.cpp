
#include <iostream>
#include <map>
#include <string>
#include "CStu.h"
#include "CStuMg.h"
#include "CMainView.h"

using namespace std;

CMainView::CMainView() {}
CMainView::~CMainView() {}

/* 欢迎 */
void CMainView::welcome() {
	system("cls");
	std::cout << "欢迎来到xxx大系统" << std::endl;

}

/* 显示菜单 */
void CMainView::showMenu() {
	std::cout << "\n";
	std::cout << "操作步骤" << std::endl;

	std::cout << "1. 录入" << std::endl;
	std::cout << "2. 修改" << std::endl;
	std::cout << "3. 查找" << std::endl;
	std::cout << "4. 删除" << std::endl;
	std::cout << "5. 显示所有" << std::endl;
	std::cout << "6. 保存至文件" << std::endl;
	std::cout << "7. 从文件导入" << std::endl;
	std::cout << "0. 退出" << std::endl;
	std::cout << "\n";	

	std::cout << "\n";
	std::cout << "请选择操作(选择1~7)：";

}

/* view 显示所有学生 */
void CMainView::showAllStuAtView(const std::map<int, CStu>& stu_m1) {
	system("cls");
	std::cout << "id    |" << "name  |" << "age" << std::endl;
	CStuMg cStuMg;
	cStuMg.showAll(stu_m1);

	system("pause");
	system("cls");
	welcome();
	showMenu();		
}
/* view层 添加一个学生 */
void CMainView::addStuAtView(std::map<int, CStu>& stu_m1) {
	CStuMg cStuMg;

	int id;
	std::string name;
	int age;
	CStu cStu;

	system("cls");

	std::cout << "录入\n";
	std::cout << "id:";
	std::cin >> id;

	std::cout << "name:";
	std::cin >> name;

	std::cout << "age:";
	std::cin >> age;

	cStu.setId(id);
	cStu.setName(name);
	cStu.setAge(age);

	// 保存
	cStuMg.addAStu(stu_m1, cStu);

	system("cls");
	welcome();
	showMenu();


}
/* view 查找一个学生 */
void CMainView::findStuAtView(const std::map<int, CStu>& m1){
	system("cls");
	std::cout << "请输入要查找学生的id" << std::endl;
	int id;
	std::cin >> id;

	CStuMg cStuMg;
	CStu cStu;
	cStu = cStuMg.findById(m1, id);

	if (cStu.getId() != -1)
	{
		std::cout << cStu << std::endl;
	}
	else
	{
		std::cout << "查无此人" << std::endl;
	}

	system("pause");
	system("cls");
	welcome();
	showMenu();

}
/* view层删除一个学生 */
void CMainView::deleteByIdAtView(std::map<int, CStu>& v1) {
	system("cls");
	std::cout << "请输入要删除的学生的id" << std::endl;
	int id;
	std::cin >> id;

	CStuMg cStuMg;
	bool b = cStuMg.deleteStuById(v1, id);

	if (b)
	{
		std::cout << "删除成功" << std::endl;
	}
	else {
		std::cout << "查无此人" << std::endl;
	}

	system("pause");
	system("cls");
	welcome();
	showMenu();

}
/* view层 更新一个学生 */
void CMainView::updateByIdAtView(std::map<int, CStu>& m1) {
	system("cls");

	std::cout << "请输入要修改的学生的id" << std::endl;
	int id;
	std::cin >> id;
	std::string name;

	std::cout << "name:";
	std::cin >> name;

	int age;
	std::cout << "age:";
	std::cin >> age;

	CStu cStu;
	cStu.setId(id);
	cStu.setName(name);
	cStu.setAge(age);

	CStuMg cStuMg;

	CStu cStu2 = cStuMg.updateStu(m1, cStu);

	if (cStu2.getId() != -1)
	{
		std::cout << cStu2 << std::endl;
		std::cout << "修改成功" << std::endl;
	}
	else
	{
		std::cout << "查无此人" << std::endl;
	}

	system("pause");
	system("cls");
	welcome();
	showMenu();

}

/* view层 把map保存进文件 */
void CMainView::saveToFileAtView(const std::map<int, CStu>& m1, std::string pathName) {
	if (m1.begin() == m1.end()) {   //map为空
		system("cls");
		std::cout << "还没有任何学生信息，无法保存" << std::endl;
	}
	else {
		// 保存
		CStuMg cStuMg;
		bool b = cStuMg.saveToFile(m1, pathName);
		if (b) {
			system("cls");
			std::cout << "保存成功" << std::endl;
		}
		else {
			std::cout << "保存失败" << std::endl;
		}
	}

	system("pause");
	system("cls");
	welcome();
	showMenu();

}

/* view层 把文件中的东西导入 map */
void CMainView::readFromFileAtView(std::map<int, CStu>& m, std::string pathName) {
	system("cls");

	CStuMg cStuMg;
	bool b = cStuMg.readFromFile(m, pathName);
	if (b) {
		std::cout << "读取成功" << std::endl;
	}
	else {
		std::cout << "读取失败" << std::endl;
	}
	system("pause");
	system("cls");
	welcome();
	showMenu();	
}
