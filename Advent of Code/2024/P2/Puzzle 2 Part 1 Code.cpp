#include <bits/stdc++.h>
#include <cstddef>
using namespace std;

int main() {
    int total = 0;

    int i = 0;
    while(i++ < 1000)
    {
        string report;
        getline(cin, report);
        std::istringstream levels(report);

        int prev, next, count = 0, inc = 0, dec = 0;
        bool safe = true;

        levels >> next;

        while ((prev = next) && (levels >> next))
        {
            if (abs(prev-next) > 3 || (prev == next))
                {safe = false; break;}
            
            ++count;

            if (prev < next) inc++;
            else dec++;
        }
        if(safe == false) continue;

        if (safe && ((inc == count) || (dec == count)))
            total++;
    }

    cout << total;
    return 0;
}