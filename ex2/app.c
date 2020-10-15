#include"head.h"
int main(){
	char loc[20];
	FILE *f1,*f2,*f3,*f4,*f5;
	opnode temp;
	char li[30],la[20],ma[20],oa[20];
	int start_ad=0;
	f1=fopen("alp.txt","r");
	f3=fopen("output.txt","w+");
	f4=fopen("outop.txt","w");
	f5=fopen("outsym.txt","w");
	fscanf(f1,"%s",li);
	char *ptr=strtok(li,"#");
	int flag=0;
	while(ptr!=NULL){
		if(flag==0){
			strcpy(la,ptr);
			flag++;
		}
		else if(flag==1){
			strcpy(ma,ptr);
			flag++;
		}
		else if(flag==2){
			strcpy(oa,ptr);
		}
		else{
			printf("1st line over\n");
		}
		ptr=strtok(NULL,"#");
	}
	printf("hi\n");
	if(strcmp("START",ma)==0){
		if(strcmp("1000",oa)==0)
			start_ad=1000;
			strcpy(loc,"1000");
	}
	else{
		start_ad=0;
		strcpy(loc,"0000");
	}
	printf("Assigned\n");
	printf("Loc Start : %s\n",loc);
        int n,i=0,f=0;
	opnode final[10];
	final[0]=token();
	printf("%s %s %s\n",final[0].label,final[0].mne,final[0].op);
        fprintf(f3,"%s %s %s %s\n",loc,final[0].label,final[0].mne,final[0].op);
        if (strcmp(final[0].label,"")!=0){
        	fprintf(f5,"%s %s\n",loc,final[0].label);
        }
	fremove();
	i++;
	while(strcmp(final[i-1].mne,"END")!=0){
		final[i]=token();
		printf("%s %s %s\n",final[i].label,final[i].mne,final[i].op);
		char *temp_loc=cal_loc(final[i].op,final[i].mne,loc);
                strcpy(loc,temp_loc);
                
		fprintf(f3,"%s %s %s %s\n",loc,final[i].label,final[i].mne,final[i].op);

                if(strcmp(final[i].mne,"START")!=0 && strcmp(final[i].mne,"END")!=0 && strcmp(final[i].mne,"WORD")!=0 && strcmp(final[i].mne,"BYTE")!=0 && strcmp(final[i].mne,"RESW")!=0 &&strcmp(final[i].mne,"RESB")!=0){
                        int temp_mne=mne_value(final[i].mne);
                        fprintf(f4,"%s %d\n",final[i].mne,temp_mne);
                }

                if (strcmp(final[i].label,"")!=0){
                        fprintf(f5,"%s %s\n",loc,final[i].label);
                }
		fremove();
		i++;
	}
		
	fclose(f1);
	fclose(f3);
	fclose(f4);
	fclose(f5);
}	
