
#include <iostream>
#include <string>
#include "CStu.h"
using namespace std;

// 学生默认id是-1，说明这暂时是一个无效的学生。
CStu::CStu() { this->id = -1; }
CStu::~CStu() {}

 
int CStu::getId() const { return id; }
void CStu::setId(int val) { id = val; }

std::string CStu::getName() const { return name; }
void CStu::setName(std::string val) { name = val; }


int CStu::getAge() const { return age; }
void CStu::setAge(int val) { age = val; }


std::ostream& operator<<(std::ostream& os, CStu& stu) {

	// 保存的时候，千万不要把,也保存进去！不然输入的时候，非常不好解决！-_-!
	// ss >> x; 会失败！！有逗号！！
// 	os<<"id: "<<stu.getId()<<", name: "<<stu.getName()<<", age: "
// 		<<stu.getAge();

	os << stu.getId() << "     " << stu.getName() << "     " << stu.getAge();

	return os;
}

std::istream& operator>>(std::istream& is, CStu& stu) {
	is >> stu.id >> stu.name >> stu.age;
	return is;
}
