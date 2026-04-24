#include <bits/stdc++.h>

int main() {
    namespace fs = std::filesystem;
    const fs::path p = "P3_input.txt";
    std::ifstream in(p,std::ios::binary);
    std::string test = "^v^v^v^v^v";

    std::pair<int,int> point {0,0};
    auto& [x,y] = point;

    std::set<std::pair<int,int>> visited;
    visited.insert({x,y});

    // for (char c: test)
    char c;
    while (in.get(c)) {
        switch (c) {
            case '^': y++; break;
            case 'v': y--; break;
            case '<': x--; break;
            case '>': x++; break;
        }
        visited.insert({x,y});
    }
    int count = visited.size();
    std::cout << "Number of Distinct Houses visited: " << count << std::endl;
}