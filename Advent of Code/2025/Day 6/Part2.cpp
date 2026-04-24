#include <bits/stdc++.h>
typedef unsigned long long int ull;
using namespace std;

std::string source = "Input.txt";
int p_size;
vector<vector<int>> problem;
vector<char> operation;

ull check_char_at(const string& l, const int i) {
    const char c = l[i];
    return (c==' ')?0:static_cast<int>(c-48);
}

ull apply_operation(ull num, ull a, char op) {
    switch (op) {
        case '*': return (a*num); break;
        case '+': return (a+num); break;
    }
}

int main() {
    ifstream fin(source);
    ull solution = 0;

    string l1,l2,l3,l4,o1;
    getline(fin, l1);
    getline(fin, l2);
    getline(fin, l3);
    getline(fin, l4);
    getline(fin, o1);

    //Manual Padding
    l1 += " ";
    l2 += " ";
    l3 += " ";
    o1 += " ";

    int length = l1.length();
    vector<ull> numbers;

    for(int i = length-1; i >= 0; i--) {
        string digits = "";
        digits += l1[i];
        digits += l2[i];
        digits += l3[i];
        digits += l4[i];

        auto eraser = std::remove(digits.begin(), digits.end(), '0');
        digits.erase(eraser, digits.end());
        digits.erase(std::remove(digits.begin(), digits.end(), ' '), digits.end());
        if (digits.empty()) continue;

        numbers.push_back(std::stoll(digits));

        if (o1[i] == '*') {
                ull count = 1;
                cout << o1[i] << " = ";
                for (ull numeral : numbers) {
                    count = apply_operation(count,numeral,o1[i]);
                }
                solution += count;
                cout << count << endl;
                numbers.clear();
            }
            else if (o1[i] == '+') {
                ull count = 0;
                cout << o1[i] << " = ";
                for (ull numeral : numbers)
                    count = apply_operation(count,numeral,o1[i]);
                solution += count;
                cout << count << endl;
                numbers.clear();
        }
    }
    std::cout << endl << "Solution: " << solution << std::endl;
    return 0;
}




// ull num = thou*1000 + hund*100 + tens*10 + ones;
// if (!num) continue;
// numbers.push(num);
// cout << num << ", ";
//
// if (o1[i] == '*') {
//     ull count = 1;
//     cout << o1[i] << " = ";
//     for (ull numeral : numbers) {
//         count = apply_operation(count,numeral,o1[i]);
//     }
//     solution += count;
//     cout << count << endl;
//     numbers.clear();
// }
// else if (o1[i] == '+') {
//     ull count = 0;
//     cout << o1[i] << " = ";
//     for (ull numeral : numbers)
//         count = apply_operation(count,numeral,o1[i]);
//     solution += count;
//     cout << count << endl;
//     numbers.clear()