#include <bits/stdc++.h>
using namespace std;

int main() {
	string s;
	cin >> s;
	s.erase(remove(s.begin(),s.end(),'.'),s.end());
	cout << s << "\n";
	return 0;
}