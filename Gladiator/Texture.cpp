#include "Texture.h"

Texture::Texture() {
	tex = nullptr;
	renderer = nullptr;
	width = 0;
	height = 0;
}

Texture::~Texture() {
	if (tex != nullptr) {
		SDL_DestroyTexture(tex);
		tex = nullptr;
		width = 0;
		height = 0;
	}
}

void Texture::setRenderer(SDL_Renderer* renderObj) {
	renderer = renderObj;
}

void Texture::loadFromFile(std::string path) {
	tex = nullptr;

	SDL_Texture* newTexture = nullptr;

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
	if (clip != nullptr) {
		renderQuad.w = clip->w;
		renderQuad.h = clip->h;
	}

	//Render to screen
	SDL_RenderCopyEx(renderer, tex, clip, &renderQuad, angle, center, flip);
	//printf("%s", SDL_GetError());
}
