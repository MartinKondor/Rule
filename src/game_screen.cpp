#include <game_screen.hpp>


GameScreen::GameScreen() {

}

ScreenType GameScreen::display(sf::RenderWindow&) {
    return ScreenType::GAME;
}
