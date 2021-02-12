#include <stdio.h>
#include <string.h>
#include <stdlib.h>

FILE *fp1, *fp2;

typedef struct ESTAB
{
	char csname[10];
	char address[7];
	char length[5];
	char symname[10];
}ESTAB;

typedef struct Memorymap
{
	char address[5];
	char packed[3];
	char objectcode[3];
}Memorymap;

void loadMemory(char[],char[],ESTAB [],int,char[]);
int pack (char,char);
void display(char[]);
ESTAB searchESTAB(char[],ESTAB[],int);
void displayTable(char[]);
