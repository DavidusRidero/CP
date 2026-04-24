#include <bits/stdc++.h>

std::string source = "Input.txt";
int solution = 0;

typedef unsigned long long ull;
std::set<std::pair<ull,ull>> valid;

void print_valid() {
    for (auto [a,b]:valid)
        std::cout << a << " - " << b << std::endl;
}

void ingest(std::ifstream &fin) {
    std::string line;
    ull first,second;

    while (std::getline(fin,line) and !line.empty()) {
        std::stringstream ss(line);
        ss >> first; ss.ignore(1); ss >> second;
        valid.insert(std::pair<ull,ull>(first,second));
    };
}

void optimisation() {
    auto current = valid.begin(); ++current;
    for (; current != valid.end(); ++current) {
        auto prev = std::prev(current);
        // No overlap case
        if (prev->second < current->first) continue;

        //By here, they either meet or prev subsumes the current.
        auto element = std::pair(prev->first, std::max(prev->second, current->second));
        valid.insert(element);
        valid.erase(current);
        valid.erase(prev);
        current = std::prev(valid.find(element));

    }
}

int main() {
    std::ifstream fin(source);

    ingest(fin);
    std::cout << "Original: " << std::endl;
    print_valid();
    std::cout << std::endl;

    optimisation();
    std::cout << "Optimised: " << std::endl;
    print_valid();
    std::cout << std::endl;

    ull current;
    while (fin >> current) {
        std::cout << current << " : ";
        auto range = valid.lower_bound(std::make_pair(current,0));
        if (range == valid.begin()) continue;
        auto it = std::prev(range);

        bool fresh = current >= it->first and current <= it->second;
        if (it != valid.end() and fresh) {
            std::cout << "Valid with " << it->first << " - " << it->second << std::endl;
            solution++;
            continue;
        }
        std::cout << "Invalid" << std::endl;
    }
    std::cout << std::endl << solution << std::endl;
    return 0;
}