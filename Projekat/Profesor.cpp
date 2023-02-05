#include "Profesor.h"

#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>


Profesor::Profesor()
{
	strcpy_s(this->ime, "Ime");
	strcpy_s(this->prezime, "Prezime");
}

void Profesor::setIme()
{
	std::cout << "Unesite ime profesora: ";
	std::cin.getline(this->ime, 20);
}

void Profesor::setPrezime()
{
	std::cout << "Unesite prezime profesora: ";
	std::cin.getline(this->prezime, 20);
}

char* Profesor::getIme()
{
	return this->ime;
}

char* Profesor::getPrezime()
{
	return this->prezime;
}

void Profesor::ispisiStudente()
{
	char naziv[20];
	std::cout << "Unesite predmet: ";
	std::cin.getline(naziv, 20);
	std::string str, index, predmet, ects, ocjena, line;
	int ocjenaInt, br = 0;
	std::ifstream file("Student_predmeti.txt");
	std::ifstream data("Student.txt");
	file >> index;
	data >> str;
	while (true)
	{
		if (file.eof())
		{
			break;
		}
		for (int i = 0; i < 5; i++)
		{
			file >> predmet;
			file >> ects;
			file >> ocjena;
			if (predmet == naziv)
			{
				ocjenaInt = stoi(ocjena);
				if (ocjenaInt == 5)
				{
					while (true)
					{
						if (str == index)
						{
							std::getline(data, line);
							std::cout << index;
							std::cout << line << std::endl;
							data >> str;
							br++;
							break;
						}
						break;
					}
				}
			}
		}
		std::getline(data, line);
		data >> str;
		file >> index;
	}
	data.close();
	file.close();
	if (br == 0)
	{
		std::cout << "Nema studenata!" << std::endl;
	}
}

void Profesor::unosOcjene()
{
	char naziv[20];
	std::cout << "Unesite predmet: ";
	std::cin.getline(naziv, 20);
	std::string str;
	std::string index;
	std::string predmet;
	std::string ects;
	std::string ocjena;
	std::string line;
	int ocjenaInt, br = 0;
	std::ifstream file("Student_predmeti.txt");
	std::ifstream data("Student.txt");
	file >> index;
	data >> str;
	while (true)
	{
		if (file.eof())
		{
			break;
		}
		for (int i = 0; i < 5; i++)
		{
			file >> predmet;
			file >> ects;
			file >> ocjena;
			if (predmet == naziv)
			{
				ocjenaInt = stoi(ocjena);
				if (ocjenaInt == 5)
				{
					while (true)
					{
						if (str == index)
						{
							std::getline(data, line);
							std::cout << index;
							std::cout << line << std::endl;
							data >> str;
							br++;
							break;
						}
					}
				}
			}
		}
		std::getline(data, line);
		data >> str;
		file >> index;
	}
	data.close();
	file.close();
	if (br == 0)
	{
		std::cout << "Nema studenata!" << std::endl;
	}
	else
	{
		int indeks, ocjenaUnos;
		std::cout << "Unesite index studenta: ";
		std::cin >> indeks;
		std::cin.ignore();
		do
		{
			std::cout << "Unesite ocjenu: ";
			std::cin >> ocjenaUnos;
			std::cin.ignore();
		} while (ocjenaUnos < 6 || ocjenaUnos > 10);
		std::ifstream fajl("Student_predmeti.txt");
		std::ofstream fajla("Student_predmeti1.txt");
		fajl >> index;
		while (true)
		{
			if (fajl.eof())
			{
				break;
			}
			fajla << index << "\n";
			for (int i = 0; i < 5; i++)
			{
				fajl >> predmet;
				fajl >> ects;
				fajl >> ocjena;
				if (index == std::to_string(indeks))
				{
					if (predmet == naziv)
					{
						ocjena = std::to_string(ocjenaUnos);
						fajla << std::setw(5) << std::left << predmet << std::setw(3) << std::left << ects
							<< std::setw(3) << std::left << ocjena << "\n";

					}
					else
					{
						fajla << std::setw(5) << std::left << predmet << std::setw(3) << std::left << ects
							<< std::setw(3) << std::left << ocjena << "\n";
					}
				}
				else
				{
					fajla << std::setw(5) << std::left << predmet << std::setw(3) << std::left << ects
						<< std::setw(3) << std::left << ocjena << "\n";
				}

			}
			fajl >> index;
		}
		fajla.close();
		fajl.close();
		std::string lajn;
		std::ifstream dat("Student_predmeti1.txt");
		std::ofstream datoteka("Student_predmeti.txt");
		while (true)
		{
			if (dat.eof())
			{
				break;
			}
			std::getline(dat, lajn);
			datoteka << lajn << std::endl;
		}
		datoteka.close();
		dat.close();
	}
}

void Profesor::setPassword()
{
	std::cout << "Password: ";
	std::cin.getline(this->password, 10);
}

char* Profesor::getPassword()
{
	return this->password;
}
