#include <bits/stdc++.h>
using namespace std;

vector<int> Power = {1, 3, 9, 27, 81, 243, 729, 2187, 6561, 19683, 59049};
int power(int n)
{
	return Power[n];
}

int main() {
	long m;
	cin >> m;
	
	vector<int> res;
	int n;

	while(m)
	{
		//Find the index of the greatest Power of 3 smaller than M
		int index = 0;	
		for(int i = 0;i <= 10;i++){
			if(m<power(i))
				break;
			index = i;
		}

		int quotient = m/power(index);
		for(int i = 1;i <= quotient;i++)
			res.push_back(index);
		
		m %= power(index);
	}

	cout << res.size() << "\n";
	for(int i:res)
		cout << i << " ";
	return 0;
}