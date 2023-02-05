#pragma once
#include <istream>

#include "Profesor.h"
#include "Student.h"
class Admin
{
private:
	char user[10], password[10];
	Student s;
	Profesor p;
public:
	Admin();

	friend std::istream& operator>>(std::istream& stream, Admin& a);
	friend std::ostream& operator<<(std::ostream& stream, Admin& a);
	void setProfesor();
	void getProfesor();

	~Admin() = default;
};
