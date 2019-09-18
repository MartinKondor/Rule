#ifndef MAIN_MENU_SCREEN_HPP
#define MAIN_MENU_SCREEN_HPP

#include <SFML/Graphics.hpp>
#include <screen.hpp>
#include <button.hpp>


class MainMenuScreen : public Screen {
    private:
        Button newGameButton;
        Button loadSaveGameButton;
        Button settingsButton;
        Button creditsButton;
        Button exitButton;

    public:
        MainMenuScreen();
        virtual ScreenType display(sf::RenderWindow& window);
};

#endif // MAIN_MENU_SCREEN_HPP
