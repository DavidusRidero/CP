#include <iostream>
using namespace std;

int main() {
    int t,z=1;
    cin >> t;


    while(t--) {
        int n; long long k,s,minS=1000000001;
        cin >> n >> k;
        for (int i = 0; i < n; ++i) {
            cin >> s;
            if(s<minS)
                minS = s;
        }
        int trips = 0;
        if(n<=2) trips = 1;
        else trips = 2*(n-2) + 1;

        cout << "Case #"<<(z++)<<": ";
        if(minS*trips<=k)
            cout << "YES" << "\n";
        else
            cout << "NO" << "\n";
    }
    return 0;
}