#include "main_menu_screen.hpp"


MainMenuScreen::MainMenuScreen() {
    this->newGameButton = Button(0, 0, "New game");
    this->loadSaveGameButton = Button(0, 0, "Load game");
    this->settingsButton = Button(0, 0, "Settings");
    this->creditsButton = Button(0, 0, "Credits");
    this->exitButton = Button(0, 0, "Exit");
}

ScreenType MainMenuScreen::display(sf::RenderWindow &window) {
    this->newGameButton.display(window);
    this->loadSaveGameButton.display(window);
    this->settingsButton.display(window);
    this->creditsButton.display(window);
    this->exitButton.display(window);
    return ScreenType::MAIN_MENU;
}
