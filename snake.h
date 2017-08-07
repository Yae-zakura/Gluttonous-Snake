#ifndef __SNAKE__H
#define __SNAKE__H


#include "hong.h"
#include "time.h"

typedef struct snake{
	int x;
	int y;
	struct snake *next;
}snake;

extern snake *head;
extern snake *rear;

extern int dc;

extern char C;

extern int a,b;

extern char area[WIDE][HIGH];
extern int count,level,score,flag,life;

extern int sx,sy,fx,fy,deadx,deady;
extern int f,t;
extern clock_t start,end;

#endif
