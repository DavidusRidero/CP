#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;cin >> t;
    vector<int>out;

    while(t--)
    {
        int n; cin >> n;
        vector<int> arr;
        for (int i = 0; i < n; ++i){
            int temp;
            cin >> temp;
            arr.push_back(temp);
        }

        if(n <= 3){
            out.push_back(0);
            continue;
        }

        std::sort(arr.begin(), arr.end());
        vector<int> min;

        auto first = arr.begin();
        auto last = arr.end() - 1;

        min.push_back(*last - *first);          //No deletions
        min.push_back(*(last - 1) - *first);      //1 Del : Highest
        min.push_back(*last - *(first + 1));      //1 Del : Lowest
        min.push_back(*(last - 2) - *first);      //2 Del : Highest
        min.push_back(*last - *(first + 2));      //2 Del : Lowest
        min.push_back(*(last - 1) - *(first + 1));  //2 Del : Both

        std::sort(min.begin(), min.end());
        out.push_back(min.front());
    }

    for (int n : out) cout << n << "\n";
    return 0;
}
