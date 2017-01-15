/*Shawn Higgins Towers of Hanoi
Mr.Creelman Monday, May 2,2016*/

#include <iostream>
#include <allegro.h>
#include <cmath>
#include <alfont.h>
#include "Towers of Hanoi Header.h"

using namespace std;

#define nodeHeight 15

int main(){
	int type=0;
	BITMAP *buffer = NULL;
	Peg peg[3];
	int pegX[3];
	int size = 0;
	int base = 0;
	int boxX = 0;
	int boxX2 = 0;
	bool valid = false;
	int sizeI = 0;
	int r,b,g;
	int moves = 0;
	button solve(15,85,10,35);
	button reset(100,170,10,35);
	int numDisks = 0;
	bool solved = false;
	bool quit;
	int key;
	
	//intializes the coordinates of the pegs
	for (int i = 0; i < 3; i++){
		peg[i].setCo(120+(i*195));
		pegX[i] = peg[i].getX();
	}
	
	//allegro intialization
	allegro_init(); 
	install_mouse();
	install_keyboard(); 
	install_timer();
	alfont_init();   
	
	//creates buffer
	buffer = create_bitmap(640,300);
	
	//makes sure the buffer is valid
	if (!buffer){
    	cout << "Bitmap didn't load properly"; 
    	return 1;
	}
	
	//intializing alfonts
	ALFONT_FONT *arial = alfont_load_font("C:/Windows/Fonts/arial.ttf");
	alfont_set_font_size(arial, 30); 
	
	set_color_depth(32); 
	set_gfx_mode(GFX_AUTODETECT_WINDOWED, 640,300,0,0);
	set_window_title("Towers of Hanoi");
	show_mouse(screen);
	
	//prompts the user to input a number of disks and checks that it is valid
	cout << "Please enter the number of disks you would like (2-6): ";
	cin >> numDisks;
	while(numDisks > 6 || numDisks < 2){
		cout << "Not a valid input" << endl; 
		cout << "Please enter the number of disks you would like (2-6): ";
		cin >> numDisks;
	}
	
	//adds the number of disks the user requested onto the first peg
	for(int i = 1; i <= numDisks; i++){
		peg[0].add(i);
	}
	
	//draws the background and all the disks
	drawBackground(buffer,moves);
	for(int i = 0; i < 3; i++){
		peg[i].print(buffer);
	}
	blit(buffer, screen, 0, 0, 0, 0, 640, 300);
	
	//loops through until the user decides to quit
	while(!quit){
		//checks to see if the puzzle has been completed
		if(peg[2].getSize() == numDisks-1){
			clear(buffer);
			blit(buffer, screen, 0, 0, 0, 0, 640, 300);
			
			//prints out win screnn
			alfont_textprintf_aa_ex(screen, arial,200 ,100, makecol(255, 0, 0), -1, "Congratulations");
			if(solved){
				alfont_textprintf_aa_ex(screen, arial,145 ,125, makecol(255, 0, 0), -1, "The computer solved it for you"); 
			}
			else if(moves == pow(2,numDisks)-1){
				alfont_textprintf_aa_ex(screen, arial,170 ,125, makecol(255, 0, 0), -1, "You got a perfect score");
			}
			else{
				alfont_textprintf_aa_ex(screen, arial,200 ,125, makecol(255, 0, 0), -1, "You solved it");
			}
			alfont_textprintf_aa_ex(screen, arial,180 ,150, makecol(255, 0, 0), -1, "Press Y to continue.");
			
			//prompts the user to either continue or quit
			clear_keybuf();
			key=readkey();
			if((key & 0xff) != 'y'){
				quit = true;
			}
			else{
				//resets the puzzle
				for(int i = 0; i < 3; i++){
					peg[i].remove();
				}
				for(int i = 1; i <= numDisks; i++){
					peg[0].add(i);
				}
				clear(buffer);
				clear(screen);
				moves = 0;
				solved = false;
				drawBackground(buffer,moves);
				for(int i = 0; i < 3; i++){
					peg[i].print(buffer);
				}
				blit(buffer, screen, 0, 0, 0, 0, 640, 300);
			}
		}
		//loops through the three pegs to see if the user has clicked on anyone on of the
		//disks on the top
		for(int i = 0; i < 3; i++){
			size = peg[i].pop();
			valid = false;
			//makes sure there are disks on that peg
			if(size != -1){
				//determines coorindates of top disk
				base = 250-(15*(peg[i].getSize()+1));
				boxX = pegX[i]-(50-8*(size));
				boxX2 = pegX[i]+(50-8*(size))+10;
				//checks to see if that disk had been selected
				if(mouse_x > boxX && mouse_x < boxX2 && mouse_y < base && mouse_y > base-15 && mouse_b == 1){
					//determines new coorindates of mouse location
					valid = false;
					boxX = boxX-mouse_x;
					boxX2 = boxX2-mouse_x;
					base = base-mouse_y;
					//loops through until mouse is realised
					while(mouse_b == 1){
						//clears the buffer reprints background along with disk based on mouse location
						clear(buffer);
						setColour(r,b,g,size);
						rectfill(buffer,mouse_x+boxX,mouse_y+base,mouse_x+boxX2,mouse_y+base-15,makecol(r,b,g));
						drawBackground(buffer,moves);
						for(int i = 0; i < 3; i++){
							peg[i].print(buffer);
						}
						blit(buffer, screen, 0, 0, 0, 0, 640, 300);
					}
					//loops through the three pegs
					for(int j = 0; j < 3; j++){
						//makes sure the peg isn't the one the disk came from
						if(j!=i){
							//checks to see if the disk is near a peh
							if(mouse_x > pegX[j]-boxX2&& mouse_x < pegX[j]+10-boxX&&mouse_y > 50 && mouse_y < 250){
								//pops of the top disk on that peg
								sizeI = 0;
								sizeI = peg[j].pop();
								//adds that disk back to the peg 
								if(sizeI != -1){
									peg[j].add(sizeI);
								}
								//adds the new disk to the peg if it is smaller that the previous disk
								if(size > sizeI){
									peg[j].add(size);
									valid = true;
									moves++;
								}
							}
						}
					}
					//adds the orginal value back to the old peg if the move wasn't valid
					if(!valid){
						peg[i].add(size);
						valid = true;
					}
					//reprints everything
					clear(buffer);
					drawBackground(buffer,moves);
					for(int k = 0; k < 3; k++){
						peg[k].print(buffer);
					}
					blit(buffer, screen, 0, 0, 0, 0, 640, 300);
				}
			}
			//adds the disk back if it wasn't selected
			if(!valid && size!=-1){
				peg[i].add(size);
			}
		}
		//checks to see if the user pressed solve
		if(solve.valid() && mouse_b == 1 ){
			//resets all the values and reprints
			for(int i = 0; i < 3; i++){
				peg[i].remove();
			}
			for(int i = 1; i <= numDisks; i++){
				peg[0].add(i);
			}
			clear(buffer);
			moves = 0;
			drawBackground(buffer,moves);
			for(int i = 0; i < 3; i++){
				peg[i].print(buffer);
			}
			blit(buffer, screen, 0, 0, 0, 0, 640, 300);
			
			//solves the puzzle
			hanoi(numDisks,peg[0],peg[2],peg[1],buffer,moves);
			solved = true;
		}
		//checks to see if the user pressed rest
		if(reset.valid() && mouse_b == 1){
			//resets all the values and reprints
			for(int i = 0; i < 3; i++){
				peg[i].remove();
			}
			for(int i = 1; i <= numDisks; i++){
				peg[0].add(i);
			}
			clear(buffer);
			moves = 0;
			drawBackground(buffer,moves);
			for(int i = 0; i < 3; i++){
				peg[i].print(buffer);
			}
			blit(buffer, screen, 0, 0, 0, 0, 640, 300);
		}
	}
	
	destroy_bitmap(buffer);
	allegro_exit();
	alfont_exit(); 
	return 0;
}
END_OF_MAIN();
