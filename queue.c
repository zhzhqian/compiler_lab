#include "var.h"
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