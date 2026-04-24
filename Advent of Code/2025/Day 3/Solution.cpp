//
// Created by VijayKumar on 13-02-2026.
//
#include <bits/stdc++.h>

void print_stack(std::stack<int> stack) {
    while (!stack.empty()) { std::cout << stack.top() << " "; stack.pop();}
}

std::pair<int, int> bottom_two(std::stack<int> stack) {
    while (stack.size()>2) stack.pop();
    int second_pop = stack.top(); stack.pop();
    return std::make_pair(stack.top() , second_pop);
}

int main()
{
    std::ifstream fin("Input.txt");
    std::stack<int> stack;

    int solution = 0;
    std::string line;
    int last_pop;

    while (fin >> line) {
        std::stack<int>().swap(stack);
        stack.push(-1);

        for (char c : line) {
            int num = c - '0';
            while (not stack.empty() and (num>stack.top())) {
                last_pop = stack.top();
                stack.pop();
            }
            stack.push(num);
        }
        // print_stack(stack);
        // std::cout << " . " << last_pop << std::endl;

        int sum;
        if (stack.size()>1) {
            auto [a, b] = bottom_two(stack);
            sum = a*10+b;
        }
        else
            sum = last_pop*10 + stack.top();

        solution += sum;
        std::cout << sum << " " << stack.size() << std::endl;
    }
    std::cout << std::endl << solution << std::endl;
}