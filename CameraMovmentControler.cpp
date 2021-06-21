#include "CameraMovmentControler.h"
#include<SFML/Window.hpp>
#include <glm/gtx/quaternion.hpp>
#include "FrameManager.h"

CameraMovmentControler::CameraMovmentControler(Camera& camera):camera(camera){
}

void CameraMovmentControler::Start()
{
}

float between(float value, float min, float max) {
    if (value < min)
        return min;
    if (value > max)
        return max;
    return value;
}

void CameraMovmentControler::Update()
{
    timer.stop();
    float time = timer.getMicroseconds()/1000000;
    //std::cout << time << std::endl;
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
        camera.position += camera.direction * ((cameraSpeed * time));
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)) {
        camera.position += camera.direction * -((cameraSpeed * time));
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)) {
        glm::vec3 v = glm::normalize(glm::vec3(camera.direction.z, 0, -camera.direction.x));
        camera.position += v * ((cameraSpeed * time));
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {
        glm::vec3 v = glm::normalize(glm::vec3(-camera.direction.z, 0, camera.direction.x));
        camera.position += v * ((cameraSpeed * time));
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::LShift)) {
        cameraSpeed = 40.0f;
    }
    else {
        cameraSpeed = 5.0f;
    }

    if (FrameManager::isFucus) {
        sf::Vector2f mousePosition = FrameManager::getMousePosition();
        FrameManager::setCoursorCenter();

        rotation.x += mousePosition.y;
        rotation.y += mousePosition.x;
        rotation.x = between(rotation.x, -1.570f, 1.570f);
        rotation.y = fmodf(rotation.y, 2.0f * 3.14159265359f);

        glm::vec3 v(0.0f, 0.0f, -1.0f);
        glm::quat q1 = glm::angleAxis(rotation.x, glm::vec3(1.0f, 0.0f, 0.0f));
        glm::quat q2 = q1 * glm::angleAxis(rotation.y, glm::vec3(0.0f, 1.0f, 0.0f));
        camera.direction = glm::normalize(v * q2);
    }
    timer.start();
}
