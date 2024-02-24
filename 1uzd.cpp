#include "biblioteka.h" 

using namespace std;

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
            ifstream fd("studentai1000000.txt");
            failoSkaitymas(fd, v);
            fd.close();
            break;
        }
        if(variantas == 5) break;

        baloSkaiciavimas(s);

        v.push_back(s);
    }
    rusiavimas(v);
    spausdinimas(v);

    return 0;
}
