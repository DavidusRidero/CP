#include <bits/stdc++.h>

using namespace std;
typedef unsigned long long ull;


int main() {
    ull n = 245000;
    ull denominator = 6;

    ull full_sum_numerator = n*(n+1)*(2*n+1);
    ull even_sum_numerator = 0;
    if(n^1) {
        ull n2 = n/2;
        cout << "N is even.";
        even_sum_numerator = 4*(n2)*(n2+1)*(2*n2+1);
    }
    else {
        ull n2 = (n-1)/2;
        cout << "N is odd.";
        even_sum_numerator = 4*(n2)*(n2+1)*(2*n2+1);
    }

    ull numerator = full_sum_numerator - even_sum_numerator;
    ull odd_sum_of_squares = numerator/denominator;


    cout << "\nOdd sum of first " << n << " squares: " << odd_sum_of_squares << "\n";
    return 0;
}
