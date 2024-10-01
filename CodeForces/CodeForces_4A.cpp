#include <iostream>
using namespace std;

int main()
{
    int n; cin >> n;
    if(n==2) {cout << "NO"; return 0;} 
    if(n&1) cout << "NO";
    else cout << "YES";
    return 0;
}