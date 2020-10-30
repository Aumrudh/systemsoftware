#include<stdio.h>
	#include<string.h>
	#include<stdlib.h>

	void inttohex(int n,char h[],int len){
		int i=0,j;
		char s[10] = {0};
		if(n == 0)
			s[i] = '0';
		while(n != 0){
			s[i] = "0123456789ABCDEF"[n%16];
			i++;	n /= 16;
		}
	        if(len==6)
		{
		        int a=strlen(s);
			if(a==4)
			   strcat(s,"00");
			else if(a==5)
			   strncat(s,"0",1);
		}
		for(i=0,j=strlen(s)-1;i<strlen(s);i++,j--)
			h[i] = s[j];
		h[i] = '\0';
	}
	int size(char* ch)
	{
		char c[100];
		int count=0;
	     for(int i=0;i<=2;i++)
	  {
		  		  if(ch[i]=='A')
				  {
					
					strcat(c,"1010");
				  }
				  else if(ch[i]=='B')
				  {
					
					strcat(c,"1011");
					
				  }
				  else if(ch[i]=='C')
				  {
					
					strcat(c,"1100");
					
				  }
				  else if(ch[i]=='D')
				  {
				
					strcat(c,"1101");
					
				  }
				  else if(ch[i]=='E')
				  {
					
					strcat(c,"1110");
					
				  }
				  else if(ch[i]=='F')
				  {
					
					strcat(c,"1111");
					
				  }
				  else
				  {
					  strcat(c,"000");
					  int a=strlen(c)-1;
					  c[a]=ch[i];
				  }
	  }
	     c[12]='\0';
	     for(int i=0;i<=12;i++)
	     {
		     if(c[i]=='1')
		     {
			     count+=1;
		     }
	     }
	     return count;
	}


	int hextoint(char h[])
	{
		int l = strlen(h),base = 1,d = 0,i;
		for(i=l-1;i>=0;i--)
		{
			if(h[i] >= '0' && h[i] <= '9')
				d += (h[i] - 48) * base;
			else if(h[i] >= 'A' && h[i] <= 'F')
				d += (h[i] - 55) * base;
			base *= 16;
		}
		return d;
	}
	void add(int start,char* ch)
	{
	  char la[4],loc[5];
	  inttohex(start,loc,4);
	  strcpy(la,loc);
	  la[4]='\0';
	  printf("%s\t",la);
	  for(int i=0;i<=1;i++)
	  {
		  		  if(ch[i]=='A')
				  {
					
					printf("1010");
				  }
				  else if(ch[i]=='B')
				  {
					
					printf("1011");
					
				  }
				  else if(ch[i]=='C')
				  {
					
					printf("1100");
					
				  }
				  else if(ch[i]=='D')
				  {
				
					printf("1101");
					
				  }
				  else if(ch[i]=='E')
				  {
					
					printf("1110");
					
				  }
				  else if(ch[i]=='F')
				  {
					
					printf("1111");
					
				  }
				  else
				  {
					  printf("000%c",ch[i]);
				  }
				  printf("\t");
	  }
	  printf("(%c,%c)\n",ch[0],ch[1]);
	}


	int main()
	{
		FILE *f1;
		f1=fopen("alp.txt","r");
		char progname[20],startaddr[20],newaddr[20],c;
		int start,new,new1,res,flag=0,i=0,j=0;
		printf("Enter new address:");
		scanf("%s",newaddr);
		newaddr[4]='\0';
		c=fgetc(f1);
		while(flag<=2)
		{
			if(c=='^')
			{
				flag+=1;
			}
			if(flag==1)
			{
				c=fgetc(f1);
				if(c!='^')
				{
				 progname[i]=c;
				 i++;
				}
				progname[i]='\0';
			}
			else if(flag==2)
			{
				c=fgetc(f1);
				if(c!='^')
				{
				  startaddr[j]=c;
				  j++;
				}
				startaddr[j]='\0';
			}
			else
				c=fgetc(f1);
		}
		printf("progname=%s",progname);
		new1=new=hextoint(newaddr);
		res=hextoint(startaddr)+new;
	        strcpy(newaddr,"");
		inttohex(res,newaddr,4);
		newaddr[4]='\0';
		printf("\nstartaddr=%s\n",newaddr);
		c=fgetc(f1);
		flag=0;
		char objcode[6],objcode1[6],ch[2],siz[3];
		int objint,g=0,a;
		while(c!=EOF)
		{
			if(c=='^')
			{
				flag+=1;
				if(flag==4)
				{
					for(int i=0;i<=2;i++)
					{
						siz[i]=fgetc(f1);
					}
					siz[3]='\0';
					a=size(siz);
					a+=flag;
				}
			
			if(c=='^' && flag>4)
			{
				for(int i=0;i<=5;i++)
				{
					objcode[i]=fgetc(f1);
				}
				objcode[6]='\0';
				if((objcode[1]!='E')&&(objcode[2]!='^'))
				{	
					if(flag<=a)
					{
						objint=hextoint(objcode)+new1;
						inttohex(objint,objcode1,6); 
						objcode1[6]='\0';
						//printf("\nobjectcode:%s",objcode1); 
					}
					else
						strcpy(objcode1,objcode);
					for(int i=0;i<=5;i+=2)
					{
						ch[0]=objcode1[i];
						ch[1]=objcode1[i+1];
						ch[2]='\0';
						add(res,ch);
						res+=1;
						strcpy(ch,"");
					}
					strcpy(objcode1,"");
					strcpy(objcode,"");
				}
				else
			                exit(0);
			}
			
			}
			c=fgetc(f1);
		}
		return 0;
	}


