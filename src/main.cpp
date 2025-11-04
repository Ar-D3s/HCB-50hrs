#include <iostream>
#include <SFML/Graphics.hpp>

int main() {

    unsigned int windowHeight = 600.f;
    unsigned int windowWidth = 800.f;

    sf::RenderWindow window(sf::VideoMode({windowWidth, windowHeight}), "My game");
    sf::View view;
    view.setCenter({0.f, 0.f});
    view.setSize({800.f, 600.f});

    while (window.isOpen()) {

        while (const std::optional event = window.pollEvent()) {

            if (event->is<sf::Event::Closed>()) {
                window.close();
            }

            else if (const auto* resize = event->getIf<sf::Event::Resized>()) {
                windowWidth = resize->size.x;
                windowHeight = resize->size.y;

                view.setSize({static_cast<float>(windowWidth), static_cast<float>(windowHeight)});
                window.setView(view);
            }

        }

        window.clear({34, 73, 93});
        window.setView(view);
        window.display();
    }

    return 0;
}
