#include "Text.h"

/* CONSTRUCTORS */

Text::Text (void):
	content_("-"),
	path_(""),
	fontSize_(0),
	position_(glm::vec2((int) 0, (int) 0)),
	font_(nullptr),
	texture_(nullptr),
	renderer_(nullptr)
{}

Text::Text (const char* content, const char* path, int fontSize, SDL_Renderer & renderer):
	content_(content),
	path_(path),
	fontSize_(fontSize),
	position_(glm::vec2((int) 0, (int) 0)),
	font_(TTF_OpenFont(path, fontSize)),
	texture_(nullptr),
	renderer_(&renderer)
{
	Text::updateTexture();
}

Text::Text (int x, int y, const char* content, const char* path, int fontSize, SDL_Renderer & renderer):
	content_(content),
	path_(path),
	fontSize_(fontSize),
	position_(glm::vec2((int) x, (int) y)),
	font_(TTF_OpenFont(path, fontSize)),
	texture_(nullptr),
	renderer_(&renderer)
{
	Text::updateTexture();
}

Text::~Text (void)
{
	if (font_ != nullptr)
		TTF_CloseFont(font_);
	
	if (texture_ != nullptr)
		SDL_DestroyTexture(texture_);
}

/* SETTERS */

void Text::setRenderer(SDL_Renderer & renderer)
{
	renderer_ = &renderer;
}

void Text::setContent (const char* content)
{
	content_ = content;
	Text::updateTexture();
}

void Text::setContent (int number)
{
	std::string s = std::to_string(number);
	content_ = s.c_str();
	Text::updateTexture();
}

void Text::setPosition (int x, int y)
{
	position_ = glm::vec2(x, y);
}

void Text::setPositionX (int x)
{
	position_.x = x;
}

void Text::setPositionY (int y)
{
	position_.y = y;
}

void Text::setFont (const char* path, int fontSize)
{
	if (font_ != nullptr)
		TTF_CloseFont(font_);
	
	path_ = path;
	fontSize_ = fontSize;

	font_ = TTF_OpenFont(path, fontSize);

	Text::updateTexture();
}


/* GETTERS */

const char* Text::getContent (void) const
{
	return content_;
}

glm::vec2 Text::getPosition (void) const
{
	return position_;
}

SDL_Texture & Text::getTexture (void) const
{
	return *texture_;
}

int Text::getPositionX (void)
{
	return position_.x;
}

int Text::getPositionY (void)
{
	return position_.y;
}

int Text::getWidth (void)
{
	return width_;
}

int Text::getHeight (void)
{
	return height_;
}

/* PRIVATE */

void Text::updateTexture (void)
{
	if (font_ != nullptr && renderer_ != nullptr)
	{
		if (texture_ != nullptr)
			SDL_DestroyTexture(texture_);
	
		SDL_Color white = {255, 255, 255};

		SDL_Surface* surface = TTF_RenderText_Solid(font_, content_, white);
		texture_ = SDL_CreateTextureFromSurface(renderer_, surface);
	
		width_ = surface -> w;
		height_ = surface -> h;

		SDL_FreeSurface(surface);
	}
}
