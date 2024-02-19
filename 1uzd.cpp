#include <bits/stdc++.h>

using namespace std;



struct studentas
{
    string vardas, pavarde;
    vector<int> pazymiai;
    int egzaminas;
    double galutinis, mediana;
};

void baloSkaiciavimas(studentas&);

string generuoti_varda(int ilgis)
{
    string vardas;
    for(int i=0; i<ilgis; i++)
    {
        if(i==0) vardas += (char) (65 + rand()%25);
        else vardas += (char) (97 + rand()%25);
    }
    return vardas;
}

bool yraint(string s)
{
    for(int i=0; i<s.size(); i++) if(isdigit(s[i])) return true;
    return false;
}

vector<int> generuoti_pazymius(int dydis)
{
    vector<int> pazymiai(dydis);
    for(int i=0; i<dydis; i++)
    {
        pazymiai[i] = rand()%10;
    }
    return pazymiai;
}

void failoSkaitymas(ifstream &fd, vector<studentas> &v)
{
    long long cnt = 0;
    while(!fd.eof())
    {
        string s;
        getline(fd, s);
        if(cnt)
        {
            istringstream ss(s);
            studentas stud;
            ss >> stud.vardas >> stud.pavarde;
            int x;
            while(ss >> x)
            {
                stud.pazymiai.push_back(x);
            }
            stud.egzaminas = stud.pazymiai.back();
            stud.pazymiai.pop_back();
            baloSkaiciavimas(stud);
            v.push_back(stud);
        }
        cnt++;
    }
}


void vardoSkaitymas(studentas &s)
{
    cout << "Irasykite studento varda\n";
    while( !(cin >> s.vardas) || yraint(s.vardas) )
    {
        cin.clear();
        cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        cout << "Netinkama ivestis. Iveskite varda be skaiciu\n";
        cout << "Irasykite studento varda\n";
    };
    cout << "Irasykite studento pavarde\n";
    while( !(cin >> s.pavarde) || yraint(s.pavarde) )
    {
        cin.clear();
        cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        cout << "Netinkama ivestis. Iveskite varda be skaiciu\n";
        cout << "Irasykite studento pavarde\n";
    };
    return;
}

void pazymiuSkaitymas(studentas &s)
{
    while(true)
    {
        int x;
        cout << "Irasykite studento pazymi arba noredami uzbaigti iveskite -1\n";
        while(!(cin >> x) || x<1 || x>10)
        {
            if(x == -1) break;
            cin.clear();
            cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            cout << "Netinkama ivestis. Iveskite skaiciu nuo 1 iki 10\n";
        }
        if(x == -1) break;
        s.pazymiai.push_back(x);
    }
    cout << "Irasykite studento egzamino pazymi\n";
    while(!(cin >> s.egzaminas) || s.egzaminas<1 || s.egzaminas > 10)
    {
        cout << "Netinkama ivestis. Iveskite skaiciu nuo 1 iki 10\n";
    }
    return;
}

void baloSkaiciavimas(studentas &s)
{
    if(s.pazymiai.size())
    {
        int sum = accumulate(s.pazymiai.begin(), s.pazymiai.end(), 0);
        s.galutinis = 0.4 * sum/s.pazymiai.size() + 0.6 * s.egzaminas;
        sort(s.pazymiai.begin(), s.pazymiai.end());
        int vid = s.pazymiai.size()/2;
        if (s.pazymiai.size()%2)
        {
            s.mediana = s.pazymiai[vid];
        }
        else
        {
            s.mediana = (s.pazymiai[vid] + s.pazymiai[vid - 1]) / 2.0;
        }
        s.mediana = 0.4*s.mediana + 0.6*s.egzaminas;
    }
    else
    {
        s.galutinis = 0.6*s.egzaminas;
        s.mediana = 0.6*s.egzaminas;
    }
    return;
}

void spausdinimas(vector<studentas> v)
{
    //Spausdinimas
    cout << left << setw(15)  << "Pavarde" << setw(10) << "Vardas" << setw(17) << "Galutinis (Vid.) " << setw(20) << "\\ Galutinis (Med.)\n";
    int bruksneliai = 55;
    while(bruksneliai--) cout << '-';
    cout << "\n";

    for (int i=0; i<v.size(); i++)
    {
        cout << fixed << setprecision(2) << setw(15) << v[i].pavarde << setw(10) << v[i].vardas << setw(19) << v[i].galutinis << setw(20) << v[i].mediana <<"\n";
    }
}


int main()
{
    srand(time(nullptr));

    vector<studentas> v;

    while(true)
    {
        int variantas;
        cout << "1 - ranka, 2 - generuoti pazymius, 3 - generuoti ir pazymius ir studentu vardus, pavardes, 4 - skaityti is failo, 5 - baigti darba\n";

        while(!(cin>> variantas) || variantas < 1 || variantas > 5)
        {
            cin.clear();
            cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            cout << "Netinkama ivestis\n";
            cout << "1 - ranka, 2 - generuoti pazymius, 3 - generuoti ir pazymius ir studentu vardus, pavardes, 4 - baigti darba\n";
        }

        studentas s;

        if(variantas == 1)
        {
            vardoSkaitymas(s);
            pazymiuSkaitymas(s);
        }
        if(variantas == 2)
        {
            vardoSkaitymas(s);
            s.pazymiai = generuoti_pazymius(rand()%10);
            s.egzaminas = rand()%10;
        }
        if(variantas == 3)
        {
            s.vardas = generuoti_varda(3+rand()%5);
            s.pavarde = generuoti_varda(3+rand()%10);
            s.pazymiai = generuoti_pazymius(rand()%10);
            s.egzaminas = rand()%10;
        }
        if(variantas == 4)
        {
            ifstream fd("studentai10000.txt");
            failoSkaitymas(fd, v);
            break;
        }
        if(variantas == 5) break;

        baloSkaiciavimas(s);

        v.push_back(s);
    }

    spausdinimas(v);

    return 0;
}
