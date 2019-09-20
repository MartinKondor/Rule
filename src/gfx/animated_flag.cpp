#include "animated_flag.hpp"


AnimatedFlag::AnimatedFlag(const std::string flagName, const unsigned int waveCount)
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

    this->waveCount = waveCount;
    this->flagTexture.loadFromImage(flagImg);
    this->lightWaveTexture.loadFromFile(FLAG_FOLDER + flagName + "/light_wave.png");
    this->darkWaveTexture.loadFromFile(FLAG_FOLDER + flagName + "/dark_wave.png");
    this->flag.setTexture(this->flagTexture);
    this->flag.setScale((float) CONFIG.WINDOW_WIDTH / this->imgSize.x, (float) CONFIG.WINDOW_HEIGHT / this->imgSize.y);

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

        this->darkWaveXs.push_back(this->darkWaveTexture.getSize().x / 1.5);
        this->lightWaveXs.push_back(0);
    }

    this->imgSize.x *= this->flag.getScale().x;
    this->imgSize.y *= this->flag.getScale().y;
}

void AnimatedFlag::play(sf::RenderWindow &window)
{
    window.draw(this->flag);

    for (unsigned int i = 0; i < this->waveCount; i++)
    {
        log(this->lightWaveXs[i]);

        this->lightWaves[i].setPosition(this->lightWaveXs[i]++, 0);
        this->darkWaves[i].setPosition(this->darkWaveXs[i]++, 0);

        if ((this->darkWaveXs[i] + this->darkWaveTexture.getSize().x / 2) > this->imgSize.x)
        {
            this->darkWaveXs[i] = this->darkWaveTexture.getSize().x / 1.5;
        }

        if ((this->lightWaveXs[i] + this->lightWaveTexture.getSize().x / 2) > this->imgSize.x)
        {
            this->lightWaveXs[i] = 0;
        }

        window.draw(this->lightWaves[i]);
        window.draw(this->darkWaves[i]);
    }
}
