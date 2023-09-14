#include"address_book.h"

//初始化通讯录信息
void init_message(message* mess)
{
	mess->available_data = 0;
	memset(mess->all_data, 0, sizeof(mess->all_data));//memset内存设置(初始化可全0或非全0)
}

void add_message(message* mess)
{
	if (mess->available_data == max_person)
	{
		printf("通讯录可用信息容量已满，无法添加新信息！\n");
		return;//结束执行，但不用返回值
	}
	else
	{
		// mess->all_data[mess->available_data]：将可用空间的信息放进总容量对应下标的空间
		// 把第n个添加进来的信息放在总数据中下标为n的位置
		// available=1 ==》all_data=1
		// 例：第0个学生放在下标为0的all_data中
		printf("请输入姓名：");
		scanf("%s", mess->all_data[mess->available_data].name);
		printf("请输入性别：");
		scanf("%s", mess->all_data[mess->available_data].sex);//无法读取性别原因：scanf中加了"\n"！！！！！！
		//int i=0;scanf("%d",&i);
		//要取地址
		printf("请输入年龄：");
		scanf("%d", &(mess->all_data[mess->available_data].age));
		printf("请输入联系方式：");
		scanf("%d",&(mess->all_data[mess->available_data].tele));
		printf("请输入住址：");
		scanf("%s", mess->all_data[mess->available_data].address);

		mess->available_data++;//已用空间+1
		printf("输入信息成功！\n");
	}
}

void print_message(const message* mess)//根本没想到要固定mess
{
	//打印标题(-左对齐)
	printf("%-8s\t%-8s\t%-8s\t%-20s\t%-20s\n", "姓名", "性别", "年龄", "联系方式", "住址");
	//打印内容
	int i = 0;
	for ( i = 0; i < mess->available_data; i++)
	{
		printf("%-8s\t%-8s\t%-8d\t%-20d\t%-20s\n",//忘记把 "年龄", "联系方式"改为“%d”
			mess->all_data[i].name,//没有考虑到【i】，而是写成all_data.name
			mess->all_data[i].sex,
			mess->all_data[i].age,
			mess->all_data[i].tele,
			mess->all_data[i].address);
	}
}
//static:只能在本源文件用，不能被其他源文件使用
//又是一个想不到的地方
static int find_name(message* mess,char name[])
{
	int i = 0;
	for ( i = 0; i < mess->available_data; i++)
	{
		//两个字符串不能直接用等号！！！！！
		if (strcmp(name, mess->all_data[i].name) == 0)
			return i;
	}
	return -1;//放在for循环里面了
}
void delete_message(message* mess)
{
	//判断
	if (mess->available_data == 0)
	{
		printf("通讯录为空！无法删除！\n");
		return;
	}
	char name[max_name] = { 0 };//写成int类型（无语）
	printf("请输入你要删除的(信息)名字：");
	//int改成char之后，%d没改成%s，导致无论输什么，都提示信息不存在！！！！
	scanf("%s", name);
	int ret = find_name(mess, name);//没考虑到删除、修改、查询都要用到“查找”指令
	if (ret == -1)
	{
		printf("你输入的信息不存在！无法删除！\n");
		return;
	}
	//执行
	int i = 0;
	for ( i = ret; i < mess->available_data - 1; i++)
		//available_data - 1原因：最后一个数字替换之后，还会出现最后一个数字下标+1的数，栈溢出
		//例：1 2 3 4 5，把1删除后，2覆盖到1的位置，3覆盖2位置，4覆盖3，5覆盖4，如果不减一，会出现5后面的空值覆盖5的情况
	{
		mess->all_data[i] = mess->all_data[i + 1];
	}
	mess->available_data--;//--写成++，导致无论怎么删，打印依旧还存在
	printf("删除成功！\n");
}