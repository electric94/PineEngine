/*
 * CoreEngine.hpp
 * PineEngine
 *
 * Created by Matthew Segraves on 6/6/18
 * Copyright © 2018 MJS. All rights reserved.
 *
 */

#ifndef INCLUDED_COREENGINE_H
#define INCLUDED_COREENGINE_H

#include "display_manager.hpp"
#include "graphics_manager.hpp"

class CoreEngine
{
public:
  CoreEngine();

  void Run();
  void Input();
  void Update();
  void Render();

  ~CoreEngine();
protected:
private:
  DisplayManager m_displayManager;
  GraphicsManager m_graphicsManager;
};

#endif
