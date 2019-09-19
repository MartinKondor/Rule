#include "game_play.hpp"


GamePlay::GamePlay()
{
    this->entities.push_back(new Human(0, 10, 10));
}

void GamePlay::display(sf::RenderWindow& window)
{
    // Display entities
    for (Entity* entity : this->entities)
    {
        entity->display(window);
    }
}
