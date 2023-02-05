#include "Student.h"

#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>
#include <time.h>

Student::Student()
{
}

void Student::setIme()
{
	std::cout << "Unesi ime studenta: ";
	std::cin.getline(this->ime, 20);
}

void Student::setPrezime()
{
	std::cout << "Unesi prezime studenta: ";
	std::cin.getline(this->prezime, 20);
}

void Student::setJMBG()
{
	std::cout << "Unesi JMBG studenta: ";
	std::cin.getline(this->JMBG, 20);
}

void Student::setIndex()
{
	std::cout << "Unesite index: ";
	std::cin >> this->index;
	std::cin.ignore();
}

void Student::setPassword()
{
	std::cout << "Password: ";
	std::cin.getline(this->password, 10);
}

void Student::setSemestar()
{
	int a;
	std::cout << "Unesite semestar: ";
	std::cin >> a;
	std::cin.ignore();
	this->semestar = static_cast<Semestar>(a);
}

char* Student::getIme()
{
	return this->ime;
}

char* Student::getPrezime()
{
	return this->prezime;
}

char* Student::getJMBG()
{
	return this->JMBG;
}

int Student::getIndex()
{
	return this->index;
}

char* Student::getPassword()
{
	return this->password;
}

Semestar Student::getSemestar()
{
	return this->semestar;
}

void Student::ispisPolozenihIspita()
{
	int br = 0, ectsUkupno = 0, sum = 0;
	std::string index, indexa, predmet, ects, ocjena, login, ime, prezime, user, line, prof, profPrezime, str, line2;
	std::ifstream file("Student_login.txt");
	std::ifstream data("Student.txt");
	std::ifstream datoteka("Student_predmeti.txt");
	std::ifstream fajl("Profesor_login.txt");
	fajl >> prof;
	std::ifstream fajla("Profesor.txt");
	fajla >> profPrezime;
	fajla >> str;
	while (true)
	{
		if (fajla.eof())
		{
			break;
		}
		if (str == prof)
		{
			break;
		}
		getline(fajla, line2);
		fajla >> profPrezime;
		fajla >> str;
	}
	fajla.close();
	fajl.close();
	file >> login;
	while (true)
	{
		if (data.eof())
		{
			break;
		}
		data >> index >> ime >> prezime >> user;
		getline(data, line);
		if (user == login)
		{
			while (true)
			{
				if (datoteka.eof())
				{
					break;
				}
				datoteka >> indexa;
				if (indexa == index)
				{
					for (int i = 0; i < 5; i++)
					{
						datoteka >> predmet >> ects >> ocjena;
						if (stoi(ocjena) > 5)
						{
							ectsUkupno += stoi(ects);
							sum += stoi(ocjena);
							if (br == 0)
							{
								std::cout << std::setw(10) << std::left << "Predmet" << std::setw(5) << std::left << "ECTS"
									<< std::setw(10) << std::left << "Ocjena" << std::setw(10) << std::left << "Ocjenio" << std::endl;
								std::cout << "-----------------------------------------------------------\n";
							}
							std::cout << std::setw(10) << std::left << predmet << std::setw(5) << std::left << ects
								<< std::setw(10) << std::left << ocjena << std::left << prof << " " << profPrezime << std::endl;
							br++;
						}
					}
				}

			}
			datoteka.close();
		}
	}
	data.close();
	file.close();
	if (br == 0)
	{
		std::cout << "Nema polozenih ispita.\n";
	}
	else
	{
		std::cout << "\nProsjek ocjena: " << float(sum) / br;
		std::cout << "\nUkupno ECTS kredita: " << ectsUkupno << "\n";
		std::cout << "-----------------------------------------------------------\n";
	}
}

void Student::prijavaIspita()
{
	int br = 0;
	std::string index, indexa, indexb, predmet, ects, ocjena, login, ime, prezime, user, line;
	std::ifstream file("Student_login.txt");
	std::ifstream data("Student.txt");
	std::ifstream datoteka("Student_predmeti.txt");
	std::ofstream fajla("Ispiti.txt");
	file >> login;
	while (true)
	{
		if (data.eof())
		{
			break;
		}
		data >> index >> ime >> prezime >> user;
		getline(data, line);
		if (user == login)
		{
			while (true)
			{
				if (datoteka.eof())
				{
					break;
				}
				datoteka >> indexa;
				if (indexa == index)
				{
					indexb = indexa;
					datoteka >> predmet >> ects >> ocjena;
					for (int i = 0; i < 5; i++)
					{
						if (stoi(ocjena) == 5)
						{
							if (br == 0)
							{
								std::cout << std::setw(20) << std::left << "Linijska grupa" << std::setw(10) << std::left << "Ispit"
									<< std::setw(15) << std::left << "Datum" << std::setw(15) << std::left << "Status" << std::endl;
								std::cout << "-----------------------------------------------------------------------------------\n";
							}
							fajla << std::setw(20) << std::left << "Svi studenti" << std::setw(10) << std::left << predmet
								<< std::setw(15) << std::left << "07.02.2022." << std::setw(15) << std::left << "Otvoren za prijave" << std::endl;
							br++;
						}
						datoteka >> predmet >> ects >> ocjena;
					}
				}
			}
			fajla.close();
			datoteka.close();
		}
	}
	data.close();
	file.close();
	if (br == 0)
	{
		std::cout << "Nema ispita koji su otvoreni za prijavu i koje mozete prijaviti ili vec niste prijavili.\n";
	}
	else
	{
		char naziv[20], ch;
		std::string str;
		std::ifstream fajl("Ispiti.txt");
		while (true)
		{
			if (fajl.eof())
			{
				break;
			}
			getline(fajl, str);
			std::cout << str << std::endl;
		}
		std::ofstream dat("Prijavljeni_ispiti.txt");
		do
		{
			std::cout << "\nUnesite naziv ispita koji zelite prijaviti: ";
			std::cin.getline(naziv, 20);
			dat << std::setw(10) << std::left << naziv << std::setw(20) << std::left << "07.02.2022."
				<< std::setw(20) << std::left << "Otvoren za prijave" << std::endl;
			std::cout << "Da li zelite prijaviti jos jedan predmet (d/n): ";
			std::cin >> ch;
			std::cin.ignore();
		} while (ch != 'n');
		dat.close();
		fajl.close();
	}
}

void Student::prijavljeniIspiti()
{
	std::string line;
	std::cout << std::setw(10) << std::left << "Ispit" << std::setw(20) << std::left << "Datum"
		<< std::setw(15) << std::left << "Status" << std::endl;
	std::cout << "-----------------------------------------------------------------------------------\n";
	std::ifstream file("Prijavljeni_ispiti.txt");
	while (true)
	{
		if (file.eof())
		{
			break;
		}
		getline(file, line);
		std::cout << line << std::endl;
	}
	file.close();
}
