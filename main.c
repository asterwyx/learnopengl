#include <GLFW/glfw3.h>
#include "application.h"
#include <stdio.h>

int main(int argc, char *argv[]) {
    int result = glfwInit();
    if (result == GLFW_FALSE) {
        const char *err = NULL;
        glfwGetError(&err);
        printf("%s\n", err);
    }
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3); 
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
    GLFWwindow *window = glfwCreateWindow(800, 600, "learnopengl", NULL, NULL);
    if (window == NULL) {
        fprintf(stderr, "Failed to create GLFW window\n");
        return -1;
    }
    glfwMakeContextCurrent(window);
    const GLubyte *version = glGetString(GL_VERSION);
    GLenum error = glGetError();
    if (error != GL_NO_ERROR) {
        printf("OpenGL error: %d\n", error);
        return -1;
    } else {
        printf("OpenGL version: %s\n", version);
    }
    application_init();
    int exec_result = application_exec();
    application_cleanup();
    return exec_result;
}
