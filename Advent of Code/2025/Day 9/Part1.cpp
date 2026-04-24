#include <bits/stdc++.h>
using namespace std;

string source = "Input.txt";
set<pair<long long,long long>> Points;
int max_x = 0, max_y = 0;

void ingest() {
    ifstream fin(source);
    int x, y; char comma;

    while (fin >> x >> comma >> y) {
        Points.insert(make_pair(x, y));
        if (x > max_x) max_x = x;
        if (y > max_y) max_y = y;
    }

    fin.close();
}

void print() {
    for (auto& [first, second] : Points) {
        cout << first << " " << second << endl;
    }
}

void search() {
    long long max_area = 0;
    auto start = std::chrono::high_resolution_clock::now();
    for (auto& [first_x, first_y] : Points)
        for (auto& [second_x, second_y] : Points) {
            if (first_x == second_x or first_y == second_y) continue;
            long long area = (abs(first_x - second_x)+1) * (abs(first_y - second_y)+1);
            max_area = max(max_area, area);
        }
    auto stop = std::chrono::high_resolution_clock::now();

    cout << endl;
    auto duration = std::chrono::duration_cast<std::chrono::microseconds>(stop - start);
    cout << "Time taken for brute-force: " << duration.count() << "us" << endl;
    if (max_area > 0) {
        cout << "Largest Rectangle Area: " << max_area << endl;
    } else {
        cout << "No valid rectangles found." << endl;
    }
}

int main() {

    ingest();
    print();
    search();

    return 0;
}