#include"address_book.h"

//��ʼ��ͨѶ¼��Ϣ
void init_message(message* mess)
{
	mess->available_data = 0;
	memset(mess->all_data, 0, sizeof(mess->all_data));//memset�ڴ�����(��ʼ����ȫ0���ȫ0)
}

void add_message(message* mess)
{
	if (mess->available_data == max_person)
	{
		printf("ͨѶ¼������Ϣ�����������޷��������Ϣ��\n");
		return;//����ִ�У������÷���ֵ
	}
	else
	{
		// mess->all_data[mess->available_data]�������ÿռ����Ϣ�Ž���������Ӧ�±�Ŀռ�
		// �ѵ�n����ӽ�������Ϣ�������������±�Ϊn��λ��
		// available=1 ==��all_data=1
		// ������0��ѧ�������±�Ϊ0��all_data��
		printf("������������");
		scanf("%s", mess->all_data[mess->available_data].name);
		printf("�������Ա�");
		scanf("%s", mess->all_data[mess->available_data].sex);//�޷���ȡ�Ա�ԭ��scanf�м���"\n"������������
		//int i=0;scanf("%d",&i);
		//Ҫȡ��ַ
		printf("���������䣺");
		scanf("%d", &(mess->all_data[mess->available_data].age));
		printf("��������ϵ��ʽ��");
		scanf("%d",&(mess->all_data[mess->available_data].tele));
		printf("������סַ��");
		scanf("%s", mess->all_data[mess->available_data].address);

		mess->available_data++;//���ÿռ�+1
		printf("������Ϣ�ɹ���\n");
	}
}

void print_message(const message* mess)//����û�뵽Ҫ�̶�mess
{
	//��ӡ����(-�����)
	printf("%-8s\t%-8s\t%-8s\t%-20s\t%-20s\n", "����", "�Ա�", "����", "��ϵ��ʽ", "סַ");
	//��ӡ����
	int i = 0;
	for ( i = 0; i < mess->available_data; i++)
	{
		printf("%-8s\t%-8s\t%-8d\t%-20d\t%-20s\n",//���ǰ� "����", "��ϵ��ʽ"��Ϊ��%d��
			mess->all_data[i].name,//û�п��ǵ���i��������д��all_data.name
			mess->all_data[i].sex,
			mess->all_data[i].age,
			mess->all_data[i].tele,
			mess->all_data[i].address);
	}
}
//static:ֻ���ڱ�Դ�ļ��ã����ܱ�����Դ�ļ�ʹ��
//����һ���벻���ĵط�
static int find_name(message* mess,char name[])
{
	int i = 0;
	for ( i = 0; i < mess->available_data; i++)
	{
		//�����ַ�������ֱ���õȺţ���������
		if (strcmp(name, mess->all_data[i].name) == 0)
			return i;
	}
	return -1;//����forѭ��������
}
void delete_message(message* mess)
{
	//�ж�
	if (mess->available_data == 0)
	{
		printf("ͨѶ¼Ϊ�գ��޷�ɾ����\n");
		return;
	}
	char name[max_name] = { 0 };//д��int���ͣ����
	printf("��������Ҫɾ����(��Ϣ)���֣�");
	//int�ĳ�char֮��%dû�ĳ�%s������������ʲô������ʾ��Ϣ�����ڣ�������
	scanf("%s", name);
	int ret = find_name(mess, name);//û���ǵ�ɾ�����޸ġ���ѯ��Ҫ�õ������ҡ�ָ��
	if (ret == -1)
	{
		printf("���������Ϣ�����ڣ��޷�ɾ����\n");
		return;
	}
	//ִ��
	int i = 0;
	for ( i = ret; i < mess->available_data - 1; i++)
		//available_data - 1ԭ�����һ�������滻֮�󣬻���������һ�������±�+1������ջ���
		//����1 2 3 4 5����1ɾ����2���ǵ�1��λ�ã�3����2λ�ã�4����3��5����4���������һ�������5����Ŀ�ֵ����5�����
	{
		mess->all_data[i] = mess->all_data[i + 1];
	}
	mess->available_data--;//--д��++������������ôɾ����ӡ���ɻ�����
	printf("ɾ���ɹ���\n");
}