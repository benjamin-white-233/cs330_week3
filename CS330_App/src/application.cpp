#include <application.h>
#include <iostream>
#include <types.h>
#include <vector>

Application::Application(std::string WindowTitle, int width, int height) : _applicationName{ WindowTitle }, _width{ width }, _height{ height } {}

void Application::Run() {
    // Open the window
    if (!openWindow()) {
        return;
    }

    _running = true;

    // Set up the scene
    setupScene();

    // Run application
    while (_running) {
        if (glfwWindowShouldClose(_window)) {
            _running = false;
            break;
        }
        // Update
        update();
        // Draw
        draw();
    }
    glfwTerminate();
}

bool Application::openWindow() {
    // initialize glad to v3.3
    glfwInit();
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

#ifdef __APPLE__
    glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
#endif
    // creating the window, 800x600
    _window = glfwCreateWindow(800, 600, "Benjamin White", nullptr, nullptr);

    if (!_window) {
        std::cerr << "Failed to create GLFW window!" << std::endl;
        glfwTerminate();
    }

    // sets _widow to the current thread
    glfwMakeContextCurrent(_window);

    // adjusting the viewport if window is resized
    glfwSetFramebufferSizeCallback(_window, [](GLFWwindow* window, int width, int height) {
        glViewport(0, 0, width, height);
    });

    // if GLAD cannot be loaded, return false
    if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)) {
        std::cerr << "Failed to initialize GLAD" << std::endl;
        glfwTerminate();
        return false;
    }
    // otherwise, return true
    return true;
}


void Application::setupScene() {
    std::vector<Vertex> vertices = {
            {
                    // 0
                    .Position = {-1.f, 1.f, 0.f},
                    .Color = {1.f, 0.f, 0.f}
            },
            {
                    // 1
                    .Position = {-1.f, 0.f, 0.f},
                    .Color = {0.f, 0.f, 0.5f}
            },
            {
                    // 2
                    .Position = {-0.5f, 0.f, 0.f},
                    .Color = {0.f, 1.f, 0.f}
            },
            {
                    // 3
                    .Position = {0.f, -1.f, 0.f},
                    .Color = {0.f, 1.f, 0.f}
            },
            {
                    // 4
                    .Position = {0.f, 0.f, 0.f},
                    .Color = {1.f, 0.f, 0.f}
            }
    };

    // identifying the order of vertices to access
    std::vector<uint32_t> elements {
        0, 1, 2,
        2, 3, 4,
    };

    // appending vertices and elements to back of our mesh vector
    _meshes.emplace_back(std::move(vertices), std::move(elements));

}

bool Application::update() {
    return false;
}

bool Application::draw() {
    // background color
    glClearColor(0.f, 0.f, 0.f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT);

    // draw each mesh
    for (auto mesh : _meshes) {
        mesh.Draw();
    }

    glfwSwapBuffers(_window);
    glfwPollEvents();

    return false;
}

