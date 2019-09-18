#ifndef SETTINGS_SCREEN_HPP
#define SETTINGS_SCREEN_HPP

#include <SFML/Graphics.hpp>
#include "screen.hpp"
#include "button.hpp"
#include "checkbox.hpp"
#include "slider.hpp"
#include "config.hpp"

extern Config CONFIG;
extern std::string IMAGE_FOLDER;


class SettingsScreen : public Screen {
    /**
    Settings for changing the configuration.
    */
    private:
        sf::Texture logoTexture;
        sf::Sprite logo;

        sf::Text screenTitle;
        Button backButton;
        Button upButton;
        Button downButton;
        Button leftButton;
        Button rightButton;
        sf::Text controlsTitle;
        sf::Text upKeyLabel;
        sf::Text downKeyLabel;
        sf::Text leftKeyLabel;
        sf::Text rightKeyLabel;
        sf::Text volumeTitle;
        sf::Text masterVolumeLabel;
        sf::Text soundVolumeLabel;
        sf::Text musicVolumeLabel;
        Slider masterVolumeSlider;
        Slider soundVolumeSlider;
        Slider musicVolumeSlider;
        Checkbox fullscreenCheckbox;
        bool waitingForKey;

    public:
        SettingsScreen();
        sf::Keyboard::Key getPressedKey(sf::Keyboard::Key currentKey);
        virtual ScreenType display(sf::RenderWindow& window);
};

#endif // SETTINGS_SCREEN_HPP
