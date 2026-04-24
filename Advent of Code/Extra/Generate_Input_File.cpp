#include <iostream>
#include <fstream>
#include <cstdlib>
#include <ctime>

int main() {
    std::ofstream outFile("output.txt"); // output file
    if (!outFile) {
        std::cerr << "Error opening file!" << std::endl;
        return 1;
    }

    std::srand(static_cast<unsigned>(std::time(nullptr))); // seed RNG

    const int COUNT = 500;
    const int MAX_VALUE = 10000;

    for (int i = 0; i < COUNT; ++i) {
        int num = std::rand() % (MAX_VALUE + 1); // random number [0, 10000]
        outFile << num;
        if (i < COUNT - 1) outFile << "\n"; // space separator
    }

    outFile.close();
    std::cout << "File 'output.txt' generated successfully." << std::endl;
    return 0;
}
