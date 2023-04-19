
#ifndef C_STUDENT_H
#define C_STUDENT_H
#include <string>
#include <iostream>

class CStu{
	/* friend function */
	friend std::ostream& operator<<(std::ostream& os, CStu& stu);
	friend std::istream& operator>>(std::istream& is, CStu& stu);

public:
	CStu();
	~CStu();

	int getId() const;
	void setId(int val);

	std::string getName() const;
	void setName(std::string val);

	int getAge() const;
	void setAge(int val);


private:
	int id;
	std::string name;
	int age;

};
#endif

