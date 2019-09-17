#include <button.hpp>


Button::Button() : Button(0, 0, "-") {}

Button::Button(const unsigned int xPos, const unsigned int yPos, const std::string label) {
    this->xPos = xPos;
    this->yPos = yPos;
    this->width = Button::CHARACTER_SIZE * label.length();
    this->height = Button::CHARACTER_SIZE;
    this->state = ButtonState::NORMAL;
}

void Button::display(sf::RenderWindow &window) {

}
