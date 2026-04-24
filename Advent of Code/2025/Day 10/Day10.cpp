#include <bits/stdc++.h>

std::string source = "Test.txt";
struct Machine {
    std::vector<bool> Lights;
    std::vector<std::set<int>> Sequences;
    std::vector<int> Joltages;
};  std::vector<Machine> machine;

std::vector<bool>           parse_light     (const std::string_view light) {
    std::vector<bool> lights;

    for (const char c : light)
        if (c == '.') lights.emplace_back(false);
        else lights.emplace_back(true);
    return lights;
}
std::vector<std::set<int>>  parse_sequence  (const std::string_view sequence) {
    std::vector<std::set<int>> sequences;

    std::set<int> t_sequence;
    for (int i = 0; i < sequence.size(); i++)
        if (sequence[i] == '(') t_sequence.clear();
        else if (isdigit(sequence[i])) {
            int digit = sequence[i] - '0';
            while (isdigit(sequence[++i])) digit = digit * 10 + sequence[i] - '0';
            t_sequence.emplace(digit);
            i--;
        }
        else if (sequence[i] == ')') sequences.push_back(t_sequence);

    return sequences;
}
std::vector<int>            parse_joltage   (const std::string_view joltage) {
    std::vector<int> joltages;

    for (int i =0; i < joltage.size(); i++) {
        if (isdigit(joltage[i])) {
            int digit = joltage[i] - '0';
            while (isdigit(joltage[++i])) digit = digit * 10 + joltage[i] - '0';
            joltages.emplace_back(digit);
            i--;
        }
    }
    return joltages;
}

void ingestion() {
    std::ifstream fin(source);
    std::string line;
    while (std::getline(fin, line)) {
        std::string_view line_view = line;

        auto first_square = line.find(']');
        std::vector<bool> lights = parse_light(line_view.substr(1, first_square-1));

        auto first_curly = line_view.find('{');
        auto length = first_curly-first_square;
        std::vector<std::set<int>> sequences = parse_sequence(line_view.substr(first_square+2,length));

        std::vector<int> joltages = parse_joltage(line_view.substr(first_curly+1));

        machine.push_back({
            .Lights = lights,
            .Sequences = sequences,
            .Joltages = joltages});
    }
}

//For a machine to start,
//  'Lights' must be the final state, with all off being the initial state.
//Each set in sequence, toggles those particular lights.
//Joltage





int main() {
    ingestion();
    return 0;
}