#include "glfw-util.hh"

#include <iostream>

void framebuffer_size_callback(GLFWwindow* window, int width, int height);
void processInput(GLFWwindow *window);

#define BUFFER_OFFSET(a) ((void*)(a))

int main()
{
  GLFWwindow* window;
  glfw::setup(window, "demo", 800, 600);

  // GL Part -- START
  enum VAO_IDs { Triangles, NumVAOs };
  enum Buffer_IDs { ArrayBuffer, NumBuffers };
  enum Attrib_IDs { vPosition = 0 };

  GLuint VAOs[NumVAOs];
  GLuint Buffers[NumBuffers];

  const GLuint NumVertices = 6;

  glGenVertexArrays(NumVAOs, VAOs);
  glBindVertexArray(VAOs[Triangles]);

  GLfloat vertices[NumVertices][2] = {
    { -1.00, -1.00 },
    {  1.00, -1.00 },
    { -1.00,  1.00 },
    {  1.00, -1.00 },
    {  1.00,  1.00 },
    { -1.00,  1.00 },
  };

  glGenBuffers(NumBuffers, Buffers);
  glBindBuffer(GL_ARRAY_BUFFER, Buffers[ArrayBuffer]);
  glBufferData(GL_ARRAY_BUFFER, sizeof(vertices),
               vertices, GL_STATIC_DRAW);

  //ShaderInfo shaders[] = {
  //  { GL_VERTEX_SHADER, "triangles.vert" },
  //  { GL_FRAGMENT_SHADER, "triangles.frag" },
  //  { GL_NONE, NULL },
  //};

  //GLuint program = LoadShaders(shaders);
  //glUseProgram(program);

  //glVertexAttribPointer(vPosition, 2, GL_FLOAT,
  //                      GL_FALSE, 0, BUFFER_OFFSET(0));
  //glEnableVertexAttribArray(vPosition);

  //while (!glfwWindowShouldClose(window))
  //{
  //  processInput(window);

  //  glClear(GL_COLOR_BUFFER_BIT);
  //  glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
  //  glBindVertexArray(VAOs[Triangles]);
  //  glDrawArrays(GL_TRIANGLES, 0, NumVertices);
  //  glFlush();

  //  glfwSwapBuffers(window);
  //  glfwPollEvents();
  //}

  // GL Part -- END
  glfw::teardown();
  return 0;
}

void processInput(GLFWwindow *window)
{
  if(glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
    glfwSetWindowShouldClose(window, true);
}

void framebuffer_size_callback(GLFWwindow* window, int width, int height)
{
  glViewport(0, 0, width, height);
}


