#include "textbox.h"

Textbox::Textbox() : Textbox(sf::Vector2f{100.0, 100.0}, sf::Vector2f{0, 0}, 20) {
}

Textbox::Textbox(sf::Vector2f size, sf::Vector2f position, int fontSize, const std::string &fontPath) :
        size_(size), position_(position), fontSize_(fontSize) {

    font_.loadFromFile(fontPath);
    text_.setFont(font_);
    text_.setCharacterSize(fontSize_);
    text_.setPosition(position);
    text_.setFillColor(sf::Color::Black);
    rectangle_.setSize(size_);
    rectangle_.setPosition(position_);

}

void Textbox::draw(sf::RenderTarget &target, sf::RenderStates states) const {
    states.transform *= getTransform();
    target.draw(rectangle_, states);
    target.draw(text_, states);
}


void Textbox::setString(const std::string &str) {
    content_ = str;
    text_.setString(content_);
}

std::string Textbox::getString() const {
    return content_;
}

void Textbox::clear() {
    setString("");
}

void Textbox::setMargin(float margin) {
    text_.setPosition(position_ + sf::Vector2f{margin, margin});
}

void Textbox::fillBackgroundColor(const sf::Color &color) {
    rectangle_.setFillColor(color);
}

void Textbox::setBoxSize(const sf::Vector2f &size) {
    rectangle_.setSize(size);
    size_ = size;
}

void Textbox::setBorderBoxStyle(const sf::Color &color, float thickness) {
    setBorderColor(color);
    setBorderThickness(thickness);
}

void Textbox::setBorderColor(const sf::Color &color) {
    rectangle_.setOutlineColor(color);
}

void Textbox::setBorderThickness(float thickness) {
    rectangle_.setOutlineThickness(thickness);
}
