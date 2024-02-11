#include <bits/stdc++.h>

using namespace std;

struct studentas{
	string vardas, pavarde;
	int skaicius;
	int pazymiai[10000], egzaminas;
	double galutinis, mediana;
};


int main(){

	int n;
	cin >> n;
	studentas v[n];

	for(int i=0; i<n; i++){
		cin >> v[i].vardas >> v[i].pavarde >> v[i].skaicius;
		for(int j=0; j<v[i].skaicius; j++){
			cin >> v[i].pazymiai[j];
		}
		cin >> v[i].egzaminas;
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