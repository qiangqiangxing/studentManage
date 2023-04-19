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

	// Ôö
	CStu addAStu(std::map<int, CStu>& m1, CStu& stu);

	// É¾
	bool deleteStuById(std::map<int, CStu>& m1, const int& id);

	// ¸Ä
	CStu updateStu(std::map<int, CStu>& m1, const CStu& stu);

	// ²é by id
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
