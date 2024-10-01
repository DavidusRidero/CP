#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n,p1,p2,p3,t1,t2; 
    cin >> n >> p1 >> p2 >> p3 >> t1 >> t2;

    int p1s = 0, p2s = 0, p3s = 0;
    
    vector<int> l(n+1), r(n+1);
    
    for(int i = 1; i<= n; i++){
        cin >> l[i] >> r[i];
        p1s+=r[i]-l[i];
        
        if(i==1)continue;
        
        int p1t = 0,p2t = 0,p3t = 0;

        p1t = min(l[i]-r[i-1],t1);              p1s += p1t;
        p2t = min(max(l[i]-r[i-1]-p1t,0),t2);   p2s += p2t;
        p3t = max(l[i]-r[i-1]-p1t-p2t,0);       p3s += p3t;
    }

    int total = p1*p1s + p2*p2s + p3*p3s;
    cout << total << "\n";

    return 0;
}