#include "head.h"

void openAndClose(){
	FILE *f1 = fopen("op.txt","w");	
	FILE *f2 = fopen("spl.txt","w");
	FILE *f3 = fopen("var.txt","w");	
	FILE *f4 = fopen("key.txt","w");
	FILE *f5 = fopen("acc.txt","w");
	fclose(f1);	
	fclose(f2);
	fclose(f3);	
	fclose(f4);	
	fclose(f5);
}

int isOperator(char c){
	int i;
	char op[] = {"+-*/=><"};
	for(i=0;i<strlen(op);i++)
		if(op[i] == c)
			return 1;
	return 0;
}

int isSpclChar(char c){
	int i;
	char op[] = {"{};,[].()''"""};
	for(i=0;i<strlen(op);i++)
		if(op[i] == c)
			return 1;
	return 0;
}

void insert(char file[],char key){
	FILE *f = fopen(file,"a+");
	fprintf(f,"%c\n",key);
	fclose(f);
}

void insspeci(char file[],char s){
	char key[3] = {0};
	key[0] = '%';	key[1] = s;	key[2] = '\0';
	FILE *f = fopen(file,"a+");
	fprintf(f,"%s\n",key);
	fclose(f);
}

void insKeyVar(char key[]){
	int i;
	char keywrd[][15] = {"printf","scanf","int","void","main","char","float","include","stdio.h"};
	char file[25]={0};
	int flg = 1;
	for(i=0;i<9;i++)
		if(!strcmp(keywrd[i],key))
			flg = 0;
	if(flg)
		strcpy(file,"var.txt");
	else
		strcpy(file,"key.txt");
	if(!search(file,key)){
		FILE *f = fopen(file,"a+");
		fprintf(f,"%s\n",key);
		fclose(f);
	}
	strcpy(key,"\0");
}

int search(char file[],char s[]){
	char a[10] = {0};
	FILE *f = fopen(file,"r");
	while(fscanf(f,"%s",a) == 1)
		if(!strcmp(a,s)){
			fclose(f);
			return 1;
		}
	fclose(f);
	return 0;
}

