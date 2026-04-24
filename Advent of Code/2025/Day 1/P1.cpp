#include <bits/stdc++.h>
bool last_marker_is_zero = false;
void circular_op(int* marker, int* zero_count, char direction,int value) {
    *zero_count+=value/100;
    value %= 100;

    if (direction == 'L')
        value=-value;

    *marker+=value;

    if (*marker>=100)
        {*marker%=100; return;}
    if (*marker<0)
        {*marker+=100; if (!last_marker_is_zero)*zero_count+=1;}
}


int main() {
    namespace fs = std::filesystem;
    std::ifstream fin("Input.txt");
    // int repeat = 4484;
    int repeat = 10;

    int marker=50;
    int zero_count = 0;

    char direction; int value;

    while (repeat--) {
        fin >> direction >> value;
        circular_op(&marker, &zero_count, direction,value);
        if (marker == 0) {zero_count++;last_marker_is_zero = true;}
        if (marker != 0) last_marker_is_zero = false;
    }
    std::cout<< "Zero Counts: " << zero_count << std::endl;
}