#include "screens/game.hpp"


GameScreen::GameScreen()
{
    this->game = GamePlay();
    this->subScreen = GameSubScreen::GAME;
}

ScreenType GameScreen::display(sf::RenderWindow& window)
{
    this->game.display(window);
    return ScreenType::GAME;
}
