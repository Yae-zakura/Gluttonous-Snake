#include"stdio.h"
#include "sys/time.h"
#include "sys/types.h"
#include "unistd.h"
#include "termios.h"
#include "time.h"
#include "limits.h"
#include "string.h"
#include "snake.h"
#include "hong.h"
#include "stdio.h"
#include "string.h"
#include "stdlib.h"
static struct termios ori_attr,cur_attr;
static inline int tty_reset();
static inline int kbhit();
static inline int tty_set();

int control();

void add();
void re();
int getch();
int move(int dc);

void preproccess();

int t=0;

int dc=0;
	
int before[2]={0,0};

int after[2]={0,0};
int a=0,b=0;
	
char C=0;

void inputjudge(){
	

	a=after[0]-before[0];
	b=after[1]-before[1];

//	printf("x:%d\n",temp2[0]-temp1[0]);
//	printf("y:%d\n",temp2[1]-temp1[1]);


	double sec=(7-level)*0.1;


	clock_t tick = clock();
	while((clock()-tick) < (CLOCKS_PER_SEC*sec))
	{
		C=control();
		
		C=tolower(C);

		if(C=='p'){
		
			C=getch();
		}

		if(C=='l'){
		
			C=getch();
			preproccess();
		}


		if(C==27){
			printf("\n");
			exit(0);
		}
	
		
		if(C==MUP && a!=1){
			dc=up;
			sec=0.05;
		}
		
		if(C==MDOWN && a!=-1){
			dc=down;
			sec=0.05;
		}
		
		if(C==MLEFT && b!=1){
			dc=left;
			sec=0.05;
		}
		
		if(C==MRIGHT && b!=-1){
			dc=right;
			sec=0.05;
		}
	}
	
	before[0]=sx;
	before[1]=sy;

	if(t==1){
		start=clock();
	}
//	printf("dc = %d\n",dc);	
	
	move(dc);
	
	end=clock();

	after[0]=sx;
	after[1]=sy;
	
	

}

