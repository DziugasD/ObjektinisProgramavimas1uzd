#include <bits/stdc++.h>

using namespace std;

struct studentas{
	string vardas, pavarde;
	vector<int> pazymiai;
	int egzaminas;
	double galutinis, mediana;
};


int main(){

	vector<studentas> v;

	while(true){
        studentas s;
        cout << "Irasykite studento varda arba noredami baigti iveskite bet koki skaiciu\n";
        cin >> s.vardas;
        if(isdigit(s.vardas[0])){
            break;
        }
        cout << "Irasykite studento pavarde\n";
        cin >> s.pavarde;

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

		int sum = accumulate(s.pazymiai.begin(), s.pazymiai.end(), 0);

		if(s.pazymiai.size()){
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
