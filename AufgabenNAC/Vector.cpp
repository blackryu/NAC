#include "Vector.h"
#include <iostream>
#include <math.h>
#include <limits>

const double PI  =3.141592653589793238463;

using namespace std;

// m = 1
// n = spalten
Vector::Vector(int n)
	:Matrix(1,n){

}

Vector::~Vector(){
	//cout << "Vector ( ";
	//ausgabe();
	//cout << ") wird zerstoert" << endl;
}

float Vector::skalarprodukt(Vector &v){
	int skalar = 0;
	if(m_Spalten != v.m_Spalten || m_Zeilen != v.m_Zeilen){
		return numeric_limits<float>::quiet_NaN();
	} else{
		for(int i=0; i < m_Spalten*m_Zeilen;i++){
			skalar += m_Element[i] * v.m_Element[i];
		}
	}
	return skalar;
}

//void Vector::betrag(){
//	float betrag = 0.0;
//	for(int i=0; i < m_Spalten*m_Zeilen;i++){
//		betrag += m_Element[i]*m_Element[i];
//	}
//	cout <<  "Der Betrag ist: " << sqrt(betrag) << endl;
//}

float Vector::betrag(){
	//float betrag = 0.0;
	return sqrt(skalarprodukt(*this));
	//cout << "Der Betrag ist: " << betrag << endl;
}

float Vector::winkel(Vector &v){
	if(m_Spalten != v.m_Spalten || m_Zeilen != v.m_Zeilen){
		return numeric_limits<float>::quiet_NaN();
	} else {
		return acos(skalarprodukt(v) / (betrag() * v.betrag())) * 180 / PI;
	}
}
