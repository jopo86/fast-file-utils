#include "FFUApplication.h"

FFUApplication::FFUApplication()
{
    response = "";
    paths = extensionFilter = {};
    noFilter = false;
}

void FFUApplication::start()
{
    mainMenu();
}

void FFUApplication::mainMenu()
{
    CU::Clear();
    CU::SetColor(CU::BLUE);
    std::cout << "FAST-FILE-UTILS by jopo86\n\n";
    CU::ResetStyle();

    std::cout << 
        "Select an option (enter the corresponding number):\n"
        "[0] Check if a file/directory exists\n"
        "[1] List all files/directories in a directory\n"
        "[2] Read a file\n"
        "[3] Write to a file\n"
        "[4] Find text in a file\n"
        "[5] Count occurences of text in file(s)\n"
        "[6] Count lines of file(s)\n"
        "[7] Count words in file(s)\n"
        "[8] Count characters in file(s)\n";
    
main_input:
    switch (parseInput())
    {
        case -1:
            err();
            break;
        case 0:
            checkExistence();
            break;
        case 1:
            listInDir;
            break;
        case 2:
            read();
            break;
        case 3:
            write();
            break;
        case 4:
            find();
            break;
        case 5:
            countOccurences();
            break;
        case 6:
            countLines();
            break;
        case 7:
            countWords();
            break;
        case 8:
            countChars();
            break;
    }
}

int FFUApplication::parseInput()
{
    int col = CU::GetColor();
    CU::SetColor(CU::WHITE);
    std::cout << ": ";
    CU::SetColor(CU::YELLOW);
    std::string response;
    std::getline(std::cin, response);
    CU::SetColor(col);

    std::string responseNoSpaces;
    for (int i = 0; i < response.length(); i++)
    {
        if (response[i] != ' ') responseNoSpaces += response[i];
    }
    response = responseNoSpaces;

    if (!isNumber(response)) return -1;
    return std::stoi(response);
}

bool FFUApplication::isNumber(char c)
{
    return c >= '0' && c <= '9';
}

bool FFUApplication::isNumber(std::string str)
{
    for (char c : str)
    {
        if (!isNumber(c)) return false;
    }
    return true;
}
