
// datum: 2022-12-26
// filnamn: textbox.h
// definition for class Textbox.

#ifndef BATTLE_CITY_PROJECT_TEXTBOX_H
#define BATTLE_CITY_PROJECT_TEXTBOX_H

#include <SFML/Graphics.hpp>
#include <vector>
#include <string>

/// Represent a textbox object.
class Textbox : public sf::Transformable, public sf::Drawable {
private:
    sf::RectangleShape rectangle_;
    sf::Font font_;
    std::string content_;
    sf::Text text_;
    sf::Vector2f size_;
    sf::Vector2f position_;
    int fontSize_;

    void draw(sf::RenderTarget &target, sf::RenderStates states) const override;

public:
    /**
     * Construct textbox of size 100x100 and position 0x0 and font size 20.
     */
    Textbox();

    /**
     * Construct textbox of given size, pos, font size and font path.
     * @param size
     * @param location
     * @param fontSize
     * @param fontPath
     */
    Textbox(sf::Vector2f size, sf::Vector2f location, int fontSize,
            const std::string &fontPath = "resources/arial.ttf");

    void setString(const std::string &str);

    std::string getString() const;

    /// Clear the current string in textbox
    void clear();

    /// Margin around the text.
    void setMargin(float margin);

    void fillBackgroundColor(const sf::Color &color);

    void setBoxSize(const sf::Vector2f &size);

    void setBorderBoxStyle(const sf::Color &color, float thickness);

    void setBorderColor(const sf::Color &color);

    void setBorderThickness(float thickness);
};

#endif //BATTLE_CITY_PROJECT_TEXTBOX_H
