#include <iostream>
#include <allegro.h>
#include <cmath>
#include <alfont.h>
#include "Towers of Hanoi Header.h"

using namespace std;

#define nodeHeight 15

//solves the tower of hanoi
void hanoi(int n,Peg &s,Peg &d,Peg &i, BITMAP *buffer, int &moves){
	if (n > 0){
		hanoi(n-1,s,i,d,buffer,moves);
		move(s,d,buffer,i,moves);
		hanoi(n-1,i,d,s,buffer,moves);
	}
	return;
}

//this animates the disks moving from one peg to another
void move(Peg &s, Peg &d, BITMAP *buffer, Peg same, int &moves){
	//int type;
	/*int x,x2;
	int base,base1;
	x = s.getX();
	x2 = d.getX();
	base = 250-(15*s.getSize());
	base1 = 250-(15*(d.getSize()+1));
	int xPoint[3];
	int yPoint[3];*/
	//type = s.pop();
	/*int increment;
	int r,b,g;	
	
	//this intializes the 3 key points the disk will travel to
	xPoint[0] = x;
	yPoint[0] = 76;
	xPoint[1] = x2;
	yPoint[1] = 76;
	xPoint[2] = x2;
	yPoint[2] = base1;
	
	//determines colour
	setColour(r,b,g,type);*\
	
	//loops through the three points
	/*for(int i = 0; i < 3; i++){
		//determines distance and then how many increments based on the distance
		//between the disk and the key point
		increment = sqrt(pow(xPoint[i]-x,2)+pow(yPoint[i]-base,2))/3;
		//moves the disk and prints out the result as it moves
		for(int j = 0; j <= increment;j++){
			if(yPoint[i] < base){
				base -= 3;
			} 
			else if(yPoint[i] > base){
				base += 3;
			}
			if(xPoint[i] < x){
				x -= 3;
			} 
			else if (xPoint[i] > x){
				x += 3;
			}
			clear(buffer);
			drawBackground(buffer,moves);
			s.print(buffer);
			d.print(buffer);
			same.print(buffer);
			rectfill(buffer,x-(50-8*type),base-nodeHeight,x+10+(50-8*type),base,makecol(r,b,g));
			blit(buffer, screen, 0, 0, 0, 0, 640, 300);
			rest(8);
		}
	}*/
	
	//increases moves and prints out the result
	moves++;
	d.add(s.pop());
	clear(buffer);
	drawBackground(buffer,moves);
	s.print(buffer);
	d.print(buffer);
	same.print(buffer);
	blit(buffer, screen, 0, 0, 0, 0, 640, 300);
	return;
}

//this draws the pegs and the buttons which make up the background
void drawBackground(BITMAP *buffer, int moves){
	rectfill(buffer,50,250,590,300,makecol(153,51,51));
	rectfill(buffer,315,250,325,100,makecol(153,51,51));
	rectfill(buffer,120,250,130,100,makecol(153,51,51));
	rectfill(buffer,510,250,520,100,makecol(153,51,51));
	rectfill(buffer,15,10,85,35,makecol(153,51,51));
	rectfill(buffer,100,10,170,35,makecol(153,51,51));
	textprintf_ex(buffer, font, 30, 20, 15, -1,"Solve");
	textprintf_ex(buffer, font, 115, 20, 15, -1,"Reset");
	textprintf_ex(buffer, font, 520, 20, 15, -1,"Moves: ");
	textprintf_right_ex(buffer, font, 590, 20, 15, -1,"%d", moves);
	return;
}

//this sets the colour of the disk based on its type
void setColour(int &r, int &b, int &g, int type){
	switch (type){
			case 1 : 
			r = 255;
			g = 255;
			b = 255;
			break;
		case 2 : 
			r = 255;
			g = 50;
			b = 30;
			break;
		case 3 : 
			r = 78;
			g = 200;
			b = 164;
			break;
		case 4 : 
			r = 89;
			g = 76;
			b = 255;
			break;
		case 5 : 
			r = 255;
			g = 43;
			b = 153;
			break;
		case 6:
			r = 130;
			b = 190;
			g = 65;
			break;
	}
}
