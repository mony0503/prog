#include <iostream>
#include <vector>
#include <fstream>

using namespace std;

enum Hibak{
	NEGATIV_DB,
	NEGATIV_KORSZ,
	HIBAS_KORIDO
};

void matrixBeolvas(istream& in, vector<vector<double> > &verseny) {
	int db, mkor, skor;
	in >> db >> mkor;
	if( db < 0 ) {
		throw NEGATIV_DB;
	}
	else if( mkor < 0) {
		throw NEGATIV_KORSZ;
	}
	else if(db >= 0 && mkor >=0 ){
		verseny.resize(db);
		for(int i=0; i<db; ++i) {
			in >> skor;
			if( skor <0) {
				throw NEGATIV_KORSZ;
			}
			else{
				verseny.at(i).resize(skor);
				for(int j=0; j<skor; ++j){
					in >> verseny.at(i).at(j);
// valahogy itt kene ellenorizni, hogy jok-e az idoeredmenyek: 0.1 <= korido <= 10
/*					if(verseny.at(i).at(j) > 10 || verseny.at(i).at(j) < 0.1) {
						throw HIBAS_KORIDO;
					}*/
				}
			}
		}
	}
}

template<class T>
void matrixKiir(ostream &out, vector<vector<T> > &verseny ){
    if(verseny.size() == 0){
        out << "0 ";
    }else{
        out << verseny[0].size() << " kor ";
    }

    out << verseny.size() << " versenyzo"<< endl;
    for(int a =0;a<verseny.size();a++){
        for(int b = 0;b<verseny[a].size();b++){
            out << verseny[a][b] << " ";
        }
        out << endl;
    }
}

double SorOssz(const vector<double> &verseny) {
	double s=0;
	for(int i=0; i<verseny.size();++i){
		for(int j=0; j<verseny.size(); j++){
			s += verseny.at(i);
		}
	}
	return s;
}

int MinKer(const vector<vector<double> > &verseny, bool &volte){
	int ind = 0;
	double most;
	double nyertes = SorOssz(verseny[0]);
	for(int i=1; i<verseny.size(); ++i){
		most = SorOssz(verseny.at(i));
		if(nyertes > most ){
			nyertes = most;
			ind = i;
			volte = true;
		}
	}
	return ind;
}

int main()
{
	vector<vector<double> > verseny;
	ifstream f("bemenoauto.txt");
	if(!f.is_open())
	{
		cout << "Nem talalhato a megadott fajl!" << endl;
		f.clear();
	}
	matrixBeolvas(f,verseny);
	f.close();
	matrixKiir(cout,verseny);
	
	bool volte = false;	
	int s = MinKer(verseny,volte);
	if( volte ){
		cout << s << endl;
	}
	else{
		cout <<"Nem volt, aki vegigcsinalta a versenyt." << endl;
	}
	
	try {
		matrixBeolvas(f,verseny);
	}catch(Hibak e){
		switch(e) {
		case NEGATIV_DB:
			cout << "A versenyzok szama nem lehet negativ!" << endl;
			break;
		case NEGATIV_KORSZ:
			cout << "A korok szama nem lehet negativ!" << endl;
			break;
		case HIBAS_KORIDO:
			cout << "Hibas a korido!" << endl;
			break;
		}
	}
	
	return 0;
}
