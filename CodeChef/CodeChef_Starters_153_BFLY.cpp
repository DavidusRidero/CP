#include <bits/stdc++.h>
using namespace std;

int main() {
	int t; cin >> t;
	while(t--)
	{
	    int r,g,b; cin >> r >> g >> b;
	    int sum = r+g+b;
	    if(r<=g+b and g<=r+b and b<=r+g)
	        cout << "YES\n";
	    else
	        cout << "NO\n";
	}

}
