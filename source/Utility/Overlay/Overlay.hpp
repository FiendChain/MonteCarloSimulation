#pragma once

#include "../../Runnable.hpp"

class Overlay: public IRunnable 
{
    private:
        IRunnable& mOverlay;
        IRunnable& mBackground;
    public:
        Overlay(IRunnable& overlay, IRunnable& background);
        void Update(float deltatime);
        bool PollEvent(const sf::Event& event);
    private:
        void draw(sf::RenderTarget& target, sf::RenderStates states) const;
};