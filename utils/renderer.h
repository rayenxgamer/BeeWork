#pragma once

#include <glad/glad.h>
#include <cglm/cglm.h>
#include <shader.h>
#include <stdint.h>
#include <texture.h>
#include <window.h>
#include <general.h>

typedef uint8_t BColor;


typedef struct {
  int x,y;
  float height,width;
  struct Texture texture;
} Rect;

typedef struct {
  float r;
  float b;
  float g;
  float a;
} Color;

typedef struct {
  Rect* rect;
  Color* color;
  struct Shader* shaders;
  uint* VAOs,VBOs,EBOs;
  int count;
} RenderBatch;

#define BEE_WHITE struct Color white = {1.0,1.0,1.0,1.0}
#define BEE_BLACK struct Color black = {0.0,0.0,0.0,1.0}
#define BEE_RED   struct Color red   = {1.0,0.0,0.0,1.0}
#define BEE_GREEN struct Color green = {0.0,1.0,0.0,1.0}
#define BEE_BLUE  struct Color blue  = {0.0,0.0,1.0,1.0}
#define BEE_ORANGE struct Color orange = {1.0,0.34,0.0,1.0}
#define BEE_PINK struct Color pink = {0.0,0.0,0.0,1.0}
#define BEE_YELLOW struct Color yellow = {1.0,1.0,0.0,1.0}
#define BEE_BROWN struct Color brown = {0.36,0.14,0.0,1.0}


void DrawBatch(RenderBatch* batch){
  for (int i = 0; i<batch->count; i++) {
    mat4 model;
    glm_mat4_identity(model);
    glm_translate_make(model,(vec3){batch->rect->x});
    Shader_SetMat4(*batch->shaders, "model", model);
    T_Bind(batch->rect->texture);
  }
}

void DrawRectangleTex(int x, int y,float height, float width,struct Shader shader, struct Texture texture,
                       unsigned int VAO, unsigned int VBO, unsigned int EBO)
{
  struct Texture self = texture;
  T_Bind(texture);

  Rect R_self;

  R_self.x = x;
  R_self.y = y;
  R_self.height = height;
  R_self.width = width;
  R_self.texture = texture;

  mat4 model;
  float uvX1 = 0.0f, uvX2 = 0.0f, uvY1 = 0.0f, uvY2 = 0.0f;
  glm_mat4_identity(model);
  glm_translate_make(model, (vec3){x,y,0});
  Shader_SetMat4(shader, "model", model);

  // checks if its an atlas then if it is then work out the uv's
  // otherwise use the whole texture
  if (self.isAtlas) {
    uvX1 = self.uvX / self.width;
    uvX2 = (self.uvX + self.GridSize) / self.width;
    uvY1 = self.uvY / self.height;
    uvY2 = (self.uvY + self.GridSize) / self.height;
  } else {
    uvX1 = 0.0f; uvX2 = 1.0f;
    uvY1 = 0.0f; uvY2 = 1.0f;
  }

  // Center the rectangle around (0, 0)
  float RectangleVertices[] = {
    -width / 2.0f,  height / 2.0f, 0.0f, uvX1, uvY1,  // top left
    -width / 2.0f, -height / 2.0f, 0.0f, uvX1, uvY2,  // bottom left
    width / 2.0f, -height / 2.0f, 0.0f, uvX2, uvY2,  // bottom right
    width / 2.0f,  height / 2.0f, 0.0f, uvX2, uvY1   // top right
  };

  unsigned int indices[] = {
    0, 1, 3,  // first triangle
    1, 2, 3   // second triangle
  };

  BindVAO(VAO);
  BindVBO(VBO);
  BufferVBO(sizeof(RectangleVertices), RectangleVertices);

  BindEBO(EBO);
  BufferEBO(sizeof(indices), indices);

  // draw call
  glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);

  // reset the model matrix
  glm_mat4_identity(model); // Reset the model matrix
  Shader_SetMat4(shader, "model", model);
};

void DrawRectangle(int x, int y,float height, float width, Color Color,
                       unsigned int VAO, unsigned int VBO, unsigned int EBO)
{
  struct Shader shader = BdefaultColorShader(shader);
  BindShader(shader);

  mat4 model;
  vec4 c = {Color.r, Color.g, Color.b, Color.a};
  glm_mat4_identity(model);
  glm_translate_make(model, (vec3){x,y,0});
  Shader_SetMat4(shader, "model", model);
  Shader_SetVec4(shader, "color", c);

  // Center the rectangle around (0, 0)
  float RectangleVertices[] = {
    -width / 2.0f,  height / 2.0f, 0.0f,  // top left
    -width / 2.0f, -height / 2.0f, 0.0f,  // bottom left
    width / 2.0f, -height / 2.0f, 0.0f,   // bottom right
    width / 2.0f,  height / 2.0f, 0.0f,   // top right
  };

  unsigned int indices[] = {
    0, 1, 3,  // first triangle
    1, 2, 3   // second triangle
  };

  BindVAO(VAO);
  BindVBO(VBO);
  BufferVBO(sizeof(RectangleVertices), RectangleVertices);

  BindEBO(EBO);
  BufferEBO(sizeof(indices), indices);

  // draw call
  glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);

  // reset the model matrix
  glm_mat4_identity(model); // Reset the model matrix
  Shader_SetMat4(shader, "model", model);
};

void Renderer_FillBackground(float height, float width,struct Shader shader, struct Texture self, struct window window,
                             unsigned int VAO, unsigned int VBO, unsigned int EBO)
{
  int x = window.height/2;
  int y = window.height/2;

  mat4 model;
  float uvX1 = 0.0f, uvX2 = 0.0f, uvY1 = 0.0f, uvY2 = 0.0f;
  glm_mat4_identity(model);
  glm_translate_make(model, (vec3){x,y,0});
  Shader_SetMat4(shader, "model", model);

    uvX1 = 0.0f; uvX2 = 1.0f;
    uvY1 = 0.0f; uvY2 = 1.0f;

  float RectVertices[] = {
    -width / 2.0f,  height / 2.0f, 0.0f, uvX1, uvY1,  // top left
    -width / 2.0f, -height / 2.0f, 0.0f, uvX1, uvY2,  // bottom left
    width / 2.0f, -height / 2.0f, 0.0f, uvX2, uvY2,  // bottom right
    width / 2.0f,  height / 2.0f, 0.0f, uvX2, uvY1   // top right
  };

  unsigned int indices[] = {
    0, 1, 3,
    1, 2, 3
  };

    BindVAO(VAO);
    BindVBO(VBO);
    BindEBO(EBO);
    BufferEBO(sizeof(indices), indices);

    // draw call
    glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);

    glm_mat4_identity(model); // Reset the model matrix
    Shader_SetMat4(shader, "model", model);
};

