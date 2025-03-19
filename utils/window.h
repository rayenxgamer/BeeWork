#pragma once

#include <stdint.h>
#include <stdio.h>
#include <assert.h>
#include <glad/glad.h>
#include <SDL2/SDL.h>

typedef uint32_t u32;

struct window{
  int height;
  int width;
  const char* title;
  SDL_bool running;
  SDL_Window** window;
  SDL_GLContext context;
  u32 flags;
};

struct window Init_Window(struct window self){

  SDL_Init(SDL_INIT_VIDEO);
  SDL_GL_SetAttribute( SDL_GL_CONTEXT_MAJOR_VERSION, 3 );
  SDL_GL_SetAttribute( SDL_GL_CONTEXT_MINOR_VERSION, 3 );
  SDL_GL_SetAttribute( SDL_GL_CONTEXT_PROFILE_MASK, SDL_GL_CONTEXT_PROFILE_CORE);

  assert(SDL_Init(self.flags));
  *self.window = SDL_CreateWindow(self.title, SDL_WINDOWPOS_CENTERED,
                             SDL_WINDOWPOS_CENTERED ,self.width, self.height, self.flags);
  assert(self.window);
  SDL_GLContext context  = SDL_GL_CreateContext(*self.window);
  assert(context);
  SDL_GL_MakeCurrent(*self.window, context);

  if (SDL_GL_SetSwapInterval(1) < 0) {
    printf("Warning!: unable to set vsync, application will continue in unlimited fps mode\n");
  }

  if (!gladLoadGLLoader((GLADloadproc)SDL_GL_GetProcAddress)) {
      printf("Failed to initialize OpenGL context\n");
      exit(EXIT_FAILURE);
  }

  return self;
}

void Update_Window(struct window self){
  SDL_GL_SwapWindow(*self.window);
}

void Clear_Window(float red, float green, float blue, float alpha){
  glClear(GL_COLOR_BUFFER_BIT);
  glClearColor(red, green, blue, alpha);
}

void Shut_Window(struct window self){
  printf("Shutting down..\n");
  SDL_GL_DeleteContext(self.context);
  SDL_DestroyWindow(*self.window);
  SDL_Quit();
}
