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

Texture::Texture() {
	tex = NULL;
	width = 0;
	height = 0;
}

Texture::~Texture() {
	if (tex != NULL) {
		SDL_DestroyTexture(tex);
		tex = NULL;
		width = 0;
		height = 0;
	}
}

void Texture::setRenderer(SDL_Renderer* renderObj) {
	renderer = renderObj;
}

void Texture::loadFromFile(std::string path) {
	tex = NULL;

	SDL_Texture* newTexture = NULL;

	//Load image at specified path
	SDL_Surface* loadedSurface = IMG_Load(path.c_str());

	//Color key image
	SDL_SetColorKey(loadedSurface, SDL_TRUE, SDL_MapRGB(loadedSurface->format, 0, 0xFF, 0xFF));

	//Create texture from surface pixels
	newTexture = SDL_CreateTextureFromSurface(renderer, loadedSurface);

	//Get image dimensions
	width = loadedSurface->w;
	height = loadedSurface->h;

	//Get rid of old loaded surface
	SDL_FreeSurface(loadedSurface);

	//Return success
	tex = newTexture;
}

void Texture::setColor(Uint8 r, Uint8 b, Uint8 g) {
	SDL_SetTextureColorMod(tex, r, g, b);
}

void Texture::render(int x, int y, SDL_Rect* clip, double angle, SDL_Point* center, SDL_RendererFlip flip) {
	//Set rendering space and render to screen
	SDL_Rect renderQuad = { x, y, width, height };

	//Set clip rendering dimensions
	if (clip != NULL)
	{
		renderQuad.w = clip->w;
		renderQuad.h = clip->h;
	}

	//Render to screen
	SDL_RenderCopyEx(renderer, tex, clip, &renderQuad, angle, center, flip);
	printf("%d %s\n", tex, SDL_GetError());
}