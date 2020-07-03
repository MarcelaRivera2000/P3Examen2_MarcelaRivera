#ifndef NODE_H
#define NODE_H
#include "Object.h"

class Node{
	public: 
		Node(int);
	private:
		int dato;
		Node *der;
		Node *izq;
};
#endif
