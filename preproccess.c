#include"stdio.h"
#include"hong.h"
#include"snake.h"
#include"time.h"



void print(int fx,int fy,int sx,int sy);

void add();


void preproccess(){
	level=1;
	count=0;
	score=0;
	sx=WIDE/2;
	sy=HIGH/2;
	a=0;b=0;
	life=2;
	t=0;

	srand(time(NULL));


	fx=rand()%(WIDE-2)+1;
	fy=rand()%(HIGH-2)+1;
	deadx=rand()%(WIDE-2)+1;
	deady=rand()%(HIGH-2)+1;

	while((sx==fx && sy==fy) || (fx==deadx && fy==deady) || (sx==deadx && sy==deady)){
		fx=rand()%(WIDE-2)+1;
		fy=rand()%(HIGH-2)+1;

		deadx=rand()%(WIDE-2)+1;
		deady=rand()%(HIGH-2)+1;

	}

	add();
	head->x=sx;
	head->y=sy;


	system("clear");
	start = clock();
	end = clock();
	
	print(fx,fy,sx,sy);
}
