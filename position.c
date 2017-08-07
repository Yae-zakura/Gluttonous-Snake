#include"stdio.h"
#include"stdlib.h"
#include"snake.h"
#include"time.h"
#include"hong.h"

snake *head=NULL;
snake *rear=NULL;

extern char area[WIDE][HIGH];

void add(int x,int y){

	snake *p=(snake *)malloc(sizeof(snake));
	if(!p)
		return;
	p->next=NULL;
	if(head==NULL){
		head=p;
		rear=NULL;
	}else{
	
		p->next=head;
		head=p;
//		free(head->next->next);
	}
	p->x=x;
	p->y=y;

}

void re(){

	snake *p=(snake *)malloc(sizeof(snake));
	p=head;
	if(!p)
		return;

	while(p->next->next){
		p=p->next;
	}
	free(p->next);
	p->next=NULL;

}


/*
	while(p->next->next){
		p=p->next;
	}
	free(p->next);
	p->next=NULL;

	while(p->next){
	
		p=p->next;
	}
	free(p);
	*/
