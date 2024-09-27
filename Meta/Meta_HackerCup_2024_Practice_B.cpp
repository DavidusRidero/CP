#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <cmath>
#include <ctime>

using namespace std;

long gcd(long a, long b) {
    return b == 0 ? a : gcd(b, a % b);
}

// Line of Best Fit

long maxPointsOnLine(const vector<pair<long long, long long>> &points) {
    long maxPoints = 0;
    long n = points.size();

    if (n < 2) return n;

    for (long i = 0; i < n; ++i) {
        unordered_map<string, long> slopeMap;
        long overlap = 0;
        long vertical = 0;
        long localMax = 0;

        for (long j = i + 1; j < n; ++j) {
            long dx = points[j].first - points[i].first;
            long dy = points[j].second - points[i].second;

            if (dx == 0 && dy == 0) {
                overlap++;
                continue;
            }

            if (dx == 0) {
                vertical++;
                continue;
            }

            long g = gcd(dx, dy);
            dx /= g;
            dy /= g;

            if (dx < 0) {
                dx = -dx;
                dy = -dy;
            }

            string slopeKey = to_string(dy) + "/" + to_string(dx);
            slopeMap[slopeKey]++;

            localMax = max(localMax, slopeMap[slopeKey]);
        }

        maxPoints = max(maxPoints, max(localMax, vertical) + overlap + 1);
    }

    return maxPoints;
}

int main() {
    clock_t start = clock();

    int t, z = 1;
    cin >> t;

    while (t--) {
        long n;
        cin >> n;
        vector<pair<long long, long long>> points;
        long long x, y;
        for (long i = 0; i < n; ++i) {
            cin >> x >> y;
            points.push_back({x, y});
        }
        long maxPoints = maxPointsOnLine(points);
        long result = n - maxPoints;

        cout << "Case #" << (z++) << ": " << result << "\n";
    }

    clock_t stop = clock();
    //double elapsed = static_cast<double>(stop - start) / CLOCKS_PER_SEC;
    //cout << "\nTime elapsed: " << elapsed << " seconds\n";

    return 0;
}