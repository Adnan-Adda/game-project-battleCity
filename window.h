
// datum: 2022-12-26
// filnamn: window.h
// definition for class Window.

#ifndef BATTLE_CITY_PROJECT_WINDOW_H
#define BATTLE_CITY_PROJECT_WINDOW_H

#include <SFML/Graphics.hpp>
#include <memory>

/// Represent rendering window.
class Window {
private:
    const float FrameRate_ = 60.0f;
    std::string title_;
    sf::VideoMode videoMode_;
    bool is_done_;
    bool is_full_screen_;
    sf::RenderWindow window_;

    void create();

public:
    /**
     * Construct window with title and size.
     * @param title
     * @param size
     */
    Window(std::string title, const sf::Vector2u &size);

    ~Window();

    /// Clear window, must be called before drawing on screen
    void beginDraw();

    /// Display objects on window, must be called after draw()
    void endDraw();

    /// Checks for window events.
    void update();

    /// Return true if window still open otherwise false. This is triggered by window events.
    bool isDone() const;

    void toggleFullscreen();

    void draw(const sf::Drawable &drawable);

    sf::Vector2f getSize();
};

/**
 * Call window's draw() on vector of drawables
 * @tparam T drawable
 * @param drawables
 * @param window
 */
template<class T>
void draw_all(const std::vector<std::shared_ptr<T>> &drawables, const std::unique_ptr<Window> &window) {
    for (const auto &drawable: drawables)
        window->draw(*drawable);
}

/**
 * Call window's draw() on vector of drawables
 * @tparam T drawable
 * @param drawables
 * @param window
 */
template<class T>
void draw_all(const T &drawables, const std::unique_ptr<Window> &window) {
    for (const auto &drawable: drawables) {
        window->draw(drawable);
    }
}


#endif //BATTLE_CITY_PROJECT_WINDOW_H
