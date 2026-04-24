#include <bits/stdc++.h>
#include <algorithm>

using namespace std;
typedef unsigned long long ull;
std::string source = "Input.txt";

std::set<int> beam_indices;

std::vector<std::string> string_output;

int ingestion(std::ifstream &fin, std::vector<ull>& path_values) {
    std::set<int> indices;
    std::vector<ull> values;
    std::string line;
    int count = 0;

    //Peel
    getline(fin, line);

    string_output.push_back(line);
    const int s_location = static_cast<int>(line.find('S'));
    beam_indices.insert(s_location);
    std::vector<ull>(line.size(),0).swap(path_values);
    std::vector<ull>(line.size(),0).swap(values);
    path_values[s_location] = 1;



    while (getline(fin, line)) {
        for (int i:beam_indices)
            if (line[i] == '^') {
                count++;
                indices.insert(i-1); line[i-1] = '|'; values[i-1] += path_values[i];
                indices.insert(i+1); line[i+1] = '|'; values[i+1] += path_values[i];
            }
            else {
                indices.insert(i); line[i] = '|'; values[i] += path_values[i];
            }
        string_output.push_back(line);
        beam_indices.swap(indices);
        path_values.swap(values);
        indices.clear();
        std::vector<ull>(line.size(),0).swap(values);
    }
    return count;
}

void print_output() {
    for (const std::string& line:string_output)
        std::cout << line << std::endl;
}

void print_values(const std::vector<ull>& path_values) {
    ull count = 0;
    for (const ull i:path_values) {
        if (i) std::cout << i << " ";
        count += i;
    }
    std::cout << std::endl << "Total number of paths: " << count << std::endl;
}

int main() {
    std::ifstream fin (source);
    std::vector<ull> path_values;
    int solution = ingestion(fin,path_values);
    // print_output();
    print_values(path_values);
    // std::cout << std::endl << "Solution: " << solution << std::endl;

    return 0;
}



// std::string line;
// std::vector<std::string> temp_output;
// std::vector<bool> temp_beams {};
//
// std::getline(fin, line);
//
// edge = line.size();
// beams.resize(edge);
// temp_beams.resize(edge);
//
// beams[line.find('S')] = true;
// temp_output.push_back(line);
//
// while (getline(fin, line)) {
//     for (int i = 0; i < edge; i++) {
//         char c = line[i];
//         if (beams[i]) {
//             if (c=='^') {
//                 temp_beams[i-1] = true;
//                 temp_beams[i] = false;
//                 temp_beams[i+1] = true;
//             }
//         }
//     }
//     beams.swap(temp_beams);
//     std::ranges::fill(temp_beams, false);
// }