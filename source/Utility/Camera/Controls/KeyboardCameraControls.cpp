#include "KeyboardCameraControls.hpp"

KeyboardCameraControls::KeyboardCameraControls(ICamera& camera)
    : mCamera(camera),
      mSpeed(1.0f)
{

}

bool KeyboardCameraControls::PollEvent(const sf::Event& event)
{
    switch (event.type)
    {
    case sf::Event::KeyPressed:
        PollKeyPress(event.key.code);                   break;
    }
    return false;
}

void KeyboardCameraControls::PollKeyPress(sf::Keyboard::Key key)
{
    switch (key)
    {
    case sf::Keyboard::W:
        mCamera.Translate(mCamera.Move::Up, mSpeed); break;
    case sf::Keyboard::S:
        mCamera.Translate(mCamera.Move::Down, mSpeed); break;
    case sf::Keyboard::A:
        mCamera.Translate(mCamera.Move::Left, mSpeed); break;
    case sf::Keyboard::D:
        mCamera.Translate(mCamera.Move::Right, mSpeed); break;
    }
}
