#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int top = -1,l=0,m,n;
char stack[20]={0};

struct table{
	char col;
	char row;
	char value[10];
};
typedef struct table table;
table *tab;

void push(char c){
	if(top < 20)
		stack[++top] = c;
}

char pop(){
	if(top != -1)
		stack[top--] = '\0';
}

void getAction(char r, char c){
	int i,j,k,f;
	char pro[10]={0},buf[10]={0};
	for(i=0,k=0;i<n;i++)
		for(j=0;j<m;j++){
			if((tab[k].col == c) && (tab[k].row == r))
				if(strcmp(tab[k].value,"-")){
					strcpy(buf,tab[k].value);	strtok(buf,"->");
					strcpy(pro,strtok(NULL,"->"));
					pop();
					if(pro[0] != 'e')
						for(f=strlen(pro)-1;f>=0;f--)
							push(pro[f]);
					return;
				}
			k++;
		}
	printf("\n> The input string not accepted...\n\n");
	exit(1);
}

void display(char inp[]){
	int i = 0;
	if(top != -1){
		printf("\n> %s\t\t",stack);
		for(i=l;i<strlen(inp);i++)
		printf("%c",inp[i]);
		printf("\n");
	}
}

int main(){
	int len,i,j,k;
	char input[10]={0},ter[10],var[10];

	printf("\n> Enter the Terminals:\t");
	scanf("%s",ter);
	printf("\n> Enter the Variables:\t");
	scanf("%s",var);

	m = strlen(ter);	n = strlen(var);

	tab = (table*) malloc (sizeof(table) * (m + n));
	if(tab == NULL){
		printf("\n> Error in creating the Table...\n");
		exit(1);
	}
	printf("\n> Enter the Input Table:\n\n");
	for(i=0;i<m;i++)
		printf("\t%c",ter[i]);
	printf("\n");
	for(i=0,k=0;i<n;i++){
		printf("\n%c\t",var[i]);
		for(j=0;j<m;j++){
			tab[k].col = ter[j];
			tab[k].row = var[i];
			scanf("%s",tab[k].value);
			k++;
		}
	}
	printf("\n> Enter the input string:\t");
	scanf("%s",input);

	push('$');	push(var[0]);	display(input);

	for(l=0;l<strlen(input);){
		if(input[l] == stack[top]){
			pop();	l++;
		}else{
			getAction(stack[top],input[l]);
		}
		display(input);
	}
	printf("\n> The given string is accepted...\n\n");
}
