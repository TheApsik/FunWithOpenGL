#include<string>
#include<iostream>
#include "Frame.h"
#include "OpenGL.h"
#include "VertexArray.h"
#include "Buffer.h"
#include "Shader.h"
#include "ShaderProgram.h"
#include "Vector3.h"
#include "Mesh.h"
#include "Object.h"
#include "Attribute.h"
#include "MeshComponent.h"
#include "CameraMovmentControler.h"
#include "FrameManager.h"
#include "ObjectMovmentControler.h"
#include "Scene.h"
#include "MaterialComponent.h"
#include "Texture.h"
#include "SbSStereoscopeRenderer.h"
#include "AnaglyphStereoscopeRenderer.h"
#include "RendererSwaper.h"

int main()
{
    {
        Frame frame(1920, 1080, "OpenGL");
        FrameManager::setMainFrame(frame);

        OpenGL::init(true);

        VertexArray vao;
        vao.bind();

        Shader fragmentShader(FRAGMENT, "fragment.shader");
        Shader vertexShader(VERTEX, "vertex.shader");

        ShaderProgram sProgram;
        sProgram.attachShader(fragmentShader);
        sProgram.attachShader(vertexShader);
        sProgram.bindFragmentOutput("outColor", 0);
        sProgram.link();
        sProgram.use();

        Attribute vectorAttribute(sizeof(Vector3), FLOAT, false);
        Attribute v2Attribute(sizeof(glm::vec2), FLOAT, false);

        sProgram.addAttribute("position", vectorAttribute);
        sProgram.addAttribute("color", vectorAttribute);
        sProgram.addAttribute("texCoord", v2Attribute);
        sProgram.addUniformVariable("Texture", 0);

        Mesh mesh;

        /*mesh.setPositions({
                Vector3(-0.5f,  0.5f, 0.0f),
                Vector3( 0.5f,  0.5f, 0.0f),
                Vector3(-0.5f, -0.5f, 0.0f),
                Vector3( 0.5f, -0.5f, 0.0f)
            });

        mesh.setColors({
                Vector3(-0.5f,  0.5f, 0.0f),
                Vector3( 0.5f,  0.5f, 0.0f),
                Vector3(-0.5f, -0.5f, 0.0f),
                Vector3( 0.5f, -0.5f, 0.0f)
            });

        mesh.setIndexes({
            0, 1, 2,
            1, 3, 2
            });*/

        mesh.setPositions({ 
                Vector3(-0.5, -0.5,  0.5),
                Vector3( 0.5, -0.5,  0.5),
                Vector3( 0.5,  0.5,  0.5),
                Vector3(-0.5,  0.5,  0.5),

                Vector3(-0.5, -0.5, -0.5),
                Vector3( 0.5, -0.5, -0.5),
                Vector3( 0.5,  0.5, -0.5),
                Vector3(-0.5,  0.5, -0.5),

                Vector3(-0.5, -0.5,  0.5),
                Vector3(0.5, -0.5,  0.5),
                Vector3(0.5,  0.5,  0.5),
                Vector3(-0.5,  0.5,  0.5),

                Vector3(-0.5, -0.5, -0.5),
                Vector3(0.5, -0.5, -0.5),
                Vector3(0.5,  0.5, -0.5),
                Vector3(-0.5,  0.5, -0.5),


            });
        mesh.setTextureCoords({
                glm::vec2( 0.0f, 0.0f), //0
                glm::vec2( 1.0f, 0.0f), //1
                glm::vec2( 1.0f, 1.0f), //2
                glm::vec2( 0.0f, 1.0f), //3

                glm::vec2(0.0f, 1.0f),  //4
                glm::vec2(1.0f, 1.0f),  //5
                glm::vec2(1.0f, 0.0f),  //6
                glm::vec2(0.0f, 0.0f),  //7

                glm::vec2( 0.0f, 0.0f),  //8 
                glm::vec2(0.0f, 1.0f),  //9 ++
                glm::vec2(0.0f, 0.0f),  //10 ++
                glm::vec2(0.0f, 1.0f),  //11

                glm::vec2(1.0f, 0.0f),  //12
                glm::vec2(1.0f, 1.0f),  //13 +
                glm::vec2(1.0f, 0.0f),  //14 ++
                glm::vec2(1.0f, 1.0f),  //15
            });

//            glm::vec2(0.0f, 1.0f),
//            glm::vec2(1.0f, 1.0f),
//            glm::vec2(1.0f, 0.0f),
//            glm::vec2(0.0f, 0.0f)
//
        mesh.setColors({ 
                Vector3(1.0f,   1.0f,   1.0f),
                Vector3(0.0f,   1.0f,   1.0f),
                Vector3(0.0f,   0.0f,   1.0f),
                Vector3(1.0f,   1.0f,   0.0f),

                Vector3(1.0f,   0.0f,   0.0f),
                Vector3(0.0f,   1.0f,   0.0f),
                Vector3(1.0f,   0.0f,   1.0f),
                Vector3( .5f,    .5f,    .5f),

                Vector3(1.0f,   1.0f,   1.0f),
                Vector3(0.0f,   1.0f,   1.0f),
                Vector3(0.0f,   0.0f,   1.0f),
                Vector3(1.0f,   1.0f,   0.0f),

                Vector3(1.0f,   0.0f,   0.0f),
                Vector3(0.0f,   1.0f,   0.0f),
                Vector3(1.0f,   0.0f,   1.0f),
                Vector3(.5f,    .5f,    .5f)
            });

        mesh.setIndexes({
            //front
            0, 1, 2,
            2, 3, 0,
            // right
            1 + 8, 5 + 8, 6 + 8,
            6 + 8, 2 + 8, 1 + 8,
            // back
            7, 6, 5,
            5, 4, 7,
            // left
            4 + 8, 0 + 8, 3 + 8,
            3 + 8, 7 + 8, 4 + 8,
            // bottom
            4, 5, 1,
            1, 0, 4,
            // top
            3, 2, 6,
            6, 7, 3
            });

        mesh.load();

        Mesh mesh2;
        mesh2.setPositions({
            Vector3(-0.500000, -0.500000,  0.500000),
            Vector3(0.500000, -0.500000,  0.500000),
            Vector3(0.500000,  0.500000,  0.500000)
        });

        mesh2.setColors({
                Vector3(1.0f,   1.0f,   1.0f),
                Vector3(0.0f,   1.0f,   1.0f),
                Vector3(0.0f,   0.0f,   1.0f)
            });

        mesh2.setIndexes({
            0, 1, 2
            });

        mesh2.setTextureCoords({
                glm::vec2(0.0f, 1.0f),
                glm::vec2(1.0f, 1.0f),
                glm::vec2(0.0f, 0.0f),
                glm::vec2(0.0f, 1.0f)
            });
        
        mesh2.load();

        Camera camera;
        RendererSwaper swaper(sProgram, camera, 1920, 1080);
        //AnaglyphStereoscopeRenderer renderer(sProgram, camera, TRIANGLES);
        //renderer.setViewport(0, 0, 1920, 1080);

        RendererManager& menager = RendererManager::getInstance();
        //menager.setRenderer(renderer);

        CameraMovmentControler cameraControler(camera);
        ObjectMovmentControler mComponent;
        MeshComponent meshComponent;
        meshComponent.mesh = &mesh;
        MaterialComponent materialComp;
        Image image("assets/crate.bmp");
        Texture texture(image);
        materialComp.texture = &texture;

        MeshComponent meshComponent2;
        meshComponent2.mesh = &mesh2;

        Object object;
        object.addComponent<>(cameraControler);
        object.addComponent<>(swaper);

        Object object2;
        object2.position = Vector3(0.5f, 0.5f, 0.5f);
        object2.addComponent<>(meshComponent);
        object2.addComponent<>(materialComp);

        Scene scene;
        scene.add(object);
        scene.add(object2);

        size_t many = 1000;
        std::unique_ptr<Object[]> objects = std::make_unique<Object[]>(many);

        for (size_t i = 0; i < many; i++)
        {
            //std::cout << x << " " << y << " " << z << std::endl;
            Vector3::random(objects[i].position);
            //std::cout << objects[i].position.toString() << std::endl;
            objects[i].addComponent<>(mComponent);
            objects[i].addComponent<>(i%2==0?meshComponent: meshComponent2);
            scene.add(objects[i]);
        }
        frame.start(scene);
    }
    return 0;
}