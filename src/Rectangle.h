#ifndef RECTANGLE_H
#define RECTANGLE_H

#include <glm/glm.hpp>

#include "Color.h"
#include "GameRenderer.h"

class Rectangle
{
	public:
		Rectangle (void);
		Rectangle (float x, float y, int w, int h);
		Rectangle (const Rectangle & rhs);
		~Rectangle (void);
		
		void setPosition (float x, float y); // position
		void setPositionX (float x);
		void setPositionY (float y);

		glm::vec2 getPosition (void) const;
		float getPositionX (void) const;
		float getPositionY (void) const;
		
		void addPositionX (float x);
		void addPositionY (float y);

		void move (float x, float y); // movement
		void moveX (float x);
		void moveY (float y);

		void setSize (int w, int h); // size
		void setWidth (int w);
		void setHeight (int h);
		
		void addWidth (int w);
		void addHeight (int h);

		glm::vec2 getSize (void) const;
		int getWidth (void) const;
		int getHeight (void) const;
		
		void setColor (Color color); // color
		Color getColor (void) const;

		void draw (void);
		
		const Rectangle & operator = (const Rectangle & rhs);

	private:
		glm::vec2 position_;
		int width_;
		int height_;
		Color color_;
};

#endif
