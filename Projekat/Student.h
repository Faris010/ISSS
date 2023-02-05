#pragma once
#include <istream>

enum Semestar { prvi = 1, drugi, treci, cetvrti, peti, sesti };

class Student
{
private:
	char ime[20], prezime[20], JMBG[20], password[20];
	int index;
	Semestar semestar;

public:
	Student();

	void setIme();
	void setPrezime();
	void setJMBG();
	void setIndex();
	void setPassword();
	void setSemestar();

	char* getIme();
	char* getPrezime();
	char* getJMBG();
	int getIndex();
	char* getPassword();
	Semestar getSemestar();

	void ispisPolozenihIspita();
	void prijavaIspita();
	void prijavljeniIspiti();

	~Student() = default;
};

