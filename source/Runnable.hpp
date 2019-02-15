#pragma once
#include <SFML/Graphics.hpp>

class IRunnable: public sf::Drawable {
    public:
        virtual void Update(float deltaTime) = 0;
        virtual bool PollEvent(const sf::Event& event) = 0;
    private:
        virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const  = 0;
};