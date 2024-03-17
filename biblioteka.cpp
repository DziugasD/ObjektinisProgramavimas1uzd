#include "biblioteka.h"

using namespace std;

//funkcijos
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

template <typename Container>
void failoSkaitymas(ifstream &fd, Container &v)
{
    long long cnt = 0;
    string s;
    std::stringstream buffer;
    buffer << fd.rdbuf();
    if (std::is_same<Container, std::vector<studentas>>::value) {
        std::stringstream::pos_type pos = buffer.tellg();
        while(!buffer.eof())
        {
            getline(buffer, s);
            cnt++;
        }
        buffer.clear();
        buffer.seekg (pos, buffer.beg);
        v.reserve(cnt);
        cnt = 0;
    }
    while(getline(buffer, s))
    {
        if(s=="") continue;
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
		try{
			throw runtime_error("Netinkama ivestis. ");
		}
		catch(const runtime_error &e){
			cin.clear();
			cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			cout << e.what();
			cout << "Iveskite varda be skaiciu\n";
			cout << "Irasykite studento varda\n";
		}
    };
    cout << "Irasykite studento pavarde\n";
    while( !(cin >> s.pavarde) || yraint(s.pavarde) )
    {
		try{
			throw runtime_error("Netinkama ivestis. ");
		}
		catch(const runtime_error &e){
			cin.clear();
			cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			cout << e.what();
			cout << "Iveskite varda be skaiciu\nIrasykite studento pavarde\n";
		}
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
            try{
				throw runtime_error("Netinkama ivestis. ");
			}
			catch(const runtime_error &e){
			    cin.clear();
				cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
				cout << e.what();
				cout << "Iveskite skaiciu nuo 1 iki 10\n";
			}
        }
        if(x == -1) break;
        s.pazymiai.push_back(x);
    }
    cout << "Irasykite studento egzamino pazymi\n";
    while(!(cin >> s.egzaminas) || s.egzaminas<1 || s.egzaminas > 10)
    {
		try{
			throw runtime_error("Netinkama ivestis. ");
		}
		catch(const runtime_error &e){
			cin.clear();
			cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			cout << e.what();
			cout << "Iveskite skaiciu nuo 1 iki 10\n";
		}
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

void spausdinimas(vector<studentas> &v)
{
    stringstream spausdinimas;
    //Spausdinimas
    spausdinimas << left << setw(15)  << "Pavarde" << setw(10) << "Vardas" << setw(17) << "Galutinis (Vid.) " << setw(20) << "\\ Galutinis (Med.)\n";
    int bruksneliai = 55;
    while(bruksneliai--) spausdinimas << '-';
    spausdinimas << "\n";


    int vardoIlgis=0, pavardesIlgis = 0;
    for (int i=0; i<v.size(); i++)
    {
        vardoIlgis = max(vardoIlgis, (int) v[i].vardas.size());
        pavardesIlgis = max(pavardesIlgis, (int) v[i].pavarde.size());
    }

    for (int i=0; i<v.size(); i++)
    {
        spausdinimas << fixed << setprecision(2) << setw(pavardesIlgis+5) << v[i].pavarde << setw(vardoIlgis+5) << v[i].vardas << setw(19) << v[i].galutinis << setw(20) << v[i].mediana <<"\n";
    }
    cout << spausdinimas.rdbuf();
}

bool sortbyVardas(const studentas &a, const studentas &b)
{
    return (a.vardas > b.vardas);
}
bool sortbyPavarde(const studentas &a, const studentas &b)
{
    return (a.pavarde > b.pavarde);
}
bool sortbyGalutinis(const studentas &a, const studentas &b)
{
    return (a.galutinis > b.galutinis);
}
bool sortbyMediana(const studentas &a, const studentas &b)
{
    return (a.mediana > b.mediana);
}

void rusiavimas(vector<studentas>& v){
    cout << "Pagal ka norite rusiuoti? 1 - vardas, 2 - pavarde, 3 - Galutinis vidurkis, 4 - Galutinis mediana, 5 - nerusiuoti\n";
    int variantas;
    while(!(cin>> variantas) || variantas < 1 || variantas > 5)
    {
		try{
			throw runtime_error("Netinkama ivestis\n");
		}
		catch(const runtime_error &e){
			cin.clear();
			cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			cout << "Netinkama ivestis\n";
			cout << "1 - vardas, 2 - pavarde, 3 - Galutinis vidurkis, 4 - Galutinis mediana\n";
		}

    }
    if(variantas == 1) sort(v.begin(), v.end(), sortbyVardas);
    if(variantas == 2) sort(v.begin(), v.end(), sortbyPavarde);
    if(variantas == 3) sort(v.begin(), v.end(), sortbyGalutinis);
    if(variantas == 4) sort(v.begin(), v.end(), sortbyMediana);
    return;
}

void failoGeneravimas(int dydis, string pavadinimas){
	auto start = chrono::high_resolution_clock::now();
	stringstream buf;
	buf << left << setw(30) << "Vardas" << setw(30) << "Pavarde";
	for(int i=1; i<=10; i++){
		buf << "ND" << setw(4) << i;
	}
	buf << "Egz.\n";
	for(int i=1; i<=dydis; i++){
		buf <<  "Vardas"  << setw(24) << i << "Pavarde"  << setw(23) << i;
		for(int j=0; j<11; j++){
			buf << setw(6) << rand()%10;
		}
		if(i!=dydis)
            buf << "\n";
	}
	ofstream fr(pavadinimas);
	fr << buf.rdbuf();
	fr.close();
	auto end = chrono::high_resolution_clock::now();
	auto diff = chrono::duration_cast<chrono::milliseconds>(end - start);
	cout << "Sugeneruotas " << pavadinimas << " failas per: " << diff.count() << " ms\n";
}


bool compareByGalutinis(const double b, const studentas& a){
    return a.galutinis < b;
}

bool compareByMediana(const double b, const studentas& a){
    return a.mediana < b;
}

void spausdinimasFaila(vector<studentas> &v, string pavadinimas){
        stringstream spausdinimas;
    //Spausdinimas
    spausdinimas << left << setw(15)  << "Pavarde" << setw(10) << "Vardas" << setw(17) << "Galutinis (Vid.) " << setw(20) << "\\ Galutinis (Med.)\n";
    int bruksneliai = 55;
    while(bruksneliai--) spausdinimas << '-';
    spausdinimas << "\n";


    int vardoIlgis=0, pavardesIlgis = 0;
    for (int i=0; i<v.size(); i++)
    {
        vardoIlgis = max(vardoIlgis, (int) v[i].vardas.size());
        pavardesIlgis = max(pavardesIlgis, (int) v[i].pavarde.size());
    }

    for (int i=0; i<v.size(); i++)
    {
        spausdinimas << fixed << setprecision(2) << setw(pavardesIlgis+5) << v[i].pavarde << setw(vardoIlgis+5) << v[i].vardas << setw(19) << v[i].galutinis << setw(20) << v[i].mediana <<"\n";
    }
    ofstream fr(pavadinimas);
    fr << spausdinimas.rdbuf();
    fr.close();
}

void uzd4(int dydis, string pavadinimas){
    cout << "\n" << pavadinimas.substr(0, pavadinimas.size()-4) << "\n";

//	failoGeneravimas(dydis, pavadinimas);

    auto visasLaikas = chrono::high_resolution_clock::now();

    auto start = chrono::high_resolution_clock::now();
	ifstream fd(pavadinimas);
	vector<studentas> pirmunai, vargsai;
	failoSkaitymas(fd, pirmunai);
	fd.close();
    auto end = chrono::high_resolution_clock::now();
	auto diff = chrono::duration_cast<chrono::milliseconds>(end - start);
    cout << "Failas perskaitytas per: " << diff.count() << " ms\n";


    auto rinkLaikas = chrono::high_resolution_clock::now();
    int x = 0;
    cout << "Rusiuoti pagal 1 - Galutinis vid., 2 - Galutinis med.\n";
    while(!(cin >> x) && x>2 && x<1){
		try{
			throw runtime_error("Netinkama ivestis\n");
		}
		catch(const runtime_error &e){
			cin.clear();
			cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			cout << e.what();
			cout << "Rusiuoti pagal 1 - Galutinis vid., 2 - Galutinis med.\n";
		}
    }
    auto rinkLaikasPab = chrono::high_resolution_clock::now();
	auto rinkLaikasdiff = chrono::duration_cast<chrono::milliseconds>(rinkLaikasPab - rinkLaikas);


    start = chrono::high_resolution_clock::now();
    if(x==1)
        sort(pirmunai.begin(), pirmunai.end(), sortbyGalutinis);
    else
        sort(pirmunai.begin(), pirmunai.end(), sortbyMediana);

    end = chrono::high_resolution_clock::now();
	diff = chrono::duration_cast<chrono::milliseconds>(end - start);
    cout << "Surikiuoti studentai per: " << diff.count() << " ms\n";


    start = chrono::high_resolution_clock::now();
    vector<studentas>::iterator vieta;
    if(x==1)
        vieta = upper_bound(pirmunai.begin(), pirmunai.end(), 5.0, compareByGalutinis);
    else
        vieta = upper_bound(pirmunai.begin(), pirmunai.end(), 5.0, compareByMediana);
	copy(vieta, pirmunai.end(), back_inserter(vargsai));
	pirmunai.erase(vieta, pirmunai.end());
    end = chrono::high_resolution_clock::now();
	diff = chrono::duration_cast<chrono::milliseconds>(end - start);
    cout << "Paskirstyti pirmunai ir vargsai per: " << diff.count() << " ms\n";


    start = chrono::high_resolution_clock::now();
	spausdinimasFaila(pirmunai, "pirmunai.txt");
    end = chrono::high_resolution_clock::now();
	diff = chrono::duration_cast<chrono::milliseconds>(end - start);
    cout << "Isspausdintas pirmunu failas per: " << diff.count() << " ms\n";

    start = chrono::high_resolution_clock::now();
	spausdinimasFaila(vargsai, "vargsai.txt");
    end = chrono::high_resolution_clock::now();
	diff = chrono::duration_cast<chrono::milliseconds>(end - start);
    cout << "Isspausdintas vargsu failas per: " << diff.count() << " ms\n";


    auto visasLaikasPab = chrono::high_resolution_clock::now();
	auto visasLaikasdiff = chrono::duration_cast<chrono::milliseconds>(visasLaikasPab - visasLaikas);
	cout << "Visas programos veikimo laikas: " << visasLaikasdiff.count() - rinkLaikasdiff.count() << " ms\n";

}

