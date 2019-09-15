#include "main_menu_screen.hpp"


MainMenuScreen::MainMenuScreen() {
    /*
    this->newGameButton = ;
    this->loadSaveGameButton = ;
    this->settingsButton = ;
    this->exitButton = ;
    */
}

ScreenType MainMenuScreen::display(sf::RenderWindow &window) {
    return ScreenType::MAIN_MENU;
}
