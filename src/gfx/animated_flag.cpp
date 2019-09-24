#include "animated_flag.hpp"

#include <iostream>


AnimatedFlag::AnimatedFlag(const std::string flagName)
{
    const std::string fileName = FLAG_FOLDER + flagName + "/flag.png";

    if (!Utils::isFileExists(fileName))
    {
        openMessageBox("Animated flag (" + fileName + ") cannot be loaded.");
        exit(EXIT_FAILURE);
    }

    sf::Image flagImg;
    flagImg.loadFromFile(fileName);
    sf::Vector2u imgSize = flagImg.getSize();

    this->waveCounter = 0;
    this->flagTexture.loadFromImage(flagImg);
    this->lightWaveTexture.loadFromFile(FLAG_FOLDER + flagName + "/light_wave.png");
    this->darkWaveTexture.loadFromFile(FLAG_FOLDER + flagName + "/dark_wave.png");
    this->flag.setTexture(this->flagTexture);
    this->flag.setScale((float) CONFIG.WINDOW_WIDTH / imgSize.x, (float) CONFIG.WINDOW_HEIGHT / imgSize.y);

    imgSize.x *= this->flag.getScale().x;
    imgSize.y *= this->flag.getScale().y;

    // Setup flag vertices
    unsigned int nOfVertices = 50;
    this->flagVertices = sf::VertexArray(sf::TrianglesStrip, nOfVertices);

    for (unsigned int i = 0; i < nOfVertices; i += 2)
    {
        this->flagVertices[i].position = sf::Vector2f(i * CONFIG.WINDOW_WIDTH / (nOfVertices - 2), 0);
        this->flagVertices[i + 1].position = sf::Vector2f(i * CONFIG.WINDOW_WIDTH / (nOfVertices - 2), CONFIG.WINDOW_HEIGHT);

        this->flagVertices[i].texCoords = sf::Vector2f((i * imgSize.x / nOfVertices) / this->flag.getScale().x, 0);
        this->flagVertices[i + 1].texCoords = sf::Vector2f((i * imgSize.x / nOfVertices) / this->flag.getScale().x, CONFIG.WINDOW_HEIGHT / this->flag.getScale().y);
    }
}

void AnimatedFlag::play(sf::RenderWindow &window)
{
    for (unsigned int i = 0; i < this->flagVertices.getVertexCount(); i++)
    {
        double sinPart = sin((this->waveCounter + i) / 3.5);

        this->flagVertices[i].color = sf::Color(239 + 16 * sinPart, 239 + 16 * sinPart, 239 + 16 * sinPart, 255);
        this->flagVertices[i].position.y += 2 * sinPart;
    }

    this->waveCounter++;
    window.draw(this->flagVertices, &this->flagTexture);
}
