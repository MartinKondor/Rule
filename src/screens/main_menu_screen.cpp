#include "main_menu_screen.hpp"

#include <iostream>


extern Config CONFIG;


MainMenuScreen::MainMenuScreen(irr::IrrlichtDevice* device, irr::scene::ISceneManager* smgr, irr::video::IVideoDriver* driver)
    : Screen(device, smgr, driver)
{
    this->env = device->getGUIEnvironment();

    // Load and set fonts
    irr::gui::IGUIFont* basicFont = env->getFont((CONFIG.BASE_FOLDER + "fonts/basic.bmp").c_str());
    irr::gui::IGUISkin* basicSkin = env->createSkin(irr::gui::EGUI_SKIN_TYPE::EGST_BURNING_SKIN);
    basicSkin->setFont(basicFont);
    basicSkin->setColor(irr::gui::EGUI_DEFAULT_COLOR::EGDC_BUTTON_TEXT, irr::video::SColor(255, 50, 50, 50));
    this->env->setSkin(basicSkin);

    // Setup buttons
    unsigned int buttonXMargin = 10;
    unsigned int buttonXSize = 107;
    unsigned int buttonYSize = 37;
    unsigned int xPos = buttonXSize / 2;
    unsigned int yPos = CONFIG.WINDOW_HEIGHT - buttonYSize / 2;

    this->newGameButton = this->env->addButton(irr::core::rect<irr::s32>(xPos - buttonXSize / 2, yPos - buttonYSize / 2, xPos + buttonXSize / 2, yPos + buttonYSize / 2), 0, 0, L"New Game");

    xPos += buttonXSize + buttonXMargin;
    this->settingsButton = this->env->addButton(irr::core::rect<irr::s32>(xPos - buttonXSize / 2, yPos - buttonYSize / 2, xPos + buttonXSize / 2, yPos + buttonYSize / 2), 0, 1, L"Settings");

    xPos += buttonXSize + buttonXMargin;
    this->exitButton = this->env->addButton(irr::core::rect<irr::s32>(xPos - buttonXSize / 2, yPos - buttonYSize / 2, xPos + buttonXSize / 2, yPos + buttonYSize / 2), 0, 1, L"Exit");
}

ScreenType MainMenuScreen::display()
{
    // Draw buttons
    if (this->newGameButton->isPressed())
    {
        return ScreenType::GAME;
    }
    else if (this->settingsButton->isPressed())
    {
        return ScreenType::SETTINGS;
    }
    else if (this->exitButton->isPressed())
    {
        return ScreenType::EXIT;
    }

    this->env->drawAll();
    return ScreenType::MAIN_MENU;
}
