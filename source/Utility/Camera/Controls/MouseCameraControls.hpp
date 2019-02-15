#pragma once
#include "ICameraControls.hpp"
#include "../ICamera.hpp"

class MouseCameraControls: public ICameraControls {
    private:
        ICamera& m_Camera;
        bool m_MousePositionEnabled, m_DragWithMouse;
        sf::Vector2i m_LastMousePosition;
        sf::Vector2f m_Scale;
        unsigned int m_Width, m_Height;
    public:
        MouseCameraControls(ICamera& camera);
        bool PollEvent(const sf::Event& event);
    private:
        void Resize(float x, float y);
    private:
        void PollKeyPress(sf::Keyboard::Key key);
        void PollKeyRelease(sf::Keyboard::Key key);
        void PollMouseWheelScroll(const sf::Event::MouseWheelScrollEvent& wheel);
        void PollMouseButtonPress(const sf::Event::MouseButtonEvent& mouse);
        void PollMouseButtonRelease(const sf::Event::MouseButtonEvent& mouse);
        void PollMouseMove(const sf::Event::MouseMoveEvent& mouse);public:
};