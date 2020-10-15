#include "head.h"

int main(){
	int ch,i;
	char tsymb[10];
	struct hash h[25];
	hashtable temp;
	for(i=0;i<25;i++){
		hashtable *temp;
		temp=(hashtable*)malloc(sizeof(hashtable));
		if(temp==NULL){
			printf("Hash table not created\n");
			exit(0);
		}
		temp->next=NULL;
		strcpy(temp->symbol,"\0");
		h[i].head=temp;
	}
	while(1){
		printf("\n1-Insert\n2-Find\n3-Modify\n4-Delete\n5-Exit");
		printf("\nEnter Your Choice:\t");
		scanf("%d",&ch);
		switch(ch){
			case 1: printf("Enter the Symbol : ");
                                scanf("%s",temp.sybmol);
                                printf("Enter the Length : ");
                                scanf("%d",&temp.length);
                                if(insert(ele,h[temp.symbol[0]%65].head))
                                        printf("inserted\n");
                                else
                                        printf("\ninsertion failed\n");
                                break;
			case 2: printf("Enter symbol : ");
                                scanf("%s",tsymb);
                                i = toupper(symbl[0]);
                                display(find(h[i%65].start,symbl));
                                break;
			case 3: printf("Enter Symbol : ");
                                scanf("%s",temp.sybmol);
                                printf("Enter the new Length : ");
                                scanf("%d",&temp.length);
                                if(modify(ele,h[temp.symbol[0]%65].head))
                                        printf("modified\n");
                                else
                                        printf("modification failed\n");
                                break;
			case 4: printf("\nEnter a Symbol to Delete:\t");
                                scanf("%s",tsymb);
                                if(delete(h[tsymb[0]%65].start,symbl))
                                        printf("Deleted\n");
                                else
                                        printf("deletion failed");
                                break;
			case 5: exit(1);
		}
	}
}
