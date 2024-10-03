#include <bits/stdc++.h>
using namespace std;

int main() {
	int t; cin >> t;
    while(t--)
    {
        int n; cin >> n; 
        string input; cin >> input;

        n = 0;
        size_t pos = 0;
        string s1 = "mapie", s2 = "pie", s3 = "map";

        while((pos = input.find(s1,pos)) != string::npos) {n++; input[pos+2]='0'; pos+=5;}
        pos = 0;
        while((pos = input.find(s2,pos)) != string::npos) {n++; pos+=3;}
        pos = 0;
        while((pos = input.find(s3,pos)) != string::npos) {n++; pos+=3;}
        cout << n << "\n";
    }
}