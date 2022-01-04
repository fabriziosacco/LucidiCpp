// F. Sacco: dato un file in markdown (.md o anche .txt) estrae il codice nel file indicato 
// Ho estratto il codice da LucidiCpp.md in Codice.cpp
#include <iostream>
#include <fstream>
using namespace std;
#define LSTR 256
int main() {
	char fileinput[LSTR],fileoutput[LSTR], str[LSTR+2];
	bool codice=false;
	cout << "Nome file .md o .txt (lettura)->";
	cin >> fileinput;
	cout << "Nome file codice (.c, .cpp, ...) (scrittura)->";
	cin >> fileoutput;

	ifstream fi(fileinput);
	ofstream fo(fileoutput);

	while (fi.getline(str,LSTR,'\n')) {
		//cout << str;
		string s=str;
		if(s.find('```')!=string::npos) {
			codice=!codice;
			if (codice) {
				fo << "//-------------------------------\n";
				continue;
			}
		}
		if(codice)
			fo << str << endl;
	}
	fi.close();
	fo.close();
}
