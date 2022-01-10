#include <iostream>
#include <fstream>
using namespace std;
#define LSTR 4096
int main() {
	char fileinput[128],fileoutput[128], str[LSTR];
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
		if(s.find("```")!=string::npos) {
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
