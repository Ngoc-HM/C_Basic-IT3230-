#include<stdio.h>
int main(int argc, char *argv[]){
  char c;
  if(argc != 3){
    printf("ERROR SYNTAX!");
    return 1;
  }
  FILE *fin, *fout;
  fin=fopen(argv[1],"r");
  fout=fopen(argv[2],"w");
  if(fin == NULL){
    printf("Cannot open %s.\n", argv[1]);
    return 1;
  }
  if(fout == NULL){
    printf("Cannot open %s.\n", argv[2]);
    return 1;
  } 
  while((c= fgetc(fin)) != EOF){
    fputc(c, fout);
    if(c=='\n') fputc('\n',fout);
  }
  return 0;
}
