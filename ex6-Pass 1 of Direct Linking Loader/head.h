#include <stdio.h>
#include <string.h>
#include <stdio.h>

FILE *fp1, *fp2;

typedef struct ESTAB
{
  char csname[10];
  char address[7];
  char length[5];
  char symname[10];
}ESTAB;

void externalSymbolTableGeneration(char[],char [],char[]);
void displayTable(char []);
