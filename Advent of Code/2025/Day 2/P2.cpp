#include <bits/stdc++.h>

int main() {
    std::ifstream fin("Input.txt");

    //The solution.
    unsigned long long count = 0;

    //The input numbers.
    unsigned long long n1,n2;

    //Length of the input.
    int l1,l2;

    //Helper variable to maintain counts.
    int index = 1;

    //variable to hold the hyphen, only to be not used.
    char ignore;

    while (fin >> n1 >> ignore >> n2) {
        l1 = static_cast<int>(std::log10((n1))) + 1;
        l2 = static_cast<int>(std::log10((n2))) + 1;

        std::cout << index++ << ". " << n1 << " - " << n2 << " : ";

        //True if even
        bool o1 = not (l1&1);
        bool o2 = not (l2&1);

        if(not o1 and not o2) {std::cout << "\n"; continue;}
        if(not o1) {n1 = (long long)std::pow(10,l1);}

        std::string s1 = std::to_string(n1);
        l1 = static_cast<int>(std::log10((n1))) + 1;

        for (int len = l1; len <= l2; ++len) {
            if (len&1) continue; // Only even lengths can have double repeats

            long long multiplier = std::pow(10, len / 2) + 1;
            long long firstHalfStart = std::pow(10, (len / 2) - 1);
            long long firstHalfEnd = std::pow(10, len / 2) - 1;

            for (long long half = firstHalfStart; half <= firstHalfEnd; ++half) {
                long long candidate = half * multiplier;

                if (candidate > n2) break; // Optimization: Stop if we passed the range
                if (candidate >= n1) {
                    std::cout << candidate << " ";
                    count += candidate;
                }
            }
        }

        std::cout << "\n";
    }
    std::cout << "Number of counts: " << count << std::endl;
}


//        if(o2)
//        {
//        ss2 = s2.substr(0, l2/2);
//        ss2 += ss2;
//        check = std::stoll(ss2);
//
//        if(check>=n1 and check <= n2) {count+= check; std::cout << check << " ";}
//        }
//
//while(true){
//check = nn1 * ((long long)std::pow(10,l1/2) + 1);
//if(check>=n1 and check <= n2) {count+= check; std::cout << check << " ";}
//if(check > n2) break;
//nn1++;
//}