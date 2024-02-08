#include <bits/stdc++.h>

using namespace std;

struct studentas{
	string vardas, pavarde;
	int skaicius;
	int pazymiai[10000], egzaminas;
	double galutinis, mediana;
};


int main(){

	freopen("duota.txt", "r", stdin);

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



	for (int i=0; i<n; i++){
		cout << v[i].vardas << " " << v[i].pavarde << " " << v[i].galutinis << " " << v[i].mediana <<"\n";
	}


	return 0;
}
