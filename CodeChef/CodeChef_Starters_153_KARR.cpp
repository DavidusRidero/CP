#include <bits/stdc++.h>
using namespace std;

int main() {
	int t; cin >> t;
	while(t--)
	{
	    int n; cin >> n;
	    int max = 0,current,count=0;
	    for(int i = 0;i<n;i++)
	    {
	        cin >> current;
	        if(current > max){
	            max = current;
	            count+=1;
	        }
	    }
	    if(count == n) {cout << 0 << "\n";continue;}
	    cout << max+1 <<"\n";
	}

}
