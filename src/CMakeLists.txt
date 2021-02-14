add_executable(sample_target sample_file.cc)
target_link_libraries(sample_target PRIVATE glfw OpenGL::GL glad)
