#include "checkbox.hpp"


Checkbox::Checkbox() {}

Checkbox::Checkbox(const unsigned int xPos, const unsigned int yPos, const std::string label) {
    this->xPos = xPos;
    this->yPos = yPos;
    this->label = sf::Text(label, CONFIG.MAIN_FONT, CONFIG.CHARACTER_SIZE);
    this->label.setPosition(this->xPos + 2 * CONFIG.CHARACTER_SIZE, this->yPos + 3);
    this->isChecked = false;
    this->width = 18;
    this->height = 18;
    this->hoverColor = sf::Color(199, 100, 14);
    this->checkedColor = sf::Color(199, 19, 14);
    this->unCheckedColor = sf::Color(242, 136, 45);

    int outlineThickness = 4;

    this->body = sf::RectangleShape(sf::Vector2f(this->width, this->height));
    this->body.setFillColor(this->unCheckedColor);
    this->body.setPosition(this->xPos, this->yPos + this->body.getSize().y / 4);

    this->innerBody = sf::RectangleShape(sf::Vector2f(this->width - outlineThickness, this->height - outlineThickness));
    this->innerBody.setFillColor(this->checkedColor);
    this->innerBody.setPosition(this->xPos + outlineThickness / 2, this->yPos + this->body.getSize().y / 4 + outlineThickness / 2);
}

void Checkbox::display(sf::RenderWindow &window) {
    sf::Vector2i mousePos = sf::Mouse::getPosition(window);

    if (mousePos.x > this->xPos && mousePos.y > this->yPos && mousePos.x < this->xPos + this->width && mousePos.y < this->yPos + this->height) {
        if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
            this->state = ButtonState::CLICKED;
        }
        else if (this->state == ButtonState::CLICKED) {
            this->state = ButtonState::RELEASED;
        }
        else {
            this->state = ButtonState::HOVERED;
        }
    }
    else {
        this->state = ButtonState::NORMAL;
    }

    if (this->state == ButtonState::RELEASED) {
        this->isChecked = !this->isChecked;
    }
    else if (this->state == ButtonState::HOVERED) {
        this->body.setFillColor(this->hoverColor);
    }
    else {
        this->body.setFillColor(this->unCheckedColor);
    }

    if (this->isChecked) {
        this->innerBody.setFillColor(this->checkedColor);
    }
    else {
        this->innerBody.setFillColor(this->unCheckedColor);
    }

    window.draw(this->body);
    window.draw(this->innerBody);
    window.draw(this->label);
}
