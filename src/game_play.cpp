#include "game_play.hpp"


GamePlay::GamePlay() {}

GamePlay::GamePlay(bool load)
{
    // For testing load a map and an example human
    this->map = new Map("flatland.map");
    this->entityIndex = 0;

    // Adding entities for testing
    this->entities.push_back(new Human(0, 10, 10));

    this->cameraX = 0;
    this->cameraY = 0;
    this->view.reset(sf::FloatRect(0, 0, CONFIG.WINDOW_WIDTH, CONFIG.WINDOW_HEIGHT));
}

void GamePlay::display(sf::RenderWindow& window)
{
    // Check for keypress
    if (sf::Keyboard::isKeyPressed(CONFIG.KEY_UP))
    {
        this->cameraY -= this->map->tileset.tileHeight / 4;
    }
    if (sf::Keyboard::isKeyPressed(CONFIG.KEY_DOWN))
    {
        this->cameraY += this->map->tileset.tileHeight / 4;
    }
    if (sf::Keyboard::isKeyPressed(CONFIG.KEY_LEFT))
    {
        this->cameraX -= this->map->tileset.tileWidth / 4;
    }
    if (sf::Keyboard::isKeyPressed(CONFIG.KEY_RIGHT))
    {
        this->cameraX += this->map->tileset.tileWidth / 4;
    }

    // Display the map
    this->map->display(window);

    // Display entities
    for (Entity* entity : this->entities)
    {
        entity->display(window);
    }

    this->view.setCenter(this->cameraX + CONFIG.WINDOW_WIDTH / 2, this->cameraY + CONFIG.WINDOW_HEIGHT / 2);
    window.setView(this->view);
}
