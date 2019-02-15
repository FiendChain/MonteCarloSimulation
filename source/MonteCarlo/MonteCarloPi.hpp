#pragma once
#include "MonteCarloPlotter.hpp"
#include "MonteCarlo.hpp"
#include <SFML/Graphics.hpp>
#include <random>

class MonteCarloPi: public MonteCarloSimulation {
    private:
        MonteCarloPlotter& mPlot;
        sf::RenderTexture mCircleOverlay;
        double mTotalPoints, mTotalInsideCircle;
        double mPiApproximation;
        const float mSize, mRadius;
        std::uniform_real_distribution<float> mDistribution;
        sf::Text mInfo;
    public:
        MonteCarloPi(MonteCarloPlotter& plot, float size, const sf::Font& font);
        void Update(float deltatime);
        bool PollEvent(const sf::Event& event);
        void Reset();
        void CreatePoint();
    private:
        float GetDistance(float x, float y);
        void UpdatePi();
        void UpdateOverlay();
        virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;
};