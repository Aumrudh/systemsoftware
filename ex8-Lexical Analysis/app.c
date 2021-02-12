#include "head.h"

int main(int argc,char *argv[]){
	FILE *f = fopen(argv[1],"r");
	openAndClose();
	char ch,buf[10]={0},buf1[3]={0},data[20]={0};
	int quot = 0,i,j;
	while(fscanf(f,"%s",data) == 1){
		for(i=0;i<strlen(data);i++){
			buf1[0] = data[i];
			if(data[i] == '"'){
				quot = !quot;
				if(!search("spl.txt",buf1))
					insert("spl.txt",data[i]);
				continue;
			}
			if(quot == 1 && data[i] == '%'){
				char s[] = "dsfcp";
				for(j=0;j<strlen(s);j++)
					if(data[i+1] == s[j]){
						insspeci("acc.txt",data[++i]);
						break;
					}
			}
			if(data[i] == '\n' || data[i] == '\t' || quot == 1)
				continue;
			if(isOperator(data[i])){
				if(!search("op.txt",buf1))
					insert("op.txt",data[i]);
				if(strcmp(buf,"\0"))
					insKeyVar(buf);
			}else if(isSpclChar(data[i])){
				if(!search("spl.txt",buf1))
					insert("spl.txt",data[i]);
				if(strcmp(buf,"\0"))
					insKeyVar(buf);
			}else{
				strncat(buf,&data[i],1);
			}
		}
		if(strcmp(buf,"\0"))
			insKeyVar(buf);
	}
	printf("Program executed\n");
}

