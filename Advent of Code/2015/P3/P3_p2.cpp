#include <bits/stdc++.h>

int main() {
    namespace fs = std::filesystem;
    const fs::path p = "P3_input.txt";
    std::ifstream in(p,std::ios::binary);
    std::string test = "^v^v^v^v^v";

    std::pair<int,int> point1 {0,0};
    auto& [x1,y1] = point1;
    std::set<std::pair<int,int>> visited1;
    visited1.insert({x1,y1});

    std::pair<int,int> point2 {0,0};
    auto& [x2,y2] = point2;
    std::set<std::pair<int,int>> visited2;
    visited2.insert({x2,y2});

    char c;
    int turn = 1;
    while (in.get(c)) {
    // for (char c:test){
        if (turn == 1) {
            switch (c) {
                case '^': y1++; break;
                case 'v': y1--; break;
                case '<': x1--; break;
                case '>': x1++; break;
            }
            visited1.insert({x1,y1});
        }

        if (turn == 2) {
            switch (c) {
                case '^': y2++; break;
                case 'v': y2--; break;
                case '<': x2--; break;
                case '>': x2++; break;
            }
            visited2.insert({x2,y2});
        }

        if (turn == 1) turn = 2;
        else turn = 1;
    }
    visited1.insert(visited2.begin(),visited2.end());
    int count = visited1.size();
    std::cout << "Number of distinct Houses visited: " << count << std::endl;
}