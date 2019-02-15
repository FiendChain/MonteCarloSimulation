#include "MonteCarloPi.hpp"
#include <math.h>
#include <sstream>

MonteCarloPi::MonteCarloPi(MonteCarloPlotter& plot, float size, const sf::Font& font) 
    : mTotalPoints(0), mTotalInsideCircle(0),
      mPiApproximation(0),
      mSize(size),
      mRadius(size/2.0f),
      mDistribution(0, size),
      mPlot(plot)
{
    // init overlay
    mCircleOverlay.create(size, size);
    mCircleOverlay.clear(sf::Color::Transparent);
    sf::CircleShape overlayCircle(size/2.0f, 100);
    overlayCircle.setFillColor(sf::Color::Transparent);
    overlayCircle.setOutlineColor(sf::Color::Black);
    overlayCircle.setOutlineThickness(2.0f);
    overlayCircle.setPosition(0, 0);
    mCircleOverlay.draw(overlayCircle);
    // info overlay
    mInfo.setFont(font);
    mInfo.setPosition(10, 10);
    mInfo.setFillColor(sf::Color::White);
    mInfo.setOutlineColor(sf::Color::Black);
    mInfo.setOutlineThickness(2.0f);
    mInfo.setCharacterSize(24.0f);
}

void MonteCarloPi::Update(float deltatime) 
{
    UpdatePi();
    UpdateOverlay();
}

bool MonteCarloPi::PollEvent(const sf::Event& event)
{
    if (event.type == sf::Event::KeyPressed)
    {
        if (event.key.code == sf::Keyboard::R)
        {
            Reset();
            return true;
        }
    }
    return false;
}

void MonteCarloPi::Reset()
{
    mPlot.Reset();
    mTotalPoints = 0;
    mTotalInsideCircle = 0;
    mPiApproximation = 0;
}

void MonteCarloPi::CreatePoint()
{
    float x = mDistribution(mRngEngine); 
    float y = mDistribution(mRngEngine);
    mTotalPoints++;
    float distance = GetDistance(x, y);
    if (distance < mRadius) {
        mTotalInsideCircle++;
        mPlot.AddPoint(x, y, true);
    } else {
        mPlot.AddPoint(x, y, false);
    }
}

void MonteCarloPi::UpdatePi()
{
    // square = 4*r^2
    // circle = pi*r^2
    // pi = circle/square * 4
    if (mTotalPoints > 0)
        mPiApproximation = mTotalInsideCircle/mTotalPoints * 4;
}

void MonteCarloPi::UpdateOverlay() 
{
    std::stringstream ss;
    ss << "Pi: " << mPiApproximation << '\n'
       << "Inside: " << mTotalInsideCircle << '\n'
       << "Total: " << mTotalPoints;
    mInfo.setString(ss.str());
}

float MonteCarloPi::GetDistance(float x, float y)
{
    float distanceSquared = pow(x-mRadius, 2.0f)+pow(y-mRadius, 2.0f);
    float distance  = pow(distanceSquared, 0.5f);
    return distance;
}

void MonteCarloPi::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
    target.draw(mPlot, states);
    target.draw(sf::Sprite(mCircleOverlay.getTexture()), states);
    target.draw(mInfo, states);
}
