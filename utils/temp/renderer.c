#include "renderer.h"
#include "utils/shader/shader.h"
#include "utils/board/board.h"
#include "utils/texture/texture.h"

// fill the rectangle that was created by using InitRect,
// will automatically get assigned the position of the passed body (messy asf)
    BufferVBO(sizeof(RectVertices), RectVertices);

void Renderer_FillRect(float height, float width,struct Shader shader,struct piece* piece,
                       unsigned int VAO, unsigned int VBO, unsigned int EBO)
{
  struct Texture self = piece->texture;
  mat4 model;
  float uvX1 = 0.0f, uvX2 = 0.0f, uvY1 = 0.0f, uvY2 = 0.0f;
  glm_mat4_identity(model);
  glm_translate_make(model, (vec3){piece->x,piece->y,0});
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
