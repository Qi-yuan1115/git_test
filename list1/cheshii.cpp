
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<iostream>
using namespace std;
int main22()
{
char buffer[20];
//memset(buffer, 0, sizeof(char) * 20);
memcpy(buffer, "123", 3);

for (int i = 0; i < 20; i++)
	cout << buffer[i] << endl;


//////////////////测试menset的作用///////////////////
	char buffer1[20];
	//memset(buffer, 0, sizeof(char) * 20);
	memcpy(buffer1, "123", 3);

	for (int i = 0; i < 20; i++)
		cout << buffer1[i] << endl;
///////////////测试数组超过限制/////////////

	char buffer2[10];
	//memset(buffer, 0, sizeof(char) * 20);
	memcpy(buffer2, "1231111", 10);

	for (int i = 0; i < 10; i++)
		cout << buffer2[i] << endl;

system("Pause");

return 0;
}