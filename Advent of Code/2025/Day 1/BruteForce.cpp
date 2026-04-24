#include <bits/stdc++.h>

int main() {
    std:std::ifstream fin("Input.txt");
    std::ios::sync_with_stdio(false);

    int initial_marker = 50;
    int zero_count = 0;

    char direction;
    int magnitude;
    int laps, remainder;

    while (fin >> direction >> magnitude) {
        laps = magnitude / 100;
        remainder = magnitude-(laps * 100);

        zero_count += laps;

        if (direction == 'L') {
            int next_pos = initial_marker - remainder;
            if (next_pos <= 0 && initial_marker > 0) zero_count++;
            initial_marker = next_pos;
            if (initial_marker < 0) initial_marker += 100;
        }
        else {
            int next_pos = initial_marker + remainder;
            if (next_pos >= 100) {
                zero_count++;
                next_pos -= 100;
            }
            initial_marker = next_pos;
        }
    }
    std::cout << "Zero Counts: " << zero_count << std::endl;
}