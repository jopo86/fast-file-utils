#pragma once

#include <iostream>
#include <string>
#include <fstream>
#include <filesystem>
#include <vector>

/*
    @brief A namespace containing all functions in the FastFileUtils library.
*/
namespace FFU
{
    /*
        @brief Checks if a file or directory exists.
        @param filepath The path of the file/directory.
        @return Whether the file/directory exists.
    */
    bool Exists(std::string filepath);

    /*
        @brief Checks if a path is a directory as opposed to a file.
        @param filepath The path of the file/directory.
        @return Whether the path is a directory.
        Will return false regardless if the path does not exist or cannot be opened.
    */
    bool IsDir(std::string filepath);

    /*
        @brief Gets the extension of a file.
     *  Does not check existence of the file!
        @param filepath The path of the file.
        @return The extension of the file.
        Will return "" if the filepath does not inlcude a '.'.
    */
    std::string GetExtension(std::string filepath);

    /*
        @brief Gets the filename of a file, excluding the extension.
     *  Does not check existence of the file!
        @param filepath The path of the file.
        @return The name of the file.
        Will return the filepath if the filepath does not inlcude a '.'.
    */
    std::string GetFilename(std::string filepath);

    /*
        @brief Gets the paths of all files and subdirectories in a directory.
     *  May contain paths that require administrator permission to open!
        @param dir The path of the directory.
        @return A vector of all the paths of the files in the directory.
        Will return `{ NULL }` if the directory does not exist or cannot be opened.
    */
    std::vector<std::string> GetFilesAndDirsInDir(std::string dir);

    /*
        @brief Gets the paths of all files only in a directory.
     *  May contain paths that require administrator permission to open!
        @param dir The path of the directory.
        @param extensionFilter Filters the extensions of the files to return.
        For example, if you only want .cpp and .h files then pass `{ "cpp", "h" }`.
        Only returns files with these extensions.
        An empty vector signifies no filter (all extensions), which is the default value.
        @return A vector of all the paths of the files in the directory.
        Will return `{ NULL }` if the directory does not exist or cannot be opened.
    */
    std::vector<std::string> GetFilesInDir(std::string dir, std::vector<std::string> extensionFilter = {});

    /*
        @brief Gets the paths of all subdirectories only in a directory.
     *  May contain paths that require administrator permission to open!
        @param dir The path of the directory.
        @return A vector of all the paths of the subdirectories in the directory.
        Will return `{ NULL }` if the directory does not exist or cannot be opened.
    */
    std::vector<std::string> GetDirsInDir(std::string dir);

    /*
        @brief Gets the paths of all files and subdirectories in a directory and all its subdirectories.
     *  May contain paths that require administrator permission to open!
        @param dir The path of the directory.
        @return A vector of all the paths of the files in the directory.
        Will return `{ NULL }` if the directory does not exist or cannot be opened.
    */
    std::vector<std::string> GetFilesAndDirsInDirRecursive(std::string dir);

    /*
        @brief Gets the paths of all files only in a directory and all its subdirectories.
     *  May contain paths that require administrator permission to open!
        @param dir The path of the directory.
        @param extensionFilter Filters the extensions of the files to return.
        Extensions should not contain the '.' - for example, if you only want .cpp files then pass `{ "cpp" }`.
        Only returns files with these extensions.
        An empty vector signifies no filter (all extensions), which is the default value.
        @return A vector of all the paths of the files in the directory.
        Will return `{ NULL }` if the directory does not exist or cannot be opened.
    */
    std::vector<std::string> GetFilesInDirRecursive(std::string dir, std::vector<std::string> extensionFilter = {});

    /*
        @brief Gets the paths of all subdirectories only in a directory and all its subdirectories.
     *  May contain paths that require administrator permission to open!
        @param dir The path of the directory.
        @return A vector of all the paths of the subdirectories in the directory.
        Will return `{ NULL }` if the directory does not exist or cannot be opened.
    */
    std::vector<std::string> GetDirsInDirRecursive(std::string dir);

    /*
        @brief Reads the file and returns the contents.
        @param filepath The path of the file.
        @return The text contents of the file as a string.
        Will return `NULL` if the file does not exist or cannot be opened.
    */
    std::string Read(std::string filepath);

    /*
        @brief Reads the file and returns the contents.
        @param filepath The path of the file.
        @return The text contents of the file as a vector of strings (lines).
        Will return `{ NULL }` if the file does not exist or cannot be opened.
    */
    std::vector<std::string> ReadLines(std::string filepath);

    /*
        @brief Writes to the file, creating a new file if it doesn't exist.
        @param contents The text contents to write to the file.
        @param filepath The path of the file.
    */
    void Write(std::string contents, std::string filepath);

    /*
        @brief Appends to the file, creating a new file if it doesn't exist.
        @param contents The text contents to append to the file.
        @param filepath The path of the file.
    */
    void WriteAppend(std::string contents, std::string filepath);

    /*
        @brief Finds the first occurence of a string in a file.
        @param str The string to find.
        @param filepath The path of the file.
        @return The index of the first occurence of the string.
        Will return `-1` if the file does not exist or cannot be opened.
    */
    int Find(std::string str, std::string filepath);

    /*
        @brief Counts the number of occurrences of a string in a file.
        @param str The string to count.
        @param filepath The path of the file.
        @return The number of occurrences of the string.
        Will return `-1` if the file does not exist or cannot be opened.
    */
    int CountOccurrences(std::string str, std::string filepath);

    /*
        @brief Counts the number of occurrences of a string in a file, without overlapping.
        Example: CountoccurrencesNoOverlap("aa", <some file with "aaa">) will return 1, not 2.
        @param str The string to count.
        @param filepath The path of the file.
        @return The number of occurrences of the string.
        Will return `-1` if the file does not exist or cannot be opened.
    */
    int CountOccurrencesNoOverlap(std::string str, std::string filepath);

    /*
        @brief Counts the number of lines in a file.
        @param filepath The path of the file.
        @return The number of lines in the file.
        Will return `-1` if the file does not exist or cannot be opened.
    */
    int CountLines(std::string filepath);

    /*
        @brief Counts the number of lines in a file, excluding empty lines.
        @param filepath The path of the file.
        @return The number of lines in the file, excluding empty lines.
        Will return `-1` if the file does not exist or cannot be opened.
    */
    int CountLinesNoEmpty(std::string filepath);

    /*
        @brief Counts the number of words in a file.
        This function may be inaccurate, it counts the number of spaces + the number of (not empty) lines.
        It will be accurate if the file is just text.
        @param filepath The path of the file.
        @return The number of words in the file.
        Will return `-1` if the file does not exist or cannot be opened.
    */
    int CountWords(std::string filepath);

    /*
        @brief Counts the number of characters in a file.
        @param filepath The path of the file.
        @return The number of characters in the file.
        Will return `-1` if the file does not exist or cannot be opened.
    */
    int CountChars(std::string filepath);

    /*
        @brief Counts the number of characters in a file, excluding spaces.
        @param filepath The path of the file.
        @return The number of characters in the file, excluding spaces.
        Will return `-1` if the file does not exist or cannot be opened.
    */
    int CountCharsNoSpaces(std::string filepath);
}
