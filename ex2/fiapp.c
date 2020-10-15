#include"head.h"
int main(){
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
		//ptr=strtok(NULL,"#");
		if(flag==0){
			strcpy(la,ptr);
			flag++;
			//printf("%s",ptr);
		}
		else if(flag==1){
			strcpy(ma,ptr);
			//printf("%s",ptr);
			flag++;
		}
		else if(flag==2){
			strcpy(oa,ptr);
			//printf("%s",ptr);
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
		//printf("Start\n");
	}
	else{
		start_ad=0;
	}
	printf("Assigned\n");
	int loc=start_ad;
	printf("Loc Start : %d\n",loc);
        int n,i=0,f=0;
	opnode final[10];
	final[0]=token();
	printf("%s %s %s\n",final[0].label,final[0].mne,final[0].op);
        fprintf(f3,"%d %s %s %s\n",loc,final[0].label,final[0].mne,final[0].op);
        if (strcmp(final[0].label,"")!=0){
        	fprintf(f5,"%d %s\n",loc,final[0].label);
        }
	fremove();
	i++;
	/*final[i]1=token();
	printf("%s %s %s\n",final[i]1.label,final1.mne,final1.op);*/
	while(strcmp(final[i-1].mne,"END")!=0){
		final[i]=token();
		printf("%s %s %s\n",final[i].label,final[i].mne,final[i].op);
		//fprintf(f3,"%s %s %s\n",final[i][i].label,final[i].mne,final[i].op);
		//final[i][i]=token();
		int temp_loc=cal_loc(final[i].op,final[i].mne,loc);
                loc=temp_loc;
                fprintf(f3,"%d %s %s %s\n",loc,final[i].label,final[i].mne,final[i].op);

                if(strcmp(final[i].mne,"START")!=0 && strcmp(final[i].mne,"END")!=0 && strcmp(final[i].mne,"WORD")!=0 && strcmp(final[i].mne,"BYTE")!=0 && strcmp(final[i].mne,"RESW")!=0 &&strcmp(final[i].mne,"RESB")!=0){
                        int temp_mne=mne_value(final[i].mne);
                        fprintf(f4,"%s %d\n",final[i].mne,temp_mne);
                }

                if (strcmp(final[i].label,"")!=0){
                        fprintf(f5,"%d %s\n",loc,final[i].label);
                }
		fremove();
		i++;
	}
	/*char l[20],m[20],o[20];
        while(n!=EOF){
                n=fgetc(f1);
                if(n!='#'&&f==0){
                        l[i]=(char)n;
                        i++;
                }
                else if(n=='#'&&f==0){
                        l[i]='\0';
                        i=0;
                        strcpy(t[j].label,l);
                        f=1;
                }
                else if(n!='#'&&f==1){
                        m[i]=(char)n;
                        i++;
                }
                else if(n=='#'&&f==1){
                        m[i]='\0';
                        i=0;
                        strcpy(t[j].mne,m);
                        f=2;
                }
                else if(n!='#'&&f==2){
                        o[i]=(char)n;
                        i++;
                }
                else if(n=='#'&&f==2){
                        o[i]='\0';
                        strcpy(t[j].op,o);
                }
                else if(n=='\n'){
			i=0;
			f=0;
			j++;
		}
		else{
			printf("else");
		}
		
		int temp_loc=cal_loc(t.op,t.mne,loc);
		loc=temp_loc;
		fprintf(f3,"%d %s %s %s\n",loc,t.label,t.mne,t.op);
		
		if(strcmp(t.mne,"START")!=0 && strcmp(t.mne,"END")!=0 && strcmp(t.mne,"WORD")!=0 && strcmp(t.mne,"BYTE")!=0 && strcmp(t.mne,"RESW")!=0 &&strcmp(t.mne,"RESB")!=0){
			int temp_mne=mne_value(t.mne);
			fprintf(f4,"%s %d\n",t.mne,temp_mne);
		}
		
		if (strcmp(t.label,"")!=0){
			fprintf(f5,"%d %s\n",loc,t.label);
                }
		n=fgetc(f1);
	}*/
	fclose(f1);
	fclose(f3);
	fclose(f4);
	fclose(f5);
}	
