#include "utils.hpp"


bool Utils::isFileExists(const std::string fileName)
{
    struct stat buffer;
    return (stat(fileName.c_str(), &buffer) == 0);
}

void Utils::ltrim(std::string &s)
{
    s.erase(s.begin(), std::find_if(s.begin(), s.end(), [](int ch)
    {
        return !std::isspace(ch);
    }));
}

void Utils::rtrim(std::string &s)
{
    s.erase(std::find_if(s.rbegin(), s.rend(), [](int ch)
    {
        return !std::isspace(ch);
    }).base(), s.end());
}

void Utils::trim(std::string &s)
{
    ltrim(s);
    rtrim(s);
}

std::string Utils::getBaseDir(const std::string exeFilePath)
{
    unsigned int lastSlashIndex = 0;
    for (unsigned int i = 0; i < exeFilePath.length(); i++)
    {
        if (exeFilePath[i] == '\\' || exeFilePath[i] == '/')
        {
            lastSlashIndex = i;
        }
    }
    return exeFilePath.substr(0, lastSlashIndex + 1);
}
