#ifndef RECTANGLE_H
#define RECTANGLE_H

#include <glm/glm.hpp>

#include "Color.h"
#include "GameRenderer.h"

class Rectangle
{
	public:
		Rectangle (void);
		~Rectangle (void);
		
		void setPosition (int x, int y); // position
		void setPositionX (int x);
		void setPositionY (int y);

		glm::ivec2 getPosition (void) const;
		int getPositionX (void) const;
		int getPositionY (void) const;

		void setSize (int w, int h); // size
		void setWidth (int w);
		void setHeight (int h);

		glm::ivec2 getSize (void) const;
		int getWidth (void) const;
		int getHeight (void) const;
		
		void setColor (Color color); // color
		Color getColor (void) const;

		void draw (void);

	private:
		glm::ivec2 position_;
		int width_;
		int height_;
		Color color_;
};

#endif
