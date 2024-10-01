// Source: https://usaco.guide/general/io

#include <bits/stdc++.h>
using namespace std;

int main() {
	int n,m,count = 0; cin >> n >> m;
	vector<int> tv(n);
	for(int i = 0;i<n;i++) cin >> tv[i];
	sort(tv.begin(),tv.end()); //Ascending Order
	int j = -1;
	while(m--) 
		if(tv[++j]<=0)
			count+=abs(tv[j]);
		else
			break;
	cout << count << "\n";
}