#ifndef LOG_HPP
#define LOG_HPP
/**
For logging errors and for notifing the user.
*/
#include <string>
#include <SFML/Graphics.hpp>
#include "config.hpp"
#include "gui/button.hpp"

extern Config CONFIG;


/**
Opens a simple window with the given message.
*/
const bool openMessageBox(const std::string message);

#endif // LOG_HPP
