#include <iostream>
#include <vector>
#include <algorithm>
#include <ctime>

using namespace std;

int main() {
    clock_t start = clock();

    int t, z = 1;
    cin >> t;

    while (t--) {
        long n,g,diff = 1000001,value = 0;
        cin >> n >> g; vector<long> arr(n);

        for (long i = 0; i < n; ++i) {
            cin >> arr[i];
            if(diff > abs(arr[i]-g)){
                diff = abs(arr[i]-g);
                value = arr[i];
            }
            if(diff == abs(arr[i]-g))
                if(value < arr[i])
                    value = arr[i];
        }
        sort(arr.begin(), arr.end());
        auto it = find(arr.begin(), arr.end(),value);
        long index = it - arr.begin();
        long nth = n - index ;

        cout  << "Case #" << (z++) << ": " << nth << " " << abs(arr[index]-g) << "\n";
    }

    clock_t stop = clock();
    double elapsed = static_cast<double>(stop - start) / CLOCKS_PER_SEC;
    //cout << "\nTime elapsed: " << elapsed << " seconds\n";

    return 0;
}