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
        hastable *p=findprev(temp.symbol,start);
        temp->next=p->next;
        p->next=temp;
        return 1;
}
position findprev(char tempsymbol[],hashtable *start){
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
position find(char tempsymbol[],hashtable *start){
        hashtable *temp=head->next;
        while(temp!=NULL){
                if(strcmp(temp->symbol,tempsymbol)==0)
                        return temp;
                temp=temp->next;
        }
        return NULL;
}
void display(hashtable *p){
	if(p == NULL)
		printf("\nThe Searched symbol is Not present...\n");
	else
		printf("\t%s\t%d\n",p->sybmpl,p->lengthgth);
}
int modify(hashtbale h,hashtable *start){
	hashtable *temp=start->next;
	if((temp=find(h.symbol,start))==NULL)
		return 0;
	temp->length=h.length;
	return 1;
}
int delete(char tempsymbol[] , hashtable *start){
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
	free(t);
	return 1;
}
