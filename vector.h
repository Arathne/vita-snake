#ifndef VECTOR2D_H
#define VECTOR2D_H

class Vector2d
{
	public:
		int x;
		int y;
		
		Vector2d (void);
		Vector2d (int x, int y);
		Vector2d (const Vector2d & rhs);
			
		~Vector2d (void);

		const Vector2d & operator = (const Vector2d & rhs);
		const Vector2d & operator + (const Vector2d & rhs);
		const Vector2d & operator - (const Vector2d & rhs);
		const Vector2d & operator += (const Vector2d & rhs);
		const Vector2d & operator -= (const Vector2d & rhs);
};

#endif
