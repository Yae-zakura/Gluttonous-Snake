#include"stdio.h"
#include"hong.h"
#include"stdlib.h"

void gameover();

extern char area[WIDE][HIGH];

extern int sx,sy;

extern int t;

void moveUP(){
	if(area[sx-1][sy] != 'w'){
		sx--;
		t++;
	}else{
		gameover();
	}
}

void moveDOWN(){
	if(area[sx+1][sy] != 'w'){
		sx++;
		t++;
	}else{	
		gameover();
	}
}

void moveLEFT(){
	if(area[sx][sy-1] != '|'){
		sy--;
		t++;
	}else{
		gameover();
	}
}

void moveRIGHT(){
	if(area[sx][sy+1] != '|'){
		sy++;
		t++;
	}else{
		gameover();
	}
}



int move(int dc){

	switch(dc){
	
		case up:
			moveUP();
			break;
		case down:
			moveDOWN();
			break;
		case left:
			moveLEFT();
			break;
		case right:
			moveRIGHT();
			break;
		default:
			break;
	}
}

