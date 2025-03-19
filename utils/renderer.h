#pragma once


#include <glad/glad.h>
#include <cglm/cglm.h>
#include <shader.h>
#include <texture.h>
#include <general.h>

struct Rect {
  int x,y;
  float height,width;
  struct Texture texture;
};

struct Rect Renderer_FillRect(int x, int y,float height, float width,struct Shader shader, struct Texture texture,
                       unsigned int VAO, unsigned int VBO, unsigned int EBO)
{
  struct Texture self = texture;
  struct Rect R_self;

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
  float RectVertices[] = {
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
  BufferVBO(sizeof(RectVertices), RectVertices);

  BindEBO(EBO);
  BufferEBO(sizeof(indices), indices);

  // draw call
  glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);

  // reset the model matrix
  glm_mat4_identity(model); // Reset the model matrix
  Shader_SetMat4(shader, "model", model);
  return R_self;
};

void Renderer_FillBackground(float height, float width,struct Shader shader, struct Texture self,
                             unsigned int VAO, unsigned int VBO, unsigned int EBO)
{
  float x = 320;
  float y = 240;
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
  float RectVertices[] = {
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
    BindEBO(EBO);
    BufferEBO(sizeof(indices), indices);

    // draw call
    glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);

    // reset the model matrix
    glm_mat4_identity(model); // Reset the model matrix
    Shader_SetMat4(shader, "model", model);
};

