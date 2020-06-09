
#include <stdio.h>
#include"include.h"
queue* creatQueue()
{
	queue* qe=(queue*)malloc(sizeof(queue));
	qe->size=0;
	qe->head=NULL;
	qe->tail=NULL;
	return qe;
}
void enqueue(queue* qe,char** s)
{
	if(!qe) return;
	QNode* p=(QNode*)malloc(sizeof(QNode));
	p->value=s;
	if(qe->size==0)
	{
		qe->head=p;
		qe->tail=p;
		qe->size++;
		return;
	}
	qe->tail->next=p;
	qe->tail=p;
	qe->size++;
}
char** dequeue(queue* qe)
{
	if(qe->size==0) return NULL;
	QNode* temp=qe->head;
	char** dd=temp->value;
	if(qe->size==1) 
	{
		qe->head=NULL;
		qe->tail=NULL;
		free(temp);
		qe->size--;
		return dd;
	}
	qe->head=temp->next;
	free(temp);
	qe->size--; 
	return dd;
}
char** getHead(queue* qe)
{
	return qe->head->value;	 
}
bool queue_isEmpty(queue* qe)
{
	return qe->size<=0;
}
stack* creatStack()
{
	stack* st=(stack*)malloc(sizeof(stack));
	st->size=0;
	st->top=NULL;
	return st; 
}
void push(stack* st,struct  var_symtab* s)
{

	SNode* temp=(SNode*)malloc(sizeof(SNode));
	temp->next=NULL;
	temp->value=s;

	if(st->size==0) 
	{
		st->top=temp;
		st->size++;
		return;
	}
	temp->next=st->top;
	st->top=temp;
	st->size++;
}
struct  var_symtab* pop(stack* st)
{
	if(st->size<=0) return NULL;
	struct  var_symtab* temp=st->top->value;
	SNode * dd=st->top;
	st->top=dd->next;
	st->size--;
	return temp;
}
bool stack_isEmpty(stack* st)
{
	return st->size<=0;
}


char* itoa(int num)
{
    int length=5;
    char* str=(char*)malloc(sizeof(char)*length);
    str[--length]='\0';
    int local_num=num;
    while(num!=0)
    {
        str[--length]=num%10+'0';
        num/=10;
    }
    while(length>0)
        str[--length]='0';
    if(local_num<0)
        str[0]='-';
    return str; 
} 

