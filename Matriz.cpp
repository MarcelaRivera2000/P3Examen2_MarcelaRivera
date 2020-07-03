#include "Matriz.h"

Matriz::Matriz(char nom,int tamo,int** mat){
	nombre=nom;
	tam=tamo;
	matriz=mat;
}

int** Matriz::getMatriz(){
	return matriz;
}

char Matriz::getChar(){
	return nombre;
}

int Matriz::getTam(){
	return tam;
}


