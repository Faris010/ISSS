#include "Admin.h"

#include <iostream>
#include <fstream>
#include <iomanip>
#include <string.h>
#include <string>

#include "Predmet.h"

Admin::Admin()
{
	strcpy_s(this->user, "admin");
	strcpy_s(this->password, "admin");
}

void Admin::setProfesor()
{
	this->p.setIme();
	this->p.setPrezime();
	this->p.setPassword();
	std::shared_ptr<Predmet> temp = std::make_shared<Predmet>();
	int n;
	std::cout << "Unesite broj predmeta: ";
	std::cin >> n;
	std::cin.ignore();
	std::ofstream file("Profesor.txt", std::ios::app);
	file << std::setw(12) << std::left << this->p.getPrezime() << std::setw(12) << std::left << this->p.getIme()
		<< std::setw(10) << std::left << this->p.getPassword();
	for (int i = 0; i < n; i++)
	{
		temp->setNaziv();
		file << std::setw(5) << std::left << temp->getNaziv();
	}
	file << "\n";
	file.close();
}

void Admin::getProfesor()
{
	std::string line;
	std::ifstream file("Profesor.txt");
	std::cout << std::setw(12) << std::left << "Prezime" << std::setw(12) << std::left << "Ime"
		<< std::setw(10) << std::left << "Password" << std::setw(13) << std::left << "Predmeti" << "\n";
	std::cout << "-----------------------------------------------------------------\n";
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
	std::cout << "-----------------------------------------------------------------\n";
}

std::istream& operator>>(std::istream& stream, Admin& a)
{
	a.s.setIme();
	a.s.setPrezime();
	a.s.setJMBG();
	a.s.setIndex();
	a.s.setSemestar();
	a.s.setPassword();
	std::shared_ptr<Predmet> temp = std::make_shared<Predmet>();
	std::ofstream file("Student.txt", std::ios::app);
	file << std::setw(10) << std::left << a.s.getIndex() << std::setw(12) << std::left << a.s.getIme() << std::setw(12) << std::left << a.s.getPrezime()
		<< std::setw(16) << std::left << a.s.getJMBG() << std::setw(10) << std::left << a.s.getPassword() << std::setw(10) << std::left << a.s.getSemestar() << " ";
	file << std::endl;
	file.close();
	std::ofstream data("Student_predmeti.txt", std::ios::app);
	data << a.s.getIndex() << "\n";
	for (int i = 0; i < 5; i++)
	{
		temp->setNaziv();
		temp->setECTS();
		data << std::setw(5) << std::left << temp->getNaziv() << std::setw(3) << std::left << temp->getECTS()
			<< std::setw(3) << std::left << "5" << "\n";
	}
	data.close();
	return stream;
}

std::ostream& operator<<(std::ostream& stream, Admin& a)
{
	stream << std::setw(10) << std::left << "Index" << std::setw(12) << std::left << "Ime" << std::setw(12) << std::left << "Prezime"
		<< std::setw(16) << std::left << "JMBG" << std::setw(10) << std::left << "Password" << std::setw(9) << std::left << "Semestar\n";
	stream << "----------------------------------------------------------------------------------------\n";
	std::string line;
	std::ifstream file("Student.txt");
	while (true)
	{
		if (file.eof())
		{
			break;
		}
		getline(file, line);
		stream << line << std::endl;
	}
	stream << "----------------------------------------------------------------------------------------\n";
	file.close();
	return stream;
}
