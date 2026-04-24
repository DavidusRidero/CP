#include <bits/stdc++.h>
#include <cstddef>
using namespace std;

int main() {
    int sum = 0;
    std::multiset<int> a,b; int t1,t2;
    for (int i = 0; i<1000; i++)
    {    
        cin >> t1 >> t2;
        a.insert(t1);
        b.insert(t2);
    }
    
    auto ai = a.begin();
    auto bi = b.begin();
    
    for (int i = 0; i<1000; i++)
    {
        sum+= abs(*ai-*bi);
        ai++; bi++;
    }

    cout << sum;
    return 0;
}