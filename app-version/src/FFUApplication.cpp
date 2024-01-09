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
        "[8] Count characters in file(s)\n"
        "[9] Exit\n";
    
main_input:
    switch (inputNum())
    {
        case -1:
            err("Invalid response. Please enter a number between 0 and 9.");
            goto main_input;
            break;
        case 0:
            checkExistence();
            mainMenu();
            break;
        case 1:
            listInDir();
            mainMenu();
            break;
        case 2:
            read();
            mainMenu();
            break;
        case 3:
            write();
            mainMenu();
            break;
        case 4:
            find();
            mainMenu();
            break;
        case 5:
            countOccurences();
            mainMenu();
            break;
        case 6:
            countLines();
            mainMenu();
            break;
        case 7:
            countWords();
            mainMenu();
            break;
        case 8:
            countChars();
            mainMenu();
            break;
        case 9: break;
    }
}

void FFUApplication::checkExistence()
{
    std::cout << "\nEnter the filepath to check: ";
    std::string path = input();
    std::cout << "\n" << path << (FFU::Exists(path) ? " exists." : " does not exist.") << "\n";
    std::cout << "Press enter to go back to main menu.";
    std::cin.get();
}

void FFUApplication::listInDir()
{
    paths.clear();
    extensionFilter.clear();

    std::cout << "\nEnter the directory.\n";
directory_input:
    std::string dir = input();
    if (!FFU::Exists(dir))
    {
        err("Directory does not exist. Please re-enter.");
        goto directory_input;
    }
    std::cout << "Search subdirectories? (y/n)\n";
subdir_input:
    response = input();
    if (response == "y" || response == "Y") subdirs = true;
    else if (response == "n" || response == "N") subdirs = false;
    else
    {
        err("Invalid response. Please enter \"y\" or \"n\".");
        goto subdir_input;
    }
    std::cout << 
        "\nSelect an option (enter the corresponding number):\n"
        "[0] List all files and directories\n"
        "[1] List all files\n"
        "[2] List all directories\n"
        "[3] List all files with certain extensions\n";
    
list_input:
    switch (inputNum())
    {
        case -1:
            err("Invalid response. Please enter a number between 0 and 3.");
            goto list_input;
            break;
        case 0:
            paths = subdirs ? FFU::GetFilesAndDirsInDirRecursive(dir) : FFU::GetFilesAndDirsInDir(dir);
            break;
        case 1:
            paths = subdirs ? FFU::GetFilesInDirRecursive(dir) : FFU::GetFilesInDir(dir);
            break;
        case 2:
            paths = subdirs ? FFU::GetDirsInDirRecursive(dir) : FFU::GetDirsInDir(dir);
            break;
        case 3:
            std::cout << "\nEnter each extension on a new line (enter \"-\" to finish)\n";
            std::string ext;
            while (ext != "-")
            {
                ext = input(".");
                if (ext != "-") extensionFilter.push_back(ext);
            }
            paths = subdirs ? FFU::GetFilesInDirRecursive(dir, extensionFilter) : FFU::GetFilesInDir(dir, extensionFilter);
            break;
    }

    std::cout << "\n" << paths.size() << " files/directories found:\n";
    for (std::string path : paths)
    {
        std::cout << path << "\n";
    }
    std::cout << "\nPress enter to go back to main menu.";
    std::cin.get();
}

void FFUApplication::read()
{

}

void FFUApplication::write()
{

}

void FFUApplication::find()
{

}

void FFUApplication::countOccurences()
{

}

void FFUApplication::countLines()
{

}

void FFUApplication::countWords()
{

}

void FFUApplication::countChars()
{

}

std::string FFUApplication::input(std::string prefix)
{
    int col = CU::GetColor();
    CU::SetColor(CU::WHITE);
    std::cout << ": ";
    CU::SetColor(CU::YELLOW);
    std::cout << prefix;
    std::string response;
    std::getline(std::cin, response);
    CU::SetColor(col);
    return response;
}

int FFUApplication::inputNum()
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
    int num = std::stoi(response);
    if (num < 0 || num > 9) return -1;
    return num;
}

void FFUApplication::err(std::string msg)
{
    int col = CU::GetColor();
    CU::SetColor(CU::RED);
    std::cout << msg << "\n";
    CU::SetColor(col);
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
