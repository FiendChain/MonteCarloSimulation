#pragma once
#include "ICameraControls.hpp"

class CameraControlsConnector: public ICameraControls
{
    private:
        ICameraControls& mFirst;
        ICameraControls& mSecond;
    public:
        CameraControlsConnector(ICameraControls& first, ICameraControls& second);
        bool PollEvent(const sf::Event& event);
};