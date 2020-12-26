#include"head.h"

main(int argc, char *argv[])
{
	ESTAB es[10], e;
	int count=0, i=3,j=0, k=0, len;
	char pgmaddr[5], csaddr[5], name[10], temp[300], rtype[2];
	//printf("\nEXTERNAL SYMBOL TABLE\n");
	//displayTable(argv[2]);
	fp1=fopen(argv[2],"r");
	while(!feof(fp1))
	{
		fread(&es[count],sizeof(e),1,fp1);
		if(feof(fp1)) break;
		count++;
	}
	fclose(fp1);
	fp1=fopen(argv[1],"w");
	fclose(fp1);
	i=3;
	while(i<argc)
	{
		fp1=fopen(argv[i],"r");
		fscanf(fp1,"%[^\n]",temp);
		if(feof(fp1)) break;
		rtype[0]=temp[0];
		rtype[1]='\0';
		if (strcmp(rtype,"H")==0)
		{
			len = strlen(temp);
			j=2;
			k=0;
			while(temp[j]!='^'&&j<len)
			{
				name[k]=temp[j];
				k++;
				j++;
			}
			name[k]='\0';
			e=searchESTAB(name,es,count);
		}
		fclose(fp1);
		loadMemory(argv[1],argv[i],es,count,e.address);
		i++;
	}
	display(argv[1]);
}
