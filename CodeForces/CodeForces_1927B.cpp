#include <bits/stdc++.h>
using namespace std;

int main() {
	int t; cin >> t;
    while(t--)
    {
        int n; cin >> n; 
        vector<int> input(n);
        vector<int> count(26,0);

        for(int i = 0; i < n; i++) cin >> input[i];

        if(input[n-1] == n-1){
            for(int i = 0; i < n; i++)
                cout << "a";
            cout << "\n";
            continue;
        }

        for(int i = 0; i < n; i++)
        {
            int index = 0;
            for(;count[index]!=input[i]; index++);
            cout << static_cast<char>(index+97);
            count[index]++;
        }
        cout << "\n";
    }
}