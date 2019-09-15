#ifndef MAIN_MENU_SCREEN_HPP
#define MAIN_MENU_SCREEN_HPP

#include "../include/screen.hpp"


class MainMenuScreen : public Screen {
    private:
        Button newGameButton;
        Button loadSaveGameButton;
        Button settingsButton;
        Button exitButton;

    public:
        MainMenuScreen();
        virtual ScreenType display(sf::RenderWindow&);
};

#endif // MAIN_MENU_SCREEN_HPP
