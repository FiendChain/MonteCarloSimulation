#include "Canvas.hpp"

Canvas::Canvas(float size)
    : mSize(size)
{
    mCanvas.create(size, size);
    mCanvas.clear(sf::Color::White);
    
    // defaults
    SetBrushSize(1.0f);
    SetInsideColor(sf::Color::Red);
    SetOutsideColor(sf::Color::Blue);
}

void Canvas::SetBrushSize(float size)
{
    mInsideBrush.setRadius(size);
    mOutsideBrush.setRadius(size);
}

void Canvas::SetInsideColor(const sf::Color& color)
{
    mInsideBrush.setFillColor(color);
}

void Canvas::SetOutsideColor(const sf::Color& color)
{
    mOutsideBrush.setFillColor(color);
}

void Canvas::AddPoint(float x, float y, bool inside) 
{
    sf::CircleShape& brush = inside ? mInsideBrush : mOutsideBrush;
    brush.setPosition(x, y);
    mCanvas.draw(brush);
}

void Canvas::Reset()
{
    mCanvas.clear(sf::Color::White);
}

void Canvas::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
    target.draw(sf::Sprite(mCanvas.getTexture()), states);
}