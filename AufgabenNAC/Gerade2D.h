/*
 * Gerade2D.h
 *
 *  Created on: 06.11.2014
 *      Author: c.hamilton
 */

#ifndef __Gerade2D_h__
#define __Gerade2D_h__

#include "Vector2D.h"

class Gerade2D {
	Vector2D m_Normale;
	Vector2D m_Aufpunkt;
public:
	Gerade2D(Vector2D normale, Vector2D *aufpunkt = new Vector2D(0,0));
	void normale(Vector2D);
	void aufpunkt(Vector2D);
	Vector2D normale();
	Vector2D aufpunkt();
	bool aufGerade(Vector2D&);
	virtual ~Gerade2D(void);
	const float gerichteterAbstand(Vector2D v) const;
};

#endif // __Gerade2D_h__
