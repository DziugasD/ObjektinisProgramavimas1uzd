#include <bits/stdc++.h>

using namespace std;

struct studentas{
	string vardas, pavarde; 
	int skaicius, pazymiai, egzaminas;
	double galutinis;  	
};


int main(){
	
	freopen("duota.txt", "r", stdin);
	
	int n; 
	cin >> n; 
	studentas v[n]; 
	
	for(int i=0; i<n; i++){ 
		cin >> v[i].vardas >> v[i].pavarde >> v[i].skaicius;
		v[i].pazymiai=0;  
		for(int j=0; j<v[i].skaicius; j++){
			int x; 
			cin >> x; 
			v[i].pazymiai +=x; 
		}
		cin >> v[i].egzaminas; 
		v[i].galutinis = 0.4 * v[i].pazymiai/v[i].skaicius + 1.6 * v[i].egzaminas; 
	}
	
	for (int i=0; i<n; i++){
		cout << v[i].vardas << " " << v[i].pavarde << " " << v[i].galutinis << "\n"; 
	}
	

	return 0;
}
