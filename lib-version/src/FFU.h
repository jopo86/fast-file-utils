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
        @brief Reads the file and returns the contents.
        @param filepath The path of the file.
        @return The text contents of the file as a string.
        Will return NULL if the file does not exist or cannot be opened.
     */
    std::string Read(std::string filepath);

    /*
        @brief Reads the file and returns the contents.
        @param filepath The path of the file.
        @return The text contents of the file as a vector of strings (lines).
        Will return { NULL } if the file does not exist or cannot be opened.
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
        Will return -1 if the file does not exist or cannot be opened.
     */
    int Find(std::string str, std::string filepath);

    /*
        @brief Counts the number of occurences of a string in a file.
        @param str The string to count.
        @param filepath The path of the file.
        @return The number of occurences of the string.
        Will return -1 if the file does not exist or cannot be opened.
     */
    int CountOccurences(std::string str, std::string filepath);

    /*
        @brief Counts the number of occurences of a string in a file, without overlapping.
        Example: CountOccurencesNoOverlap("aa", <some file with "aaa">) will return 1, not 2.
        @param str The string to count.
        @param filepath The path of the file.
        @return The number of occurences of the string.
        Will return -1 if the file does not exist or cannot be opened.
     */
    int CountOccurencesNoOverlap(std::string str, std::string filepath);

    /*
        @brief Counts the number of lines in a file.
        @param filepath The path of the file.
        @return The number of lines in the file.
        Will return -1 if the file does not exist or cannot be opened.
     */
    int CountLines(std::string filepath);

    /*
        @brief Counts the number of lines in a file, excluding empty lines.
        @param filepath The path of the file.
        @return The number of lines in the file, excluding empty lines.
        Will return -1 if the file does not exist or cannot be opened.
     */
    int CountLinesNoEmpty(std::string filepath);

    /*
        @brief Counts the number of words in a file.
        This function may be inaccurate, it counts the number of spaces + the number of (not empty) lines.
        It will be accurate if the file is just text.
        @param filepath The path of the file.
        @return The number of words in the file.
        Will return -1 if the file does not exist or cannot be opened.
     */
    int CountWords(std::string filepath);

    /*
        @brief Counts the number of characters in a file.
        @param filepath The path of the file.
        @return The number of characters in the file.
        Will return -1 if the file does not exist or cannot be opened.
     */
    int CountChars(std::string filepath);

    /*
        @brief Counts the number of characters in a file, excluding spaces.
        @param filepath The path of the file.
        @return The number of characters in the file, excluding spaces.
        Will return -1 if the file does not exist or cannot be opened.
     */
    int CountCharsNoSpaces(std::string filepath);
}
