#pragma once
#include <filesystem>
#include <string>
#include <glad/glad.h>

using Path = std::filesystem::path;

class Shader {
public:
    Shader() = default;
    Shader(const std::string& vertexSource, const std::string& fragmentSource);
    Shader(const Path& vertexPath, const Path& fragmentPath);

    void Bind();

private:
    void load(const std::string& vertexSource, const std::string& fragmentSource);
private:
    GLuint _shaderProgram;
};