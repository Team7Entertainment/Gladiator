#include <SDL.h>
#include <SDL_image.h>
#include <string>

class Texture {
	public:
		Texture();
		~Texture();

		void setRenderer(SDL_Renderer* renderObj);
		void loadFromFile(std::string path);
		void setColor(Uint8 r, Uint8 b, Uint8 g);
		void render(int x, int y, SDL_Rect* clip = NULL, double angle = 0.0, SDL_Point* center = NULL, SDL_RendererFlip flip = SDL_FLIP_NONE);

		int getWidth();
		int getHeight();

	private:
		SDL_Texture* tex;
		SDL_Renderer* renderer;
		int width;
		int height;
};