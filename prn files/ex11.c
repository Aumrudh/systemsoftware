#include<stdio.h>
#include<string.h>
#include<ctype.h>
main(){
	int i,p=0;
	FILE *fp;
	fp=fopen("input.txt","r");
	char str[25],c;
	while(fscanf(fp,"%s",str)!=EOF){
		if(strlen(str)==3){
			if(str[1]=='='){
				printf("\nMOV R%d,%c",p,str[2]);
				printf("\nMOV %c,R%d",str[0],p);
				p++;
			}
		}
		for(i=0;i<strlen(str);i++){
			if(str[i]=='+'){
				printf("\nMOV R%d,%c",p,str[2]);
				p++;
				printf("\nMOV R%d,%c",p,str[4]);
				printf("\nADD R%d,R%d",p-1,p);
				printf("\nMOV %c,R%d",str[0],p-1);
				p++;
			}
			if(str[i]=='-'){
				printf("\nMOV R%d,%c",p,str[2]);
				p++;
				printf("\nMOV R%d,%c",p,str[4]);
				printf("\nSUB R%d,R%d",p-1,p);
				printf("\nMOV %c,R%d",str[0],p-1);
				p++;
			}
			if(str[i]=='*'){
				printf("\nMOV R%d,%c",p,str[2]);
				p++;
				printf("\nMOV R%d,%c",p,str[4]);
				printf("\nMUL R%d,R%d",p-1,p);
				printf("\nMOV %c,R%d",str[0],p-1);
				p++;
			}
			if(str[i]=='/'){
				printf("\nMOV R%d,%c",p,str[0]);
				p++;
				printf("\nMOV R%d,%c",p,str[4]);
				printf("\nDIV R%d,R%d",p-1,p);
				printf("\nMOV %c,R%d",str[0],p-1);
				p++;
			}
		}
		for(i=0;i<strlen(str);i++){
			if(str[i]=='<'){
				printf("\nMOV R%d,%c",p,str[i-1]);
				p++;
				printf("\nMOV R%d,%c",p,str[i+1]);
				p++;
				printf("\nSUB R%d,R%d,R%d",p,p-1,p-2);
				p++;
				fscanf(fp,"%s",str);
				if(strcmp(str,"goto")==0){
					fscanf(fp,"%s",str);
					printf("\nJLTZ %s",str);
				}
			}	
		}
		if(strcmp(str,"goto")==0){
			fscanf(fp,"%s",str);
			printf("\nJMP %s",str);
		}
		if(str[1]==':'){
			printf("\n%c%c",str[0],str[1]);
		}
	}
	printf("\nHALT");
	fclose(fp);
}

//input.txt
x=y
m=p+q
if a<b goto M
goto L
M:
i=x
s=a-b
L: