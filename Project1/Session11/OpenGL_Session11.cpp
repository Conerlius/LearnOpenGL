#include "OpenGL_Session11.h"

void OpenGL_Session11::Start(ApplicationStart* application)
{
    GLuint VAO;
    glGenVertexArrays(1, &VAO);
    glBindVertexArray(VAO);
    GLuint VBO;
    glGenBuffers(1, &VBO);
    glBindBuffer(GL_ARRAY_BUFFER, VBO);
    glBufferData(GL_ARRAY_BUFFER, sizeof(g_vertex_buffer_data), g_vertex_buffer_data, GL_STATIC_DRAW);
    // 定点
    glEnableVertexAttribArray(0);
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(GL_FLOAT), (void*)0);

    glm::mat4 Projection = glm::perspective(glm::radians(45.0f), 4.0f / 3.0f, 0.1f, 100.0f);

    glm::mat4 View = glm::lookAt(
        glm::vec3(4, 3, -3), // Camera is at (4,3,3), in World Space
        glm::vec3(0, 0, 0), // and looks at the origin
        glm::vec3(0, 1, 0)  // Head is up (set to 0,-1,0 to look upside-down)
    );
    glm::mat4 Model = glm::mat4(1.0f);

    Shader lightShader = OpenGL_Tools::GetInstance()->CompileShader1( "Session11Shader");
    lightShader.use();
    lightShader.setVec3("objectColor", glm::vec3(1.0f, 0.5f, 0.31f));
    lightShader.setVec3("lightColor", glm::vec3(1.0f, 1.0f, 1.0f));
    lightShader.setMat4("model", Model);
    lightShader.setMat4("view", View);
    lightShader.setMat4("projection", Projection);
}

void OpenGL_Session11::drawView()
{
    glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    glEnable(GL_DEPTH_TEST);
    glDepthFunc(GL_LESS);
    
    // glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
    glDrawArrays(GL_TRIANGLES, 0, 12 * 3);
    // glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
}
