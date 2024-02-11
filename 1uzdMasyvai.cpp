#include <bits/stdc++.h>

using namespace std;

struct studentas
{
    string vardas, pavarde;
    int dydis, allocated;
    int* pazymiai;
    int egzaminas;
    double galutinis, mediana;
};


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


int* generuoti_pazymius(int dydis)
{
    int *pazymiai = new int[dydis];
    for(int i=0; i<dydis; i++)
    {
        pazymiai[i] = rand()%10;
    }
    return pazymiai;
}


int main()
{
    srand(time(nullptr));


    int dydis = 0, allocated = 1;
    studentas* v = new studentas[allocated];

    while(true)
    {
        int variantas;
        cout << "1 - ranka, 2 - generuoti pazymius, 3 - generuoti ir pazymius ir studentu vardus, pavardes, 4 - baigti darba\n";
        cin >> variantas;

        if(variantas == 4) break;



        studentas s;
        s.dydis = 0, s.allocated = 1, s.pazymiai = new int[s.allocated];

        if(variantas < 3)
        {
            cout << "Irasykite studento varda\n";
            cin >> s.vardas;
            cout << "Irasykite studento pavarde\n";
            cin >> s.pavarde;

        }
        else
        {
            s.vardas = generuoti_varda(3+rand()%5);
            s.pavarde = generuoti_varda(3+rand()%10);
        }

        if(variantas == 1)
        {
            while(true)
            {
                int x;
                cout << "Irasykite studento pazymi arba noredami uzbaigti iveskite bet kokia raide\n";
                if(!(cin >> x))
                {
                    cin.clear();
                    cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                    break;
                }
                if(s.dydis==s.allocated)
                {
                    s.allocated *= 2;
                    int* naujas = new int[s.allocated];
                    for(int i=0; i<s.dydis; i++)
                    {
                        naujas[i] = s.pazymiai[i];
                    }
                    delete[] s.pazymiai;
                    s.pazymiai = naujas;
                }
                s.pazymiai[s.dydis] = x;
                s.dydis++;
            }
            cout << "Irasykite studento egzamino pazymi\n";
            cin >> s.egzaminas;
        }
        else
        {
            delete [] s.pazymiai;
            s.dydis = rand()%10;
            s.allocated = s.dydis;
            s.pazymiai = generuoti_pazymius(s.dydis);
            s.egzaminas = rand()%10;
        }


        if(s.dydis)
        {
            int sum = accumulate(s.pazymiai, s.pazymiai + s.dydis, 0);
            s.galutinis = 0.4 * sum/s.dydis + 0.6 * s.egzaminas;
            sort(s.pazymiai, s.pazymiai + s.dydis);
            int vid = s.dydis/2;
            if (s.dydis%2)
            {
                s.mediana = s.pazymiai[vid];
            }
            else
            {
                s.mediana = (s.pazymiai[vid] + s.pazymiai[vid - 1]) / 2.0;
            }
        }
        else
        {
            s.galutinis = 0.6*s.egzaminas;
            s.mediana = 0;
        }

        if(dydis==allocated)
        {
            allocated *= 2;
            studentas* newArr = new studentas[allocated];
            for(int i=0; i<dydis; i++)
            {
                newArr[i] = v[i];
            }
            delete[] v;
            v = newArr;
        }

        v[dydis] = s;
        dydis++;
    }

    //Spausdinimas
    cout << left << setw(15)  << "Pavarde" << setw(10) << "Vardas" << setw(17) << "Galutinis (Vid.) " << setw(20) << "\\ Galutinis (Med.)\n";
    int bruksneliai = 55;
    while(bruksneliai--) cout << '-';
    cout << "\n";

    for (int i=0; i<dydis; i++)
    {
        cout << fixed << setprecision(2) << setw(15) << v[i].pavarde << setw(10) << v[i].vardas << setw(19) << v[i].galutinis << setw(20) << v[i].mediana <<"\n";
    }

    for(int i=0; i<dydis; i++) delete [] v[i].pazymiai;
    delete[] v;

    return 0;
}
