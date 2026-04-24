#include <bits/stdc++.h>

int main() {
    namespace fs = std::filesystem;
    const fs::path p = "P5_input.txt";
    std::ifstream in(p,std::ios::binary);

    std::string word;

    std::string test = "uurcxstgmygtbstg";
    word = test;

    int nice = 0;

    // while (std::getline(in,word)){
        std::unordered_map<char,int> freq;
        for (auto c : word) freq[c]++;

        std::set<char> mults;
        for (auto& [character, frequency]:freq)
            if (frequency>1)mults.insert(character);

        for (char c : mults) std::cout << c << std::endl;
    // }

    std::cout << "Number of Nice words: " << nice << std::endl;
}