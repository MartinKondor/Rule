#ifndef SLIDER_HPP
#define SLIDER_HPP

#include <SFML/Graphics.hpp>
#include "config.hpp"
#include "utils.hpp"

extern Config CONFIG;


class Slider
{
    /**
    A Slider.

    Example usage:

    ```
    Slider slider(100, 100, gameFont);
    slider.create(20, 450);
    slider.setSliderValue(235);

    ...
    slider.draw(window);
    ...

    ```
    */
public:
    unsigned int xPos;
    unsigned int yPos;
    unsigned int minValue;
    unsigned int maxValue;
    unsigned int axisWidth;
    unsigned int axisHeight;
    unsigned int sliderWidth;
    unsigned int sliderHeight;
    float sliderValue;
    sf::RectangleShape slider;
    sf::RectangleShape axis;
    sf::Text text;


    Slider();
    Slider(const unsigned int xPos, const unsigned int yPos, const unsigned int min, const unsigned int max);
    sf::Text returnText(const unsigned int x, const unsigned int y, const std::string z);
    void setSliderValue(const float newValue);
    void setSliderPercentValue(const float newPercentValue);
    void display(sf::RenderWindow &window);
};

#endif // SLIDER_HPP
