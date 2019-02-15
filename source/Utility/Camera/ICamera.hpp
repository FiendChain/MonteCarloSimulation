#pragma once 

#include <SFML/Graphics.hpp>
#include "../IRenderTarget.hpp"

class ICamera: public sf::Drawable, public IRenderTarget
{
    public:
        enum Move { Up, Down, Left, Right };
    public:
        virtual void Translate(float x, float y) = 0;
        virtual void Translate(ICamera::Move move, float distance) = 0;
        virtual float GetZoom() const = 0;
        virtual void SetZoom(float zoom) = 0;
    public:
        virtual unsigned GetWidth() const = 0;
        virtual unsigned GetHeight() const  = 0;
    public:
        virtual void display() = 0;
        virtual void clear(const sf::Color& color) = 0;
        virtual void draw(sf::Drawable& drawable, sf::RenderStates states) = 0;
    private:
        virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const = 0;
};
