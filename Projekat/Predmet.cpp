#include "Predmet.h"

#include <iostream>
#include <fstream>

Predmet::Predmet()
{
}

void Predmet::setNaziv()
{
	std::cout << "Unesite naziv predmeta: ";
	std::cin.getline(this->naziv, 30);
}

void Predmet::setECTS()
{
	std::cout << "Unesite ECTS bodove: ";
	std::cin >> this->ECTS;
	std::cin.ignore();
}

void Predmet::setPrijavljen()
{
	this->prijavljen = false;
}

char* Predmet::getNaziv()
{
	return this->naziv;
}

int Predmet::getECTS()
{
	return this->ECTS;
}

bool Predmet::getPrijavljen()
{
	return this->prijavljen;
}

void Predmet::setPredmet()
{
	std::cout << "\n/****Unos predmeta****/\n";
	this->setNaziv();
	this->setECTS();
}
