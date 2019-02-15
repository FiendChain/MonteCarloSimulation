#include "StandardCamera.hpp"
#include <SFML/Graphics.hpp>

StandardCamera::StandardCamera(unsigned int width, unsigned int height)
    : m_Width(width), m_Height(height),
      m_Position(width/2.0f, height/2.0f), m_Origin(width/2.0f, height/2.0f),
      m_Zoom(1.0f)
{
    if (!m_Canvas.create(width, height))
        throw std::runtime_error("Couldn't create rendertexture canvas");
}

void StandardCamera::SetZoom(float zoom)
{
    if (zoom > 0) 
    {
        m_Zoom = zoom;
    }
}

void StandardCamera::Translate(Move move, float distance)
{
    switch (move)
    {
    case Move::Up:
        m_Origin.y -= distance; 
        break;
    case Move::Down:
        m_Origin.y += distance; 
        break;
    case Move::Left:
        m_Origin.x -= distance; 
        break;
    case Move::Right:
        m_Origin.x += distance; 
        break;
    }
}

void StandardCamera::Translate(float x, float y)
{
    m_Origin.x += x;
    m_Origin.y += y;
}

void StandardCamera::clear(const sf::Color& colour) 
{
    m_Canvas.clear(colour);
}

void StandardCamera::draw(sf::Drawable& drawable, sf::RenderStates states)
{
    m_Canvas.draw(drawable, states);
}

void StandardCamera::display()
{
    m_Canvas.display();
}

void StandardCamera::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
    sf::Sprite canvas(m_Canvas.getTexture());
    canvas.setScale(m_Zoom, m_Zoom);
    canvas.setOrigin(m_Origin);
    canvas.setPosition(m_Position);

    target.draw(canvas, states);
}
