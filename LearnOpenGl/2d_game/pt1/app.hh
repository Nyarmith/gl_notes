#ifndef __APP_HH__
#define __APP_HH__

class GLTetris
{
public:
  GLTetris(int width, int height);
  ~GLTetris();

  enum State { MainMenu, Playing, GameOver};
  State GameState;
  bool Keys[1024];  // keys hit last frame
  void resize(int width, int height);

  // called each frame
  void Update(float dt);
  void Render();
};

#endif
