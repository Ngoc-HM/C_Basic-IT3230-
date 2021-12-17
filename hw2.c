#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int main(int argc, char *argv[]){
  int a,i=0,n;
  char  c, s[100];
  FILE *fptr,*fptr1;
  if(argc != 3){
    printf("ERROR SYNTAX.\n");
    printf("TRUE SYNTAX: hw2 <filename> <offset>.\n");
  }
  if((fptr=fopen(argv[1],"r")) == NULL){
    printf("Cannot open file.\n");
    return 1;
  }
  
  while((c=fgetc(fptr)) != EOF){
    c=c+atoi(argv[2]);
    s[i]=c;
    i++;
  }
  printf("\n");
  fclose(fptr);
  if((fptr1=fopen(argv[1],"w")) == NULL){
    printf("Cannot open file.\n");
    return 1;
  }
  fputs(s,fptr1);
  return 0;
}
