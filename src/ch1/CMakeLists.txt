add_executable(triangles triangles.cc LoadShaders.cc)
target_link_libraries(triangles PRIVATE glfw OpenGL::GL glad)
