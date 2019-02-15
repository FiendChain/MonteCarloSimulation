#pragma once

#include <SFML/Graphics.hpp>
#include "../../Runnable.hpp"

class FpsCounter: public IRunnable
{
    private:
        sf::Text& m_Text;
        float m_FrameTime;
        float m_Fps;
    public:
        FpsCounter(sf::Text& text);
        void Update(float deltatime);
        bool PollEvent(const sf::Event& event) { return false; }
    private:
        void SetFps(float fps);
        virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;
};