#include <iostream>
using namespace std;

int main() {
    int t;
    cin >> t;
    while(t--) {
        int m, p;
        cin >> m >> p;
		
        int ans = 0;
		
        while(m < 299 && m+p+20*ans < 1000) {
            ++m;
            ++ans;
        }
		
        if(m+p+20*ans <= 1000) cout << ans << endl;
        else cout << ans-1 << endl;
    }
    return 0;
} 