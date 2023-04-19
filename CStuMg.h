#ifndef C_STUDENT_MG_H
#define C_STUDENT_MG_H
#include "CStu.h"
#include <map>
#include <string>

class CStuMg
{
public:
	CStuMg();
	~CStuMg();

	// ��
	CStu addAStu(std::map<int, CStu>& m1, CStu& stu);

	// ɾ
	bool deleteStuById(std::map<int, CStu>& m1, const int& id);

	// ��
	CStu updateStu(std::map<int, CStu>& m1, const CStu& stu);

	// �� by id
	CStu findById(const std::map<int, CStu>& m1, const int& id) const;


	// showAll
	void showAll(const std::map<int, CStu>& m1) const;

	// save to file
	bool saveToFile(const std::map <int, CStu>& m1, const std::string& pathName) const;

	// read from file
	bool readFromFile(std::map<int, CStu>& m1, std::string path);


private:

};
#endif
