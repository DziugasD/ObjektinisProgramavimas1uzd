#include <bits/stdc++.h>

using namespace std;

struct studentas{
	string vardas, pavarde;
	vector<int> pazymiai;
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


vector<int> generuoti_pazymius(int dydis)
{
    vector<int> pazymiai(dydis);
    for(int i=0; i<dydis; i++)
    {
        pazymiai[i] = rand()%10;
    }
    return pazymiai;
}


int main(){
    srand(time(nullptr));

	vector<studentas> v;

	while(true){

        int variantas;
        cout << "1 - ranka, 2 - generuoti pazymius, 3 - generuoti ir pazymius ir studentu vardus, pavardes, 4 - baigti darba\n";
        cin >> variantas;

        if(variantas == 4) break;

        studentas s;
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

        if(variantas == 1){
            while(true){
                int x;
                cout << "Irasykite studento pazymi arba noredami uzbaigti iveskite bet kokia raide\n";
                if(!(cin >> x)){
                    cin.clear();
                    cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                    break;
                }
                s.pazymiai.push_back(x);
            }
            cout << "Irasykite studento egzamino pazymi\n";
            cin >> s.egzaminas;
        }
        else{
            s.pazymiai = generuoti_pazymius(rand()%10);
            s.egzaminas = rand()%10;
        }


		if(s.pazymiai.size()){
            int sum = accumulate(s.pazymiai.begin(), s.pazymiai.end(), 0);
            s.galutinis = 0.4 * sum/s.pazymiai.size() + 0.6 * s.egzaminas;
            sort(s.pazymiai.begin(), s.pazymiai.end());
            int vid = s.pazymiai.size()/2;
            if (s.pazymiai.size()%2){
                s.mediana = s.pazymiai[vid];
            }
            else{
                  s.mediana = (s.pazymiai[vid] + s.pazymiai[vid - 1]) / 2.0;
            }
		}
        else{
            s.galutinis = 0.6*s.egzaminas;
            s.mediana = 0;
        }

        v.push_back(s);
	}



	//Spausdinimas
    cout << left << setw(15)  << "Pavarde" << setw(10) << "Vardas" << setw(17) << "Galutinis (Vid.) " << setw(20) << "\\ Galutinis (Med.)\n";
    int bruksneliai = 55;
    while(bruksneliai--) cout << '-';
    cout << "\n";

	for (int i=0; i<v.size(); i++){
		cout << fixed << setprecision(2) << setw(15) << v[i].pavarde << setw(10) << v[i].vardas << setw(19) << v[i].galutinis << setw(20) << v[i].mediana <<"\n";
	}

	return 0;
}
