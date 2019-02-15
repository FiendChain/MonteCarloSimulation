#include "ControllableCamera.hpp"

ControllableCamera::ControllableCamera(ICamera& camera, ICameraControls& controls, IRunnable& projection)
    : mCamera(camera),
      mControls(controls),
      mProjection(projection)
{

}

bool ControllableCamera::PollEvent(const sf::Event& event)
{
    return mControls.PollEvent(event) || mProjection.PollEvent(event);
}

void ControllableCamera::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
    mCamera.draw(mProjection, states);
    mCamera.display();
    target.draw(mCamera, states);
}