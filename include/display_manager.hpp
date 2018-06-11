#ifndef INCLUDED_DISPLAY_MANAGER_H
#define INCLUDED_DISPLAY_MANAGER_H

#include <iostream>
#include <SDL2/SDL.h>

class DisplayManager
{
public:
  DisplayManager();

  bool Closed();
  inline float ElapsedTime() {return m_elapsedTime;}
  void SwapBuffers();
  void ProcessTime();

  ~DisplayManager();
protected:
private:
  SDL_Window* m_window;
  SDL_GLContext m_glContext;
  bool m_closed;
  float m_elapsedTime;
  float m_oldTime;
  float m_totalTime;
  int m_fps;
  int m_frameCount;
};

#endif
