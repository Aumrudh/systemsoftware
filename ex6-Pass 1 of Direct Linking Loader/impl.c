#include "head.h"

void externalSymbolTableGeneration(char fname[],char fname1[], char csaddr[])
{
  ESTAB es;
  int i,len,j;
  int add,csadd;
  char temp[100];
  char address[7],csname[10],length[5],sname[10],c,rtype[2];
  fp1=fopen(fname,"r");
  fp2=fopen(fname1,"a");
  while(!feof(fp1))
  {
    fscanf(fp1,"%[^\n]",temp);
    c=fgetc(fp1);
    if(feof(fp1)) break;
    len=strlen(temp);
    rtype[0]=temp[0];
    rtype[1]='\0';
    if(strcmp(rtype,"H")==0)
    {
      i=2;
      j=0;
      while(temp[i]!='^'&&i<len)
      {
        csname[j]=temp[i];
        i++;
        j++;
      }
      csname[j]='\0';
      i=i+1;
      j=0;
      while(temp[i]!='^'&&i<len)
      {
        address[j]=temp[i];
        i++;
        j++;
      }
      address[j]='\0';
      i=i+1;
      j=0;
      while(i<len)
      {
        length[j]=temp[i];
        i++;
        j++;
      }
      length[j]='\0';
      strcpy(es.csname,csname);
      strcpy(es.symname,"\0");
      strcpy(es.length,length);
      sscanf(csaddr,"%04x",&csadd);
      sscanf(address,"%06x",&add);
      add=add+csadd;
      sprintf(address,"%04X",add);
      strcpy(es.address,address);
      strcpy(temp,"\0");
      fwrite(&es,sizeof(es),1,fp2);
    }
    if(strcmp(rtype,"D")==0)
    {
      i=2;
      j=0;
      while(temp[i]!='^'&&i<len)
      {
        sname[j]=temp[i];
        i++;
        j++;
      }
      sname[j]='\0';
      i=i+1;
      j=0;
      while(i<len)
      {
        address[j]=temp[i];
        j++;
        i++;
      }
      address[j]='\0';
      strcpy(es.csname,"\0");
      strcpy(es.length,"\0");
      strcpy(es.symname,sname);
      sscanf(csaddr,"%04x",&csadd);
      sscanf(address,"%06x",&add);
      add=add+csadd;
      sprintf(address,"%04X",add);
      strcpy(es.address,address);
      strcpy(temp,"\0");
      fwrite(&es,sizeof(es),1,fp2);
    } 
  }
  sscanf(csaddr,"%04x",&csadd);
  sscanf(length,"%04x",&add);
  csadd=csadd+add;
  sprintf(csaddr,"%04x",csadd);
  fclose(fp1);
  fclose(fp2);
}

void displayTable (char fname[])
{
  ESTAB es;
  fp1=fopen(fname,"r");
  printf("\nControlSection\tSymname\tAddress\tLength\n");
  while(!feof(fp1))
  {
    fread(&es,sizeof(es),1,fp1);
    if(feof(fp1)) break;
    printf("\n%s\t\t%s\t%s\t%s\n",es.csname,es.symname,es.address,es.length);
  }
  fclose(fp1);
}
