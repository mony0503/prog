#include <iostream>
#include <vector>
#include <fstream>

using namespace std;

enum Hibak{
	SZAM_NEG,
	B_LV,
	B_HV
};

void Beolvas (istream& in, vector<vector<int> > &adat){
/*	if(!f.is_open())
	{
		throw VEGE;
		f.clear();
	}
	else {...}
*/
	int n, hossz;
	in >> n;
	if( n < 0){
		throw SZAM_NEG;
	}
	else
	{
		adat.resize(n);
		for(int i=0; i<n; ++i){
			in >> hossz;
			if(hossz < 0){
				throw SZAM_NEG;
			}
			else
			{
				for(int j=0; j<hossz; ++j){
					int tmp;
					in >> tmp;
					if( tmp < 0){
						throw SZAM_NEG;
					}
					else if( tmp < 50 ){
						in.clear();
						throw B_LV;
					}
					else if( tmp > 100000){
						in.clear();
						throw B_HV;
					}
					else{
						adat[i].push_back(tmp);
					}
				}
			}
		}
	}
}

template<class T>
ostream& operator << (ostream& out,const vector<vector<T> > &adat){
	out << adat.size() << " nap"<< endl;
    for(int a =0;a<adat.size();a++){
        for(int b = 0;b<adat[a].size();b++){
            out << adat[a][b] << " ";
        }
        out << endl;
    }
	return out;
}

int Sorosszeg(const vector<int> &adat){
	int sum = 0;
	for(int i=0; i<adat.size(); ++i){
		sum += adat[i];
	}
	
	return sum;
}

int Erdemes(const vector<vector<int> > &adat){
	int index = 0;
	bool hveg;
	vector <double> atlag;
	for(int i=0; i<adat.size(); ++i){
		hveg = i%7==5 || i%7==6;
		if(adat[i].size() >= 3 && !hveg){
			atlag.push_back(double(Sorosszeg(adat[i])) / double(adat[i].size()));
		}
		else{
			atlag.push_back(0);
		}
	}
		
	double maxatlag = atlag[0];
	for(int i=1; i<adat.size(); ++i){
		if( maxatlag < atlag[i]){
			maxatlag = atlag[i];
			index = i+1;
		}
		else if( maxatlag = atlag[0] && maxatlag!= 0){
			index = 1;
		}
	}

	return index;
}

int main()
{
	vector<vector<int> > adat;
	ifstream f("4_zh_15_a.txt");

	try{
		Beolvas(f,adat);
	}catch(Hibak e){
		switch(e){
		case SZAM_NEG:
			cout << "NC" << endl;
			break;
		case B_LV:
			cout << "LV" << endl;
			break;
		case B_HV:
			cout << "HV" << endl;
			break;
		}
	}
	f.close();
	

	int valasz = Erdemes(adat)%7;
	switch(valasz){
		case 1:
		{
			cout << "H" << endl;
		}
		break;
		case 2: 
		{
			cout << "K" << endl;
		}
		break;
		case 3: 
		{
			cout << "SZ" << endl;
		}
		break;
		case 4: 
		{
			cout << "CS" << endl;
		}
		break;
		case 5: 
		{
			cout << "P" << endl;
		}
		break;
		default:
		{
			cout << "NM" << endl;
		}
	}

	return 0;
}