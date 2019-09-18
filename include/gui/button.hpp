#ifndef BUTTON_HPP
#define BUTTON_HPP
/**
Button class and it's utilities.

https://paletton.com/#uid=3010u0klEy-bKPnhfGnq5urtHo+
https://paletton.com/#uid=7010u0klEy-bKPnhfGnq5urtHo+

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
    /**
    GUI button with outline and hover effects.
    */
    private:
        unsigned int xPos;
        unsigned int yPos;
        unsigned int width;
        unsigned int height;
        unsigned int outlineThickness;
        sf::Color outlineColor;
        sf::Color fontColor;
        sf::Color hoverFontColor;
        sf::Color bodyColor;
        sf::RectangleShape body;

    public:
        sf::Text label;
        ButtonState state;


        Button();
        Button(const unsigned int xPos, const unsigned int yPos, const std::string label);
        Button(const unsigned int xPos, const unsigned int yPos, const std::string label,
               const unsigned int width, const unsigned int height);
        void display(sf::RenderWindow& window);
};

#endif // BUTTON_HPP
