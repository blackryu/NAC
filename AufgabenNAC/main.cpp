//#include "Matrix.h"
//#include "Vector.h"
#include "Vector2D.h"
#include <iostream>

int main() {
	{
		Matrix m(8,2);
		m.ausgabe();
		std::cout << std::endl;
		Vector v(3);
		v.ausgabe();
		std::cout << std::endl;

		// *Testprogramm zu Vector2D*

		Vector2D a(3, 1), b(1, 2), c;
		a.ausgabe();
		b.ausgabe();
		c.ausgabe();
		//addiere Vector a zu c (c aendert sich)
		c.addiere(a);
		//addiere Vector c zu b (b aendert sich)
		b.addiere(c);
		//Betrag der Summe ausgeben
		b.betrag();

		//aufgabenblatt Nr3
		//Nr 2, objekte auf dem heap anlegen
		Vector2D *z = new Vector2D(-3, 1);
		Vector2D *w = new Vector2D();

		//Heap-vektor z zu stack-vektor a addieren
		a.addiere(*z);
		a.ausgabe();
		std::cout << std::endl;
		std::cout << std::endl;

		//Heap-vektor z zu heap-vektor w addieren
		w->addiere(*z);

		//Stack-Vektor b zu heap-vektor w addieren
		w->addiere(b);
		w->ausgabe();
		std::cout << std::endl;
		std::cout << std::endl;

		Vector2D u(1, 2);
		w->kopiereIn(u);
		//w sollte 1,2 liefern
		w->ausgabe();
		std::cout << std::endl;
		std::cout << std::endl;

		a.kopiereIn(u);
		//a sollte 1,2 liefern
		std::cout << "vector a ist : ";
		a.ausgabe();

		std::cout << std::endl;
		std::cout << std::endl;

		tausche(a, *z);
		//a und z tauschen
		std::cout << "getauschtes a ist : ";
		a.ausgabe();
		std::cout << std::endl;
		std::cout << std::endl;

		std::cout << "getauschtes z ist : ";
		z->ausgabe();
		std::cout << std::endl;
		std::cout << std::endl;

		a.betrag();
		std::cout << std::endl;
		b.betrag();
		std::cout << std::endl;
		c.betrag();
		std::cout << std::endl;
		u.betrag();
		std::cout << std::endl;
		w->betrag();
		std::cout << std::endl;
		z->betrag();
		//Speicher von den Heap-Objekten wieder frei geben
		delete w;
		delete z;

		//winkel test
		Vector2D t1(1,1), t2(-5,0);

		//winkel zwischen t1 und t2
		std::cout << "Der winkel ist: " << t1.winkel(t2) << std::endl;

		//Aufgaben Blatt 5
		//normales VectorArray mit laengen angabe
		Vector2D* vecArrMitLaenge[3];

		//dynamisches Array mit 2 Vectoren
		Vector2D* varr[] = {new Vector2D(2,3), new Vector2D (-2,1)};

		//testen ob array richtig angelegt worden ist
		std::cout << "Ein Vector array mit folgenden vectoren wurde angelegt:" << std::endl;
		varr[0]->ausgabe();
		std::cout << std::endl;
		varr[1]->ausgabe();
		std::cout << std::endl;
		//2ten vector im array zum 1ten addieren
		varr[0]->addiere(*varr[1]);
		std::cout << "el2 wurde zu el1 hinzuaddiert" << std::endl;
		varr[0]->ausgabe();

		//array wieder frei geben
		for(int i = 0; i< 2; i++){
			delete varr[i];
		}
	}
	Matrix m(3,4);
	std::cout << m.getCounter();
}

int myMain() {
	{
		Vector2D v(1, 2), w(3, 4);
		Matrix M(2,3);
		Matrix* Mpointer;

		M = v;
		Mpointer = &v;

		std::cout << "Ausgabe von M und mit Mpointer" << std::endl;
		M.ausgabe();
		std::cout << std::endl;
		Mpointer->ausgabe();

		v.addiere(w);
		std::cout << "Ausgabe von v nach Addieren" << std::endl;
		v.ausgabe();

		std::cout << "Ausgabe von M/Mpointer nach Add" << std::endl;
		M.ausgabe();
		std::cout << std::endl;
		Mpointer->ausgabe();
		return 0;
	}

}

