#include"head.h"

int insert(hashtable h,hashtable *start){
        hashtable *temp;
        temp=(hashtable*)malloc(sizeof(hashtable));
        if(temp==NULL){
                printf("Memory not allocated\n");
                return 0;
        }
        strcpy(temp->symbol,h.symbol);
        temp->length=h.length;
        hashtable *p=findprev(temp->symbol,start);
        temp->next=p->next;
        p->next=temp;
        return 1;
}
hashtable* findprev(char tempsymbol[],hashtable *start){
        hashtable *temp=start->next;
        hashtable *prev=start;
        while(temp!=NULL){
                if(strcmp(temp->symbol,tempsymbol)>0)
                        return prev;
                prev =temp;
                temp=temp->next;
        }
        return prev;
}
hashtable* find(char tempsymbol[],hashtable *start){
        hashtable *temp=start->next;
        while(temp!=NULL){
                if(strcmp(temp->symbol,tempsymbol)==0)
                        return temp;
                temp=temp->next;
        }
        return NULL;
}
void display(hashtable *p){
	if(p == NULL)
		printf("\nnot found\n");
	else
		printf("\t%s\t%d\n",p->symbol,p->length);
}
int modify(hashtable h,hashtable *start){
	hashtable *temp=start->next;
	if((temp=find(h.symbol,start))==NULL)
		return 0;
	temp->length=h.length;
	return 1;
}
int del(char tempsymbol[] , hashtable *start){
	hashtable *temp=start->next;
	hashtable *prev=start;
	if(find(tempsymbol,start)==NULL)
		return 0;
	while(temp!=NULL){
		if(strcmp(temp->symbol,tempsymbol)==0)
			break;
		prev=temp;
		temp=temp->next;
	}
	prev->next=temp->next;
	free(temp);
	return 1;
}
void dis(){
  printf("inside dis\n");	
  int i;
  for (i = 0; i <26;i++){
    hashtable *temp= array[i].head;
    printf("inside for");
    if (temp == NULL){
      printf("no value\n");
    }
    else{
    	while (temp != NULL){
        	printf("%s   %d\n",temp->symbol, temp->length);
        	temp = temp->next;
      	}
        printf("\n\n\n");
    }
  }
}
