#include <stdio.h>
#include <string.h>
#include <stdlib.h>

FILE *fp2,*fp1;

typedef struct InputRec
{
  char label[10];
  char opcode[10];
  char opr1[10];
  char opr2[10];
  char address[5];
}InputRec;

typedef struct Symtab
{
  char name[10];
  char type[2];
  char address[5];
}
Symtab;

typedef struct OutRec
{
  char label[10];
  char opcode[10];
  char opr1[10];
  char opr2[10];
  char address[5];
  char machinecode[7];
}OutRec;

typedef struct Optab
{
  char opcode[10];
  char machinecode[3];
}Optab;

typedef struct HeadRec
{
  char pgmname[10];
  char address[5];
  char pgmlength[3];
}HeadRec;

typedef struct TextRec
{
  char startaddress[5];
  char length[3];
  char objcode[7];
}TextRec;

void objectCodeGeneration(char[],char[],Symtab[],Optab[],int,int);
void objectProgramGeneration(char[],char[]);
Optab searchOptab(char[],Optab[],int);
Symtab searchSymtab(char[],Symtab[],int);
void display(char[]);
char findACII(char);


