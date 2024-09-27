#include <iostream>
#include <vector>
#include <stack>

using namespace std;

int main() {
    int n; cin >> n;
    vector<int> ans;
    stack<int> s;
    
    vector<int> h(n);
    for (int i = 0; i < n; ++i) 
        cin >> h[i];  

    for (int i = n - 1; i >= 0; --i) {
        ans.push_back(s.size());
        while (!s.empty() && s.top() < h[i]) s.pop();
        s.push(h[i]);
    }

    for (int i = ans.size() - 1; i >= 0; --i) {
        cout << ans[i] << " ";
    }
    cout << endl;

    return 0;
}
