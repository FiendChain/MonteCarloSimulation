#pragma once

#include "Controls/ICameraControls.hpp"
#include "ICamera.hpp"
#include "../../Runnable.hpp"

class ControllableCamera: public IRunnable
{
    private:
        ICamera& mCamera;
        ICameraControls& mControls; 
        IRunnable& mProjection;
    public:
        ControllableCamera(ICamera& camera, ICameraControls& controls, IRunnable& projection);
        void Update(float deltatime) { mProjection.Update(deltatime); }
        bool PollEvent(const sf::Event& event);
    private:
        virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;
};