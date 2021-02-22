add_executable(2d_demo 
               app.cc
               main.cc
               ResourceManager.cc
               shader.cc
               texture.cc)

target_link_libraries(2d_demo PRIVATE glfw OpenGL::GL glad)
