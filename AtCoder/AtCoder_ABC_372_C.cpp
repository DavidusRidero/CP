#include <iostream>
#include <string>
using namespace std;

int main() {
	long n,q; cin >> n >> q;
	string s, sub = "ABC"; cin >> s;

	long count = 0;
    for (long i = 0; i <= n - 3; ++i) 
        if (s.substr(i, 3) == "ABC") 
            count++;

	while(q--)
	{
		long xi; cin >> xi; xi--;
		char ci; cin >> ci;
		
		for (long i = max(0L, xi - 2); i <= min(n - 3, xi); ++i)
            if (s.substr(i, 3) == "ABC") 
                count--;
		
		s[xi] = ci;

		for (long i = max(0L, xi - 2); i <= min(n - 3, xi); ++i)
            if (s.substr(i, 3) == "ABC") 
                count++;

		cout << count << "\n";
	}
	return 0;
}