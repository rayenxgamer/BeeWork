#include <stdlib.h>
#include "window.h"
#include "GLFW/glfw3.h"
#include "utils/types.h"


void init_window(GLFWwindow** window, int height, int width, const char* title)
{
    // Initializing GLFW
    if (!glfwInit()) {
        exit(EXIT_FAILURE);
    }

    // Setting the OpenGL window
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

    // Creating the window
    *window = glfwCreateWindow(width, height, title, NULL, NULL);
    if (!*window) {
        glfwTerminate();
        printf("Failed to create the window");
        exit(EXIT_FAILURE);
    }

    glfwMakeContextCurrent(*window);

    if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)) {
        printf("Failed to initialize OpenGL context\n");
        exit(EXIT_FAILURE);
    }

    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
}
bool ShouldCloseCheck(GLFWwindow** window, bool* running){
    if (glfwWindowShouldClose(*window)) {
        *running = false;
    }
    return running;
};

void Shutdown_window(GLFWwindow** window){
    glfwDestroyWindow(*window);

    glfwTerminate();
    exit(EXIT_SUCCESS);
}

void Clear_window(f32 red, f32 blue, f32 green , f32 alpha){
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glClearColor(red,blue,green,alpha);
}

static void error_callback(int error, const char* description)
{
    fprintf(stderr, "Error: %s\n", description);
}

