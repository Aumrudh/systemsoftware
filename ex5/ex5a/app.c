#include"head.h"
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
