#include "FFUApplication.h"

FFUApplication::FFUApplication() {}

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
        "[4] Count occurrences of text in file(s)\n"
        "[5] Count lines of file(s)\n"
        "[6] Count words in file(s)\n"
        "[7] Count characters in file(s)\n"
        "[8] Exit\n";
    
main_num_input:
    int num = inputNum();
    if (num < 0 || num > 8)
    {
        err("Invalid response. Please enter a number between 0 and 8.");
        goto main_num_input;
    }

    switch (num)
    {
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
            countOccurrences();
            mainMenu();
            break;
        case 5:
            countLines();
            mainMenu();
            break;
        case 6:
            countWords();
            mainMenu();
            break;
        case 7:
            countChars();
            mainMenu();
            break;
        case 8: break;
    }
}

void FFUApplication::checkExistence()
{
    CU::Clear();
    std::cout << "\nEnter the filepath to check.\n";
    std::string path = input();
    std::cout << "That file" <<  (FFU::Exists(path) ? " exists." : " does not exist or is inaccessible.");

    CU::SetColor(CU::GREEN);
    std::cout << "\nDone. Press enter to return to main menu.";
    std::cin.get();
}

void FFUApplication::listInDir()
{
    CU::Clear();

    std::cout << "\nEnter the directory.\n";
list_dir_input:
    std::string dir = input();
    if (!FFU::Exists(dir))
    {
        err("Directory does not exist. Please re-enter.");
        goto list_dir_input;
    }
    std::cout << "Search subdirectories? (y/n)\n";
list_subdir_input:
    std::string response = input();
    bool subdirs;
    if (response == "y" || response == "Y") subdirs = true;
    else if (response == "n" || response == "N") subdirs = false;
    else
    {
        err("Invalid response. Please enter \"y\" or \"n\".");
        goto list_subdir_input;
    }
    std::cout << 
        "\nSelect an option (enter the corresponding number):\n"
        "[0] List all files and directories\n"
        "[1] List all files\n"
        "[2] List all directories\n"
        "[3] List all files with certain extensions\n";
    
list_num_input:
    int num = inputNum();
    if (num < 0 || num > 3)
    {
        err("Invalid response. Please enter a number between 0 and 3.");
        goto list_num_input;
    }

    std::vector<std::string> paths;
    std::vector<std::string> extensionFilter;

    switch (num)
    {
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

    CU::SetColor(CU::GREEN);
    std::cout << "\nDone. Press enter to return to main menu.";
    std::cin.get();
}

void FFUApplication::read()
{
    CU::Clear();
    std::cout << "Enter the filepath to read from.\n";
read_file_input:
    std::string path = input();
    if (!FFU::Exists(path))
    {
        err("File does not exist. Please re-enter.");
        goto read_file_input;
    }
    else if (FFU::IsDir(path))
    {
        err("Path is a directory. Please re-enter.");
        goto read_file_input;
    }

    CU::Clear();
    std::cout << FFU::Read(path);

    CU::SetColor(CU::GREEN);
    std::cout << "\nDone. Press enter to return to main menu.";
    std::cin.get();
}

void FFUApplication::write()
{
    CU::Clear();

write_file_input_reprompt:
    std::cout << "Enter the filepath to write to.\n";

write_file_input:
    std::string path = input();
    if (FFU::Exists(path))
    {
        if (FFU::IsDir(path))
        {
            err("Path is a directory. Please re-enter.");
            goto write_file_input;
        }
    }
    else
    {
        std::cout << "\n";
        warn("Warning: path does not exist. If you intend to create a new file enter \"y\". To re-enter, enter \"n\".");

write_file_continue_input:
        std::string response = input();
        if (response == "y" || response == "Y") {}
        else if (response == "n" || response == "N") goto write_file_input_reprompt;
        else
        {
            err("Invalid response. Please enter \"y\" or \"n\".");
            goto write_file_continue_input;
        }
        std::cout << "\n";
    }

    bool append = false;

write_append_input:
    std::cout << "Append text or overwrite? (a/o)\n";
    std::string response = input();
    if (response == "a" || response == "A") append = true;
    else if (response == "o" || response == "O") append = false;
    else
    {
        err("Invalid response. Please enter \"a\" or \"o\".");
        goto write_append_input;
    }

    std::cout << "\nEnter the text to write.\n";
    std::string text = input();

    append ? FFU::WriteAppend(text, path) : FFU::Write(text, path);

    CU::SetColor(CU::GREEN);
    std::cout << "\nDone. Press enter to return to main menu.";
    std::cin.get();
}

void FFUApplication::countOccurrences()
{
    CU::Clear();
    std::vector<std::string> paths = inputFilepaths();
    std::cout << "Enter the text to search for.\n";
    std::string text = input();
    std::cout << "Count overlapping occurrences too? (y/n)\n";
count_occurrences_overlap_input:
    bool overlap = false;
    std::string response = input();
    if (response == "y" || response == "Y") overlap = true;
    else if (response == "n" || response == "N") overlap = false;
    else
    {
        err("Invalid response. Please enter \"y\" or \"n\".");
        goto count_occurrences_overlap_input;
    }

    std::cout << "\nSearching " << paths.size() << " file" << (paths.size() == 1 ? "" : "s") << "...\n";

    int totalOccurrences = 0;
    for (std::string path : paths)
    {
        if (!FFU::Exists(path))
        {
            err("\"" + path + "\": not found or inaccessible");
            continue;
        }
        else if (FFU::IsDir(path))
        {
            err("\"" + path + "\": is a directory");
            continue;
        }
        int occurrences = overlap ? FFU::CountOccurrences(text, path) : FFU::CountOccurrencesNoOverlap(text, path);
        std::cout << "\"" << path << "\": " << occurrences << " occurrence" << (occurrences == 1 ? "" : "s") << "\n";
        totalOccurrences += occurrences;
    }

    CU::SetColor(CU::GREEN);
    std::cout << "\nDone. Total occurrences: " << totalOccurrences << ".\nPress enter to return to main menu.";
    std::cin.get();
}

void FFUApplication::countLines()
{
    CU::Clear();
    std::vector<std::string> paths = inputFilepaths();
    std::cout << "Count empty lines too? (y/n)\n";
count_lines_empty_input:
    bool empty = false;
    std::string response = input();
    if (response == "y" || response == "Y") empty = true;
    else if (response == "n" || response == "N") empty = false;
    else
    {
        err("Invalid response. Please enter \"y\" or \"n\".");
        goto count_lines_empty_input;
    }

    std::cout << "\nSearching " << paths.size() << " file" << (paths.size() == 1 ? "" : "s") << "...\n";

    int totalLines = 0;
    for (std::string path : paths)
    {
        if (!FFU::Exists(path))
        {
            err("\"" + path + "\": not found or inaccessible");
            continue;
        }
        else if (FFU::IsDir(path))
        {
            err("\"" + path + "\": is a directory");
            continue;
        }
        int lines = empty ? FFU::CountLines(path) : FFU::CountLinesNoEmpty(path);
        std::cout << "\"" << path << "\": " << lines << " line" << (lines == 1 ? "" : "s") << "\n";
        totalLines += lines;
    }

    CU::SetColor(CU::GREEN);
    std::cout << "\nDone. Total lines: " << totalLines << ".\nPress enter to return to main menu.";
    std::cin.get();
}

void FFUApplication::countWords()
{
    CU::Clear();
    std::vector<std::string> paths = inputFilepaths();

    std::cout << "Searching " << paths.size() << " file" << (paths.size() == 1 ? "" : "s") << "...\n";

    int totalWords = 0;
    for (std::string path : paths)
    {
        if (!FFU::Exists(path))
        {
            err("\"" + path + "\": not found or inaccessible");
            continue;
        }
        else if (FFU::IsDir(path))
        {
            err("\"" + path + "\": is a directory");
            continue;
        }
        int words = FFU::CountWords(path);
        std::cout << "\"" << path << "\": " << words << " word" << (words == 1 ? "" : "s") << "\n";
        totalWords += words;
    }

    CU::SetColor(CU::GREEN);
    std::cout << "\nDone. Total words: " << totalWords << ".\nPress enter to return to main menu.";
    std::cin.get();
}

void FFUApplication::countChars()
{
    CU::Clear();
    std::vector<std::string> paths = inputFilepaths();

    std::cout << "Searching " << paths.size() << " file" << (paths.size() == 1 ? "" : "s") << "...\n";

    int totalChars = 0;
    for (std::string path : paths)
    {
        if (!FFU::Exists(path))
        {
            err("\"" + path + "\": not found or inaccessible");
            continue;
        }
        else if (FFU::IsDir(path))
        {
            err("\"" + path + "\": is a directory");
            continue;
        }
        int chars = FFU::CountChars(path);
        std::cout << "\"" << path << "\": " << chars << " character" << (chars == 1 ? "" : "s") << "\n";
        totalChars += chars;
    }

    CU::SetColor(CU::GREEN);
    std::cout << "\nDone. Total characters: " << totalChars << ".\nPress enter to return to main menu.";
    std::cin.get();
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
    return num;
}

void FFUApplication::err(std::string msg)
{
    int col = CU::GetColor();
    CU::SetColor(CU::RED);
    std::cout << msg << "\n";
    CU::SetColor(col);
}

void FFUApplication::warn(std::string msg)
{
    int col = CU::GetColor();
    CU::SetColor(CU::MAGENTA);
    std::cout << msg << "\n";
    CU::SetColor(col);
}

std::vector<std::string> FFUApplication::inputFilepaths()
{
    std::vector<std::string> paths = {};
    std::cout << 
        "Select an option (enter the corresponding number):\n"
        "[0] Enter a single filepath\n"
        "[1] Enter multiple filepaths\n"
        "[2] Enter a directory and use all files in it\n"
        "[3] Enter a directory and use all files with certain extensions in it\n";

input_file_paths_num_input:
    int num = inputNum();
    if (num < 0 || num > 3)
    {
        err("Invalid response. Please enter a number between 0 and 3.");
        goto input_file_paths_num_input;
    }
    switch (num)
    {
        case 0:
        {
            std::cout << "\nEnter the path.\n";
            paths.push_back(input());
            break;
        }
        case 1:
        {
            std::cout << "\nEnter a prefix for convenience (leave blank for none).\n";
            std::string prefix = input();
            std::cout << "\nEnter each path on a new line (enter \"-\" to finish)\n";
            std::string path;
            while (path != "-")
            {
                path = input(prefix);
                if (path != "-") paths.push_back(prefix + path);
            }
            break;
        }
        case 2:
        {
            std::cout << "\nEnter the directory.\n";
input_file_paths_case2_dir_input:
            std::string dir = input();
            if (!FFU::Exists(dir))
            {
                err("Directory does not exist. Please re-enter.");
                goto input_file_paths_case2_dir_input;
            }
input_file_paths_case2_subdir_input:
            std::cout << "Search subdirectories? (y/n)\n";
            std::string response = input();
            bool subdirs;
            if (response == "y" || response == "Y") subdirs = true;
            else if (response == "n" || response == "N") subdirs = false;
            else
            {
                err("Invalid response. Please enter \"y\" or \"n\".");
                goto input_file_paths_case2_subdir_input;
            }
            paths = subdirs ? FFU::GetFilesInDirRecursive(dir) : FFU::GetFilesInDir(dir);
            break;
        }
        case 3:
        {
            std::cout << "\nEnter the directory.\n";
input_file_paths_case3_dir_input:
            std::string dir = input();
            if (!FFU::Exists(dir))
            {
                err("Directory does not exist. Please re-enter.");
                goto input_file_paths_case3_dir_input;
            }
input_file_paths_case3_subdir_input:
            std::cout << "Search subdirectories? (y/n)\n";
            std::string response = input();
            bool subdirs;
            if (response == "y" || response == "Y") subdirs = true;
            else if (response == "n" || response == "N") subdirs = false;
            else
            {
                err("Invalid response. Please enter \"y\" or \"n\".");
                goto input_file_paths_case3_subdir_input;
            }
            std::cout << "\nEnter each extension on a new line (enter \"-\" to finish)\n";
            std::string ext;
            std::vector<std::string> extensionFilter;
            while (ext != "-")
            {
                ext = input(".");
                if (ext != "-") extensionFilter.push_back(ext);
            }
            paths = subdirs ? FFU::GetFilesInDirRecursive(dir, extensionFilter) : FFU::GetFilesInDir(dir, extensionFilter);
            break;
        }
    }
    std::cout << "\n";

    return paths;
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
