#include"hong.h"
#include"stdio.h"
#include"snake.h"
#include"stdlib.h"
#include"time.h"

extern snake *head;
extern snake *rear;

extern int level;
extern int count;
extern int score;

char area[WIDE][HIGH];
extern clock_t start,end;



void print(int fx,int fy,int sx,int sy){

	int i=0,j=0;
	for(i=0;i<WIDE;i++){
	
		for(j=0;j<HIGH;j++){
			
			area[i][j]=' ';

			if(i==0 || i==WIDE-1)
				area[i][j]='w';
	
			if(j==0 || j==HIGH-1)
				area[i][j]='|';

			
			snake *p=(snake *)malloc(sizeof(snake));
		
			p=head;
			
			int i=0;
			
			for(i=0;i<count;i++){
				area[p->next->x][p->next->y]=SNAKEBODY;
				p=p->next;
			}
			
			area[deadx][deady]=POISON;	
			area[fx][fy]=SNAKEFOOD;
			area[sx][sy]=SNAKEHEAD;	
	

		}
	}
	
	
	for(i=0;i<WIDE;i++){
	
		for(j=0;j<HIGH;j++){

			printf("%c",area[i][j]);
		}
		printf("\n");
	}
	printf("\nInput %c %c %c %c will start game\n",MUP,MLEFT,MDOWN,MRIGHT);
	printf("\nInput Esc will end game\n");
	printf("\nInput p will pause game\n");
	printf("\nInput l will restart game\n");
	printf("\nHold on button will more fast\n");
	printf("\nDon't eat '%c',it's poison\n",POISON);
	printf("\nYour score:%d\n",score);
	printf("\nYour HP:%d\n",life);
	printf("\nYour time:%.2lfs\n",(double)(end-start)/CLOCKS_PER_SEC);
}





