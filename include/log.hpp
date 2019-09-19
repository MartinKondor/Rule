#ifndef LOG_HPP
#define LOG_HPP
/**
For logging errors and for notifing the user.
*/
#include <iostream>
#include <string>
#include <SFML/Graphics.hpp>
#include "config.hpp"
#include "gui/button.hpp"

extern Config CONFIG;


/**
Opens a simple window with the given message.
*/
const bool openMessageBox(const std::string message);

template<typename T> void log(T const& s)
{
    std::cout << s << std::endl;
}

#endif // LOG_HPP
