#include "FpsCounter.hpp"

#include <sstream>
#include <iomanip>

FpsCounter::FpsCounter(sf::Text& text)
    : m_Text(text)
{
   
}

void FpsCounter::Update(float deltatime)
{
    m_FrameTime = deltatime;
    SetFps(1000.0f/(float)m_FrameTime);
}

void FpsCounter::SetFps(float fps)
{
    m_Fps = fps;
    std::stringstream ss;
    ss << std::setprecision(0) << std::fixed;
    ss << "Fps: " << fps;
    m_Text.setString(ss.str());
}

void FpsCounter::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
    target.draw(m_Text, states);
}