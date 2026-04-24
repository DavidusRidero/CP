#include <bits/stdc++.h>

int main() {
    namespace fs = std::filesystem;
    const fs::path p = "P2_input.txt";
    std::ifstream in(p,std::ios::binary);

    int area = 0;
    int ribbon = 0;

    std::string line;
    while (std::getline(in,line)) {
        size_t fx = line.find('x');
        size_t sx = line.find('x',fx+1);

        int l = std::stoi(line.substr(0,fx));
        int w = std::stoi(line.substr(fx+1, sx-fx-1));
        int h = std::stoi(line.substr(sx+1));

        area += 2*(l*w+w*h+h*l) + std::min({l*w,w*h, h*l});
        ribbon += 2*(l+w+h - std::max({l,w,h})) + l*w*h;
    }

    std::cout<< "Area required: "<< area << std::endl;
    std::cout<< "Ribbon required: "<< ribbon << std::endl;
}