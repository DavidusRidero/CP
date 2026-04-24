#include <bits/stdc++.h>
using namespace std;

std::string upper,middle,lower;

void sanitize(string& line) {
    replace(line.begin(), line.end(), '@', '1');
    replace(line.begin(), line.end(), '.', '0');
}

int count_3(const int i) {
    if (middle[i] == '1') return 1;
    return 0;
}

//had to employ 48 constant, because it's the ascii value for '0', so that 1 is considered as an int, not char.
int count_5(const int i, const char side) {
    if (middle[i] == '0') return 0;
    int sum = 0;
    if (side == 'd')
        sum += middle[i-1] + middle[i+1] + lower[i-1] + lower[i] + lower[i+1] - 48*5;
    if (side == 'u')
        sum += middle[i-1] + middle[i+1] + upper[i-1] + upper[i] + upper[i+1] - 48*5;
    if (side == 'r')
        sum += middle[i+1] + upper[i] + upper[i+1] + lower[i] + lower[i+1] - 48*5;
    if (side == 'l')
        sum += middle[i-1] + lower[i] + lower[i-1] + upper[i] + upper[i-1] - 48*5;

    return (sum < 4) ? 1 : 0;
}

int count_8(const int i) {
    int sum = upper[i-1]  + upper[i]  + upper[i+1]  +
              middle[i-1] +                   middle[i+1] +
              lower[i-1]  + lower[i]  + lower[i+1];
    sum -= 48*8;
    return (sum < 4) ? 1 : 0;
}

int main() {
    ifstream fin("Input.txt");
    string current;
    unsigned int solution = 0;
    unsigned int line = 1;


    //Manually handling operations for the first line.
    fin >> middle;
    fin >> lower;
    sanitize(middle);
    sanitize(lower);

    solution += count_3(0) + count_3(static_cast<int>(middle.size())-1);
    for (int i = 1; i < middle.size() - 1; i++)
        if (middle[i] == '1')
            solution += count_5(i, 'd');
    cout << line++ << ": " << solution << endl;

    //Upper is populated, at this point onwards.
    while (fin >> current){
        unsigned int counter = 0;
        sanitize(current);

        upper = middle;
        middle = lower;
        lower = current;

        counter += count_5(0,'r') + count_5(static_cast<int>(middle.size())-1, 'l');
        for (int i = 1; i < middle.size() - 1; i++)
            if (middle[i] == '1')
                counter += count_8(i);
        cout << line++ << ": " << counter << endl;
        solution += counter;
    }

    //Manually handling operations for the last line.
    upper = middle;
    middle = lower;
    lower.assign(middle.size(), '0');

    int counter = 0;
    counter += count_3(0) + count_3(static_cast<int>(middle.size())-1);
    for (int i = 1; i < middle.size() - 1; i++)
        if (middle[i] == '1')
            counter += count_5(i, 'u');
    cout << line++ << ": " << counter << endl;

    solution += counter;
    cout << endl << "Solution: " << solution << endl;
    return 0;
}
