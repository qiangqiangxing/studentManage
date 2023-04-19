#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <map>
#include "CStu.h"
#include "CStuMg.h"
#include "CMainView.h"

using namespace std;

int main() {

	//string pathName = "D:\Coding\vs_sy\studentManagement\studentManage_STL_map\studentManage_STL_map\student_manegement.txt";
	string pathName = "./student_manegement.txt";
	//string pathName = "D:\student_manegement.txt";

	map<int, CStu> stu_v1;

	CMainView cView;

	cView.welcome();
	cView.showMenu();

	string operateType;
	cin >> operateType;

	while (operateType != "0")
	{
		if (operateType == "1") {// 录入
			cView.addStuAtView(stu_v1);
		}
		else if (operateType == "2") { // 修改
			cView.updateByIdAtView(stu_v1);
		}
		else if (operateType == "3") { // 查找
			cView.findStuAtView(stu_v1);
		}
		else if (operateType == "4") {
			cView.deleteByIdAtView(stu_v1);
		}
		else if (operateType == "5") { // 显示所有
			cView.showAllStuAtView(stu_v1);
		}
		else if (operateType == "6") {  // 保存至文件
			cView.saveToFileAtView(stu_v1, pathName);
		}
		else if (operateType == "7") {// 从文件读取
			cView.readFromFileAtView(stu_v1, pathName);
		}
		else {

			cView.welcome();
			cView.showMenu();
		}

		cin >> operateType;
	}

	return 0;
}
