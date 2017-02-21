#ifndef APPLICATION3D_HPP
#define APPLICATION3D_HPP

#include <glm/glm.hpp>
#include "system/Application.hpp"
#include "graphics/Shader.hpp"

#define GLM_FORCE_RADIANS
class Application3D : public Application
{
public:
    Application3D();
    virtual ~Application3D();

protected:
    virtual void loop();

private:
    float time = 0.f;
    const int size = 100;

    // shader
    Shader vertexShader;
    Shader fragmentShader;
    ShaderProgram shaderProgram;

    // shader matrix uniform
    glm::mat4 projection = glm::mat4(1.0);
    glm::mat4 view = glm::mat4(1.0);

    // VBO/VAO/ibo
    GLuint vao,vbo,ibo;
};

#endif /* end of APPLICATION3D_HPP */
