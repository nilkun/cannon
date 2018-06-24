#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include "eventHandler.h"
#include "../gameEngine/creatorTools/CreatorTools.h"
#include "../gameEngine/fileManager/fileManager.h"
#include "../gameEngine/window/window.h"
#include "../gameEngine/collisionDetection/collisionDetection.h"
#include "player.h"


int main() {

  Screen screen("Cannon Defender", 1024, 768);
  screen.init();
  SDL_Renderer *renderer;
  renderer = screen.getRenderer();

  // Load some stuff
  TextureCreator images;
  FontAtlas bitfont;
  EventHandler events;
  Player player;
  bool running = true;

  player.setTexture(images.fromImage(renderer, "resources/soldier.png"));
  player.init();
  bitfont = images.create8bitAtlas(renderer);

// DEBUG
  SDL_Rect debugViewport = { 800, 0, 224, 768 };

  while(running)
  {
    switch(events.processEvents())
    {
			case QUIT:
			{
				running = false;
				break;
			}
      case UP:
			{
        running = false;
        break;
			}
      case BACKSPACE:
      {
        break;
      }
      case F1:
      {
        break;
      }
      case F2:
      {
        break;
      }
      case CLICKED_LEFT:
      {
        player.isMoving = true;
        player.target = { events.mouse.x, events.mouse.y };
        player.getPath();
        break;
      }
      case CLICKED_RIGHT:
      {
        break;
      }
      case TEXTINPUT:
      {
        break;
      }
      default:
        //ignore
      break;
    }

    player.update();
// RENDER TILES
    SDL_SetRenderDrawColor(renderer, 255, 255, 255, 0);
    SDL_RenderClear(renderer);

// DEBUG WINDOW
    SDL_RenderSetViewport(renderer, &debugViewport);
    SDL_SetRenderDrawColor(renderer, 255, 0, 0, 0);
    images.setColor(255, 0, 0, 0);
    images.showMessage(renderer, "DEBUG WINDOW", &bitfont, 10, 10);

    images.showMessage(renderer, std::to_string(player.steps), &bitfont, 20, 10);
    SDL_RenderSetViewport(renderer, NULL);
    player.render(renderer);

    SDL_RenderPresent(renderer);
  }



  return 1;
}
