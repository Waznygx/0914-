#include"address_book.h"

void menu()
{
	printf("\n  ********************************************\n");
	printf("  ********************************************\n");
	printf("  ******    通   讯   录   系   统     *******\n");
	printf("  ******    0.退出系统     1.增加信息  *******\n");
	printf("  ******    2.删除信息     3.查找信息  *******\n");
	printf("  ******    4.修改信息     5.排序信息  *******\n");
	printf("  ******    6.打印信息                 *******\n");
	printf("  ********************************************\n");
	printf("  ********************************************\n");
}

enum option
{
	EXIT,
	ADD,
	DELETE,
	SEARCH,
	MODIFY,
	SORT,
	PRINT
};
int main()
{
	//创建通讯录
	message mess;
	//初始化通讯录(&mess不是mess或 * mess；传地址而不是传值)
	init_message(&mess);
	int input = 0;
	do
	{
		menu();
		printf("please input your choose: ");
		scanf("%d",&input);
		switch (input)
		{
		case EXIT:
			printf("退出系统!\n");
			break;
		case ADD:
			printf("增加信息:\n");
			add_message(&mess);
			break;
		case DELETE:
			printf("删除信息:\n");
			delete_message(&mess);
			break;
		case SEARCH:
			printf("查找信息:\n");
			break;
		case MODIFY:
			printf("修改信息:\n");
			break;
		case SORT:
			printf("排序信息:\n");
			break;
		case PRINT:
			printf("打印信息：\n");
			print_message(&mess);
			break;
		default:
			printf("无该选项，请重新输入！\n");
			break;
		}
	} while (input);
	return 0;
}