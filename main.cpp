#include <iostream>
#include <vector>
#include <string>
#include <cmath>

#include "Object.h"
#include "Operador.h"
#include "Matriz.h"
#include "Archivo.h"

using namespace std; 
using std::cin;
using std::endl;
using std::cout;
Archivo arch;

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
				cout<<endl;
				for (int i=0;i<lista.size();i++){
				cout<<"Char "<<lista[i]->getChar()<<" :"<<endl;
				
				if(dynamic_cast<Matriz*>(lista[i])){
					Matriz* auxx =dynamic_cast<Matriz*>(lista[i]);
					for(int j=0;j<auxx->getTam();j++){
						for(int k=0;k<auxx->getTam();k++){
							cout<< " ["<<auxx->getMatriz()[j][k]<<"] ";
						}
					cout<<endl;
					}			
				}
			}	
			cout<<endl;
		}else{
		for(int i=0;i<comando.size();i++){
			if(comando[i] == '+'||comando[i] == '-'||comando[i] == '*'){
				op=1;
				break;
			}
		}
		if(op==0){
			int tam,cont=0;
			int** matriz;
			char nombre=comando[0];
			for(int i=1;i<comando.size();i++){
				if(comando[i]!='='&& comando[i]!='['&&comando[i]!=','&&comando[i]!=']'){
					cont++;
				}
			}
			tam=sqrt(cont);	
			matriz = new int*[tam];			
			for(int i=0; i<tam;i++){
				matriz[i]=new int[tam];
				for(int j=0; j<tam;j++){
					matriz[i][j]=NULL;
				}
			}
			
			string x=comando.substr(1,comando.size());
			cout<<"x: "<<x<<endl;
			int aux1=2;
			for(int i=0;i<tam;i++){
				for(int j=0;j<tam;j++){
					string numer="";
					numer+=x[aux1];
						matriz[i][j] = stoi(numer);	
					aux1+=2;
				}	
			}
			
			
			cout<<"matriz: "<<endl;
			for(int i=0;i<tam;i++){
				for(int j=0;j<tam;j++){
					cout<<" ["<<matriz[i][j]<<"] ";
				}	
			cout<<endl;
			}
			lista.push_back(new Matriz(nombre,tam,matriz));
			cout<<"Matriz creada..."<<endl;
			arch.Escribir(lista);
		}else{
			int cont1=0,cont2=0;
			for(int i=0;i<comando.size();i++){
				int** M1;
				int** M2;
				int tam;
				string x=comando.substr(cont1,cont1+1);
				string x2=comando.substr(cont1+2,cont1+1);
				string x1=comando.substr(cont1+1,cont1+1);
				for(int j=0;j<lista.size();j++){
					if(dynamic_cast<Matriz*>(lista[i])){
					Matriz* auxx =dynamic_cast<Matriz*>(lista[i]);
					string a1="";
					a1+=auxx->getChar();
					if(a1==x){	
						tam=auxx->getTam();
					}
					}	
				}
					M2 = new int*[tam];			
					for(int i=0; i<tam;i++){
						M2[i]=new int[tam];
					for(int j=0; j<tam;j++){
					M2[i][j]=NULL;
				}
		}
		M1 = new int*[tam];			
			for(int i=0; i<tam;i++){
				M1[i]=new int[tam];
				for(int j=0; j<tam;j++){
					M1[i][j]=NULL;
				}
		}
				
				for(int j=0;j<lista.size();j++){
					if(dynamic_cast<Matriz*>(lista[i])){
					Matriz* auxx =dynamic_cast<Matriz*>(lista[i]);
					string a1="";
					a1+=auxx->getChar();
					if(a1==x){	
					M1=auxx->getMatriz();
					}else if(a1==x2){
						M2=auxx->getMatriz();
					}
					}	
				}
				
				int** M3;
				M3 = new int*[tam];			
				for(int i=0; i<tam;i++){
				M3[i]=new int[tam];
				for(int j=0; j<tam;j++){
					M3[i][j]=NULL;
				}
				}
				
				
				if(x1=="+"){
				for (int i = 0; i < tam; i++) {
            		for (int j = 0; j < tam; j++) {
            
                 		   M3[i][j] = M1[i][j] + M2[i][j];
             		   }
           			 }
				}else if (x1=="-"){
					for (int i = 0; i < tam; i++) {
           			 for (int j = 0; j < tam; j++) {
                   		 M3[i][j] = M1[i][j] - M2[i][j];
           			 }
       				 }
				}else if (x1=="*"){
					for (int i = 0; i < tam; i++) {
            			for (int j = 0; j < tam; j++) {
               			 for (int k = 0; k < tam; k++) {
                  			  M3[i][j] += M1[i][k] * M2[k][j];
                		}
           				 }
       				 }
				}
			for(int i=0;i<tam;i++){
       			for (int j=0;j<tam;j++){
       				cout<< " ["<<M3[i][j]<<"] ";
				}
				cout<<endl;
			}
			}
			
			
			cout<<"Operacion terminada..."<<endl;
		}	
		}
	}
	return 0;					
	}		
			
			


				
				
				
				
		
		
		


