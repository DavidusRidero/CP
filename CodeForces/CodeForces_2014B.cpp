#include <bits/stdc++.h>
using namespace std;

string Sol(long n, long k)
{
	if(n==k and k<=2)
		return "NO\n";
	if(n%2==0 and (k/2)%2==0)
		return "YES\n";
	if(n%2==1 and ((k+1)/2)%2==0)
		return "YES\n";
	return "NO\n";
}

int main() {
	int t;
	cin >> t;

	while(t--)
	{
		long n,k; cin >> n >> k;
		cout << Sol(n,k);		 
	}
    return 0;
}