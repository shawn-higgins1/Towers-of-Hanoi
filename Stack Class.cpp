#include <iostream>
#include "Towers of Hanoi Header.h"

using namespace std;

//intializer
Node::Node(){
	_next = NULL;
	_last = NULL;
	type = 0;
}

//returns next
Node* Node::getNext(){
	return _next;
}

//return last
Node* Node::getLast(){
	return _last;
}

//returns the type
int Node::getType(){
	return type;
}

//sets the value of last
void Node::setLast(Node *last){
	_last = last;
}

//sets the value of next
void Node::setNext(Node *next){
	_next = next;
}

//sets the value of the node
void Node::setType(int _type){
	type = _type;
}

//destructor
Node::~Node(){
}

//constructor
Stack::Stack(){
	 _size = -1;
	_startNode = 0;
}

//add function
void Stack::add(int _type){
	if(!full()){
		_size++;
		Node * newNode = new Node ();
		newNode->setType(_type);
		if (_startNode != NULL){
			_startNode->setLast(newNode);
			newNode->setNext(_startNode);
		}
		_startNode = newNode;
	}
	return;
}

//Pop function
int Stack::pop(){
	int _type = -1;
	if(!empty()){
		_type = _startNode->getType();
		Node *temp = _startNode;
		_startNode = _startNode->getNext();
		delete temp;
		if (_startNode != NULL){
			_startNode->setLast(NULL);
		}
		_size--;
	}
	return _type;
}

//this checks to make sure the stack isn't empty
bool Stack::empty(){
	if(_size == -1)
		return true;	
	return false;
}

//this checks to make sure the stack isn't full
bool Stack::full(){
	if(_size == 12)
	{
		return true;
	}	
	return false;
}

//deconstructor
Stack::~Stack(){
}
