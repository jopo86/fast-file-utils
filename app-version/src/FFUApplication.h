#include <iostream>
#include <string>
#include <vector>

#include <ConsoleUtils.h>
#include <FFU.h>

namespace CU = ConsoleUtils;

class FFUApplication
{
public:
    FFUApplication();

    void start();
    void mainMenu();

    void checkExistence();
    void listInDir();
    void read();
    void write();
    void find();
    void countOccurences();
    void countLines();
    void countWords();
    void countChars();

    int parseInput();
    void err();

private:
    bool isNumber(char c);
    bool isNumber(std::string str);

    std::string response;
    std::vector<std::string> paths;
    std::vector<std::string> extensionFilter;
    bool noFilter;

};
