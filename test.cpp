#include <bits/stdc++.h>

using namespace std;


struct studentas
{
    string vardas, pavarde;
    vector<int> pazymiai;
    int egzaminas;
    double galutinis, mediana;
};

void baloSkaiciavimas(studentas*);

void failoSkaitymas(ifstream &fd, vector<studentas*> &v)
{
    long long cnt = 0;
    string s;
    std::stringstream buffer;
    buffer << fd.rdbuf();

    while(!buffer.eof())
    {
        getline(buffer, s);
        if(cnt)
        {
            istringstream ss(s);
            studentas *stud = new studentas;
            ss >> (*stud).vardas >> (*stud).pavarde;
            int x;
            while(ss >> x)
            {
                (*stud).pazymiai.push_back(x);
            }
            (*stud).egzaminas = (*stud).pazymiai.back();
            (*stud).pazymiai.pop_back();
            baloSkaiciavimas(stud);
            v.push_back(stud);
        }
        cnt++;
    }
}

void baloSkaiciavimas(studentas *s)
{
    if((*s).pazymiai.size())
    {
        int sum = accumulate((*s).pazymiai.begin(), (*s).pazymiai.end(), 0);
        (*s).galutinis = 0.4 * sum/(*s).pazymiai.size() + 0.6 * (*s).egzaminas;
        sort((*s).pazymiai.begin(), (*s).pazymiai.end());
        int vid = (*s).pazymiai.size()/2;
        if ((*s).pazymiai.size()%2)
        {
            (*s).mediana = (*s).pazymiai[vid];
        }
        else
        {
            (*s).mediana = ((*s).pazymiai[vid] + (*s).pazymiai[vid - 1]) / 2.0;
        }
        (*s).mediana = 0.4*(*s).mediana + 0.6*(*s).egzaminas;
    }
    else
    {
        (*s).galutinis = 0.6*(*s).egzaminas;
        (*s).mediana = 0.6*(*s).egzaminas;
    }
    return;
}

void spausdinimas(vector<studentas*> &v)
{
    stringstream spausdinimas;
    //Spausdinimas
    spausdinimas << left << setw(15)  << "Pavarde" << setw(10) << "Vardas" << setw(17) << "Galutinis (Vid.) " << setw(20) << "\\ Galutinis (Med.)\n";
    int bruksneliai = 55;
    while(bruksneliai--) spausdinimas << '-';
    spausdinimas << "\n";


    int vardoIlgis=0, pavardesIlgis = 0;
    for (int i=0; i<v.size(); i++)
    {
        vardoIlgis = max(vardoIlgis, (int) (*v[i]).vardas.size());
        pavardesIlgis = max(pavardesIlgis, (int) (*v[i]).pavarde.size());
    }

    for (int i=0; i<v.size(); i++)
    {
        spausdinimas << fixed << setprecision(2) << setw(pavardesIlgis+5) << (*v[i]).pavarde << setw(vardoIlgis+5) << (*v[i]).vardas << setw(19) << (*v[i]).galutinis << setw(20) << (*v[i]).mediana <<"\n";
    }
    cout << spausdinimas.rdbuf();
}

bool sortbyGalutinis(const studentas *a, const studentas *b)
{
    return ((*a).galutinis > (*b).galutinis);
}


void rusiavimas(vector<studentas*>& v){
	sort(v.begin(), v.end(), sortbyGalutinis);
}

int main()
{
    vector<studentas*> v;

	ifstream fd("studentai1000000.txt");
	failoSkaitymas(fd, v);
	fd.close();
    rusiavimas(v);
    spausdinimas(v);

    return 0;
}
