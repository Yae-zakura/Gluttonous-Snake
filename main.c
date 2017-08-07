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
#include "stdlib.h"
static struct termios ori_attr,cur_attr;
static inline int tty_reset();
static inline int kbhit();
static inline int tty_set();

int control();

int life=2;

int fx=0,fy=0;
int sx=10,sy=10;
int deadx=0,deady=0;

void preproccess();

void inputjudge();

void gamejudge();

void print(int fx,int fy,int sx,int sy);


void add();

int count=0;

int flag=0;

int score=0;

int move();

int level=1;

clock_t start,end;

int main(){


	preproccess();

	
	while(1){

		inputjudge();

		gamejudge();

		print(fx,fy,sx,sy);

		fflush(stdout);
	}
	

}

	
	

/*	
void wait(double sec)
{
	clock_t tick = clock();
	while((clock()-tick) < (CLOCKS_PER_SEC*sec));

}
*/	
