#pragma once
class Predmet
{
private:
	char naziv[30];
	int ECTS, ocjena;
	bool prijavljen;
public:
	Predmet();
	void setNaziv();
	void setECTS();
	void setPrijavljen();

	char* getNaziv();
	int getECTS();
	bool getPrijavljen();

	void setPredmet();
	~Predmet() = default;
};
