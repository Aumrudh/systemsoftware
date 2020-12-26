#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int isoper(char c)
{
            char oper[8]= {'+','-','*','/','=','>','<','%'};
            int i;

           for(i=0;i<8;i++)
           {
                if(oper[i] == c)
                        return 1;
           }
           return 0;
}

char *getr(char s[],int ri)
{
	 char *cd   = (char*)malloc(10*sizeof(char));
	 char *rstr = (char*)malloc(10*sizeof(char));
	 strcpy(cd,s);
	 strcat(cd," R[");
         sprintf(rstr,"%d",ri);
         strcat(cd,rstr);
         strcat(cd,"]");
	 return cd;
}

int main()
{
	FILE *fp = fopen("in","r");

	char line[50],tline[10],lines[50][50];

	char code[40][30];int ci=0;

	int ri=0,nl=0,i=0;char *rstr =(char*)malloc(10*sizeof(char));

	char str[10];

	
	while(1)
	{
		fscanf(fp,"%[^\n]%*c",lines[nl]);
		 if(feof(fp)>0)
                        break;
		//printf("\n%s",lines[nl]);
		nl++;	
       	}

	for(i=0;i<nl;i++)
	{	

		if(strlen(lines[i])==3 && lines[i][1]=='=')
		{
		
			strcpy(code[ci],getr("MOV",ri));
			strcat(code[ci],",");
			code[ci][strlen(code[ci])+1]='\0';
			code[ci][strlen(code[ci])]=lines[i][2];
			
			printf("\n%s",code[ci]);
			ci++;
			
			strcpy(code[ci],"");
	
			strcpy(code[ci],"MOV ");
			code[ci][strlen(code[ci])+1]='\0';
			code[ci][strlen(code[ci])]=lines[i][0];
			strcat(code[ci],",R[");
			sprintf(rstr,"%d",ri);
                        strcat(code[ci],rstr);
                        strcat(code[ci],"]");
			
			ri++;

			printf("\n%s",code[ci]);
		}
		
		else if(lines[i][0]=='i' && lines[i][1]=='f')
		{
			strcpy(code[ci],getr("MOV",ri));
			strcat(code[ci],",");
                        code[ci][strlen(code[ci])+1]='\0';
                        code[ci][strlen(code[ci])]=lines[i][3];
			printf("\n%s",code[ci]);
			ci++;ri++;
			
			strcpy(code[ci],getr("MOV",ri));
			strcat(code[ci],",");
                        code[ci][strlen(code[ci])+1]='\0';
                        code[ci][strlen(code[ci])]=lines[i][5];
			printf("\n%s",code[ci]);
			ci++;ri++;

			strcpy(code[ci],getr("SUB",ri));
			strcat(code[ci],",");
                        strcat(code[ci],getr("",ri-2));
			strcat(code[ci],",");
			strcat(code[ci],getr("",ri-1));
			
			printf("\n%s",code[ci]);

			ci++;ri++;

			if(lines[i][4] == '<')
				strcpy(code[ci],"JLTZ");
			else if(lines[i][4] =='>')
				strcpy(code[ci],"JGTZ");

			strcat(code[ci]," ");
			code[ci][strlen(code[ci])+1]='\0';

                        code[ci][strlen(code[ci])]=lines[i][strlen(lines[i])-1];

			printf("\n%s",code[ci]);

			ri++;ci++;
		}
		else
		{
			if(strlen(lines[i])>4)
			{
			strncpy(str,lines[i],4);
			str[4]='\0';
			if(strcmp(str,"goto")==0)
			{
				strcpy(code[ci],"JMP ");
		      		code[ci][strlen(code[ci])+1]='\0';
				code[ci][strlen(code[ci])]=lines[i][strlen(lines[i])-1];
				printf("\n%s",code[ci]);
				ci++;
					
			}
			
			}
			
		}
	}
	printf("\n");
	return 0;
}
