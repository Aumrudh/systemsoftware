#include"head.h"
int main()
{
	FILE *f1;
	f1=fopen("objpgm.txt","r");
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

