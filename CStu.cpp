
#include <iostream>
#include <string>
#include "CStu.h"
using namespace std;

// ѧ��Ĭ��id��-1��˵������ʱ��һ����Ч��ѧ����
CStu::CStu() { this->id = -1; }
CStu::~CStu() {}

 
int CStu::getId() const { return id; }
void CStu::setId(int val) { id = val; }

std::string CStu::getName() const { return name; }
void CStu::setName(std::string val) { name = val; }


int CStu::getAge() const { return age; }
void CStu::setAge(int val) { age = val; }


std::ostream& operator<<(std::ostream& os, CStu& stu) {

	// �����ʱ��ǧ��Ҫ��,Ҳ�����ȥ����Ȼ�����ʱ�򣬷ǳ����ý����-_-!
	// ss >> x; ��ʧ�ܣ����ж��ţ���
// 	os<<"id: "<<stu.getId()<<", name: "<<stu.getName()<<", age: "
// 		<<stu.getAge();

	os << stu.getId() << "     " << stu.getName() << "     " << stu.getAge();

	return os;
}

std::istream& operator>>(std::istream& is, CStu& stu) {
	is >> stu.id >> stu.name >> stu.age;
	return is;
}
