#include "../include/graphics_manager.hpp"

GraphicsManager::GraphicsManager()
{
  // Initialize glew
  glewExperimental = GL_TRUE;
  GLenum status = glewInit();

  // Set window close variable so that window stays open
  if(status != GLEW_OK)
  {
    std::cout << "ERROR INITIALIZING GLEW!" << std::endl;
    std::exit(EXIT_FAILURE);
  }
}

void GraphicsManager::ClearScreen()
{
  static float x = 0.0f;
  static bool flag = true;
  //glClearColor(0.1f, 0.3f, 0.5f, 1.0f);
  glClearColor(x, 0.3f, 0.5f, 1.0f);
  glClear( GL_COLOR_BUFFER_BIT );
  glClear( GL_DEPTH_BUFFER_BIT );

  if(flag)
  {
    x += 0.02f;
    if(x >= 0.98f)
    {
      flag = false;
    }
  }
  else
  {
    x -= 0.02f;
    if(x <= 0.02f)
    {
      flag = true;
    }
  }
}

GraphicsManager::~GraphicsManager()
{

}
