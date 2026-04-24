#include <bits/stdc++.h>
#include <ranges>
using namespace std;

constexpr size_t length = 138;
//Extra row at the beginning and the end are added and padded.
array<array<int, length>, length+2> rolls{};

void ingestion() {
    std::ifstream fin("Input.txt");

    string line;
    int r = 1;
    while(fin >> line) {
        int c = 0;
        for (const auto ch : line) {
            if (ch == '@')
                rolls[r][c] = 1;
            c++;
        }
        r++;
    }
}

int row = 3;
auto* upper = &rolls[0];
auto* middle = &rolls[1];
auto* lower = &rolls[2];

void init() {
    row = 3;
    upper = &rolls[0];
    middle = &rolls[1];
    lower = &rolls[2];
}

int c5(const int i, const char c) {
    if ((*middle)[i] == 0) return 0;

    int sum = 0;
    sum += (*upper)[i] + (*lower)[i];

    if (c == '+') sum +=(*upper)[i+1] + (*middle)[i+1] +(*lower)[i+1];
    if (c == '-') sum +=(*upper)[i-1] + (*middle)[i-1] +(*lower)[i-1];

    if (sum < 4) { (*middle)[i] = 0; return 1;}
    return 0;
}

int c8(const int i) {
    int sum = -(*middle)[i];
    int counter = -1;
    while (counter != 2){
        sum += (*upper)[i+counter] + (*middle)[i+counter] + (*lower)[i+counter]; counter++;}

    if (sum < 4) { (*middle)[i] = 0; return 1;}
    return 0;
}

void print_rolls() {
    cout << "Rolls Matrix: " << endl;
    for (const auto& row: rolls) {
        for (int val : row)
            cout << val;
        cout << endl << endl;
    }
}


int main() {
    ingestion();

    int solution = 0;
    int counter = 1;
    int pass_changes;
    // int kill_switch = 15;

    do {
        init();
        pass_changes = 0;

        while (row != length+3) {
            int row_changes = 0;

            row_changes += c5(0, '+') + c5(length-1, '-');
            for (auto iter = middle->begin()+1; iter!=middle->end()-1; ++iter)
                if (*iter == 1)
                    pass_changes += c8(iter - middle->begin());

            pass_changes += row_changes;
            upper = middle;
            middle = lower;
            lower = &rolls[row];
            row++;
        }
        solution += pass_changes;
        cout << "Pass " << counter++ << ": " << pass_changes << endl;
        // print_rolls();
    }
    while (pass_changes > 0);
    cout << "Solution: "<< solution << endl;
}