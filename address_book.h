#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<memory.h>
#include<string.h>

#define max_name 12
#define max_sex 10
#define max_tele 20
#define max_address 30
#define max_person 10000

//��Ϣ����������
typedef struct message_content//©��typedef������main.c��struct�޷�ʡ��
{
	char name[max_name];
	char sex[max_sex];
	int age;
	int tele;
	char address[max_address];
}content;

//ͨѶ¼
typedef struct person_message
{
	content all_data[max_person];//ͨѶ¼������
	int available_data;//������Ϣ�ĸ���
}message;


//��������(д��message��������struct�Ļ��ᱨ��)
void init_message(message* mess);
void add_message(message* mess);
void print_message(const message* mess);//����û�뵽Ҫ�̶�mess
void delete_message(message* mess);
int find_name(message* mess,char name[]);//û���ǵ�ɾ�����޸ġ���ѯ��Ҫ�õ������ҡ�ָ��