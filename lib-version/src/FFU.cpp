#include "FFU.h"

bool FFU::Exists(std::string filepath)
{
    std::ifstream file(filepath);
    return std::filesystem::exists(filepath) || file.is_open();
}

bool FFU::IsDirectory(std::string filepath)
{
    return std::filesystem::is_directory(filepath);
}

std::string FFU::GetExtension(std::string filepath)
{
    std::string extension = "";
    for (int i = filepath.length() - 1; i >= 0; i--)
    {
        if (filepath[i] == '.')
        {
            extension = filepath.substr(i + 1, filepath.length() - i);
            break;
        }
    }
    return extension;
}

std::string FFU::GetFilename(std::string filepath)
{
    std::string filename = "";
    for (int i = filepath.length() - 1; i >= 0; i--)
    {
        if (filepath[i] == '.')
        {
            filename = filepath.substr(0, i);
            break;
        }
    }
    return filename == "" ? filepath : filename;
}

std::vector<std::string> FFU::GetFilesAndDirsInDir(std::string dir)
{
    if (!Exists(dir)) return { NULL };

    std::vector<std::string> files = {};
    for (const auto &entry : std::filesystem::directory_iterator(dir))
    {
        files.push_back(entry.path().string());
    }
    return files;
}

std::vector<std::string> FFU::GetFilesInDir(std::string dir)
{
    if (!Exists(dir)) return { NULL };

    std::vector<std::string> files = {};
    for (const auto &entry : std::filesystem::directory_iterator(dir))
    {
        if (!IsDirectory(entry.path().string())) files.push_back(entry.path().string());
    }
    return files;
}

std::vector<std::string> FFU::GetDirsInDir(std::string dir)
{
    if (!Exists(dir)) return { NULL };

    std::vector<std::string> files = {};
    for (const auto &entry : std::filesystem::directory_iterator(dir))
    {
        if (IsDirectory(entry.path().string())) files.push_back(entry.path().string());
    }
    return files;
}

std::vector<std::string> FFU::GetFilesAndDirsInDirRecursive(std::string dir)
{
    if (!Exists(dir)) return { NULL };

    std::vector<std::string> files = {};
    for (const auto &entry : std::filesystem::recursive_directory_iterator(dir))
    {
        files.push_back(entry.path().string());
    }
    return files;
}

std::vector<std::string> FFU::GetFilesInDirRecursive(std::string dir)
{
    if (!Exists(dir)) return { NULL };

    std::vector<std::string> files = {};
    for (const auto &entry : std::filesystem::recursive_directory_iterator(dir))
    {
        if (!IsDirectory(entry.path().string())) files.push_back(entry.path().string());
    }
    return files;
}

std::vector<std::string> FFU::GetDirsInDirRecursive(std::string dir)
{
    if (!Exists(dir)) return { NULL };

    std::vector<std::string> files = {};
    for (const auto &entry : std::filesystem::recursive_directory_iterator(dir))
    {
        if (IsDirectory(entry.path().string())) files.push_back(entry.path().string());
    }
    return files;
}

std::string FFU::Read(std::string filepath)
{
    std::ifstream file(filepath);
    if (!file.is_open()) return NULL;
    std::string contents = "";
    std::string line = "";

    while (std::getline(file, line))
    {
        contents += line + "\n";
    }

    file.close();
    return contents;
}

std::vector<std::string> FFU::ReadLines(std::string filepath)
{
    std::ifstream file(filepath);
    if (!file.is_open()) return { NULL };
    std::vector<std::string> lines = {};
    std::string line = "";

    while (std::getline(file, line))
    {
        lines.push_back(line);
    }

    file.close();
    return lines;
}

void FFU::Write(std::string contents, std::string filepath)
{
    std::ofstream file(filepath);
    file << contents;
    file.close();
}

void FFU::WriteAppend(std::string contents, std::string filepath)
{
    Write(Read(filepath) + contents, filepath);
}

int FFU::Find(std::string str, std::string filepath)
{
    if (!Exists(filepath)) return -1;
    return Read(filepath).find(str);
}

int FFU::CountOccurences(std::string str, std::string filepath)
{
    if (!Exists(filepath)) return -1;

    int i = 0;
    int count = 0;
    std::string contents = Read(filepath);
    while (i < contents.length())
    {
        i = contents.find(str, i);
        if (i == -1) break;
        i++;
        count++;
    }
    return count;
}

int FFU::CountOccurencesNoOverlap(std::string str, std::string filepath)
{
    if (!Exists(filepath)) return -1;

    int i = 0;
    int count = 0;
    std::string contents = Read(filepath);
    while (i < contents.length())
    {
        i = contents.find(str, i);
        if (i == -1) break;
        i += str.length();
        count++;
    }
    return count;
}

int FFU::CountLines(std::string filepath)
{
    if (!Exists(filepath)) return -1;

    std::ifstream file(filepath);
    std::string line = "";
    int nLines = 0;

    while (std::getline(file, line)) 
    {
        nLines++;
    }

    file.close();
    return nLines;
}

int FFU::CountLinesNoEmpty(std::string filepath)
{
    if (!Exists(filepath)) return -1;

    std::ifstream file(filepath);
    std::string line = "";
    int nLines = 0;

    while (std::getline(file, line)) if (line != "") nLines++;

    file.close();
    return nLines;
}

int FFU::CountWords(std::string filepath)
{
    if (!Exists(filepath)) return -1;

    return CountOccurences(" ", filepath) + CountLinesNoEmpty(filepath);
}

int FFU::CountChars(std::string filepath)
{
    if (!Exists(filepath)) return -1;

    return Read(filepath).length();
}

int FFU::CountCharsNoSpaces(std::string filepath)
{
    if (!Exists(filepath)) return -1;

    return CountChars(filepath) - CountOccurences(" ", filepath);
}
