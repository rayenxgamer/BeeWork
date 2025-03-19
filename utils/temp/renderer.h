#pragma once

#include <cglm/cglm.h>
#include <utils/shader/shader.h>
#include <utils/texture/texture.h>
#include <utils/board/board.h>

#include "../VAO.h"
#include "../VBO.h"
#include "../EBO.h"


void Renderer_FillRect(float height, float width,struct Shader shader,struct piece* piece,
                       unsigned int VAO, unsigned int VBO, unsigned int EBO);

void Renderer_FillBackground(float height, float width,struct Shader shader, struct Texture self,
                       unsigned int VAO, unsigned int VBO, unsigned int EBO);
