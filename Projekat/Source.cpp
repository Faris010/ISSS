#include <iostream>

#include "Admin.h"
#include <fstream>

#include "Predmet.h"

int glavniMeni() {
    int br;
    std::cout << "/****MENI****/\n"
        << "1. Admin\n"
        << "2. Profesor\n"
        << "3. Student\n"
        << "0. Izlaz\n";
    do {
        std::cout << "Izbor: ";
        std::cin >> br;
        std::cin.ignore();
    } while (br < 0 || br > 3);
    system("cls");
    return br;
}

int adminMeni()
{
    int br;
    std::cout << "/****ADMIN MENI****/\n"
        << "1. Kreiraj studenta\n"
        << "2. Kreiraj profesora\n"
        << "3. Ipisi studente\n"
        << "4. Ispisi profesore\n"
        << "0. Izlaz\n";
    do {
        std::cout << "Izbor: ";
        std::cin >> br;
        std::cin.ignore();
    } while (br < 0 || br > 4);
    system("cls");
    return br;
}

int profesorMeni()
{
    int br;
    std::cout << "/****PROFESOR MENI****/\n"
        << "1. Upisi ocjenu\n"
        << "2. Ispisi studente\n"
        << "0. Izlaz\n";
    do {
        std::cout << "Izbor: ";
        std::cin >> br;
        std::cin.ignore();
    } while (br < 0 || br > 2);
    system("cls");
    return br;
}

int studentMeni()
{
    int br;
    std::cout << "/****STUDENT MENI****/\n"
        << "1. Polozeni ispiti\n"
        << "2. Prijava ispita\n"
        << "3. Prijavljeni ispiti\n"
        << "0. Izlaz\n";
    do {
        std::cout << "Izbor: ";
        std::cin >> br;
        std::cin.ignore();
    } while (br < 0 || br > 3);
    system("cls");
    return br;
}

bool adminLogin()
{
    int pokusaj = 0;
    char user[10], pass[10];
    do {
        std::cout << "Username: ";
        std::cin.getline(user, 10);
        std::cout << "Password: ";
        std::cin.getline(pass, 10);
        pokusaj++;
        if (pokusaj == 3) {
            return false;
        }
        else if (strcmp(user, "admin") || strcmp(pass, "admin"))
        {
            std::cout << "GRESKA!\n";
        }
    } while (strcmp(user, "admin") || strcmp(pass, "admin"));
    system("cls");
    return true;
}

bool profesorLogin()
{
    std::shared_ptr<Predmet> temp = std::make_shared<Predmet>();
    int pokusaj = 0;
    char user[10], pass[10];
    std::string str;
    do {
        std::ifstream file("Profesor.txt");
        std::ofstream data("Profesor_login.txt");
        std::cout << "Username: ";
        std::cin.getline(user, 10);
        std::cout << "Password: ";
        std::cin.getline(pass, 10);
        file >> str;
        while (true)
        {
            if (file.eof())
            {
                break;
            }
            if (str == user)
            {
                file >> str;
                if (str == pass)
                {
                    system("cls");
                    data << user;

                    return true;
                }
            }
            file >> str;
        }
        pokusaj++;
        data.close();
        file.close();
    } while (pokusaj < 3);
    return false;
}

bool studentLogin()
{
    int pokusaj = 0;
    char user[20], pass[20];
    std::string str;
    do {
        std::ifstream file("Student.txt");
        std::ofstream data("Student_login.txt");
        std::cout << "Username: ";
        std::cin.getline(user, 20);
        std::cout << "Password: ";
        std::cin.getline(pass, 20);
        file >> str;
        while (true)
        {
            if (file.eof())
            {
                break;
            }
            if (str == user)
            {
                file >> str;
                if (str == pass)
                {
                    system("cls");
                    data << user;
                    return true;
                }
            }
            file >> str;
        }
        pokusaj++;
        data.close();
        file.close();
    } while (pokusaj < 3);
    return false;
}

int main() {
    Admin a;
    Profesor p;
    Student s;
    bool istrue;
    bool profLog;
    bool studLog;
    int izbor;
    do
    {
        izbor = glavniMeni();
        if (izbor == 1)
        {
            istrue = true; //adminLogin();
            if (istrue == true)
            {
                int br = 0;
                do {
                    br = adminMeni();
                    switch (br)
                    {
                    case 1:
                        std::cin >> a;
                        std::cout << "\nStudent kreiran!\n";
                        break;
                    case 2:
                        a.setProfesor();
                        std::cout << "\nProfesor kreiran!\n";
                        break;
                    case 3:
                        std::cout << a;
                        break;
                    case 4:
                        a.getProfesor();
                        break;
                    }
                    system("pause");
                    system("cls");
                } while (br != 0);
            }
        }
        if (izbor == 2)
        {
            profLog = profesorLogin();
            if (profLog == true)
            {
                int br;
                do
                {
                    br = profesorMeni();
                    switch (br)
                    {
                    case 1:
                        p.unosOcjene();
                        break;
                    case 2:
                        p.ispisiStudente();
                        break;
                    }
                    system("pause");
                    system("cls");
                } while (br != 0);
            }
        }
        if (izbor == 3)
        {
            studLog = studentLogin();
            if (studLog == true)
            {
                int br;
                do
                {
                    br = studentMeni();
                    switch (br)
                    {
                    case 1:
                        s.ispisPolozenihIspita();
                        break;
                    case 2:
                        s.prijavaIspita();
                        break;
                    case 3:
                        s.prijavljeniIspiti();
                        break;
                    }
                    system("pause");
                    system("cls");
                } while (br != 0);
            }
        }
    } while (izbor != 0);
    return 0;
}