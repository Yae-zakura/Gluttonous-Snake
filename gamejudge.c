#include"stdio.h"
#include"stdlib.h"
#include"snake.h"
#include"hong.h"


void gameover(){
		char z=0;

		printf("\nGame Over!\n");
		printf("Do you want to restart game? y(yes) or anykey(no)\n");
		scanf("%c",&z);
		if(z=='y')
			preproccess();
		else
			exit(0);
		z=getchar();
		C=getch();
	
}

void add(int x,int y);

void gamejudge(){

	if(area[sx][sy]==SNAKEBODY){
		gameover();
	}
	
	if((area[deadx][deady]==SNAKEHEAD)){
		life=life-2;
		if(life<=0)
			gameover();
		deadx=rand()%(WIDE-2)+1;
		deady=rand()%(HIGH-2)+1;

		while((area[deadx][deady]==SNAKEFOOD) || (area[deadx][deady]==SNAKEHEAD) || (area[deadx][deady]==SNAKEBODY)){
			deadx=rand()%(WIDE-2)+1;
			deady=rand()%(HIGH-2)+1;
		}
	}
	
	system("clear");

	if(sx==fx && sy==fy){

		flag=0;
		count++;
		life++;
		add(sx,sy);

		score=score+level*100;

		fx=rand()%(WIDE-2)+1;
		fy=rand()%(HIGH-2)+1;
		deadx=rand()%(WIDE-2)+1;
		deady=rand()%(HIGH-2)+1;


		while((area[fx][fy]==SNAKEHEAD) || (area[fx][fy]==SNAKEBODY) || (area[deadx][deady]==SNAKEFOOD) || (area[deadx][deady]==SNAKEHEAD) || (area[deadx][deady]==SNAKEBODY)){
		
			fx=rand()%(WIDE-2)+1;
			fy=rand()%(HIGH-2)+1;

			deadx=rand()%(WIDE-2)+1;
			deady=rand()%(HIGH-2)+1;
	
		}
	}else{
	
		add(sx,sy);
		re();
	}

	if((count+1)%5==0 && flag==0 && level<6){
		level++;
		flag=-1;
	}
}




