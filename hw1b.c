#include<stdio.h>
#include<stdlib.h>
#define MAX 100
typedef struct{
  char name[30];
  char tl[12];
  char mail[30];
} pa;
int main(int argc, char *argv[]){
  if(argc != 4){
    printf("ERROR SYNTAX!\n");
    printf("TRUE SYNTAX: filemerge <filename> <filename1> <filename2>\n");
    return 1;
  }
  FILE *f1,*f2,*f3;
  pa b1[MAX],b2[MAX];
  int irc1=0,irc2 = 0, i;
  f1 = fopen(argv[1],"rb");
  f2 = fopen(argv[2],"rb");
  f3 = fopen(argv[3],"w+b");
  if(f1 == NULL){
    printf("Cannot open %s\n",argv[1]);
  }
  if(f2 == NULL){
    printf("Cannot open %s\n",argv[2]);
  }
  if(f3 == NULL){
    printf("Cannot open %s\n",argv[3]);
  }
  i=0;
  while(!feof(f1)){
    irc1+= fread(b1+i, sizeof(pa), 1, f1);
    i++;
  }
  i=0;
  while(!feof(f2)){
    irc2+= fread(b2+i, sizeof(pa), 1, f2);
    i++;
  }
  printf("%d\n",irc2);
  fwrite(b1, sizeof(pa), irc1, f3);
  fwrite(b2, sizeof(pa), irc2, f3);
  fclose(f1);
  fclose(f2);
  fclose(f3);
  return 1;
}
