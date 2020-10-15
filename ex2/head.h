#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>
typedef struct opnode{
	char label[20];
	char mne[20];
	char op[20];
}opnode;


opnode token();
char* cal_loc(char[],char[],char*);
int mne_value(char[]);
void fremove();
