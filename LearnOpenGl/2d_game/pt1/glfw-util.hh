#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include <stdexcept>
#include <cstdio>

namespace glfw {

int SRC_WIDTH{0};
int SRC_HEIGHT{0};

void error_callback(int error, const char* description)
{
  fprintf(stderr, "GLFW error: %d -  %s\n", error, description);
}

void glfw_resize_cb(GLFWwindow*,int w, int h)
{
  SRC_WIDTH  = w;
  SRC_HEIGHT = h;
}

static void setup(GLFWwindow *&win, const char* window_name, int width, int height)
{
    glfwSetErrorCallback(error_callback);
    if (!glfwInit())
    {
        throw std::runtime_error("Failed to initialize glfw\n");
    }

    // direct opengl version
    #ifdef __APPLE__
        glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
        glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 2);
        glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
        glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
    #else
        glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
        glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 2);
    #endif

    win = glfwCreateWindow(width, height, window_name, NULL, NULL);
    if (!win)
    {
        glfwTerminate();
        throw std::runtime_error("Failed to create GLFW window\n");
    }

    glfwSetWindowSizeCallback(win, glfw_resize_cb);
    glfwMakeContextCurrent(win);
    // opengl thing
    if (!gladLoadGLLoader(reinterpret_cast<GLADloadproc>(glfwGetProcAddress)))
    {
        glfwTerminate();
        throw std::runtime_error("Failed to initialize GLAD\n");
    }
    glfwSwapInterval(1);

    fprintf(stderr,"OpenGL version from glad: %d.%d",GLVersion.major, GLVersion.minor);
}

void teardown()
{
    glfwTerminate();
}

}
