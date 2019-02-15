#pragma once
#include <SFML/Graphics.hpp>
#include "MonteCarloPlotter.hpp"

class Canvas: public MonteCarloPlotter {
    private:
        const float mSize;
        sf::RenderTexture mCanvas;
        sf::CircleShape mInsideBrush, mOutsideBrush;
        sf::Color mInsideColor, mOutsideColor; 
    public:
        Canvas(float size);
        virtual void AddPoint(float x, float y, bool inside);
        virtual void Reset();
        void SetBrushSize(float size);
        void SetInsideColor(const sf::Color& color);
        void SetOutsideColor(const sf::Color& color);
    private:
        virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;
};