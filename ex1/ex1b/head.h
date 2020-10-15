#include<stdio.h>
#include<string.h>
#include<stdlib.h>

typedef struct node{
	char sybm[10];
	char type[10];
	int len;
}node;

int insert();
node search(char[]);
void display(node);
int modify();
int deletee();
void displayall();
