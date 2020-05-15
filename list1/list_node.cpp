#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<iostream>
#include<stack>
using namespace std;
typedef struct list_node
{
	int data;
	struct list_node *next;
}list_single;
/*
int main(void)
{
	list_single *node = NULL;
	node = (list_single *)malloc(sizeof(list_single));
	if (node == NULL) {
		printf("malloc fair!\n");

	}
	memset(node, 0, sizeof(list_single));
	node->data = 100;
	node->next = NULL;
	cout << node->data<<endl;
	free(node);
	system("Pause");
	return 0;
}
*/



/*为了方便我们把创建一个节点封装成一个函数*/

list_single *creat_list_node(int data)
{
	list_single *node = NULL;
	node = (list_single *)malloc(sizeof(list_single));
	if (node == NULL) {
		printf("malloc fair!\n");

	}
	memset(node, 0, sizeof(list_single));
	node->data = data;
	node->next = NULL;
	return node;
}

/*链表的尾插*/
void tail_insret(list_single *pH,list_single *new1)

{
	//获取当前的位置
	list_single *p = pH;
	while (NULL != p->next)
	{
		p = p->next;
	}
	p->next = new1;
}


/*链表的头插*/
void top_insert(list_single *pH, list_single *new1)
{
	list_single *p = pH;
	new1->next = p->next;
	p->next = new1;
}



/*打印链表*/
void Print_node(list_single *pH)
{
	list_single *p = pH;
	p = p->next;
	while (NULL != p->next)
	{
		cout << p->data<<endl;
		p = p->next;
	}
	cout << p->data << endl;
}

/*删除链表中的节点*/
int detele_list_node(list_single *pH, int data1)
{
	list_single *p = pH;
	list_single *prev = NULL;
	while(NULL != p->next)
	{
		prev = p;
		p = p->next;
		if (p->data == data1)
		{
			if (p->next != NULL)
			{
				prev->next = p->next;
				//Print_node(prev);
				free(p);
			}
			else
			{
				prev->next = NULL;
				//Print_node(prev);
			free(p);
			}


			return 0;
		}

		
	}
	cout << "没有删除的节点" << endl;
	return -1;
}


void fanzhuan(list_single *PH)
{
	list_single *p = PH->next;
	//list_single *p1=p;
	
	PH = PH->next;
	PH->next = NULL;
	p = p->next;
	while (p != NULL)
	{
		p->next = PH->next;
		PH->next = p;
		p = p->next;
	}
	//PH = p1;

}

/*将链表反过来*/
void trave_list(list_single *pH)
{
	//保存第一个节点的位置 
	list_single *p = pH->next;
	list_single *pBack;
	int i = 0;
	if (p->next == NULL || p == NULL)
		return;

	while (NULL != p->next) //遍历链表 
	{
		//保存第一个节点的下一个节点 
		pBack = p->next;
		//找到第一个有效节点,其实就是头指针的下一个节点 
		if (p == pH->next)
		{
			//第一个有效节点就是最后一个节点，所以要指向NULL 
			p->next = NULL;
		}
		else
		{
			/*
			new->next = p->next ;
			p->next = new ;
			*/
			p->next = pH->next; //尾部连接 
		}
		pH->next = p; //头部连接 
		p = pBack; //走下一个节点 
	}
	p->next = pH->next;
	pH->next = p; //头部连接 

}
/*链表反转用堆栈实现*/


list_single * fan(list_single * pHead)
{

	if (pHead == NULL || pHead->next == NULL) {
		return pHead;
	}
	stack<list_single *>stack1;
	list_single *new1 = pHead;
	list_single *new2;
	while (new1->next != NULL)
	{
		stack1.push(new1);
		new1 = new1->next;
	}
	new2 = new1;
	while (!stack1.empty())
	{
		new1->next = stack1.top();
		stack1.pop();
		new1 = new1->next;
	}
	new1->next = NULL;
		return new2;
}


int main()
{
	int data = 0;
	list_single *header = creat_list_node(data);
	list_single *header1 = header;
	cout << "header->data=" << header->data << endl;
	cout << "header->next=" << header->next << endl;
	for (int i = 0; i < 10; i++)
	{
		tail_insret(header, creat_list_node(i));
	}
	Print_node(header);
	cout << "尾插尾比"<<endl;

	top_insert(header, creat_list_node(5));
	Print_node(header);
	cout << endl;
	cout << "头插尾比" << endl;
	//删除节点
	detele_list_node(header, 5);
	Print_node(header);
	cout << endl;

	cout << "逆序" << endl;
	trave_list(header1);
	Print_node(header1);
	cout << endl;

	fan(header1);
	cout << "反转111" << endl;
	//fanzhuan(header1);
	Print_node(header1);
	cout << endl;


	cout << "反转" << endl;
	fanzhuan(header1);
	Print_node(header1);
	cout << endl;
	free(header);
	system("Pause");
	return 0;
}