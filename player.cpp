#include "player.h"
#include <cmath>

void Player::setTexture(SDL_Texture* t)
{
  texture = t;
}
void Player::init()
{
  position = { 50, 50, 8, 16 };
  pos_x = position.x;
  pos_y = position.y;
  ammo = 100;
  isMoving = false;
  walkingSpeed = 5;
  speed = 5;
  float left;


}
void Player::render(SDL_Renderer* renderer)
{
  SDL_RenderCopy(renderer, texture, NULL, &position );
}
void Player::update()
{
  if(isMoving) {
    pos_x += velocity_x;
    pos_y += velocity_y;
    position.x = pos_x;
    position.y = pos_y;
    steps--;
    if(steps<=0)
    {
      isMoving = false;
    }
  //  if pos_x > distance.x && pos_y
  }
}

void Player::getPath() {
  float temp_x = target.x - pos_x;
  float temp_y = target.y - pos_y;

  float x_to_y_ratio = abs(temp_x / temp_y);
  // y + ratio;
  // velocity_x = temp_x / temp_y;
  // velocity_y = temp_y / temp_x;
  velocity_y = (speed / (x_to_y_ratio + 1));
  velocity_x = (x_to_y_ratio * velocity_y);
  if(temp_x < 0) velocity_x = -velocity_x;
  if(temp_y < 0)
  {
    velocity_y = -velocity_y;
  }
//  steps = abs(temp_x * velocity_x);
  steps = temp_x * velocity_x;
  if(steps < 1)
  {
    steps = temp_y * velocity_y;
  }

  // Simpler:
  //
}
