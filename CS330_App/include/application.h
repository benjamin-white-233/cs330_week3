#pragma once

#include <string>
#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <shader.h>

#include <mesh.h>

class Application {
public:
    Application(std::string WindowTitle, int width, int height);
    void Run();

private:
    bool openWindow();
    void setupScene();
    bool draw();
    bool update();

private:
    std::string _applicationName {};
    int _width {};
    int _height {};
    GLFWwindow* _window { nullptr };

    std::vector<Mesh> _meshes;
    Shader _shader;
    bool _running { false };

};