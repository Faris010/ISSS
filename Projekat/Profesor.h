#pragma once
#include <string>

class Profesor
{
private:
	char ime[20], prezime[20], password[10];
public:
	Profesor();
	void setIme();
	void setPrezime();
	char* getIme();
	char* getPrezime();
	void ispisiStudente();
	void unosOcjene();
	void setPassword();
	char* getPassword();
	~Profesor() = default;
};
