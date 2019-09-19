#include "log.hpp"


const bool openMessageBox(const std::string message)
{
    const sf::Color bgColor = sf::Color(37, 37, 37);
    const sf::Color fontColor = sf::Color::White;
    const unsigned int charSize = CONFIG.CHARACTER_SIZE;
    const unsigned int windowWidth = charSize * message.length() / 2 + charSize * 2.5;
    const unsigned int windowHeight = charSize * 7;

    sf::RenderWindow msgWindow(sf::VideoMode(windowWidth, windowHeight), "Rule: Notice", sf::Style::Close);
    msgWindow.setFramerateLimit(24);
    msgWindow.resetGLStates();

    sf::Event event;
    sf::Text messageText(message, CONFIG.MAIN_FONT, charSize);
    Button okButton(10, (int) (windowHeight - charSize * 2.5), "Ok");

    okButton.label.setCharacterSize(charSize);
    okButton.label.setColor(fontColor);
    messageText.setColor(fontColor);
    messageText.setPosition((int) (windowWidth / 2 - message.length() * charSize / 4), (int) (charSize / 2));

    while (msgWindow.isOpen()) {
        while (msgWindow.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                msgWindow.close();
            }
        }
        msgWindow.clear(bgColor);

        // Handle ok button press
        if (okButton.state == ButtonState::RELEASED) {
            okButton.state = ButtonState::NORMAL;
            return true;
        }

        msgWindow.draw(messageText);
        okButton.display(msgWindow);
        msgWindow.display();
    }

    return false;
}

