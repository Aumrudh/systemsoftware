#include"head.h"

void loadMemory (char fname[],char fname1[], ESTAB es[],int count, char csaddr[])
{
	ESTAB e;
	Memorymap mp[30];
	int i, mpcount=0, lcount=0, add, csadd, len, j, chadd, k, p;
	char rtype[2], length[3], address[5], code[7], temp[100], name[10];
	char chaddr[7], name1[10],c;
	fp1=fopen(fname1,"r");
	fp2=fopen(fname,"a");
	while(!feof(fp1))
	{
		fscanf(fp1,"%[^\n]",temp);
		c=fgetc(fp1);
		if(feof(fp1)) break;
		len = strlen(temp);
		rtype[0]=temp[0];
		rtype[1]='\0';
		if(strcmp(rtype,"T")==0)
		{
			i=2;
			j=0;
			while(temp[i]!='^'&&i<len)
			{
				address[j]=temp[i];
				i++;
				j++;
			}
			address[j]='\0';
			j=0;
			i=i+1;
			while(temp[i]!='^'&&i<len)
			{
				length[j]=temp[i];
				i++;
				j++;
			}
			length[j]='\0';
			j=0;
			i=i+1;
			while(i<len)
			{
				code[j]=temp[i];
				i++;
				j++;
			}
			code[j]='\0';
			sscanf(address,"%04x",&add);
			sscanf(csaddr,"%04x",&csadd);
			add = add+csadd;
			sprintf(mp[mpcount].address,"%04X",add);
			sscanf(length,"%02x",&len);
			i=0;
			lcount=0;
			while(lcount<len)
			{
				sprintf(mp[mpcount].address,"%04X",add);
				add++;
				mp[mpcount].objectcode[0]=code[i];
				mp[mpcount].objectcode[1]=code[i+1];
				mp[mpcount].objectcode[2]='\0';
				i=i+2;
				lcount++;
				mpcount++;
			}
		}
		if(strcmp(rtype,"M")==0)
		{
			i=2;
			j=0;
			while(temp[i]!='^'&&i<len)
			{
				address[j]=temp[i];
				i++;
				j++;
			}
			address[j]='\0';
			j=0;
			i=i+1;
			while(temp[i]!='^'&&i<len)
			{
				length[j]=temp[i];
				j++;
				i++;
			}
			length[j]='\0';
			j=0;
			i=i+1;
			while(i<len)
			{
				name[j]=temp[i];
				j++;
				i++;
			}
			name[j]='\0';
			sscanf(address,"%04x",&add);
			sscanf(csaddr,"%04x",&csadd);
			add=add+csadd;
			sprintf(address,"%04X",add);
			for(i=0;i<mpcount;i++)
			{
				if(strcmp(address,mp[i].address)==0)
				{
					len=strlen(name);
					j=1;
					k=0;
					while(k<len-1)
					{
						name1[k]=name[j];
						k++;
						j++;
					}
					name1[k]='\0';
					e=searchESTAB(name1,es,count);
					strcpy(chaddr,"\0");
					strcat(chaddr,mp[i].objectcode);
					strcat(chaddr,mp[i+1].objectcode);
					strcat(chaddr,mp[i+2].objectcode);
					sscanf(chaddr,"%06x",&chadd);
					sscanf(e.address,"%04x",&add);
					if(name[0]=='+')
					chadd=chadd+add;
					else
					chadd=chadd-add;
					sprintf(chaddr,"%06X",chadd);
					mp[i].objectcode[0]=chaddr[0];
					mp[i].objectcode[1]=chaddr[1];
					mp[i].objectcode[2]='\0';
					mp[i+1].objectcode[0]=chaddr[2];
					mp[i+1].objectcode[1]=chaddr[3];
					mp[i+1].objectcode[2]='\0';
					mp[i+2].objectcode[0]=chaddr[4];
					mp[i+2].objectcode[1]=chaddr[5];
					mp[i+2].objectcode[2]='\0';
					break;
				}
			}
		}
	}
	for(i=0;i<mpcount;i++)
	{
		p=pack(mp[i].objectcode[0],mp[i].objectcode[1]);
		sprintf(mp[i].packed,"%02X",p);
		fwrite(&mp[i],sizeof(mp[i]),1,fp2);
	}
	fclose(fp1);
	fclose(fp2);
}

void display(char fname[])
{
	Memorymap mp;
	fp1=fopen(fname,"r");
	printf("MEMORY MAP\n\n");
	while(!feof(fp1))
	{
		fread(&mp,sizeof(mp),1,fp1);
		if(feof(fp1)) break;
		printf("%s\t%s\n",mp.address,mp.packed);
	}
	fclose(fp1);
}

int pack (char a, char b)
{
	int c,d;
	c=a;
	if(c=='A'||c=='B'||c=='C'||c=='D'||c=='E'||c=='F')
	c=a-0x37;
	else if (c>='0'|| c<='9')
	c=a-0x30;
	c=c<<4;
	d=b;
	if(d=='A'||d=='B'||d=='C'||d=='D'||d=='E'||d=='F')
	{
		d=d-0x37;
	}
	else if(d>='0' || d<='9')
	{
		d=d-0x30;
	}
	c=c+d;
	return c;
}

ESTAB searchESTAB ( char name[], ESTAB es[], int count)
{
	int i;
	ESTAB e;
	for(i=0;i<count;i++)
	{
		if(strcmp(es[i].symname,name)==0||strcmp(es[i].csname,name)==0)
		{
			e=es[i];
			return e;
		}
	}
	strcpy(e.address,"\0");
	return e;
}

void displayTable (char fname[])
{
	ESTAB es;
	fp1=fopen(fname,"r");
	printf("\nControlSection\tSymname\tAddress\tLength\n");
	while(!feof(fp1))
	{
		fread(&es,sizeof(es),1,fp1);
		if(feof(fp1)) break;
		printf("\n%s\t\t%s\t%s\t%s\n",es.csname,es.symname,es.address,es.length);
	}
	fclose(fp1);
}

