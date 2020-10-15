#include"head.h"



char* cal_loc(char op[],char c[],char temp[]){
	int len=strlen(temp);
	int i=0,j,res=0,z=len-1;
	for (i=0;i<len;i++){
		if(temp[i]=='A') 
 			j=10;
		else if(temp[i]=='B') 
			j=11;
		else if(temp[i]=='C') 
			j=12;
		else if(temp[i]=='D') 
			j=13;
		else if(temp[i]=='E') 
			j=14;
		else if(temp[i]=='F') 
			j=15;
		else{
			char *array=(char*)malloc(2);
 			array[0] = temp[i];
			array[1] = '\0';
			j=atoi(array);
 			free(array);
 		}
	res=res+(j*pow(16, z));
	z-=1;
	}
	if(strcmp(c,"BYTE")==0){
		if(op[0]=='X'){
			res=res+strlen(op)-3;
		}
		else{
			res=res-3+strlen(op)/2;
		}
	}
	else if(strcmp(c,"RESW")==0){
		res+=3*(atoi(op));
	}
	else if(strcmp(c,"RESB")==0){
	        res+=atoi(op);
	}
	else{
	        res+=3;
	}
	char *ans=(char*)malloc(5);
	sprintf(ans,"%X",res);
	return ans;
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











opnode token(){
	int n,i=0,f=0;
	char l[20],m[20],o[20];
	opnode t;
	FILE *f1= fopen("alp.txt", "r");
	while(n!='\n'&&n!=EOF){
		n=fgetc(f1);
		if(n!='#'&&f==0){
			l[i]=(char)n;
			i+=1;
		}
		else if(n=='#'&&f==0){
			l[i]='\0';
			i=0;
			strcpy(t.label,l);
			//printf("l-%s\n",l);
			//printf("t.l-%s\n",t.label);
			f=1;
		}
		else if(n!='#'&&f==1){
			m[i]=(char)n;
			i+=1;
	        }
		else if(n=='#'&&f==1){
			m[i]='\0';
			i=0;
			strcpy(t.mne,m);
			f=2;
		}
		else if(n!='#'&&f==2){
			o[i]=(char)n;
			i+=1;
		}
		o[i]='\0';
		strcpy(t.op,o);
	}
	/*FILE *f2=fopen("a.txt","w+");
	char str[25];
	int ln=0,c=0;
	while (!feof(f1)) 
        {	   
            strcpy(str, "\0");
            fgets(str, 25, f1);
            if (!feof(f2)) 
            {
                c++;
                if (c != ln) 
                {
                    fprintf(f2, "%s", str);
                }
            }
        }
	remove("alp.txt");
	rename("a.txt","alp.txt");*/
	fclose(f1);
	return t;
}

void fremove(){
	FILE *f1= fopen("alp.txt", "r");
	FILE *f2=fopen("a.txt","w");
        char str[25];
        int ln=0,c=0;
        while (!feof(f1))
        {
            strcpy(str, "\0");
            fgets(str, 25, f1);
            if (!feof(f2))
            {
               // c++;
                if (c != ln)
                {
                    fprintf(f2, "%s", str);
                }
		c++;
            }
        }
	fclose(f1);
	fclose(f2);
        remove("alp.txt");
        rename("a.txt","alp.txt");
}
