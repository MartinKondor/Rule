#include "animated_flag.hpp"


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
    this->imgSize = flagImg.getSize();

    this->flagTexture.loadFromImage(flagImg);
    this->lightWaveTexture.loadFromFile(FLAG_FOLDER + flagName + "/light_wave.png");
    this->darkWaveTexture.loadFromFile(FLAG_FOLDER + flagName + "/dark_wave.png");
    this->flag.setTexture(this->flagTexture);
    this->flag.setScale((float) CONFIG.WINDOW_WIDTH / this->imgSize.x, (float) CONFIG.WINDOW_HEIGHT / this->imgSize.y);
    this->flag.setColor(sf::Color(220, 220, 220, 255));

    this->waveCount = CONFIG.WINDOW_WIDTH / this->lightWaveTexture.getSize().x;

    int xOffset = 0;

    for (unsigned int i = 0; i < this->waveCount; i++)
    {
        sf::Sprite ls;
        ls.setTexture(this->lightWaveTexture);
        ls.setPosition(0, 0);
        this->lightWaves.push_back(ls);

        sf::Sprite ds;
        ds.setTexture(this->darkWaveTexture);
        ds.setPosition(0, 0);
        this->darkWaves.push_back(ds);

        this->darkWaveXs.push_back(xOffset + this->darkWaveTexture.getSize().x);
        this->lightWaveXs.push_back(xOffset);

        xOffset += 2 * this->darkWaveTexture.getSize().x;
    }

    this->imgSize.x *= this->flag.getScale().x;
    this->imgSize.y *= this->flag.getScale().y;


    sf::VertexArray flagVertices(sf::Quads, 4);
    flagVertices[0].position = sf::Vector2f(0, 0);
    flagVertices[1].position = sf::Vector2f(CONFIG.WINDOW_WIDTH, 0);
    flagVertices[2].position = sf::Vector2f(0, CONFIG.WINDOW_HEIGHT);
    flagVertices[3].position = sf::Vector2f(CONFIG.WINDOW_WIDTH, CONFIG.WINDOW_HEIGHT);

    flagVertices[0].texCoords = sf::Vector2f(0.f, 0.f);
    flagVertices[1].texCoords = sf::Vector2f(this->imgSize.x, 0.f);
    flagVertices[2].texCoords = sf::Vector2f(0, this->imgSize.y);
    flagVertices[3].texCoords = sf::Vector2f(this->imgSize.x, this->imgSize.y);
    this->flagVertices = flagVertices;
}

void AnimatedFlag::play(sf::RenderWindow &window)
{
    this->flagVertices[0].position.x += 1;

    window.draw(this->flagVertices, &this->flagTexture);

    /*
    window.draw(this->flag);

    for (unsigned int i = 0; i < this->waveCount; i++)
    {
        this->lightWaveXs[i] = this->lightWaveXs[i] + 10;
        this->darkWaveXs[i] = this->darkWaveXs[i] + 10;

        this->lightWaves[i].setPosition(this->lightWaveXs[i], 0);
        this->darkWaves[i].setPosition(this->darkWaveXs[i], 0);

        if (this->darkWaveXs[i] > (int) (this->imgSize.x + this->darkWaveTexture.getSize().x / 2))
        {
            this->darkWaveXs[i] =  -(int) this->darkWaveTexture.getSize().x;
        }

        if (this->lightWaveXs[i] > (int) (this->imgSize.x + this->lightWaveTexture.getSize().x / 2))
        {
            this->lightWaveXs[i] = -(int) this->lightWaveTexture.getSize().x;
        }

        window.draw(this->lightWaves[i]);
        window.draw(this->darkWaves[i]);
    }
    */
}
