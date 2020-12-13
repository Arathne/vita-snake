#ifndef TEXT_H
#define TEXT_H

#include <string>
#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>
#include <glm/glm.hpp>

#include "GameRenderer.h"

class Text
{
	public:
		Text (void);
		Text (const char* content, const char* path, int fontSize, SDL_Renderer & renderer);
		Text (int x, int y, const char* content, const char* path, int fontSize, SDL_Renderer & renderer);
		Text (const Text & rhs);
		~Text (void);
		
		void draw (void);

		void setContent (const char* content);
		void setContent (int number);
		void setPosition (int x, int y);
		void setPositionX (int x);
		void setPositionY (int y);
		void setFont (const char* path, int fontSize);
		void setRenderer (SDL_Renderer & renderer);

		const char* getContent (void) const;
		glm::vec2 getPosition (void) const;
		SDL_Texture & getTexture (void) const;
		int getPositionX (void);
		int getPositionY (void);
		int getWidth (void);
		int getHeight (void);

		const Text & operator = (const Text & rhs);

	private:
		void updateTexture (void);
		
		const char* content_;
		const char* path_;
		int fontSize_;
		
		glm::vec2 position_;
		int width_;
		int height_;
		
		TTF_Font* font_;
		SDL_Texture* texture_;
		SDL_Renderer* renderer_;
};

#endif
