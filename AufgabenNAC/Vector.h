#include "Matrix.h"

class Vector: public Matrix {
public:
	Vector(int);
	virtual ~Vector(void);
	void subtrahieren(Vector);
	const float skalarprodukt(Vector) const;
	const float betrag() const;
	float winkel(Vector) const;
};
