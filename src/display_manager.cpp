#include "../include/display_manager.hpp"

DisplayManager::DisplayManager()
{
  // Initialize sdl
  if(SDL_Init(SDL_INIT_EVERYTHING) != 0)
  {
    std::cout << "ERROR INITIALIZING SDL2!" << std::endl;
    std::exit(EXIT_FAILURE);
  }

  // These attributes define window specifications for OpenGL
  SDL_GL_SetAttribute(SDL_GL_RED_SIZE, 8);
  SDL_GL_SetAttribute(SDL_GL_GREEN_SIZE, 8);
  SDL_GL_SetAttribute(SDL_GL_BLUE_SIZE, 8);
  SDL_GL_SetAttribute(SDL_GL_ALPHA_SIZE, 8);
  SDL_GL_SetAttribute(SDL_GL_BUFFER_SIZE, 32);
  SDL_GL_SetAttribute(SDL_GL_DEPTH_SIZE, 16);
  SDL_GL_SetAttribute(SDL_GL_DOUBLEBUFFER, 1);

  // Initialize the window and OpenGL context
  m_window = SDL_CreateWindow("video", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 640, 480, SDL_WINDOW_OPENGL);
  m_glContext = SDL_GL_CreateContext(this->m_window);

  // Initialize time-based valriables
  m_oldTime = (double)SDL_GetTicks()/1000.0;
  m_totalTime = 0.0;
  m_fps = 0;
  m_frameCount = 0;
}

bool DisplayManager::Closed()
{
  SDL_Event event;
  while( SDL_PollEvent(&event) )
  {
      switch (event.type)
      {
        case SDL_QUIT:
          return true;
          break;
      }
  }
  return false;
}

void DisplayManager::SwapBuffers()
{
  SDL_GL_SwapWindow(this->m_window);
}

void DisplayManager::ProcessTime()
{
  float currentTime = (double)SDL_GetTicks()/1000.0;
  m_elapsedTime = currentTime - m_oldTime;
  m_oldTime = currentTime;

  m_totalTime += m_elapsedTime;
  if(m_totalTime >= 1.0)
  {
    m_fps = m_frameCount;
    m_frameCount = 0;
    m_totalTime--;
  }
  m_frameCount++;
}

DisplayManager::~DisplayManager()
{
  SDL_DestroyWindow(m_window);
}
