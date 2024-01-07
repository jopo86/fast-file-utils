#include "../src/FFU.h"

int main()
{
    std::cout << "\nReading from test.txt\n\n";
    std::cout << "Exists --------------------- " << (FFU::Exists("../tests/test.txt") ? "true" : "false") << "\n";
    std::cout << "Find \"what's\" -------------- "   << FFU::Find("what's", "../tests/test.txt") << "\n";
    std::cout << "Count \"cc\" ----------------- "   << FFU::CountOccurences("cc", "../tests/test.txt") << "\n";
    std::cout << "Count no overlap \"cc\" ------ "   << FFU::CountOccurencesNoOverlap("cc", "../tests/test.txt") << "\n";
    std::cout << "Count lines ---------------- " << FFU::CountLines("../tests/test.txt") << "\n";
    std::cout << "Count lines no empty ------- " << FFU::CountLinesNoEmpty("../tests/test.txt") << "\n";
    std::cout << "Count words ---------------- " << FFU::CountWords("../tests/test.txt") << "\n";
    std::cout << "Count chars ---------------- " << FFU::CountChars("../tests/test.txt") << "\n";
    std::cout << "Count chars ---------------- " << FFU::CountCharsNoSpaces("../tests/test.txt") << "\n";

    return 0;
}
