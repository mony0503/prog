#include <iostream>
#include <vector>
#include <fstream>
#include <cstdlib>
#include <string>
#include <conio.h>

using namespace std;

enum Hibak{
    NEM_TALALHATO_FILE,
	MAXNAL_TOBB_SZAM,
	NEGATV_DARABSZAM,
	FORMATUM_HIBA
};

void Menu(){
	cout << "11. Feladat" << endl;
	cout << "Neptun kod: HFYCXJ" << endl;
	cout << "============" << endl;
	cout << "\nMenu:\n" << endl;
    cout << "1. beolvas fajlbol" <<endl;
    cout << "2. beolvas konzolrol" <<endl;
    cout << "9. kilepes\n" <<endl;
}

void Fajlbol(istream &in, vector <int> &utlevel) {
	int db;
	in >> db;
	if( db <0 ){
		throw NEGATV_DARABSZAM;
	}
	int tmp;
	for(int i = 0; i < db; ++i) {
		in >> tmp;
		utlevel.push_back(tmp);	
	}
} 

template <class T>
void Konzolrol(istream &in, vector <T> &utlevel) {
	int db;
	cout << "Hatart atlepok szama: ";
	in>>db;
	if( cin.fail() ){
		cout << "Rossz formatumban adtad meg!" << endl;
	}
	else if (db == 0) {
		cout << "Nincs hatar atlepo." << endl;
	}
	else if( db <0) {
		cout << "Negativ szamot adtal meg." << endl;
	}
	/*
	do {
		cout << "Hatart atlepok szama: ";
		in >> db;
		hiba = db <= 0 || cin.fail();
		if(hiba) {
			cout << "
			
		}
	} while(hiba);
	*/
	int n;
	bool hiba;
	for(int i=0; i<db; ++i) {
		string str;
		do{
			cout << i+1 <<". hatart atlepo ember utlevelszama: ";
			in >> str;
			n=atoi(str.c_str()); // a helyes formatum mellett a stringbol kiszamolt egesz szam erteket, hibas formatum eseten a 0-t adja vissza
			hiba = 0 == n && str!="0" || cin.fail();
			if(hiba){
				cout << "Helytelen erteket adott meg!" << endl;
				cin.clear();
				cin.ignore(1000,'\n');
			}
			else {
				utlevel.push_back(n);
			}
		}while(hiba);		
	}
	
	if(db > 0){
		cout << "\nSikeres beolvasas!" << endl;
	}
} 

template <class T>
ostream& operator<<(std::ostream &out, const vector <T> &utlevel) {
	for(int i=0; i<utlevel.size(); i++) {
		out << utlevel.at(i) << " ";
	}
	return out;
} 

void Futtatas(int valasz, vector<int> &utlevel) {
	switch(valasz){
		case 1:
		{
			utlevel.clear();
			string eleres;
			cout <<"Adja meg a fajl nevet: ";
			cin >> eleres;
			ifstream f(eleres.c_str());
			
		//	ifstream f("utlevel.txt");
			if(!f.is_open())
			{
				throw NEM_TALALHATO_FILE;
				f.clear();
			}
			Fajlbol (f,utlevel);
			cout << "\nSikeres beolvasas!" << endl;
			cout << utlevel << endl;
			
			f.close();
		}
		break;
		case 2:
		{
			utlevel.clear();
			Konzolrol(cin,utlevel);
			cout << utlevel << endl;
		}
		break;
		case 9:
		break;
		default: 
		{
			throw FORMATUM_HIBA;
		}
	}
}

int main()
{
	int valasz;
	vector <int> utlevel; //csak számokból áll az útlevélszám
	
	
	do {
		Menu();
		cin >> valasz;
		if(cin.fail()){
			cin.clear();
			cin.ignore(1000,'\n');
		}
		
        try{ 
           Futtatas(valasz,utlevel);
        }catch(Hibak e){
            switch(e){
            case NEM_TALALHATO_FILE:
                cout << "Nem talalhato a megadott file!" << endl;
                break;
            case UTLEVELSZAMBAN_BETU:
                cout << "Az utlevelszam csak szamokat tartalmazhat, betuket nem!" << endl;
                break;
			case MAXNAL_TOBB_SZAM:
				cout << "6 szamjegynel hosszabb utlevelszamot adott meg!" << endl;
				break;
			case NEGATV_DARABSZAM:
				cout << "A hataron atlepok szama nem lehet negativ!" << endl;
				break;
			case FORMATUM_HIBA:
				cout<< "Nem jo formatumban adta meg a valaszt!" << endl;
				break;
			}
        }
/*		cout << "Uss le egy billentyuzetet!";
		getch();
		system("cls");
*/   }while(valasz != 9);
	
	return 0;
}