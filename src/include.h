#ifndef VAR_H 
#define VAR_H
#define ALREAY_EXIST 1 
#define ERRO_NONE 0  //插入符号表返回的标记

#define MACHINE_BIT 32
#define MAX_PARA_CONT 10 //最多支持的参数个数

#define var_symtab_type struct var_symtab
#define func_symtab_type struct func_symtab
#define str_symtab_type struct str_symtab
//各类型的大小
#define INT_BYTE 4
#define FLOAT_BYTE 4
#define BOOL_BYTE 1
#define DOUBLE_BYTE 8
#define STRING_BYTE 20
//生成代码的最长只能有10部分
#define MAX_STMT_LENGTH 10

#define addr_type struct char_set

#define bool char
#define true 1
#define false 0
#define OUTPUT_PATH "output/output.o"
#include <stdlib.h>
    struct str_symtab* str_env;
    struct func_symtab* func_env;
    struct var_symtab* var_env;
//结构体/类的符号表,结构体中可以定义变量，函数，所以符号表包含了变量的符号表，函数的符号表
struct str_symtab{
    char* var;
    int width;
    struct str_symtab* next;
    struct func_symtab* func_tab;
    struct var_symtab* var_tab;
    struct str_symtab* str_tab;
};
//函数的符号表，函数中有局部变量，参数，返回值类型等
struct func_symtab {
    char* name;
    int para_cont;
    struct variable_type** paras_type;
    char** paras_name;
    char* addr;
    struct var_symtab* var_tab;
    struct func_symtab* next;
    struct variable_type* return_type;
};
//变量符号表可以保存变量的类型，变量的名称，变量的宽度（方便数组计算元素个数）
struct var_symtab {
    char *var;
    char* addr;
    char* value;
    struct variable_type* var_type;
    struct variable_type* elem_type;
    int width;
    struct var_symtab* next;
};

//实现栈的数据链表，栈用于保存作用域的环境
typedef struct sNode
{
	struct  var_symtab* value;
	struct sNode* next;
	
}SNode;
//实现队列的链表，队列用于保存要输出的中间代码
typedef struct qNode
{
	char** value;
	struct qNode* next;
	
}QNode;
//用于表示地址的数据结构，类似于并查集
struct char_set{
    char is_top;
    char* content;
    struct char_set* upper;
};
//栈
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
 //栈操作
 stack* creatStack();
struct var_symtab* pop(stack* st);
bool stack_isEmpty(stack* st);
void push(stack* st,struct var_symtab* s);


char* itoa(int num);
//队列操作
queue* creatQueue();
void enqueue(queue* qe,char** s);
char** dequeue(queue* qe);
char** getHead(queue* qe);
bool queue_isEmpty(queue* qe);
//变量的类型，由基本类型和扩展类型组成，基本类型指int,char,short等，扩展类型指pointer，arrary
struct variable_type{
    char* base;
    char* exten;
};
struct variable_type* void_type;

void yyerror(const char* msg);
void my_yyerror(int num,...);
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
char* creat_temp_name();
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
struct str_symtab* creat_str_env();
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
void debug(int num,...);
//输出提示信息
void my_info(int num,...);
void my_warrning(int num,...);
#endif