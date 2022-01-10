#include <iostream>
#include <fstream>
using namespace std;
#define LSTR 4096
int main() {
	char fileinput[128],fileoutput[128], str[LSTR];
	cout << "Nome file .md o .txt (lettura)->";
	cin >> fileinput;
	cout << "Nome file .md o .txt (scrittura)->";
	cin >> fileoutput;

	ifstream fi(fileinput);
	ofstream fo(fileoutput);

	while (fi.getline(str,LSTR,'\n')) {
		//cout << str;
		string s=str;
		
		if(s.find("#include <iostream>")!=string::npos)
			s="#include <iostream> // OnLineCompiler:[https://www.onlinegdb.com/online_c++_compiler]"; 
		else if(s.find("#include <stdio.h>")!=string::npos)
			s="include <stdio.h>   // OnLineCompiler:[https://www.onlinegdb.com/online_c_compiler/]"; 
			// Aggiungo link
		fo << s << endl;
	}
	fi.close();
	fo.close();
}
