#ifndef VAR_H
#define VAR_H
#define ALREAY_EXIST 1
#define ERRO_NONE 0
#define MACHINE_BIT 32
#define MAX_PARA_CONT 10
#define var_symtab_type struct var_symtab
#define func_symtab_type struct func_symtab
#define str_symtab_type struct str_symtab
#define INT_BYTE 4
#define FLOAT_BYTE 4
#define BOOL_BYTE 1
#define DOUBLE_BYTE 8
#define STRING_BYTE 20
#define NSYMS 50
#define MACHINE_BIT 32
#define MAX_STMT_LENGTH 10
#define addr_type struct char_set
#define bool char
#define true 1
#define false 0
#include <stdlib.h>
struct str_symtab{
    struct envirement * var_tab;
    char* var;
    int width;
    struct str_symtab* next;
    struct envirement* env;
};

struct func_symtab* func_env;
struct func_symtab {
    char* name;
    int para_cont;
    struct variable_type** paras_type;
    char** paras_name;
    char* addr;
    struct envirement* env;
    struct func_symtab* next;
    struct variable_type* return_type;
};
struct var_symtab {
    char *var;
    char* addr;
    char* value;
    struct variable_type* var_type;
    struct variable_type* elem_type;
    int width;
    struct var_symtab* next;
};
struct envirement {
    struct var_symtab* var_tab;
    struct str_symtab* str_tab;
    unsigned int offset;
};
typedef struct sNode
{
	struct  envirement* value;
	struct sNode* next;
	
}SNode;
typedef struct qNode
{
	char** value;
	struct qNode* next;
	
}QNode;
struct char_set{
    char is_top;
    char* content;
    struct char_set* upper;
};
typedef struct 
{
	int size;
	SNode* top;
 }stack; 
typedef struct 
{
	int size;
	QNode* head;
 	QNode* tail;
 }queue; 
 stack* creatStack();
struct  envirement* pop(stack* st);
bool stack_isEmpty(stack* st);
void push(stack* st,struct  envirement* s);
struct envirement * creat_envirement();
char* itoa(int num);

queue* creatQueue();
void enqueue(queue* qe,char** s);
char** dequeue(queue* qe);
char** getHead(queue* qe);
bool queue_isEmpty(queue* qe);

struct variable_type{
    char* base;
    char* exten;
};
struct variable_type* void_type;
void yyerror(const char* msg);
int yylex();

//merge two addr list
void merge(addr_type* list1,addr_type* list2);
//backPatch list with another known list
void backPatch(addr_type* list,addr_type* instr);
//backPtach list with explicit addr
void assign_addr(addr_type* list,char* instr);
//creat a addr list
addr_type* make_list(char* content);
//creat a temp loaction 
char* creat_temp_lab();
//creat a temp variable name
char* creat_temp_add();
//
char* emit_stm(int num,...);
//get the list's addr 
char* get_value(addr_type* list);
//return width by type
int get_width_by_type(struct variable_type* type);
//add a vriable to variable symtab
int var_sym_look(var_symtab_type* var_sym);
//add a function to function symtab
int func_sym_look(char* sym_name,func_symtab_type* func_tab);
//query specific function by it's name
struct func_symtab* query_fuc_sym(char* name);
//query specific variable by it's name
struct var_symtab* query_var_sym(char* name);
//creat variable type malloc!!!
struct variable_type* creat_variable_type();
//creat one line of vaiable symtable
var_symtab_type*  creat_symtab(char* name,struct variable_type* temp_type);
//handle type tansform
struct variable_type* handle_type(struct variable_type* a,struct variable_type* b);
//compare whether two type is compatible 
char typecmp(struct variable_type* one,struct variable_type* other);
//queue to store statement which need to backpatch
queue* stmt_queue;
//check whether statement in queue head is ready
bool check_stmt_ready();
//when the statement in queue head is ready ,write it to file
void emit_stm_head();
//creat function symtab
func_symtab_type* creat_func_env();
//for test reason 
void iterate_env();
//prepare a location which need to be backpatch
char* emit_stm_ready(addr_type* addr);
//add a struct to struct symtab
int str_sym_look(char* sym_name,str_symtab_type* str_tab);
//store the file pointer
FILE* file;
//store the address break and contine need
addr_type* break_addr;
addr_type* continue_addr;
#endif