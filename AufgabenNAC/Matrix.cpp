#include <iostream>
#include "Matrix.h"

using namespace std;

int Matrix::m_counter;

//m = Spalten
//n = Zeilen
Matrix::Matrix(int m, int n)
	:m_Zeilen(n), m_Spalten(m){
	const int length = m_Zeilen * m_Spalten;
	m_Element = new float[length]();

	m_counter++;
	//cout << "Standardkonstruktor von Matrix wurde aufgerufen" << endl;
}

int Matrix::getCounter(){
	return m_counter;
}

Matrix::~Matrix(){
	m_counter--;
	delete [] m_Element;

	//cout << "Matrix( ";
	//ausgabe();
	//cout << ") wird zerstoert" << endl;
}

void Matrix::ausgabe(){
	for(int i=0; i <m_Zeilen * m_Spalten; i++){
		cout << m_Element[i] << " ";
	}
}
