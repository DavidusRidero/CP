#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

int main() {
    int n,d,count = 0; cin >> n >> d;
    vector<int> a(n);
    
    for(int i = 0; i<n; i++)
    {
        cin >> a[i]; 

        if(i == 0) continue;        
        if(a[i] > a[i-1]) continue;

        int x = ceil((a[i-1] - a[i]+1)/static_cast<double>(d));
        count+= x;
        a[i] += x*d;
    }

    cout << count;
    return 0;
}