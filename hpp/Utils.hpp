#ifndef UTILS_HPP_INCLUDED
#define UTILS_HPP_INCLUDED

#include <string>
#include <sstream>
#include <sys/stat.h>


namespace utils
{

/**
Parses the current working directory from the exeFilePath parameter.
@returns the base folder
*/
std::string getBaseDir(std::string exeFilePath);

/**
@returns true if the given file exists
*/
bool isFileExists(const std::string fileName);

/**
Turns type T to string.
*/
template<typename T> std::string to_string(T const& n)
{
    std::ostringstream stm;
    stm << n;
    return stm.str();
}

} // namespace utils

#endif // UTILS_HPP_INCLUDED
