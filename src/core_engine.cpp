#include "../include/core_engine.hpp"

CoreEngine::CoreEngine()
{

}

void CoreEngine::Run()
{
  while(!m_displayManager.Closed())
  {
    Input();
    Update();
    Render();
  }
}

void CoreEngine::Input()
{
  m_displayManager.ProcessTime();
}

void CoreEngine::Update()
{

}

void CoreEngine::Render()
{
  m_graphicsManager.ClearScreen();
  m_displayManager.SwapBuffers();
}

CoreEngine::~CoreEngine()
{

}
