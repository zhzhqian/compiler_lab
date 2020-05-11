
#include <stdio.h>
#include"var.h"
stack* creatStack()
{
	stack* st=(stack*)malloc(sizeof(stack));
	st->size=0;
	st->top=NULL;
	return st; 
}
void push(stack* st,struct  envirement* s)
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
struct  envirement* pop(stack* st)
{
	if(st->size<=0) return NULL;
	struct  envirement* temp=st->top->value;
	SNode * dd=st->top;
	st->top=dd->next;
	st->size--;
	return temp;
}
bool stack_isEmpty(stack* st)
{
	return st->size<=0;
}
bool isContain(stack* st,int val)
{
	SNode* p =st->top;
	while(p)
	{
		if(p->value==val)
			return true;
	}
	return false;
}
struct envirement * creat_envirement()
{
    struct envirement * tab=(struct envirement *)malloc(sizeof( struct envirement));
	tab->str_tab=(struct str_symtab*)0;
	tab->var_tab=(struct var_symtab*)0;
    return tab;
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