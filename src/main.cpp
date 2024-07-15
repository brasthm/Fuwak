#include <iostream>

#include <SFML/Graphics.hpp>
#include "Interpolable.h"


int main()
{
    sf::RenderWindow window(sf::VideoMode(1000, 1000), "Test Animation");

    sf::Texture myrtille;
    myrtille.loadFromFile("../myrtille.png");

    sf::Texture portrait;
    portrait.loadFromFile("../myrtille.png", sf::IntRect(600, 135, 390, 390));

    sf::Sprite idle;
    idle.setTexture(myrtille);

    sf::Sprite icon;
    icon.setTexture(portrait);
    icon.setOrigin(195, 195);


    IFloat size(EaseOutExpo), rotation(EaseInLinear);
    size.set(0.7, 1);
    rotation.setInstant(5);
    rotation.set(10, 3);

    IVector2f iconPosition(EaseInLinear), idlePosition(EaseOutBack);
    iconPosition.setInstant(sf::Vector2f(500, 500));
    iconPosition.set(sf::Vector2f(550, 520), 3);

    idle.setScale(0.7, 0.7);
    idlePosition.setInstant(sf::Vector2f(-idle.getGlobalBounds().width, 0));
    idlePosition.set(sf::Vector2f(0, 0), 1);

    bool drawIcon = false;

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed) {
                window.close();
            }
            if(event.type == sf::Event::KeyPressed) {
                if(event.key.code == sf::Keyboard::Return) {
                    size.setInstant(0);
                    size.set(0.7, 1);
                    rotation.setInstant(5);
                    rotation.set(10, 3);
                    iconPosition.setInstant(sf::Vector2f(500, 500));
                    iconPosition.set(sf::Vector2f(550, 520), 3);

                    idlePosition.setInstant(sf::Vector2f(-idle.getGlobalBounds().width, 0));
                    idlePosition.set(sf::Vector2f(0, 0), 1);
                }
            }
            if(event.type == sf::Event::MouseButtonPressed) {
                drawIcon = !drawIcon;
            }
        }

        icon.setScale(size.get(), size.get());
        icon.setRotation(rotation.get());
        icon.setPosition(iconPosition.get());

        idle.setPosition(idlePosition.get());

        window.clear();
        if(drawIcon) window.draw(icon);
        else window.draw(idle);

        window.display();
    }

    return 0;
}