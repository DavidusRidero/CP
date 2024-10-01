// Source: https://usaco.guide/general/io

#include <bits/stdc++.h>
using namespace std;

int main() {
	int t;
    cin >> t;
    while(t--)
    {
        int n,temp,first = -1,second = -1,fi = -1; cin >> n;
        for(int i = 0; i<n; i++)
        {
            cin >> temp;
            if(temp>first)
            {
                second = first;
                first = temp;   fi = i;
            }
        }

        int score;

        if(!(n%2))
            score = max(first,second) + n/2;
        else
        {
            if(!(fi%2))
                score = max(first + ((n+1)/2), second + ((n-1)/2));
            else
                score = max(first + ((n-1)/2), second + ((n+1)/2));
        }

        cout << score << "\n";
    }

}
