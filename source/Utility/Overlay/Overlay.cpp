#include "Overlay.hpp"

Overlay::Overlay(IRunnable& overlay, IRunnable& background)
    : mOverlay(overlay),
      mBackground(background)
{

}

void Overlay::Update(float deltatime)
{
    mOverlay.Update(deltatime);
    mBackground.Update(deltatime);
}

bool Overlay::PollEvent(const sf::Event& event)
{
    return mOverlay.PollEvent(event) || mBackground.PollEvent(event);
}

void Overlay::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
    target.draw(mBackground, states);
    target.draw(mOverlay, states);
}