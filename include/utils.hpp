#ifndef UTILS_HPP
#define UTILS_HPP

#include <string>
#include <sstream>
#include <sys/stat.h>
#include <algorithm>


namespace Utils
{

/**
@returns true if the given file exists
*/
bool isFileExists(const std::string fileName);

/**
Parses the current working directory from the exeFilePath parameter.
*/
std::string getBaseDir(const std::string exeFilePath);

void ltrim(std::string &s);

void rtrim(std::string &s);

/**
* Trim the given string from both ends (in place)
*/
void trim(std::string &s);

/**
Turns type T to string.
*/
template<typename T> std::string to_string(T const& n)
{
    std::ostringstream stm;
    stm << n;
    return stm.str();
}
}

#endif // UTILS_HPP
