#ifndef __PLAYER_H__
#define __PLAYER_H__

#include <SDL2/SDL.h>
#include <list>

class Player {
public:
  SDL_Point target;
  SDL_Rect position;
  bool isMoving;
  SDL_Texture* texture;
  void setTexture(SDL_Texture* texture);
  int ammo;
  int walkingSpeed;
  void render(SDL_Renderer* renderer);
  void init();
  void update();
  float pos_x;
  float pos_y;
  float velocity_x;
  float velocity_y;
  void getPath();
  int speed;
  struct Bullet {
    SDL_Rect position;
  };
  std::list<Bullet> bullets;
  int steps;
};
#endif
