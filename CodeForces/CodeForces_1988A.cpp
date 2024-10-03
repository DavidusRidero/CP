#include <bits/stdc++.h>
//#define int long long
using namespace std;

int32_t main() {
	int t; cin >> t;
	int n,k;
	while(t-- and cin >> n >> k)	
		cout << (n - 1 + k - 2) / (k - 1) << "\n";
	return 0;
}