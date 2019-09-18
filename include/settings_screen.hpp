#ifndef SETTINGS_SCREEN_HPP
#define SETTINGS_SCREEN_HPP

#include <SFML/Graphics.hpp>
#include <screen.hpp>
#include <button.hpp>


class SettingsScreen : public Screen {
    private:
        Button backButton;

    public:
        SettingsScreen();
        virtual ScreenType display(sf::RenderWindow& window);
};

#endif // SETTINGS_SCREEN_HPP
