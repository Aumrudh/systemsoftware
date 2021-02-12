#include<stdio.h>
#include<stdlib.h>
#include<string.h>
typedef struct node{
	char symbol[20];
	int length;
	struct node *next;
}hashtable;
struct hash{
	struct node *head;
};

struct hash *array;
//typedef hashtable ptrtonode*;
//typedef ptrtonode postion;

int insert(hashtable,hashtable *);
hashtable* findprev(char[],hashtable *);
hashtable* find(char[],hashtable *);
void display(hashtable *);
int modify(hashtable,hashtable *);
int del(char[],hashtable*);
void dis();
