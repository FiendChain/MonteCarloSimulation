#pragma once
#include <SFML/Graphics.hpp>

// plotter interface
class MonteCarloPlotter: public sf::Drawable
{
    public:
        virtual void AddPoint(float x, float y, bool inside) = 0;
        virtual void Reset();
    private:
        virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const = 0;
};