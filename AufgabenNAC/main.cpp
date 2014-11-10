//#include "Matrix.h"
//#include "Vector.h"
//#include "Vector2D.h"
#include "Gerade2D.h"
//#include "Vector2D.h"
#include <iostream>
#include <math.h>



static void falsch()
{
  std::cout << "falsch" << std::endl;
}

#define TEST(bedingung)                   \
  if(bedingung)                           \
    std::cout << "richtig" << std::endl;  \
  else                                    \
    falsch();

void geradenTest(const Gerade2D& g)
{
  Vector2D v(6,0);
  TEST(g.aufGerade(v) == true);

  TEST(fabs(g.gerichteterAbstand(Vector2D(9,4)) - (-5)) < 0.0001);

  TEST(fabs(g.normale().winkel(Vector2D(1,-7)) - 45) < 0.0001);

  Gerade2D g2(Vector2D(7,7));
  g2.normale(g.normale());
  TEST(fabs(g2.normale().betrag() - 5) < 0.0001);

  TEST(g2.aufGerade(g.aufpunkt()) == false);
}





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

		std::cout << "coutner : " << m.getCounter() << std::endl;

		//aufgabenblatt Nr3
		//Nr 2, objekte auf dem heap anlegen
		Vector2D *z = new Vector2D(-3, 1);
		Vector2D *w = new Vector2D();

		std::cout << "coutner : " << m.getCounter() << std::endl;

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

		std::cout << "coutner : " << m.getCounter() << std::endl;

		std::cout << std::endl;
		std::cout << std::endl;

		std::cout << "a.betrag() : " << a.betrag() << std::endl;
		std::cout << "b.betrag() : " << b.betrag() << std::endl;
		std::cout << "c.betrag() : " << c.betrag() << std::endl;
		std::cout << "u.betrag() : " << u.betrag() << std::endl;

		std::cout << std::endl;
		std::cout << std::endl;

		std::cout << "coutner : " << m.getCounter() << std::endl;

		std::cout << std::endl;
		std::cout << std::endl;

		std::cout << "w->betrag() : " << w->betrag() << std::endl;
		std::cout << "z->betrag() : " << z->betrag() << std::endl;

		std::cout << std::endl;
		std::cout << std::endl;

		std::cout << "coutner : " << m.getCounter() << std::endl;

		std::cout << std::endl;
		std::cout << std::endl;

		//Speicher von den Heap-Objekten wieder frei geben
		delete w;
		delete z;

		std::cout << "coutner : " << m.getCounter() << std::endl;

		//winkel test
		Vector2D t1(1,1), t2(-5,0);
		std::cout << "still working" <<std::endl;

		std::cout << "t1.betrag() : " << t1.betrag() << std::endl;
		std::cout << "t2.betrag() : " << t2.betrag() << std::endl;

		//=======DOENST WORK ANYMORE==============

		//winkel zwischen t1 und t2
		std::cout << "Der winkel ist: " << t1.winkel(t2) << std::endl;

		//Aufgaben Blatt 5
		//normales VectorArray mit laengen angabe
		//Vector2D* vecArrMitLaenge[3];

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

		Gerade2D g(Vector2D(-3,-4));

		std::cout << "gerichteter abstand ist" << g.gerichteterAbstand(Vector2D(4,3)) << std::endl;

		Vector2D h(4,-3);
		std::cout << g.aufGerade(h) << std::endl;



		g.aufpunkt(h);
		g.normale(h);


		geradenTest(g);

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

