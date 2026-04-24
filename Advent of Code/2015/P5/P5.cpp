#include <bits/stdc++.h>

int main() {
    namespace fs = std::filesystem;
    fs::path p = "P5_input.txt";
    std::ifstream in(p,std::ios::binary);

    std::string word;
    std::vector<std::string> banned = {"ab","cd","pq","xy"};

    int nice = 0;

    while (std::getline(in,word)) {
        std::unordered_map<char,int> freq;
        for (auto c : word) freq[c]++;

        bool naughty = false;
        for (auto p : banned)
            if (word.find(p) != std::string::npos) {naughty = true; break;}
        if (naughty) continue;

        if (freq['a'] + freq['e'] + freq['i'] + freq['o'] + freq['u'] < 3) continue;

        bool no_doubles = true;
        // std::set<char> doubles;
        for (auto const& [letter, frequency] : freq)
            if (frequency > 1) {
                std::string pattern;
                pattern+=letter;
                pattern+=letter;
                if (word.find(pattern) != std::string::npos) {no_doubles = false; break;}
            }
        if (no_doubles) continue;

        nice++;
    }

    std::cout << "Number of Nice words: " << nice << std::endl;
}