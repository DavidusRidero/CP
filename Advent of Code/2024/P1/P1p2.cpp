#include <bits/stdc++.h>

int main() {
    namespace fs = std::filesystem;
    std::ifstream fin("Puzzle 1 Input.txt");
    // std::ifstream fin("test.txt");
    int count = 1000;

    std::unordered_map<int,int> first;
    std::unordered_map<int,int> second;
    int t1 = 0, t2 = 0;

    while (count--) {
        fin >> t1 >> t2;
        first[t1]++; second[t2]++;
    }


    int similarity = 0;

    for (auto& [num, mult] : first)
        similarity += num*mult*second[num];

    std::cout << "Similarity Score is " << similarity << std::endl;
}