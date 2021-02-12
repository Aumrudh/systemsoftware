#include <stdio.h>
#include <stdlib.h>
#include <string.h>
void copyFile(char file1[],char file2[]){
	char row[100];
	FILE *f1 = fopen(file1,"r");
	FILE *f2 = fopen(file2,"w");
	while(fscanf(f1,"%s",row) == 1)
		fprintf(f2,"%s\n",row);
	fclose(f1);
	fclose(f2);
}

int isOpe(char line[]){
	char op[] = {"+-*/=%"};
	int i,j;
	for(i=0;i<strlen(line);i++)
		for(j=0;j<strlen(op);j++)
			if(op[j] == line[i])
				return 1;
	return 0;
}


char isLeGr(char line[]){
	int i,j;
	char op[] = {"><"};
	for(i=0;i<strlen(line);i++)
		for(j=0;j<strlen(op);j++)
			if(op[j] == line[i])
				return line[i];
	return '\0';
}

int findadd(int line,int addr){
        FILE *f1 = fopen("temp.txt","r");
        int lin=1;
        char l[25]={0};
        while(fgets(l,25,f1) != NULL){
                if(isOpe(l))
                        addr += 2;
                else if(isLeGr(l))
                        addr++;
                if(line <= lin)
                        if(!strcmp(l,"}\n"))
                                return addr;
                lin++;
        }
        fclose(f1);
}

void insOperator(int addr,char line[],int tcnt,FILE *f2){
	char lhs[5],rhs[5];
	strcpy(lhs,strtok(line,"="));
	strcpy(rhs,strtok(NULL,"="));
	fprintf(f2,"%d\ttemp%d = %s",addr,tcnt,rhs);
	fprintf(f2,"%d\t%s = temp%d\n",++addr,lhs,tcnt);
}



void insCondition(int addr,char line[],int lin,char rel,FILE *f2,int s){
	char key[5],cond[5];
	int jaddr,i;
	strcpy(key,strtok(line,"("));
	strcpy(cond,strtok(NULL,")"));
	if(rel == '>'){
		for(i=0;i<strlen(cond);i++)
			if(cond[i] == '>'){
				cond[i] = '<';
				break;
			}
	}else{
		for(i=0;i<strlen(cond);i++)
			if(cond[i] == '<'){
				cond[i] = '>';
				break;
			}
	}
	jaddr = findadd(lin,s);
	fprintf(f2,"%d\t%s %s goto %d\n",addr,key,cond,jaddr);
}

int main(){
	int i,j,tcnt=0,linno=1;
	int lineaddr,strt;
	char line[25]={0},c;
	printf("Enter the Starting Line Address : ");
	scanf("%d",&lineaddr); 
	strt = lineaddr;
	FILE *f1 = fopen("pgm.txt","r");
	copyFile("pgm.txt","temp.txt");
	FILE *f2 = fopen("tac.txt","w");
	while(fgets(line,25,f1) != NULL){
		if(isOpe(line)){
			insOperator(lineaddr,line,tcnt++,f2);
			lineaddr += 2;
		}else if((c = isLeGr(line)) != '\0'){
			insCondition(lineaddr,line,linno,c,f2,strt);
			lineaddr ++;
		}
		linno++;
	}
	fclose(f1);
	fclose(f2);
	remove("temp.txt");
	FILE *fptr=fopen("tac.txt","r");
	c = fgetc(fptr); 
	while (c != EOF){ 
       		printf ("%c", c); 
        	c = fgetc(fptr); 
    	}	 
    	fclose(fptr); 
}


