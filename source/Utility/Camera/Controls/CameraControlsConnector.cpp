#include "CameraControlsConnector.hpp"

CameraControlsConnector::CameraControlsConnector(ICameraControls& first, ICameraControls& second)
    : mFirst(first), mSecond(second)
{

}

bool CameraControlsConnector::PollEvent(const sf::Event& event)
{
    return mFirst.PollEvent(event) || mSecond.PollEvent(event);
}