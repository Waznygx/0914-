#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<memory.h>
#include<string.h>

#define max_name 12
#define max_sex 10
#define max_tele 20
#define max_address 30
#define max_person 10000

//信息包含的内容
typedef struct message_content//漏掉typedef，导致main.c中struct无法省略
{
	char name[max_name];
	char sex[max_sex];
	int age;
	int tele;
	char address[max_address];
}content;

//通讯录
typedef struct person_message
{
	content all_data[max_person];//通讯录总容量
	int available_data;//可用信息的个数
}message;


//函数声明(写在message上面且无struct的话会报错)
void init_message(message* mess);
void add_message(message* mess);
void print_message(const message* mess);//根本没想到要固定mess
void delete_message(message* mess);
int find_name(message* mess,char name[]);//没考虑到删除、修改、查询都要用到“查找”指令