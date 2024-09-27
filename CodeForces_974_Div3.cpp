#include <bits/stdc++.h>
using namespace std;


int main() {
	int t;
	cin >> t;

	while(t--)
	{
		double n; cin >> n;
		
		vector<double> m;
		double sum = 0;

		for(double i = 0;i<n;i++)
		{
			double temp; cin >> temp;
			sum+=temp;
			m.push_back(temp);
		}

		if(n<=2)
		{
			cout << "-1"<<"\n";
			continue;
		}

		std::sort(m.begin(),m.end());

		double avg = sum/n;
		double half_avg = avg/2;

		int half_pop = static_cast<int>(n/2);
		double mid_guy = m[half_pop];

		if(mid_guy<half_avg)
			cout << "0" << "\n";
		else 
		{
			double pot = (2*n*mid_guy)-sum+1;
			cout << pot << "\n";
		}

	}
    return 0;
}