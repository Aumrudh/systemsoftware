#include"head.h"
int main(){
	FILE *f1,*f2,*f3,*f4,*f5;
	opnode temp;
	char la[20],ma[20],oa[20];
	int start_ad=0;
	f1=fopen("alp.txt","r");
	f3=fopen("output.txt","w");
	f4=fopen("outop.txt","w");
	f5=fopen("outsym.txt","w");
	fscanf(f1,"%s%s%s",la,ma,oa);
	if(strcmp("START",ma)==0&&strcmp("1000",oa)==0){
		int start_ad=1000;
		printf("Start");
	}
	else{
		start_ad=0;
	}
	int loc=start_ad;
        int n,i=0,f=0;
        opnode t;
	n=fgetc(f1);
	char l[20],m[20],o[20];
        while(n!=EOF){
                //n=fgetc(f1);
                if(n!='#'&&f==0){
                        l[i]=(char)n;
                        i++;
                }
                else if(n=='#'&&f==0){
                        l[i]='\0';
                        i=0;
                        strcpy(t.label,l);
                        f=1;
                }
                else if(n!='#'&&f==1){
                        m[i]=(char)n;
                        i++;
                }
                else if(n=='#'&&f==1){
                        m[i]='\0';
                        i=0;
                        strcpy(t.mne,m);
                        f=2;
                }
                else if(n!='#'&&f==2){
                        o[i]=(char)n;
                        i++;
                }
                else if(n=='#'&&f==2){
                        o[i]='\0';
                        strcpy(t.op,o);
                }
                else if(n=='\n'){
			i=0;
			f=0;
		}
		else{}
		
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
	}
	fclose(f1);
	fclose(f3);
	fclose(f4);
	fclose(f5);
}	
