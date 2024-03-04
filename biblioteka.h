#ifndef BIBLIOTEKA_H
#define BIBLIOTEKA_H

#include <bits/stdc++.h>

struct studentas
{
    std::string vardas, pavarde;
    std::vector<int> pazymiai;
    int egzaminas;
    double galutinis, mediana;
};
void baloSkaiciavimas(studentas&);
std::string generuoti_varda(int);
bool yraint(std::string);
std::vector<int> generuoti_pazymius(int);
void failoSkaitymas(std::ifstream &, std::vector<studentas>&);
void vardoSkaitymas(studentas &);
void pazymiuSkaitymas(studentas &);
void baloSkaiciavimas(studentas &);
void spausdinimas(std::vector<studentas> &);
bool sortbyVardas(const studentas &, const studentas &);
bool sortbyPavarde(const studentas &, const studentas &);
bool sortbyGalutinis(const studentas &, const studentas &);
bool sortbyMediana(const studentas &, const studentas &);
void rusiavimas(std::vector<studentas>&);
void failoGeneravimas(int, std::string); 


#endif
