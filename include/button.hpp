#ifndef BUTTON_HPP
#define BUTTON_HPP

#include <string>
#include <SFML/Graphics.hpp>


enum class ButtonState {
    NORMAL
};


class Button {
    private:
        unsigned int xPos;
        unsigned int yPos;
        unsigned int width;
        unsigned int height;
        ButtonState state;

    public:
        static const unsigned int CHARACTER_SIZE = 15;

        Button();
        Button(const unsigned int xPos, const unsigned int yPos, const std::string label);
        void display(sf::RenderWindow& window);
};

#endif // BUTTON_HPP
