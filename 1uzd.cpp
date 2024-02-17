#include <bits/stdc++.h>

using namespace std;

struct studentas{
	string vardas, pavarde;
	int skaicius;
	int pazymiai[10000], egzaminas;
	double galutinis, mediana;
};

bool yraint(string s){
    for(int i=0; i<s.size(); i++) if(isdigit(s[i])) return true;
    return false;
}


int main(){

	int n;
	cout << "Iveskite studentu skaiciu\n";
	while(!(cin >> n) || n<1 )
    {
        cin.clear();
        cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        cout << "Netinkamas formatas\n";
    }
	studentas v[n];

	for(int i=0; i<n; i++){
        cout << "Iveskite studento varda\n";
        while(!(cin >> v[i].vardas) || yraint(v[i].vardas) )
        {
            cin.clear();
            cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            cout << "Netinkamas formatas\n";
        }
        cout << "Iveskite studento pavarde\n";
        while(!(cin >> v[i].pavarde) || yraint(v[i].pavarde) )
        {
            cin.clear();
            cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            cout << "Netinkamas formatas\n";
        }
        cout << "Iveskite studento pazymiu skaiciu\n";
        while(!(cin >> v[i].skaicius) || v[i].skaicius<0)
        {
            cin.clear();
            cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            cout << "Netinkamas formatas\n";
        }
		for(int j=0; j<v[i].skaicius; j++){
            cout << "Iveskite studento namu darbu pazymi\n";
            while(!(cin >> v[i].pazymiai[j]) || v[i].pazymiai[j] < 1 || v[i].pazymiai[j] > 10)
            {
                cin.clear();
                cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                cout << "Netinkamas formatas\n";
            }
		}
        cout << "Iveskite studento egzamino pazymi\n";
        while(!(cin >> v[i].egzaminas) || v[i].egzaminas < 1 && v[i].egzaminas > 10)
        {
            cin.clear();
            cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            cout << "Netinkamas formatas\n";
        }

        if(v[i].skaicius == 0 ){
            v[i].galutinis = 0.6 * v[i].egzaminas;
            v[i].mediana = 0.6 * v[i].egzaminas;
        }
        else{
            int sum = accumulate(v[i].pazymiai, v[i].pazymiai + v[i].skaicius, 0);
            v[i].galutinis = 0.4 * sum/v[i].skaicius + 0.6 * v[i].egzaminas;

            sort(v[i].pazymiai, v[i].pazymiai + v[i].skaicius);
            int vid = v[i].skaicius/2;
            if (v[i].skaicius%2){
                v[i].mediana = v[i].pazymiai[vid];
            }
            else{
                  v[i].mediana = (v[i].pazymiai[vid] + v[i].pazymiai[vid - 1]) / 2.0;
            }
            v[i].mediana = 0.4 * v[i].mediana + 0.6 * v[i].egzaminas;
        }

	}

    cout << left << setw(15)  << "Pavardė" << setw(10) << "Vardas" << setw(17) << "Galutinis (Vid.) " << setw(20) << "\\ Galutinis (Med.)\n";
    int bruksneliai = 55;
    while(bruksneliai--) cout << '-';
    cout << "\n";

	for (int i=0; i<n; i++){
		cout << fixed << setprecision(2) << setw(15) << v[i].pavarde << setw(10) << v[i].vardas << setw(19) << v[i].galutinis << setw(20) << v[i].mediana <<"\n";
	}

	return 0;
}
