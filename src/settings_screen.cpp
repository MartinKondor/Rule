#include "settings_screen.hpp"


SettingsScreen::SettingsScreen() {

}

ScreenType SettingsScreen::display(sf::RenderWindow &window) {
    return ScreenType::SETTINGS;
}
