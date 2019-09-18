#include <utils.hpp>


bool Utils::isFileExists(const std::string fileName) {
    struct stat buffer;
    return (stat(fileName.c_str(), &buffer) == 0);
}
