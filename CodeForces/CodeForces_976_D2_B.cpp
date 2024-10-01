#include <bits/stdc++.h>
using namespace std;

long long calc(long long y)
{
	long long inner_sqrt = 1 + 4 * y;
	double sqrt_value = sqrt(inner_sqrt);
	double numerator = 1 + sqrt_value;
	long long result = static_cast<long long>((numerator * numerator) / 4);
	return result;
}

int main() {
	int t; cin >> t;
	while(t--)
	{
		int n; cin >> n;
		cout << calc(n) << "\n";
	}
}
