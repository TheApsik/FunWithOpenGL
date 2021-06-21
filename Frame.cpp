#include "Frame.h"
#include <math.h>
#include <chrono>
#include <GL/glew.h>
#include <glm/gtx/quaternion.hpp>
#include <glm/gtx/string_cast.hpp>
#include "Time.h"
#include "FrameManager.h"
#include <sstream>

void Frame::start(Scene& scena)
{
    RendererManager& rendererMenager = RendererManager::getInstance();

	bool running = true;
    int fps = 0;
    int fpsNow = 0;

    float frameTime = 0.0f;
    float updateCicle = 0.0f;
    Time frame;
    Time updateTime;
    Time renderTime;
    //window.setFramerateLimit(5);
    glEnable(GL_DEPTH_TEST);
    while (running) {

        sf::Event windowEvent;
        while (window.pollEvent(windowEvent)) {
            switch (windowEvent.type) {
                case sf::Event::Closed:
                    running = false;
                    break;
                case sf::Event::KeyPressed:
                    if (windowEvent.key.code == sf::Keyboard::Escape)
                        running = false;
                    break;
            }
        }

        frame.stop();
        updateCicle = frame.getMicroseconds();
        frameTime += updateCicle;
        frame.start();

        updateTime.start();
        scena.update();
        updateTime.stop();
        renderTime.start();
        rendererMenager.renderAll();
        renderTime.stop();
        FrameManager::isFucus = window.hasFocus();

        window.display();

        if ( frameTime/1000.0f > 1000.0f) {
            fps = fpsNow;
            fpsNow = -1;
            std::stringstream ss;
            ss << "FPS: " << fps
                << ", FrameTime: " << std::fixed << std::setprecision(2) << (frameTime / fps)/1000
                << "ms, Update: " << std::fixed << std::setprecision(2) << updateTime.getMicroseconds() / 1000
                << "ms, Render: " << std::fixed << std::setprecision(2) << renderTime.getMicroseconds() / 1000
                << "ms";

            window.setTitle(ss.str());
            frameTime = 0;
        }
        fpsNow++;
    }
}


Frame::Frame(int width, int height, std::string title) : settings(24, 8), window(sf::VideoMode(width, height, 32), title, sf::Style::Titlebar | sf::Style::Close, settings)
{
    sf::Mouse::setPosition(sf::Vector2i(window.getSize()) / 2, window);
}
