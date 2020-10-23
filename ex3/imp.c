#include "head.h"

void objectCodeGeneration(char fname[],char fname1[],Symtab sys[],Optab opt[],int syscount,int opcount)
{
  int len=0, j=0,i;
  char value[10],temp[3],ch;
  fp1=fopen(fname,"r");
  fp2=fopen(fname1,"w");
  OutRec out;
  Optab o;
  Symtab s;
  InputRec in;
  while(!feof(fp1))
  {
    fread(&in,sizeof(in),1,fp1);
    if(strcmp(in.opcode,"START")==0||strcmp(in.opcode,"END")==0||
				strcmp(in.opcode,"RESB")==0||strcmp(in.opcode,"RESW")==0||
				strcmp(in.opcode,"EQU")==0)
    {
      strcpy(out.machinecode,"\0");
    }
    else if(strcmp(in.opcode,"BYTE")==0)
    {
      if(in.opr1[0]=='X')
      {
        len=strlen(in.opr1);
        j=0;
        for(i=2;i<len-1;i++)
        {
          out.machinecode[j]=in.opr1[i];
          j++;
        }
        out.machinecode[j]='\0';
      }
      else if(in.opr1[0]=='C')
      {
        j=2;
        len=strlen(in.opr1);
        for(i=0;i<len-3;i++)
        {
          value[i]=in.opr1[j];
          j++;
        }
        value[i]='\0';
        len=strlen(value);
        strcpy(out.machinecode,"\0");//initilize to get rid of garbage value
        i=0;
        while(i<len)
        {
           sprintf(temp,"%02x",value[i]);
           i++;
           strcat(out.machinecode,temp);
        } 
      }
    }
    else if(strcmp(in.opcode,"WORD")==0)
    {
      strcpy(out.machinecode,"000000");
      len=strlen(in.opr1);
      j=6-len;
      for(i=0;i<len;i++)
      {
        out.machinecode[j]=in.opr1[i];
        j++;
      }
      out.machinecode[6]='\0';
    }
    else
    {
      o=searchOptab(in.opcode,opt,opcount);
      if(strcmp(in.opr1,"\0")!=0)
      {
        s=searchSymtab(in.opr1,sys,syscount);
        if(strcmp(in.opr2,"X")==0)
        { 
          ch=s.address[0];
          if(ch=='0')
            s.address[0]='8';
          else if (ch=='1')
            s.address[0]='9';
          else if (ch=='2')
            s.address[0]='a';
          else if (ch=='3')
            s.address[0]='b';
          else if (ch=='4')
            s.address[0]='c';
          else if (ch=='5')
            s.address[0]='d';
          else if (ch=='6')
            s.address[0]='e';
          else if (ch=='7')
            s.address[0]='f';
        }
        strcpy(out.machinecode,o.machinecode);
        strcat(out.machinecode,s.address);
      }
    }
    strcpy(out.address,in.address);
    strcpy(out.label,in.label);
    strcpy(out.opcode,in.opcode);
    strcpy(out.opr1,in.opr1);
    strcpy(out.opr2,in.opr2);
    fwrite(&out,sizeof(out),1,fp2);
  }
  fclose(fp1);
  fclose(fp2);
  printf("\nFile with machinecode\n\n");
  display(fname1);
}

void objectProgramGeneration(char fname[],char fname1[])
{
  int count=0,first,las,pl,len;
  char last[10];
  HeadRec h;
  OutRec out;
  TextRec t;
  fp1=fopen(fname,"r");
  fp2=fopen(fname1,"w");
  while(!feof(fp1))
  {
    fread(&out,sizeof(out),1,fp1);
    if(strcmp(out.opcode,"END")==0)
      strcpy(last,out.address);
  }
  fclose(fp1);
  fp1=fopen(fname,"r");
  sscanf(last,"%04x",&las);
  fread(&out,sizeof(out),1,fp1);
  strcpy(h.pgmname,out.label);
  strcpy(h.address,out.address);
  sscanf(h.address,"%2x",&first);
  pl=las-first;
  sprintf(h.pgmlength,"%2x",pl);
  if(strcmp(h.pgmname,"\0")!=0)
    fprintf(fp2,"H^%s^%s^%s\n",h.pgmname,h.address,h.pgmlength);
  else
    fprintf(fp2,"H^  ^%s^%s\n",h.address,h.pgmlength);
  fp1=fopen(fname,"r");
  while(!feof(fp1))
  {
    fread(&out,sizeof(out),1,fp1);
    if(feof(fp1)) break;
    if(strcmp(out.machinecode,"\0")!=0)
    {
      strcpy(t.startaddress,out.address);
      len=strlen(out.machinecode);
      len=len/2;
      sprintf(t.length,"%02x",len);
      strcpy(t.objcode,out.machinecode);
      fprintf(fp2,"T^%s^%s^%s\n",t.startaddress,t.length,t.objcode);
    }
  }
  fclose(fp1);
  fprintf(fp2,"E^%s\n",h.address);
  fclose(fp2);
}
Optab searchOptab(char name[],Optab opt[], int opcount)
{
  int i;
  Optab o;
  for(i=0;i<opcount;i++)
  {
    if(strcmp(opt[i].opcode,name)==0)
    {
      o=opt[i];
      return o;
    }
  }
  strcpy(o.opcode,"\0");
  return o;
}
Symtab searchSymtab(char name[], Symtab sys[], int syscount)
{
  int i=0;
  Symtab s;
  for(i=0;i<syscount;i++)
  {
    if(strcmp(sys[i].name,name)==0)
    {
      s=sys[i];
      return s;
    }
  }
  strcpy(s.name,"\0");
  return s;
}
void display(char fname[])
{
  OutRec out;
  fp1=fopen(fname,"r");
  while(!feof(fp1))
  {
    fread(&out,sizeof(out),1,fp1);
    if(feof(fp1)) break;
    printf("%s\t%s\t%s\t%s\t%s\t%s\n",out.address,out.label,out.opcode,out.opr1,out.opr2,out.machinecode);
  }
  fclose(fp1);
}

