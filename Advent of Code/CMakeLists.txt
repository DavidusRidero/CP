cmake_minimum_required(VERSION 4.0)
project(Advent_of_Code)

set(CMAKE_CXX_STANDARD 23)

add_executable(Advent_of_Code main.cpp
        2015/P1/Puzzle_1.cpp
        2015/P2/Puzzle_2.cpp
        2015/P3/Puzzle_3.cpp
        2015/P3/P3_p2.cpp
        2015/P5/P5.cpp
        2015/P5/P5_2.cpp
        2024/P1/P1p2.cpp
        2024/P3/P3.cpp
        "2025/Day 1/P1.cpp"
        "2025/Day 1/P1p2.cpp"
        "2025/Day 1/BruteForce.cpp"
        "2025/Day 2/P2.cpp"
        "2025/Day 3/Solution.cpp"
        "2025/Day 3/Part2.cpp"
        "2025/Day 3/AI_Solution.cpp"
        "2025/Day 4/Part1.cpp"
        "2025/Day 4/Part2.cpp"
        "2025/Day 5/Part1.cpp"
        "2025/Day 5/Part1_Take2.cpp"
        "2025/Day 6/Part1.cpp"
        "2025/Day 6/Part2.cpp"
        "2025/Day 7/Part1.cpp"
        "2025/Day 8/Part1.cpp"
        "2025/Day 8/Kruskals.cpp"
        "2025/Day 8/AI_solution.cpp"
        "2025/Day 9/Part1.cpp"
        "2025/Day 9/Part2_BP.cpp"
        "2025/Day 10/Day10.cpp"
        Extra/Generate_Input_File.cpp
)
