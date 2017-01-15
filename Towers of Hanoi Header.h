#include <iostream>
#include <allegro.h>

using namespace std;

class Node{
private:
	Node *_next;
	Node *_last;
	int type;
public:
	Node();
	Node *getNext();
	Node *getLast();
	int getType();

	void setNext(Node *next);
	void setLast(Node *last);
	void setType(int type);	
	~Node();	
};

class Stack{
protected:
	Node * _startNode;
	int _size;
public:		
	Stack();
	void add(int _type);
	int pop();
	bool empty();
	bool full();
	~Stack();
};

class Peg: public Stack{
	private:
		int x,x2,y,y2;
	public:
		Peg();
		int getX();
		void print(BITMAP *&buffer);
		int getSize();
		void setCo(int _x);
		void remove();
		~Peg();
};

class button{
	private:
		int xUpper;
		int yUpper;
		int xLower;
		int yLower;
	public:
		button();
		button(int x1,int x2,int y1,int y2);
		void changeCoordinates(int x1,int x2,int y1,int y2);
		bool valid();
		~button();
};

void hanoi(int n,Peg &s,Peg &d,Peg &i, BITMAP *buffer, int &moves);
void move(Peg &s,Peg &d, BITMAP *buffer, Peg same, int &moves);
void drawBackground(BITMAP *buffer, int moves);
void setColour(int &r, int &b, int &g, int type);
