void objectProgramGeneration(char fname[],char fname1[])
{
  int count=0,first,las,pl,len;
  char last[10];
  HeadRec h;
  OutRec out;
  TextRec t;
  fp1=fopen(fname,"r");
  fp2=fopen(fname1,"w");
  while(!feof(fp1))
  {
    fread(&out,sizeof(out),1,fp1);
    if(strcmp(out.opcode,"END")==0)
      strcpy(last,out.address);
  }
  fclose(fp1);
  fp1=fopen(fname,"r");
  sscanf(last,"%04x",&las);
  fread(&out,sizeof(out),1,fp1);
  strcpy(h.pgmname,out.label);
  strcpy(h.address,out.address);
  sscanf(h.address,"%2x",&first);
  pl=las-first;
  sprintf(h.pgmlength,"%2x",pl);
  if(strcmp(h.pgmname,"\0")!=0)
    fprintf(fp2,"H^%s^%s^%s\n",h.pgmname,h.address,h.pgmlength);
  else
    fprintf(fp2,"H^  ^%s^%s\n",h.address,h.pgmlength);
  fp1=fopen(fname,"r");
  while(!feof(fp1))
  {
    fread(&out,sizeof(out),1,fp1);
    if(feof(fp1)) break;
    if(strcmp(out.machinecode,"\0")!=0)
    {
      strcpy(t.startaddress,out.address);
      len=strlen(out.machinecode);
      len=len/2;
      sprintf(t.length,"%02x",len);
      strcpy(t.objcode,out.machinecode);
      fprintf(fp2,"T^%s^%s^%s\n",t.startaddress,t.length,t.objcode);
    }
  }
  fclose(fp1);
  fprintf(fp2,"E^%s\n",h.address);
  fclose(fp2);
}
