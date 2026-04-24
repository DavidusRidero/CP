#include <bits/stdc++.h>

void print_indexes(std::unordered_map<int, std::set<int>> indexes) {
    for (int i = 0; i <=9; i++) {
        if (!indexes[i].empty()){
            std::cout << i << " indexes : " << std::endl;
            for (auto it:indexes[i])
                std::cout << it << " ";
            std::cout << std::endl;
        }
    }
}

void print_create(const std::set<int>& create) {
    for (auto it: create)
        std::cout << it << " ";
    std::cout << std::endl;
}

std::string print_create_numerals(const std::set<int>& create, std::string line) {
    std::string numeral;
    for (auto it: create) {
        numeral = numeral + line[it];
    }
    std::cout << numeral << std::endl;
    return numeral;
}


int main() {
    std::ifstream fin("Test.txt");

    unsigned long long solution = 0;
    const int MAX = 12;
    std::string line;

    while (fin >> line) {
        std::cout << line << ": ";

        // We will be using create.size() to verify against MAX, instead of manual counting.
        // int count = 0;

        // This stores the indexes of numerals to be considered. This will be passed to a function to generate the jolt number.
        std::set<int> create;

        // Not needed for we are initializing a new one for each input.
        // std::set<int>().swap(create);

        // Stores which numeral exists at which index.
        std::unordered_map<int, std::set<int>> index;

        // Populate the indexes hash-set
        for (int i = 0; i < line.length(); i++) {
            int num = line[i] - '0';
            index[num].insert(i);
        }

        // Find the highest number that occurs.
        int current = -1;
        for (int i = 9; i >= 0; i--)
            //The first non-empty set, iterating downwards.
            if (!index[i].empty()){current = i; break;}

        // Logging function.
        // print_indexes(indexes);

        int partition = *index[current].begin();
        int highest = current-1;
        int first_index = -1;

        while (create.size()<MAX and current>-1) {
            bool first = true;
            int temp = -1;
            for (auto it: index[current])
                if (create.size() < MAX and it > first_index) {
                    create.insert(it);
                    if (first) { first = false; temp = it; }
                }
            if (!first) first_index = temp;
            current--;
        }

        //This is failsafe, if enough numerals exist after first highest.
        int run = line.size()-1;
        while (create.size() < MAX and run > partition) create.insert(run--);

        while (create.size() < MAX) {
            auto it = index[highest].rbegin();
            while (create.size() < MAX and it != index[highest].rend()) {
                if (*it > partition) { it++; continue; }
                create.insert(*it);
                ++it;
            }
            highest--;
        }

        std::string numeral = print_create_numerals(create, line);
        solution += std::stoll(numeral);
    }
    std::cout << std::endl << solution << std::endl;
}


// Discarded

        // while (create.size() < MAX) {
        //     auto it = index[highest].rbegin();
        //     while (create.size()<MAX and it != index[highest].rend()) {
        //         if (*it++ > partition) { it++; continue; }
        //         create.insert(*it);
        //     }
        //     highest--;
        // }

        // print_create(create);

/*
        int current_first = *index[current].begin() - 1;
        while (create.size() < MAX and current_first < 99) {
            //From reverse, add all occurrences of current, whose index is greater than current_first.
            auto it = index[current].rbegin();
            for (;(it!= index[current].rend()) and (*it > current_first) and create.size() < MAX; ++it)
                create.insert(*it);
            current_first = *(it--);
            current--;
        }


if (create.size()<MAX)
            while (create.size()<MAX and highest >-1) {
                auto it = index[highest].rbegin();
                while (create.size()<MAX and it != index[highest].rend())
                    if (*it < partition)
                        create.insert(*it);

                highest--;
            }
*/
