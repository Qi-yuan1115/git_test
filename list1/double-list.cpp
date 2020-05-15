#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//����һ��˫��������ݽṹ
typedef struct __double_list
{
	int data;
	struct __double_list *prev;
	struct __double_list *next;
}DL;




//����˫����������һ���ڵ� 
DL *create_dl_node(int data)
{
	DL *p = (DL *)malloc(sizeof(DL));
	if (NULL == p)
	{
		printf("create dl node fair!\n");
		return NULL;
	}
	//��ʼ������ 
	p->data = data;
	//��ʼ��ָ�� 
	p->next = NULL;
	p->prev = NULL;
}

//˫�������β�� 
void double_list_tail_insert(DL *header, DL *new1)
{
	//ȡ�õ�ǰ�ڵ�ĵ�ַ 
	DL *p = header;
	//�ҵ������β�ڵ� 
	while (NULL != p->next)
	{
		//�Ҳ��������� 
		p = p->next;
	}
	//�ҵ���β�ڵ㣬ָ���½ڵ���׵�ַ 
	p->next = new1;
	//�½ڵ��prevָ��ָ��ԭ����β�ڵ���׵�ַ��
	new1->prev = p;
}

//˫�������ͷ��(Ҳ���ǲ��������ڵ�֮��Ĳ��뷽ʽ)
void double_list_top_insert(DL *header, DL *new1)
{
	//�½ڵ��nextָ��ָ��ԭ���Ľڵ�һ�ĵ�ַ
	new1->next = header->next;
	//�жϵ�ǰ�ڵ����һ���ڵ�ĵ�ַ�Ƿ�Ϊ��
	if (NULL != header->next)
		header->next->prev = new1; //�ڵ�1��prevָ��ָ���½ڵ�ĵ�ַ 
	header->next = new1;
	new1->prev = header;
}

//˫�������������� 
void double_list_for_each(DL *header)
{
	DL *p = header;
	while (NULL != p->next)
	{
		p = p->next;
		printf("%d ", p->data);
	}
}

//˫������ķ������ 
void double_list_for_each_nx(DL *header)
{
	DL *p = header;
	//���ҵ�β�ڵ�
	while (NULL != p->next)
	{
		p = p->next;
	}
	//�Ѿ��ҵ���β�ڵ㣬��ǰ������ע�⣬������ͷ�ڵ�֮ǰ
	//��������: != ͷ��� 
	while (NULL != p->prev)
	{
		printf("%d ", p->data);
		p = p->prev;
	}
}

//˫������ڵ��ɾ��
int double_list_delete_node(DL *header, int data)
{
	//ȡ�õ�ǰ�ڵ� 
	DL *p = header;
	//�������еĽڵ� 
	while (NULL != p->next)
	{
		p = p->next;
		//�ҵ��˶�ӦҪɾ���������� 
		if (p->data == data)
		{
			//һ�������������
			//(1)��ǰ�ڵ����һ���ڵ㲻Ϊ��
			if (p->next != NULL)
			{
				//�ǾͰѵ�ǰ�ڵ��prev�ڵ�ָ��Ҫɾ��������ڵ��prev
				//��Ϊ��ǰ��prev�ڵ㱣�����Ҫɾ������һ���ڵ��ָ�� 
				p->next->prev = p->prev;
				//��Ҫָ������next�ڵ� 
				p->prev->next = p->next;
				free(p);
			}
			//(2)��ǰ�ڵ����һ���ڵ�Ϊ�� 
			else
			{
				//�� 
				p->prev->next = NULL;
				free(p);
			}
			return 0;
		}
	}
	printf("\nû���ҵ���ӦҪɾ���Ľڵ㣬���߽ڵ��Ѿ���ɾ����\n");
	return -1;
}

int main333333333333(void)
{
	int i;
	DL *header = create_dl_node(0);
	for (i = 0; i < 10; i++)
	{
		//˫�������β�� 
		//double_list_tail_insert(header,create_dl_node(i));
		//˫�������ͷ�� 
		double_list_top_insert(header, create_dl_node(i));
	}
	//˫�������������� 
	printf("˫��������������:");
	double_list_delete_node(header, 5);
	double_list_for_each(header);
	//	double_list_delete_node(header,9);
	double_list_delete_node(header, 5);
	putchar('\n');
	printf("˫������ķ������:");
	double_list_for_each_nx(header);

	system("Pause");
	return 0;
}



////////////�Լ��ĳ���//////////////////
/*
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<iostream>
using namespace std;

typedef struct double_list
{
	int data;
	struct double_list *prev;
	struct dpuble_list *next;
} DL;


DL *creat_dl_node(int data)
{
	DL *p =(DL *) malloc(sizeof(DL));
	if (NULL == p)
	{
		cout << "creat dl node fair" << endl;
	}
	p->data = data;
	p->next = NULL;
	p->prev = NULL;
}
 
//˫�������β��
void double_list_tail_insert(DL *header, DL *new1)
{
	//ȡ�õ�ǰ���׵�ַ
	DL *p = header;
	//�ҵ�β�ڵ�
	while (p->next != NULL)
	{
		p = p->next;
	}
	p->next = new1;
	new1->prev = p;
	//free(p);
}


//˫�������ͷ��
void double_list_top_insert(DL*header, DL *new1)
{
	new1->next = header->next;

	//�жϵ�ǰ�ڵ����һ���ڵ��ַ�Ƿ�Ϊ��
	if (NULL != header->next)
		header->next->prev = new1;//ԭ�ڵ�ָ�������Ľڵ�
	header->next = new1;
	new1->prev = header;
}

//˫��������������
void double_list_for_each(DL *header)
{
	DL *p = header;
	while (p->next != NULL)
	{
		p = p->next;
		cout << p->data << endl;
	}
}
//˫������ķ������
void double_list_for_each_nx(DL *header)
{
	DL *p = header;
	while (p->next != NULL)
	{
		p = p->next;
	}
	while (p->prev != NULL)
	{
		cout << p->data << endl;
		p = p->prev;

	}
}

//˫��������ɾ����ǰ�Ľڵ�
int double_list_delete_node(DL *header, int data)
{
	DL *p = header;
	while (NULL != p->next)
	{
		p = p->next;
		if (p->data = data)
		{

			//�����ǰ���Ϊ���һ���ڵ�
			if (p->next == NULL)
			{
				p->prev->next = NULL;
			}
			//r�����ǰ�ڵ㲻Ϊ���һ���ڵ�
			else
			{
				p->prev->next = p->next;
				p->next->prev = p->prev;
				free(p);
			}

			return 0;
		}
	}
	cout << "û��Ҫɾ���Ľڵ�"<<endl;
	return -1;
}
int main()
{
	DL *header = creat_dl_node(0);
	for (int i; i < 10; i++)
	{
		//double_list_tail_insert(header, creat_dl_node(i));
		double_list_top_insert(header, creat_dl_node(i));
	}
	cout << "˫��������������" << endl;
		double_list_for_each(header);
	cout << "˫������ķ������" << endl;
	double_list_for_each_nx(header);
	cout << "ɾ���ڵ�5" << endl;
	double_list_delete_node(header,5);
	double_list_for_each(header);

}
*/
////////////�Լ��ĳ���//////////////////