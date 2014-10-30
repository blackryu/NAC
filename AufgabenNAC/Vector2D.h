#include "Vector.h"

#ifndef VECTOR2D_H_
#define VECTOR2D_H_

class Vector2D : public Vector {
public:
	Vector2D();
	Vector2D(float, float);
	~Vector2D();
	void addiere(Vector2D&);
	void kopiereIn(Vector2D&);
	void ausgabe();
};

void tausche(Vector2D& ,Vector2D&);

#endif /* VECTOR2D_H_ */
