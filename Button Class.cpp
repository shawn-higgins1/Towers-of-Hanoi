#include <iostream>
#include "Towers of Hanoi Header.h"

using namespace std;

//constructor
button::button(){
	xUpper = 0;
	yUpper = 0;
	xLower = 0;
	yLower = 0;
}

//this allows the intialization of the the button coordinates
button::button(int x1,int x2,int y1,int y2){
	xUpper = x2;
	xLower = x1;
	yUpper = y2;
	yLower = y1;
}

//this allows for the resizing of button coordinates
void button::changeCoordinates(int x1,int x2,int y1,int y2){
	xUpper = x2;
	xLower = x1;
	yUpper = y2;
	yLower = y1;
}

//this checks to see if the mouse is within the button coordinates
bool button::valid(){
	if(mouse_x <= xUpper && mouse_x >= xLower && mouse_y <= yUpper && mouse_y >= yLower){
		return true;
	}
	return false;
}

//deconstructor
button::~button(){
}
