#include <bits/stdc++.h>

int main() {
    namespace fs = std::filesystem;
    const fs::path p = "Puzzle_1 Input.txt";
    std::ifstream in(p,std::ios::binary);

    // const std::string line = "()))()((()()()((()))))";

    int count = 0;
    int length = 0;
    int flag = 0;

    char c;
    while (in.get(c)) {
        length++;
        if (c=='(') count+=1;
        if (c==')') count-=1;
        if (!flag && count == -1) {
            std::cout << "First Basement at: " << length << std::endl;
            flag = 1;
        }
    }

    // for (char c1:line) {
    //     if (c1 == '(') count++;
    //     if (c1 == ')') count--;
    // }

    std::cout << "Floor count: " << count << std::endl;
    return 1;
}