#ifndef ARCHIVO_H
#define ARCHIVO_H
#include "Object.h"
#include <string>
#include <string.h>
using std::string;
#include <fstream>
#include <vector>
using std::ofstream;


using namespace std;

class Archivo {
	public:
		void Escribir(vector <Object*>);
		vector<Object*> leer();
		
	protected:
		string fileName="Martices.txt";
		ofstream outputFile;
		ifstream archivo;
};

#endif
