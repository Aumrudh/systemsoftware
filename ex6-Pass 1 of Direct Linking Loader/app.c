#include "head.h"

main(int argc, char *argv[])
{
  int i;
  char pgmaddr[5],csaddr[5];
  printf("Enter the program address\n");
  scanf("%s",pgmaddr);
  strcpy(csaddr,pgmaddr);
  i=2;
  fp1=fopen(argv[1],"w");
  fclose(fp1);
  while(i<argc)
  {
    externalSymbolTableGeneration(argv[i],argv[1],csaddr);
    i++;
  }
  displayTable(argv[1]);
}
