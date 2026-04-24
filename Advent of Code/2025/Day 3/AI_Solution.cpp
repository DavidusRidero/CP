#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <fstream>

// This is the "Valid" partitioning logic you asked about.
// Instead of finding the absolute max and going backwards,
// we find the max possible digit for the CURRENT position.
std::string solve_largest_subsequence(const std::string& line, int K) {
    std::string result = "";
    int n = line.length();
    int current_search_start = 0;

    // We need to pick K digits.
    for (int i = 0; i < K; ++i) {
        char max_digit = '/'; // Character smaller than '0'
        int best_index = -1;

        // The "Window": We must leave enough characters after best_index 
        // to pick the remaining (K - 1 - i) digits.
        // So, the furthest we can look is: n - (remaining digits needed)
        int search_end = n - (K - i);

        for (int j = current_search_start; j <= search_end; ++j) {
            if (line[j] > max_digit) {
                max_digit = line[j];
                best_index = j;
                // Optimization: if we find a '9', we can't do better.
                if (max_digit == '9') break; 
            }
        }

        result += max_digit;
        current_search_start = best_index + 1;
    }

    return result;
}

int main() {
    std::ifstream fin("Input.txt");
    if (!fin) {
        std::cerr << "Could not open Test.txt" << std::endl;
        return 1;
    }

    const int MAX = 12;
    unsigned long long total_solution = 0;
    std::string line;

    while (fin >> line) {
        if (line.length() < MAX) continue;

        std::string numeral = solve_largest_subsequence(line, MAX);
        std::cout << line << ": " << numeral << std::endl;
        
        total_solution += std::stoull(numeral);
    }

    std::cout << "\nTotal Solution: " << total_solution << std::endl;
    return 0;
}