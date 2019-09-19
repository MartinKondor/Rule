#include "gui/slider.hpp"


Slider::Slider() {}

Slider::Slider(const unsigned int xPos, const unsigned int yPos, const unsigned int min, const unsigned int max)
{
    this->xPos = xPos;
    this->yPos = yPos;
    this->axisHeight = 20;
    this->axisWidth = 200;
    this->sliderWidth = 20;
    this->sliderHeight = 20;

    this->sliderValue = min;
    this->minValue = min;
    this->maxValue = max;

    this->text.setFont(CONFIG.MAIN_FONT);
    this->text.setFillColor(sf::Color(250, 250, 250));

    this->axis.setPosition(xPos, yPos);
    this->axis.setOrigin(0, this->axisHeight / 2);
    this->axis.setSize(sf::Vector2f(this->axisWidth, this->axisHeight));
    this->axis.setFillColor(sf::Color(63, 63, 63));

    this->slider.setPosition(xPos, yPos);
    this->slider.setOrigin(this->sliderWidth / 2, this->sliderHeight / 2);
    this->slider.setSize(sf::Vector2f(this->sliderWidth, this->sliderHeight));
    this->slider.setFillColor(sf::Color(192, 192, 192));
}

sf::Text Slider::returnText(const unsigned int x, const unsigned int y, const std::string z)
{
    this->text.setCharacterSize(CONFIG.CHARACTER_SIZE);
    this->text.setPosition(x, y);
    this->text.setString(z);
    return text;
}

void Slider::setSliderValue(const float newValue)
{
    if (newValue >= this->minValue && newValue <= this->maxValue)
    {
        this->sliderValue = newValue;
        const float diff = this->maxValue - this->minValue;
        const float diff2 = newValue - this->minValue;
        const float zzz = this->axisWidth / diff;
        float posX = zzz * diff2;
        posX += this->xPos;
        slider.setPosition(posX, this->yPos);
    }
}

void Slider::setSliderPercentValue(const float newPercentValue)
{
    if (newPercentValue >= 0 && newPercentValue <= 100)
    {
        this->sliderValue = newPercentValue / 100 * this->maxValue;
        this->slider.setPosition(this->xPos + (this->axisWidth * newPercentValue / 100), this->yPos);
    }
}

void Slider::display(sf::RenderWindow &window)
{
    sf::Vector2i mpos = sf::Mouse::getPosition(window);

    if (sf::Mouse::isButtonPressed(sf::Mouse::Button::Left) && this->axis.getGlobalBounds().contains(mpos.x, mpos.y))
    {
        this->slider.setPosition(mpos.x, this->yPos);
        this->sliderValue = (this->minValue + ((this->slider.getPosition().x - this->xPos) / this->axisWidth * (this->maxValue - this->minValue)));

        if (this->sliderValue >= 98)
        {
            this->sliderValue = 100;
        }
    }

    window.draw(this->axis);
    window.draw(this->slider);
    window.draw(this->returnText(this->xPos + this->axisWidth + 10, this->yPos - 10, Utils::to_string((int) this->sliderValue)));
}
