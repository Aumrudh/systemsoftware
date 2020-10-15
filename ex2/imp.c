#include"head.h"


int cal_loc(char op[],char c[],int temp){
	if(strcmp(c,"WORD")==0){
		temp+=3;
	}
	else if(strcmp(c,"BYTE")==0){
		if(op[0]=='X'){
			temp+=1;
		}
		else{
			temp+=strlen(op)-2;
		}
		return temp;
	}
	else if(strcmp(c,"RESW")==0){
		temp+=3*(atoi(op));
		return temp;
	}
	else if(strcmp(c,"RESB")==0){
	        temp+=atoi(op);
	        return temp;
	}
	else{
		//return ;
	}

}

int mne_value(char mne[]){

	FILE *f=fopen("opcode.txt","r");
	int val;
	char temp_mne[20];//,*val=malloc(sizeof(20));
	while(!feof(f)){
		fscanf(f,"%s %d",temp_mne,&val);
		if(strcmp(mne,temp_mne)==0){
			return val;
		}
	}
	fclose(f);
}











/*opnode token(){
	int n,i=0,f=0;
	char l[20],m[20],o[20],ch;
	opnode t;
	FILE *f1= fopen("alp.txt", "r");
	while(n!='\n' &&n!=EOF){
		n=fgetc(f1);
		if(n!='#'&&f==0){
			l[i]=(char)ch;
			i+=1;
		}
		else if(n=='#'&&f==0){
			l[i]='\0';
			i=0;
			strcpy(t.label,l);
			f=1;
		}
		else if(n!='#'&&f==1){
			m[i]=(char)ch;
			i+=1;
	        }
		else if(n=='#'&&f==1){
			m[i]='\0';
			i=0;
			strcpy(t.mne,m);
			f=2;
		}
		else if(n!='#'&&f==2){
			o[i]=(char)ch;
			i+=1;
		}
		else if(n=='#'&&f==2){
		        o[i]='\0';
			strcpy(t.op,o);
		}
		else{}
	}
	return t;
}*/
