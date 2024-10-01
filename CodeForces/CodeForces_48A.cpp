#include <bits/stdc++.h>
using namespace std;

int main() {
	string s1,s2,s3;
	cin >> s1 >> s2 >> s3;
	
	if((s1 == s2 and s2 == s3) or (s1 != s2 and s2 != s3 and s3 != s1)) 
		{cout << "?"; return 0;}

	unordered_map<string,string> Beats = {
		{"rock","scissors"},
		{"scissors","paper"},
		{"paper","rock"}
	};

	if(s2 == s3 and Beats[s1] == s2) // s1/F is distinct
		{cout << "F"; return 0;}
	if(s1 == s3 and Beats[s2] == s3) // s2/M is distinct
		{cout << "M"; return 0;}
	if(s1 == s2 and Beats[s3] == s1) // s3/s is distinct
		{cout << "S"; return 0;}

	cout << "?"; return 0;
}