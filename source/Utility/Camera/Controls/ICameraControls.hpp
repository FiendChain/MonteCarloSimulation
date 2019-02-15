#pragma once
#include <SFML/Graphics.hpp>

class ICameraControls {
    public:
        virtual bool PollEvent(const sf::Event& event) = 0;
};