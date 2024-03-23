#include "../src/FFU.h"

int main()
{
    std::cout << "\nReading from tests\\test.txt\n---\n";
    std::cout << "Exists --------------------- " << (FFU::Exists("..\\tests\\test.txt") ? "true" : "false") << "\n";
    std::cout << "Find \"what's\" -------------- " << FFU::Find("what's", "..\\tests\\test.txt") << "\n";
    std::cout << "Count \"cc\" ----------------- " << FFU::CountOccurrences("cc", "..\\tests\\test.txt") << "\n";
    std::cout << "Count no overlap \"cc\" ------ " << FFU::CountOccurrencesNoOverlap("cc", "..\\tests\\test.txt") << "\n";
    std::cout << "Count lines ---------------- " << FFU::CountLines("..\\tests\\test.txt") << "\n";
    std::cout << "Count lines no empty ------- " << FFU::CountLinesNoEmpty("..\\tests\\test.txt") << "\n";
    std::cout << "Count words ---------------- " << FFU::CountWords("..\\tests\\test.txt") << "\n";
    std::cout << "Count chars ---------------- " << FFU::CountChars("..\\tests\\test.txt") << "\n";
    std::cout << "Count chars ---------------- " << FFU::CountCharsNoSpaces("..\\tests\\test.txt") << "\n\n";

    std::cout << "Is Dir \"tests\" ------------- " << (FFU::IsDir("..\\tests") ? "true" : "false") << "\n";
    std::cout << "Is Dir \"test.txt\" ---------- " << (FFU::IsDir("..\\tests\\test.txt") ? "true" : "false") << "\n";
    std::cout << "Extension of \"test.txt\" ---- " << FFU::GetExtension("test.txt") << "\n";
    std::cout << "Filename of \"test.txt\" ----- " << FFU::GetFilename("test.txt") << "\n\n";
    std::cout << "Directory of \"fake\\dir\\test.txt\" ---- " << FFU::GetDir("fake\\dir\\test.txt") << "\n";

    std::cout << "All files and dirs in lib-version: \n---\n";
    for (std::string path : FFU::GetFilesAndDirsInDir("..\\")) std::cout << path << "\n";
    std::cout << "\n";

    std::cout << "All files in lib-version: \n---\n";
    for (std::string path : FFU::GetFilesInDir("..\\")) std::cout << path << "\n";
    std::cout << "\n";

    std::cout << "All dirs in lib-version: \n---\n";
    for (std::string path : FFU::GetDirsInDir("..\\")) std::cout << path << "\n";
    std::cout << "\n";

    std::cout << "All files and dirs in lib-version and subdirectories: \n---\n";
    for (std::string path : FFU::GetFilesAndDirsInDirRecursive("..\\")) std::cout << path << "\n";
    std::cout << "\n";

    std::cout << "All files in lib-version and subdirectories: \n---\n";
    for (std::string path : FFU::GetFilesInDirRecursive("..\\")) std::cout << path << "\n";
    std::cout << "\n";

    std::cout << "All dirs in lib-version and subdirectories: \n---\n";
    for (std::string path : FFU::GetDirsInDirRecursive("..\\")) std::cout << path << "\n";
    std::cout << "\n";

    std::cout << "All .cpp, .exe, and .a files in fast-file-utils and subdirectories: \n---\n";
    for (std::string path : FFU::GetFilesInDirRecursive("..\\..\\", { "cpp", "exe", "a" })) std::cout << path << "\n";

    return 0;
}
