#include "head.h"

void make(char x[],int l){
	int i;
	char t[7] = {0};
	if(strlen(x) < l){
		for(i=0;i<(l-strlen(x));i++)
			t[i] = '0';
		strcat(t,x);
		strcpy(x,t);
	}
}

int htoi(char h[]){
	int l = strlen(h),base = 1,d = 0,i;
	for(i=l-1;i>=0;i--){
		if(h[i] >= '0' && h[i] <= '9')
			d += (h[i] - 48) * base;
		else if(h[i] >= 'A' && h[i] <= 'F')
			d += (h[i] - 55) * base;
		base *= 16;
	}
	return d;
}

void itoa(int n,char h[],int base){
	int i=0,j;
	char s[10] = {0};
	if(n == 0)
		s[0] = '0';
	while(n != 0){
		s[i] = "0123456789ABCDEF"[n%base];
		i++;	n /= base;
	}
	for(i=0,j=strlen(s)-1;i<strlen(s);i++,j--)
		h[i] = s[j];
	h[i] = '\0';
}

void binary(char c,char m[]){
	char s[10] = {0},ch[2] = {0};
	strncat(ch,&c,1);
	ch[1] = '\0';
	int d = htoi(ch),i=0,j;
	while(d != 0){
		s[i] = "01"[d%2];
		i++;	d /= 2;
	}
	for(i=0,j=strlen(s)-1;i<strlen(s);i++,j--)
		m[i] = s[j];
	m[i] = '\0';
	make(m,4);
}

void copyFile(char src[],char dest[]){
	char row[100];
	FILE *f1 = fopen(src,"rb");
	FILE *f2 = fopen(dest,"wb");
	while(fscanf(f1,"%s",row) == 1)
		fprintf(f2,"%s\n",row);
	fclose(f1);	fclose(f2);
}

int modRec(char m_addr[],char m_siz[],int nxt){
	char row[100] = {0};
	int i = 0;
	FILE *f1 = fopen("temp.txt","r");
	while(fscanf(f1,"%s",row) == 1){
		if(row[0] == 'M' && (++i == nxt)){
			strtok(row,"^");
			strcpy(m_addr,strtok(NULL,"^"));
			strcpy(m_siz,strtok(NULL,"^"));
			fclose(f1);
			return 1;
		}
	}
	fclose(f1);
	return 0;
}

int Load(FILE *f2,int addr,char data[],int i){
	char buf1[5] = {0},buf2[5] = {0},c_addr[5] = {0};
	itoa(addr,c_addr,16);
	make(c_addr,4);
	binary(data[i],buf1);    binary(data[i+1],buf2);
	fprintf(f2,"%s\t%s %s\t(%c%c)\n",c_addr,buf1,buf2,data[i],data[i+1]);
	return ++i;
}

void getMskBits(char msk[],char mskbit[]){
	int i;
	char bin[5];
	strcpy(mskbit,"\0");
	for(i=0;i<strlen(msk);i++){
		binary(msk[i],bin);
		strcat(mskbit,bin);
	}
}

