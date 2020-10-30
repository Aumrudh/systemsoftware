#include "head.h"

int main(int argc,char *argv[]){
	if(argc > 2 || argc < 2){
		printf("\n> Invalid Input Type...\n\n");
		exit(1);
	}
	char trow[100] = {0},row[100] = {0},len[10] = {0};
	char m_addr[7] = {0},m_bit[3] = {0},buf[7],buf2[10] = {0};
	int plen,addr,PROGADDR,modflag=0,m,mrec=1,i,j;
	printf("\n> Enter the Program name:\t");
	scanf("%s",buf);
	printf("\n> Enter the Length of the program:\t");
	scanf("%d",&plen);
	FILE *f1 = fopen(argv[1],"r");
	FILE *f2 = fopen("Loader.txt","w");
	copyFile(argv[1],"temp.txt");
	fscanf(f1,"%s",trow);
	if(!strcmp(strtok(trow,"^"),"H")){
		if(!strcmp(strtok(NULL,"^"),buf)){
			itoa(plen,len,16);	make(len,6);
			strtok(NULL,"^");
				if(strcmp(strtok(NULL,"\n"),len)){
					printf("\n> Conflicting Lengths...\n\n");
					fclose(f1); fclose(f2); remove("temp.txt");
					exit(1);
				}
		}else{
			printf("\n> Conflicting Names...\n\n");
			fclose(f1);	fclose(f2);	remove("temp.txt");
			exit(1);
		}
	}else{
		printf("\n> Error in the generated OBJECT Program(No Head)\n\n");
		fclose(f1);	fclose(f2);	remove("temp.txt");
		exit(1);
	}
	printf("\n> Enter the Relocation Address:\t");
	scanf("%s",len);
	PROGADDR = htoi(len);
	fscanf(f1,"%s",trow);
	strcpy(row,trow);
	modflag = modRec(m_addr,m_bit,mrec);	
	while(strcmp(strtok(trow,"^"),"E")){
		addr = htoi(strtok(NULL,"^"));
		strtok(NULL,"^");
		for(i=12;i<strlen(row);i++){
			if(row[i] == '^')
				continue;
			itoa(addr,buf,16);
			make(buf,6);
			if(modflag == 1 && !strcmp(m_addr,buf)){
				strcpy(buf,"\0");
				for(j=0;j<atoi(m_bit);j++)
					strncat(buf,&row[i+j+1],1);
				m = htoi(buf) + PROGADDR;
				itoa(m,buf,16);
				make(buf,atoi(m_bit));
				if(atoi(m_bit)%2 == 1){
					strcpy(buf2,"\0");
          strncat(buf2,&row[i],1);
          strcat(buf2,buf);
          strcpy(buf,buf2);
        }
				printf("\n> %s\n",buf);
				for(j=0;j<strlen(buf);j++)
					j = Load(f2,(addr++)+PROGADDR,buf,j);
				i += j-1;
				modflag = modRec(m_addr,m_bit,++mrec);
			}else
				i = Load(f2,(addr++)+PROGADDR,row,i);
		}
		fscanf(f1,"%s",trow);
		strcpy(row,trow);
	}
	fclose(f1);	fclose(f2);	remove("temp.txt");
	printf("\n> Successfully Loaded...\n\n");
}

