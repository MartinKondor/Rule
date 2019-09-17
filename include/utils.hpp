#ifndef UTILS_HPP
#define UTILS_HPP


namespace Utils {

    /**
    @returns true if the given file exists
    */
    bool Utils::isFileExists(const std::string fileName) {
        struct stat buffer;
        return (stat(fileName.c_str(), &buffer) == 0);
    }

    /**
    Turns type T to string.
    */
    template<typename T> std::string Utils::to_string(T const& n) {
        std::ostringstream stm;
        stm << n;
        return stm.str();
    }
}

#endif // UTILS_HPP
