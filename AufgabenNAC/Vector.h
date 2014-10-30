#include "Matrix.h"

class Vector : public Matrix {
	public:
		Vector(int);
		virtual ~Vector();
		float skalarprodukt(Vector&);
		float betrag();
		float winkel(Vector&);
};
