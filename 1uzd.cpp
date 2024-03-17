#include "biblioteka.h"

using namespace std;

int main()
{
    srand(time(nullptr));

    vector<studentas> v;
    while(true)
    {
        int variantas;
        cout << "1 - ranka, 2 - generuoti pazymius, 3 - generuoti ir pazymius ir studentu vardus, pavardes, 4 - skaityti is failo, 5 - baigti darba, 6 - generuoti failus\n";

        while(!(cin>> variantas) || variantas < 1 || variantas > 6)
        {
			try{
				throw runtime_error("Netinkamas ivestis\n");
			}
			catch (const runtime_error &e){
			    cin.clear();
				cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
				cout << e.what();
				cout << "1 - ranka, 2 - generuoti pazymius, 3 - generuoti ir pazymius ir studentu vardus, pavardes, 4 - skaityti is failo, 5 - baigti darba, 6 - generuoti failus\n";
			}
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
		if(variantas == 6){
//			uzd4(1000, "studentai1000.txt");
//			uzd4(10000, "studentai10000.txt");
			uzd4(100000, "studentai100000.txt");
//			uzd4(1000000, "studentai1000000.txt");
//			uzd4(10000000, "studentai10000000.txt");
			continue;
		}
        baloSkaiciavimas(s);

        v.push_back(s);
    }
    rusiavimas(v);
    spausdinimas(v);

    return 0;
}
