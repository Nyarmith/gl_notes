General gl format:
`void glCommand{sifd}(TYPE x1, TYPE y1, TYPE x2, TYPE y2);`

s,i,f,d = suffix for a gl type. types here are: GLshort, GLint, GLfloat, GLdouble

full gl types: GLboolean, GLbyte, GLubyte, GLshort, GLushort, GLint, GLuint, GLfixed (fixed pt), GLint64, GLuint64, GLsizei GLenum, GLintptr, GLsizeiptr, GLsync, GLbitfield, GLfloat, GLdouble

models = objects = primitives constructed from vertices

framebuffer = chunk of memory being fed to a display device

vertex attrib  pointers need to be enabled after being created

--------------------------------

concepts from triangles.cc

(1) After initial loading of primitives, like glBufferData()-'ing, we do the glDrawArrays() to draw those darned primitives
\-> usually means "transferring vertex data to the opengl server"

(2) vertex shader does thing for each vertex, this type of shader that does nothing is called a "pass-through shader"
- most applications have multiple vertex shaders, but only one can be active at a time


tessellation shader operations on patches of primitives, used for like LOD rendering for performance
