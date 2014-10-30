#include "Vector2D.h"
#include <iostream>

using namespace std;

void tausche(Vector2D &a, Vector2D &b){
	Vector2D temp;
	temp.kopiereIn(a);
	a.kopiereIn(b);
	b.kopiereIn(temp);
}

Vector2D::Vector2D()
	:Vector(2){
	//cout << "Standardkonstruktor von Vector2D wurde aufgerufen" << endl;
}

Vector2D::Vector2D(float a, float b)
	:Vector(2){
	m_Element[0] = a;
	m_Element[1] = b;

}

Vector2D::~Vector2D(){
	//cout << "Vector2D ( ";
	//ausgabe();
	//cout << ") wird zerstoert" << endl;
}

void Vector2D::addiere(Vector2D &v){
	for(int i=0; i < m_Zeilen * m_Spalten; i++){
		m_Element[i] += v.m_Element[i];
	}
	//cout << "it works" << endl;
}

void Vector2D::kopiereIn(Vector2D &v){
	for(int i=0; i < m_Zeilen * m_Spalten; i++){
		m_Element[i] = v.m_Element[i];
	}
}

void Vector2D::ausgabe(){
	cout << "Vector2D: ";
	Matrix::ausgabe();
	cout << endl;
}
