#ifndef MATRIZ_H
#define MATRIZ_H
#include "Object.h"

class Matriz : public Object{
	public: 
		Matriz(char,int,int**);
		int** getMatriz();
		char getChar();
		int getTam();
		
	protected:
		int tam;
		char nombre;
		int** matriz;
};

#endif
