#include"address_book.h"

void menu()
{
	printf("\n  ********************************************\n");
	printf("  ********************************************\n");
	printf("  ******    ͨ   Ѷ   ¼   ϵ   ͳ     *******\n");
	printf("  ******    0.�˳�ϵͳ     1.������Ϣ  *******\n");
	printf("  ******    2.ɾ����Ϣ     3.������Ϣ  *******\n");
	printf("  ******    4.�޸���Ϣ     5.������Ϣ  *******\n");
	printf("  ******    6.��ӡ��Ϣ                 *******\n");
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
	//����ͨѶ¼
	message mess;
	//��ʼ��ͨѶ¼(&mess����mess�� * mess������ַ�����Ǵ�ֵ)
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
			printf("�˳�ϵͳ!\n");
			break;
		case ADD:
			printf("������Ϣ:\n");
			add_message(&mess);
			break;
		case DELETE:
			printf("ɾ����Ϣ:\n");
			delete_message(&mess);
			break;
		case SEARCH:
			printf("������Ϣ:\n");
			break;
		case MODIFY:
			printf("�޸���Ϣ:\n");
			break;
		case SORT:
			printf("������Ϣ:\n");
			break;
		case PRINT:
			printf("��ӡ��Ϣ��\n");
			print_message(&mess);
			break;
		default:
			printf("�޸�ѡ����������룡\n");
			break;
		}
	} while (input);
	return 0;
}