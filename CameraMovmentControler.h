#pragma once
#include "Component.h"
#include "Camera.h"
#include "Vector3.h"
#include "Time.h"
class CameraMovmentControler :
    public Component
{
private:
    Camera& camera;
    Time timer;
public:
    float cameraSpeed = 1.0f;
    float cameraRotationSpeed = 0.001f;
    Vector3 rotation;

    CameraMovmentControler(Camera& camera);
    void Start();
    void Update();

};

