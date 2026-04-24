#include <bits/stdc++.h>
using namespace std;

// string source = "Test.txt";
// constexpr long long grid_size = 12;
// bitset<grid_size*grid_size> grid;

string source = "Input.txt";
constexpr long long grid_size = 10000;
bitset<grid_size*grid_size> grid;

set<pair<int,int>> Points;

void ingest() {
    ifstream fin(source);
    int r, c, r1, c1;
    char comma;

    fin >> c >> comma >> r;
    Points.insert(make_pair(r, c));
    int first_r = r;
    int first_c = c;

    while (fin >> c1 >> comma >> r1) {
        Points.insert(make_pair(r1, c1));
        if (r1 == r)
            for (int i = min(c1,c); i <= max(c1,c); i++)
                grid[r1*grid_size + i] = true;
        else
            for (int i = min(r1,r); i <= max(r1,r); i++)
                grid[i*grid_size + c1] = true;
        r=r1;
        c=c1;
    }

    if (first_r == r)
        for (int i = min(first_c,c); i <= max(first_c,c); i++)
            grid[first_r*grid_size + i] = true;
    else
        for (int i = min(first_r,r); i <= max(first_r,r); i++)
            grid[i*grid_size + first_c] = true;

    cout << "Ingestion Complete" << endl;
}

void tidy() {
    for (int i = 0; i < grid_size; i++) {
        bool paste = false;
        int j = 0;
        while (j < grid_size) {
            if (grid[i*grid_size+j]) {
                while (j < grid_size and grid[i*grid_size+j]) j++;
                paste = !paste;
            }
            else {
                grid[i*grid_size+j] = paste;
                j++;
            }
        }
    }
    cout << "Tidying Complete" << endl;
}

inline bool array(int i, int j) {
    return grid[i*grid_size + j];
}

void print() {
    if (source == "Input.txt") {cout << "Too Big."<< endl; return;}
    for (int i = 0; i < grid_size; i++) {
        for (int j = 0; j < grid_size; j++)
            cout << grid[i*grid_size + j] << " ";
        cout << endl;
    }
    cout << endl;
    cout << "Number of Points: " << Points.size() << endl;
}

int valid_rectangle(const int r1, const int c1, const int r2, const int c2) {
    unsigned int area = 0;
    if (grid[r1*grid_size+c2] && grid[r2*grid_size+c1]) return (abs(r1-r2)+1)*(abs(c1-c2)+1);
    return 0;
}


void solution() {
    set<unsigned int> area;

    for (auto& [r1,c1]:Points)
        for (auto& [r2,c2]:Points)
            area.insert(valid_rectangle(r1,c1,r2,c2));

    auto solution = *area.rbegin();
    cout << "Solution: " << solution << endl;
}


int main() {
    ingest();
    tidy();
    print();
    solution();

    return 1;
}