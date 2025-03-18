#pragma once

#include <glad/glad.h>
#include <cglm/cglm.h>
#include <GLFW/glfw3.h>
#include <utils/types.h>
#include <stdbool.h>
#include <stdio.h>

struct window{
    int height;
    int width;
    bool shown;
};

void init_window(GLFWwindow** window,int height,int width, const char* title);
void Clear_window(f32 red, f32 blue, f32 green , f32 alpha);
bool ShouldCloseCheck(GLFWwindow** window, bool* running);
void Shutdown_window(GLFWwindow** window);
static void error_callback(int error, const char* description);
