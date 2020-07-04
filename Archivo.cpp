#include "Archivo.h"
#include <iostream>
#include "Matriz.h"
using namespace std; 
using std::cout;


//Metodo de escritura en archivo de texto
void Archivo::Escribir(vector <Object*> M){
	outputFile.open(fileName, ios::out);
	if(outputFile.fail()){
		cout<<"No se pudo abrir el archivo...";
		exit(1);
	}
	for(int i=0;i<M.size();i++){
		
		if(dynamic_cast<Matriz*>(M[i])){
				Matriz* auxx =dynamic_cast<Matriz*>(M[i]);
				outputFile <<auxx->getChar()<<","<<auxx->getTam()<<","<<"{";
				for(int v=0;v<auxx->getTam();v++){
					for(int j=0;j<auxx->getTam();j++){
						outputFile << "["<<auxx->getMatriz()[v][j]<<"]";
					}
					if(v!=auxx->getTam()-1){
					outputFile <<",";	
					}else{
							outputFile <<"}";	
					}
					
				}
							
		}else{
			outputFile <<M[i]->getChar()<<";";	
		}
		
		
		   	
	}      
	outputFile.close();
}

//Metodo de lectura en archivo de texto
vector<Object*> Archivo::leer(){
	archivo.open(fileName,ios::in);
	if(archivo.fail()){
	cout<<"No se pudo abrir el archivo...";
	exit(1);
	}
	vector<Matriz*> aux;
	while(!archivo.eof()){
		string text;
		int tama;
		int** matriz;
		
		getline(archivo,text);
		
		//aux.push_back(text);
	}
	archivo.close();
//	return aux;
}




