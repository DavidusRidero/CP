#include <iostream>
using namespace std;

int main() {
    long t;
    cin >> t;
    long num;
    while(t-- and cin >> num) {
        int count = 0;

        while(num)
        {
            if(num%10 == 4)
                count ++;
            num/=10;
        }
        cout << count << "\n";
    }
    return 0;
}