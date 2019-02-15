#pragma once

#include <SFML/Graphics.hpp>

class IRenderTarget 
{
    public:
        virtual void draw(sf::Drawable& drawable, sf::RenderStates states) = 0;
        virtual void clear(const sf::Color& color) = 0;
        virtual void display() = 0;
};

class IRenderTargetFromSFML: public IRenderTarget
{
    private:
        sf::RenderTarget& mTarget;
    public:
        IRenderTargetFromSFML(sf::RenderTarget& target)
            : mTarget(target) {}
        void draw(sf::Drawable& drawable, sf::RenderStates states) 
        {
            mTarget.draw(drawable, states);
        }
        void clear(const sf::Color& color)
        {
            mTarget.clear(color);
        }
        void display() {};
};