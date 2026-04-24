#include <bits/stdc++.h>
using namespace std;

std::string source = "Input.txt";
int p_size;
vector<vector<int>> problem;
vector<char> operation;
typedef unsigned long long int ull;


bool is_operator(const char c) {
    return c == '+' || c == '*';
}

void initialize_problem() {
    problem.resize(p_size);
}

void populate_problem(vector<int>& data) {
    for (int i = 0; i < p_size; i++)
        problem[i].emplace_back(data[i]);
}

ull apply_op (const ull a, const ull b, const char c) {
    switch (c) {
        case '+': return a + b;
        case '*': return a * b;
    }
}

ull commit() {
    ull solution = 0;
    for (int i = 0; i < p_size; i++) {
        vector<int>& numerals = problem[i];
        const char op = operation[i];
        for (int element : numerals) cout << element << " " << op << " "; cout << "\b\b\t= ";

        ull result = op=='+'?0:1;

        for (int number : numerals)
            result = apply_op(result, number, op);
        cout << result << endl;
        solution += result;
    }
    return solution;
}

void ingest(ifstream &fin) {
    string first_line;

    getline(fin, first_line);
    stringstream ss_f(first_line);

    vector<int> data; int element;
    while (ss_f >> element) data.emplace_back(element);
    p_size = data.size();
    initialize_problem();
    populate_problem(data);

    string line;
    while (getline(fin, line)) {
        if (line.empty()) continue;

        //check for first non-whitespace position
        int i2=0;
        while (line[i2] == ' ') i2++;
        char check = line[i2];

        if (std::isdigit(check)) {
            stringstream ss_i(line);
            int operand; int i = 0;

            while (ss_i >> operand) problem[i++].emplace_back(operand);
        }
        else if (is_operator(check)) {
            stringstream ss_o(line);
            char op;
            while (ss_o >> op) operation.emplace_back(op);
        }
    }
}

void print_operands() {
    cout << endl << "Operands: " << endl;
    for (auto& i : problem){
        for (auto j : i) cout << j << " ";
        cout << endl;
    }
}

void print_operators() {
    cout << endl << "Operators: " << endl;
    for (auto i : operation)
        cout << i << " ";
    cout << endl << endl;
}

int main() {
    ifstream fin(source);
    ingest(fin);

    print_operands();
    print_operators();

    ull solution = commit();

    std::cout << endl << "Solution: " << solution << std::endl;
    return 0;
}




// while (getline(fin,line)) {
//     if (line.empty()) continue;
//
//     const char* ptr = line.data();
//     const char* end = line.data() + line.size();
//
//     if (std::isdigit(static_cast<unsigned char>(line[0]))) {
//         vector<int> current_row; int val;
//         int i = 0;
//
//         while (ptr != end) {
//             auto [next, ec] = from_chars(ptr, end, val);
//             if (ec == std::errc{}) {
//
//                 current_row.push_back(val);
//                 ptr = next;
//                 while (ptr!= end and std::isspace(*ptr)) ++ptr;
//             }
//             else ptr++;
//         }
//         operands.push_back(current_row);
//     }
//     else if (is_operator(line[0])) {
//         for (char c: line) {
//             if (is_operator(c)) operators.push_back(c);
//         }
//     }
// }