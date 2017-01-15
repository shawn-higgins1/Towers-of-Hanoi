#include <iostream>
#include <allegro.h>
#include "Towers of Hanoi Header.h"

using namespace std;

#define nodeHeight 15

//constructor
Peg::Peg(){
	x = 0;
}

//sets the coordinates
void Peg::setCo(int _x){
	x = _x;
	x2 = _x+10;
	y = 100;
	y2 = 250;
}

//returns the left x value of the peg
int Peg::getX(){
	return x;
}

//gets the number of disks on the peg
int Peg::getSize(){
	return _size;
}

//prints out all the disks on the peg
void Peg::print(BITMAP *&buffer){
	Node *traverse;
	traverse = _startNode;
	int _type;
	int base = y2;
	base -=nodeHeight*_size;
	int r,b,g;

	//this loops through all the elements in the stack printing them out in lifo order
	while(traverse != NULL){
		_type = traverse->getType();
		//this determines what colour the disk will be based on the size of the disk
		setColour(r,b,g,_type);
		//prints out the disk
		rectfill(buffer,x-(50-8*_type),base-nodeHeight,x2+(50-8*_type),base,makecol(r,b,g));
        traverse = traverse->getNext();
        base+=nodeHeight;
   }
   return;
}

//removes all the disks on the peg
void Peg::remove(){
	Node *remove;
	while (_startNode){
		remove = _startNode;
		_startNode = _startNode->getNext();
		delete remove;
	}
	_size = -1;
	return;
}

//deconstructor
Peg::~Peg(){
	Node *remove;
	while (_startNode){
		remove = _startNode;
		_startNode = _startNode->getNext();
		delete remove;
	}
	_size = -1;
}
