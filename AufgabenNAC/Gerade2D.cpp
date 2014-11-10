/*
 * Gerade2D.cpp
 *
 *  Created on: 06.11.2014
 *      Author: c.hamilton
 */

#include "Gerade2D.h"
#include <math.h>

Gerade2D::Gerade2D(Vector2D normale, Vector2D *aufpunkt) : m_Normale(normale), m_Aufpunkt(*aufpunkt)
{
}

Gerade2D::~Gerade2D(void)
{
}

float Gerade2D::gerichteterAbstand(Vector2D x) const
{
  Vector2D diff(x);
  diff.subtrahieren(m_Aufpunkt);
  //diff.subtrahieren(&m_Aufpunkt);
  return m_Normale.skalarprodukt(diff) / m_Normale.betrag();
}

bool Gerade2D::aufGerade(Vector2D x) const{
	if(fabs(this->gerichteterAbstand(x)) == 0){
		return true;
	} else {
		return false;
	}
}

void Gerade2D::normale(Vector2D normale){
	m_Normale = normale;
}

void Gerade2D::aufpunkt(Vector2D aufpunkt){
	m_Aufpunkt = aufpunkt;
}

const Vector2D Gerade2D::normale() const{
	return m_Normale;
}

const Vector2D Gerade2D::aufpunkt() const{
	return m_Aufpunkt;
}

