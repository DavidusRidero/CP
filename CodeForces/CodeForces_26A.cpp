#include <iostream>
#include <vector>
using namespace std;

vector<int> sieve(int n) 
{
    vector<int> is_prime(n + 1, 1);
    is_prime[0] = is_prime[1] = 0;
    
    for (int i = 2; i * i <= n; i++) 
        if (is_prime[i])
            for (int j = i * i; j <= n; j += i)
                is_prime[j] = 0;

    return is_prime;
}

int countAlmostPrimes(int n) {
    vector<int> is_prime = sieve(n);
    vector<int> prime_factors_count(n + 1, 0);

    for (int i = 2; i <= n; i++) 
        if (is_prime[i])  
            for (int j = i; j <= n; j += i) 
                prime_factors_count[j]++;

    int count = 0;
    for (int i = 2; i <= n; i++) 
        if (prime_factors_count[i] == 2) 
            count++;

    return count;
}

int main() {
    int n;
    cin >> n;
    cout << countAlmostPrimes(n) << "\n";
    return 0;
}