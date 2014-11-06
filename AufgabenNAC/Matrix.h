class Matrix {
	static int m_counter;
protected:
	int m_Zeilen;
	int m_Spalten;
	float * m_Element;
public:
	Matrix(int, int);
	int getCounter();
	virtual ~Matrix(void);
	virtual void ausgabe();
};
