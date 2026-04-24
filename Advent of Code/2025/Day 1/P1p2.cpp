#include <bits/stdc++.h>

int mod(int a, int b) {
    return (a%b+b)%b;
}

int main() {
    std::ifstream fin("Input.txt");

    // int repeat = 10;
    int repeat = 4484;

    int initial_marker = 50, final_marker;
    char direction; int magnitude;

    int zero_count = 0;

    while (repeat--) {
        fin >> direction >> magnitude;

        zero_count+=magnitude/100;
        magnitude = magnitude%100;

        if (direction == 'L')magnitude=-magnitude;

        final_marker = mod(initial_marker + magnitude, 100);

        if (final_marker < initial_marker and magnitude > 0) zero_count++;
        if ((final_marker > initial_marker or final_marker == 0) and magnitude < 0) zero_count++;

        initial_marker = final_marker;
    }

    std::cout << "Zero counts: " << zero_count << std::endl;
}