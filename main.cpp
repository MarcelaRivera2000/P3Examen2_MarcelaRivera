#include <iostream>
#include <vector>
#include <string>
#include <cmath>

#include "Object.h"
#include "Operador.h"
#include "Matriz.h"

using namespace std; 
using std::cin;
using std::endl;
using std::cout;

vector<Object*> lista;

int main(int argc, char** argv) {
	string comando;
	int op=0;
	cout<<"------------ COMANDOS ------------"<<endl<<"~ Salir"<<endl<<"~ Imprimir"<<endl<<"~ Ejm: A=[1,2,3,4]"<<endl<<"~ Ejm: A+B+C"<<endl<<"----------------------------------"<<endl;
	while(true){
		cout<<">>";
		cin>>comando;
		if (comando == "Salir"){
			exit (EXIT_FAILURE);
		}else if ((comando == "+"||comando == "-"||comando == "*") && comando.size()<=1){
			lista.push_back(new Operador(comando[0]));
			cout<<"Operador creado..."<<endl;
			
		}else if (comando == "Imprimir"){
				for (int i=0;i<lista.size();i++){
				cout<<lista[i]->getChar()<<":"<<endl;
				
				if(dynamic_cast<Matriz*>(lista[i])){
					Matriz* auxx =dynamic_cast<Matriz*>(lista[i]);
					for(int j=0;j<auxx->getTam();j++){
					cout<<"| ";
					for(int k=0;k<auxx->getTam();k++){
						cout<< auxx->getMatriz()[j][k];
					}
					cout<<" |";
					}			
				}
			}	
		}
		
		for(int i=0;i<comando.size();i++){
			if(comando[i] == '+'||comando[i] == '-'||comando[i] == '*'){
				op=1;
				break;
			}
		}
		if(op==0){
			int tam,cont=0;
			int*** matriz;
			char nombre=comando[0];
			for(int i=1;i<comando.size();i++){
				if(comando[i]=='='||comando[i]=='['||comando[i]==','||comando[i]==']'){
					i++;
				}else{
					cont++;
				}
			}
			tam=sqrt(cont);	
			matriz = new int**[tam];			
			for(int i=0; i<tam;i++){
				matriz[i]=new int*[tam];
				for(int j=0; j<tam;j++){
					matriz[i][j]=NULL;
				}
			}
			
			/*int aux1=0;
			for(int i=0;i<tam;i++){
				for(int j=0;j<tam;j++){
					if(aux1!=0 && (comando[aux1]!='='||comando[aux1]!='['||comando[aux1]!=','||comando[aux1]!=']')){
						matriz[i][j]=new int((int)comando[aux1]);
						cout<<"hola"<<endl;
					}
					aux1++;
				}	
			}
			cout<<"matriz: "<<endl;
			for(int i=0;i<tam;i++){
				for(int j=0;j<tam;j++){
					cout<<matriz[i][j];
				}	
			cout<<endl;
			}
				*/
			cout<<"Matriz creada..."<<endl;
		}else{
		
			cout<<"Operacion terminada..."<<endl;
		}
		
	}
	return 0;					
	}		
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
				
			/*Multi de matrices 
			
			
			public int[][] Multiplicacion(int MATRIZ[][], int MATRIZ2[][]) {// inicio del metodo
        int M3[][] = new int[MATRIZ.length][MATRIZ2[0].length];
        for (int i = 0; i < MATRIZ.length; i++) {// for controla las filas de la matriz 1
            for (int j = 0; j < MATRIZ2[0].length; j++) {// controla las columnas de la matriz 2
                for (int k = 0; k < MATRIZ2.length; k++) {// controla las filas de la matriz 2
                    M3[i][j] += MATRIZ[i][k] * MATRIZ2[k][j];// se hace la respectiva multiplicacion
                }// fin del 3er for
            }// fin del 2do for
        }// fin del 1er for

        return M3;
    }// fin del metodo*/
				
				
				
				
				
				
				
		
		
		


