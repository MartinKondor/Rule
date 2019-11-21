#include "settings_screen.hpp"

#include <iostream>


extern Config CONFIG;


SettingsScreen::SettingsScreen(irr::IrrlichtDevice* device)
{}

ScreenType SettingsScreen::display()
{
    return ScreenType::SETTINGS;
}
