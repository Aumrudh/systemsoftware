#include<stdio.h>
#include<string.h>
#include<stdlib.h>
typedef struct node{
	char sybm[10];
	char type[10];
	int len;
}node;
typedef struct opnode{
	char label[20];
	char mne[20];
	char op[20];
}opnode;

//opnode token();
int cal_loc(char[],char[],int);
int mne_value(char[]);
