#include <algorithm>
#include <bits/stdc++.h>

std::string source = "Input.txt";
int solution = 0;

typedef unsigned long long ull;
std::vector<std::pair<ull,ull>> valid;
std::vector<std::pair<ull,ull>> merged;

void print_valid() {

}

void ingest(std::ifstream &fin) {
    std::string line;
    ull first,second;

    while (std::getline(fin,line) and !line.empty()) {
        std::stringstream ss(line);
        ss >> first; ss.ignore(1); ss >> second;

        auto pair = std::make_pair(first,second);
        valid.push_back(pair);
    };
}

void optimisation() {
    sort(valid.begin(), valid.end());
    merged.emplace_back(valid.front().first, valid.front().second);

    int i = 1;
    while (i < valid.size()) {
        auto& [first, second] = merged.back();
        if(valid[i].first <= second) {second = std::max(second, valid[i].second);}
        else merged.emplace_back(valid[i].first,valid[i].second);
        i++;
    }
}

void print_valid_2() {
    for (auto [a,b]:valid)
        std::cout << a << " " << b << std::endl;
}

void print_merged() {
    for (auto [a,b]:merged)
        std::cout << a << " " << b << std::endl;
}

int main() {
    std::ifstream fin(source);
    ull solution = 0;

    ingest(fin);
    std::cout << "Original: " << std::endl;
    print_valid_2();
    std::cout << std::endl;

    optimisation();
    std::cout << "Optimised: " << std::endl;
    print_merged();
    std::cout << std::endl;

    ull current;

    while (fin >> current) {
        std::cout << current << " : ";
        auto it = std::lower_bound(merged.begin(), merged.end(), current,
            [](const std::pair<ull, ull>& range, ull id) {
                return range.second < id; // Clue: What defines being "before" a range?
            });
        if (it != merged.end() and current >= it->first and current <= it->second) {
            std::cout << "Fresh." << std::endl; solution++; continue;
        }
        std::cout << "Not Fresh" << std::endl;
    }

    std::cout << solution << std::endl;

    solution = 0;
    for (auto [a,b]:merged) solution += b-a+1;
    std::cout << "Second Solution: " << solution << std::endl;
}


// int i = 0;
// for (;i < valid.size()-1;i++) {
//     int start = i; int end = i+1;
//
//     //find consecutive ranges that overlap
//     ull first = valid[start].first;
//     ull second = valid[start].second;
//
//     while (end != valid.size() and valid[start].second >= valid[end].first) {
//         start++; end++;
//         second = std::max(second, valid[end].second);
//     }
//     //this will break when start's second element has a gap before the end's first element.
//
//     merged.emplace_back(first,second);
//     i = start;
// }
// if (i == valid.size()-2){ i++; merged.emplace_back(valid[i].first,valid[i].second); }