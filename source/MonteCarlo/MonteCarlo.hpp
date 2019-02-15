#pragma once
#include "MonteCarloPlotter.hpp"
#include "../Runnable.hpp"
#include <SFML/Graphics.hpp>
#include <random>

class MonteCarloSimulation: public IRunnable {
    protected:
        std::default_random_engine mRngEngine;
    public:
        virtual void Update(float deltatime) = 0;
        virtual void CreatePoint() = 0;
        virtual void Reset() = 0;
        virtual bool PollEvent(const sf::Event& event);
    private:
        virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const = 0;
};