#ifndef CHECKBOX_HPP
#define CHECKBOX_HPP

#include <string>
#include <SFML/Graphics.hpp>
#include "button.hpp"
#include "config.hpp"

extern Config CONFIG;


class Checkbox {
    private:
        unsigned int xPos;
        unsigned int yPos;
        unsigned int width;
        unsigned int height;
        sf::Text label;
        sf::RectangleShape body;
        sf::RectangleShape innerBody;
        sf::Color hoverColor;
        sf::Color checkedColor;
        sf::Color unCheckedColor;
        ButtonState state;

    public:
        bool isChecked;


        Checkbox();
        Checkbox(const unsigned int xPos, const unsigned int yPos, const std::string label);
        void display(sf::RenderWindow &window);
};

#endif // CHECKBOX_HPP
