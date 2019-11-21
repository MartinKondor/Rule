#include "settings_screen.hpp"

#include <iostream>


extern Config CONFIG;


SettingsScreen::SettingsScreen(irr::IrrlichtDevice* device, irr::scene::ISceneManager* smgr, irr::video::IVideoDriver* driver)
    : Screen(device, smgr, driver)
{}

ScreenType SettingsScreen::display()
{
    return ScreenType::SETTINGS;
}
