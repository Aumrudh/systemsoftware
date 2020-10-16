#include"head.h"

int pack(char a, char b)
{
	int c,d;
	c=a;
	c = a-0x30;
	if(c>9)
		c-=0x07;
	d=b-0x30;
	if(d>9)
		d-=0x07;
	c = c<<4;
	c+=d;
	return c;
}

void loader(char file[],char pgn[],char pgsize[])
{
	FILE *fp;
	char a[50],a1,c,b1,e[50];
	char size[10],start[10],h[50],name[10],sz[10];
	int len,arr[50],dec,p,i,j,m;
	fp = fopen(file,"r");
	fscanf(fp,"%[^\n]%c",a,&c);
 	printf("\n%s\n",a);
 	if(a[0] == 'H')
 	{
  	i = 2;
    j =0;
   	while(a[i] != '^')
    {
      name[j++] = a[i];
      i++;
    }
    name[j]='\0';
    i++;
    j=0;
    while(a[i] != '^')
    {
      i++;
    }
    i++;
    while(a[i] != '\0')
    {
      sz[j++] = a[i];
      i++;
    }
    sz[j]='\0';
    i++;
    if((strcmp(pgn,name)==0)&&strcmp(sz,pgsize)==0)
         printf("MEMORY MAP : \n");
    else
    {
      printf("Invalid");
      exit(0);
    }
  }
	while(!feof(fp))
	{
		if(a[0] == 'T')
		{
			i = 2;
			j =0;
			while(a[i] != '^')
			{
				start[j++] = a[i];
				i++;
			}
			start[j]='\0';
			i++;
			j=0;
			while(a[i] != '^')
    			  {
    			    size[j++] = a[i];
    			    i++;
    			  } 
      size[j]='\0';
      i++;
      j=0;
			dec = atoi(start);
      sprintf(h,"%04X",dec);
			while(a[i] != '\0')
			{
			   a1 = a[i++];
				 b1 = a[i++];
				 p = pack(a1,b1);
				 sprintf(e,"%02X\n",p);
		     printf("%s\t%s\n",h,e);
         dec ++;
         sprintf(h,"%04X",dec);
			}
	  }
    fscanf(fp,"%[^\n]%c",a,&c);
  }
}

