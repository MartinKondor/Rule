#ifndef UTILS_HPP
#define UTILS_HPP

#include <string>
#include <sstream>
#include <sys/stat.h>


namespace Utils {

    /**
    @returns true if the given file exists
    */
    bool isFileExists(const std::string fileName);

    /**
    Turns type T to string.
    */
    template<typename T> std::string to_string(T const& n) {
        std::ostringstream stm;
        stm << n;
        return stm.str();
    }
}

#endif // UTILS_HPP
