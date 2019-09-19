#include "game_play.hpp"


GamePlay::GamePlay() {}

GamePlay::GamePlay(bool load)
{
    // For testing load a map and an example human
    this->map = new Map("flatland.map");
    this->entities.push_back(new Human(0, 10, 10));
}

void GamePlay::display(sf::RenderWindow& window)
{
    // Display the map
    this->map->display(window);

    // Display entities
    for (Entity* entity : this->entities)
    {
        entity->display(window);
    }
}
