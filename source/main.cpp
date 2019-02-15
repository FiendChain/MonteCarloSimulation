#include "MonteCarlo/Canvas.hpp"
#include "MonteCarlo/MonteCarloPi.hpp"

#include "Utility/FpsCounter/FpsCounter.hpp"
#include "Utility/Overlay/Overlay.hpp"

#include "Utility/Camera/StandardCamera.hpp"
#include "Utility/Camera/ControllableCamera.hpp"

#include "Utility/Camera/Controls/MouseCameraControls.hpp"
#include "Utility/Camera/Controls/KeyboardCameraControls.hpp"
#include "Utility/Camera/Controls/CameraControlsConnector.hpp"

#include <SFML/Graphics.hpp>

int main(int argc, char *argv[])
{
    float size = 1000;
    int totalSteps = 1;
    sf::Font font;
    font.loadFromFile("resources/fonts/Arial.ttf");

    Canvas canvas(size);
    canvas.SetBrushSize(1);
    canvas.SetInsideColor(sf::Color(255, 0, 0));
    canvas.SetOutsideColor(sf::Color(0, 0, 255));

    MonteCarloPi simulation(canvas, size, font);
    IRunnable *app = &simulation;

    // Wrap camera
    StandardCamera camera(size, size);
    MouseCameraControls mouseControls(camera);
    KeyboardCameraControls keyboardControls(camera);
    // ICameraControls *controls = new CameraControlsConnector(mouseControls, keyboardControls);
    ICameraControls& controls = mouseControls;
    app = new ControllableCamera(camera, controls, *app);

    // Wrap fps counter
    sf::Text fpsCounterText;
    FpsCounter fpsCounter(fpsCounterText);

    const float fpsCounterSize = 25.0f;
    fpsCounterText.setFont(font);
    fpsCounterText.setPosition(size-fpsCounterSize*6, 0+fpsCounterSize);
    fpsCounterText.setCharacterSize(fpsCounterSize);
    fpsCounterText.setFillColor(sf::Color::Green);
    fpsCounterText.setOutlineColor(sf::Color::Black);
    fpsCounterText.setOutlineThickness(1.0f);

    app = new Overlay(fpsCounter, *app);
    
    // App
    sf::RenderWindow window(sf::VideoMode(size, size), "Monto Carlo Sim");
    sf::Clock clock;
    while (window.isOpen())
    {
        for (int i = 0; i < totalSteps; i++)
        {
            simulation.CreatePoint();
        }
        app->Update(clock.restart().asMicroseconds()/1000.0f);
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (app->PollEvent(event))
                continue;

            if (event.type == sf::Event::Closed)
            {
                window.close();
            } 
        }
        window.clear();
        window.draw(*app);
        window.display();
    }

    return 0;
}
