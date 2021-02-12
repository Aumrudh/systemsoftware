#include "head.h"

main(int argc,char* argv[])
{
  int opcount=0,syscount=0, i=0,len;
  char opcode[10],mc[3];
  Symtab sys[20];
  Optab opt[20];
  fp1=fopen(argv[1],"r");
  while(!feof(fp1))
  {
    fscanf(fp1,"%s%s%s",sys[syscount].name,sys[syscount].address,sys[syscount].type);
    if(feof(fp1)) break;
    syscount++;
  }
  fclose(fp1);
  printf("Symbol table\n\n");
  for(i=0;i<syscount;i++)
  {
    printf("%s\t%s\t%s\n",sys[i].name,sys[i].address,sys[i].type);
  }
  printf("\nOptab table\n\n");
  fp1=fopen(argv[2],"r");
  while(!feof(fp1))
  {
    fscanf(fp1,"%s %s",opcode,mc);
    if(feof(fp1)) break;
    strcpy(opt[opcount].opcode,opcode);
    strcpy(opt[opcount].machinecode,mc);
    opcount++;
  }
  fclose(fp1);
  for(i=0;i<opcount;i++)
  {
    printf("%s\t%s\n",opt[i].opcode,opt[i].machinecode);
  }
  objectCodeGeneration(argv[3],argv[4],sys,opt,syscount,opcount);
  objectProgramGeneration(argv[4],argv[5]);
}
