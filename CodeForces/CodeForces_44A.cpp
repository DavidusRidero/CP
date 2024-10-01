#include <bits/stdc++.h>
using namespace std;

int main() {
	int n; cin >> n;
	set<pair<string,string>> Leaves;

	for(int i = 0;i<n;i++)
	{
		string s1,s2;
		cin >> s1 >> s2;
		Leaves.insert({s1,s2});
	}

	cout << Leaves.size();
}