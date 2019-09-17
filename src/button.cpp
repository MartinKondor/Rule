#include <button.hpp>


Button::Button() : Button(0, 0, "-") {}

Button::Button(const unsigned int xPos, const unsigned int yPos, const std::string label)
    : Button(xPos, yPos, label, 0, 0) {}

Button::Button(const unsigned int xPos, const unsigned int yPos, const std::string label,
               const unsigned int width, const unsigned int height) {
    this->xPos = xPos;
    this->yPos = yPos;
    this->label = sf::Text(label, CONFIG.MAIN_FONT, CONFIG.CHARACTER_SIZE);
    this->width = width == 0 ? (CONFIG.CHARACTER_SIZE * label.length() + 2 * CONFIG.CHARACTER_SIZE) : width;
    this->height = height == 0 ? (2 * CONFIG.CHARACTER_SIZE) : height;
    this->state = ButtonState::NORMAL;
    this->outlineThickness = 8;
    this->outlineColor = sf::Color(28, 141, 147);
}

void Button::display(sf::RenderWindow &window) {

}
