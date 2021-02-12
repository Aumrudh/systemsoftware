#include"head.h"
main(int argc,char * argv[])
{
 char name[10],size[10];
 printf("Enter pg name n size\n");
 scanf("%s%s",name,size);
 loader(argv[1],name,size);
}
