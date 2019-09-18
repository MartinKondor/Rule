#ifndef BUTTON_HPP
#define BUTTON_HPP
/**
GUI button class.

See https://paletton.com/#uid=3010u0klEy-bKPnhfGnq5urtHo+ for colors.

*/
#include <string>
#include <SFML/Graphics.hpp>
#include <config.hpp>


extern Config CONFIG;


enum class ButtonState {
    NORMAL,
    CLICKED,
    HOVERED,
    RELEASED
};


class Button {
    private:
        unsigned int xPos;
        unsigned int yPos;
        unsigned int width;
        unsigned int height;
        unsigned int outlineThickness;
        ButtonState state;
        sf::Color outlineColor;
        sf::Text label;

    public:
        Button();
        Button(const unsigned int xPos, const unsigned int yPos, const std::string label);
        Button(const unsigned int xPos, const unsigned int yPos, const std::string label,
               const unsigned int width, const unsigned int height);
        void display(sf::RenderWindow& window);
};

#endif // BUTTON_HPP
