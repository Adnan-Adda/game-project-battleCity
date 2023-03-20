#include "window.h"
#include <utility>

Window::Window(std::string title, const sf::Vector2u &size) : title_(std::move(title)), videoMode_(size.x, size.y),
                                                              is_done_(false), is_full_screen_(true) {
    create();
    window_.setFramerateLimit(FrameRate_);
}

void Window::create() {
    auto style = sf::Style::Close | sf::Style::Titlebar;
    if (is_full_screen_) {
        style = sf::Style::Fullscreen;
        window_.create(sf::VideoMode::getDesktopMode(), title_, style);
    } else {
        window_.create(videoMode_, title_, style);
    }

}

Window::~Window() {
    window_.close();
}

void Window::beginDraw() {
    window_.clear(sf::Color::White);
}

void Window::endDraw() {
    window_.display();
}

void Window::update() {
    sf::Event event;
    while (window_.pollEvent(event)) {
        if (event.type == sf::Event::Closed)
            is_done_ = true;
        else if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Escape)
            toggleFullscreen();
        else if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::F1)
            is_done_ = true;
    }
}

bool Window::isDone() const {
    return is_done_;
}

void Window::toggleFullscreen() {
    is_full_screen_ = !is_full_screen_;
    window_.close();
    create();
}

sf::Vector2f Window::getSize() {
    return static_cast<sf::Vector2f>(window_.getSize());
}

void Window::draw(const sf::Drawable &drawable) {
    window_.draw(drawable);
}
