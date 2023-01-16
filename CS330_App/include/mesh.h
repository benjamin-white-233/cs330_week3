#pragma once
#include <vector>
#include <types.h>
#include <glad/glad.h>

class Mesh {
public:
    Mesh(std::vector<Vertex>&& vertices, std::vector<uint32_t>&& indices);

    void Draw();

private:
    uint32_t _elementCount {0};
    GLuint _vertexBufferObject {};
    GLuint _shaderProgram {};
    GLuint _vertexArrayObject {};
    GLuint _elementBufferObject {};
};