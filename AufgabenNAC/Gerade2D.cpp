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

const float Gerade2D::gerichteterAbstand(Vector2D x) const
{
  Vector2D diff(x);
  diff.subtrahieren(m_Aufpunkt);
  //diff.subtrahieren(&m_Aufpunkt);
  return m_Normale.skalarprodukt(diff) / m_Normale.betrag();
}

bool Gerade2D::aufGerade(Vector2D &x){
	if(fabs(this->gerichteterAbstand(x)) == 0){
		return true;
	} else {
		return false;
	}
}

void Gerade2D::normale(Vector2D normale){
	this->m_Normale = normale;
}

void Gerade2D::aufpunkt(Vector2D aufpunkt){
	this->m_Aufpunkt = aufpunkt;
}

Vector2D Gerade2D::normale(){
	return this->m_Normale;
}

Vector2D Gerade2D::aufpunkt(){
	return this->m_Aufpunkt;
}

