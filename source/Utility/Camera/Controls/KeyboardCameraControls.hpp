#pragma once
#include "ICameraControls.hpp"
#include "../ICamera.hpp"

class KeyboardCameraControls: public ICameraControls
{
    private:
        ICamera& mCamera;
        float mSpeed;
    public:
        KeyboardCameraControls(ICamera& camera);
        bool PollEvent(const sf::Event& event);
        void SetSpeed(float speed) { mSpeed = speed; }
    private:
        void PollKeyPress(sf::Keyboard::Key key);
};