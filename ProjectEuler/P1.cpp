#include <bits/stdc++.h>

int main() {
    const int n = 1000;
    int sum = 0;

    for (size_t i = 0; i < n; i++) {
        if (i%3 == 0)
            sum+=i;
        if (i%5 == 0)
            sum+=i;
        if (i%15==0)
            sum-=i;
    }
    std::cout << "Sum of all the multiples of 3 or 5 below" << n << " : " << sum << "\n";
    return 0;
}
