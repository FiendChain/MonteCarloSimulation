#pragma once

#include <SFML/Graphics.hpp>
#include "ICamera.hpp"

class StandardCamera: public ICamera
{
    
    private:
        sf::RenderTexture m_Canvas;
        unsigned int m_Width, m_Height;
        sf::Vector2f m_Position, m_Origin;
        float m_Zoom;
    public:
        StandardCamera(unsigned int width, unsigned int height);
        unsigned GetWidth() const { return m_Width; }
        unsigned GetHeight() const { return m_Height; }
        void SetZoom(float zoom);
        inline float GetZoom() const { return m_Zoom; }
        void Translate(Move move, float distance);
        void Translate(float x, float y);
        void clear(const sf::Color& colour);
        void draw(sf::Drawable& drawable, sf::RenderStates states);
        void display();
    private:
        virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;
};
