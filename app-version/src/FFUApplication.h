#include <iostream>
#include <string>
#include <vector>

#include <ConsoleUtils.h>
#include <FFU.h>
#include <sysinfo.h>

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
    void countOccurrences();
    void countLines();
    void countWords();
    void countChars();

    void err(std::string msg);
    void warn(std::string msg);

private:
    std::string input(std::string prefix = "");
    int inputNum();
    std::vector<std::string> inputFilepaths();

    bool isNumber(char c);
    bool isNumber(std::string str);
};
