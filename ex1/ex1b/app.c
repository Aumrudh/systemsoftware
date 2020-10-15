#include "head.h"

int main(){
        int ch;
	printf("\n1-Insert\n2-Search\n3-Modify\n4-Delete\n5-Display\n6-Exit\n");
	while(1){
		printf("Enter Your Choice : ");
		scanf("%d",&ch);
		switch(ch){
			case 1: if(insert()){
                                        printf("\nSuccessfully inserted the Symbol\n");
                                }
                                else{
                                        printf("Insertion failed\n");
                                }
                                break;
                        
			case 2: printf("Enter a Symbol to Search : ");
                                char temp[10];
                                scanf("%s",temp);
                                display(search(temp));
                                break;
			case 3: 
                                if(modify())
                                        printf("\nModification Successfull\n");
                                else
                                        printf("\nModification failed\n");
                                break;
			case 4: 
                                if(deletee())
                                        printf("\nSymbol deleted successfully\n");
                                else
                                        printf("\nFailed to delete...\n");
                                break;
			case 5: 
                                displayall();
                                break;
                        case 6:
                                exit(0);
                        default:
                                printf("Enter valid options\n");
		}
	}
}
