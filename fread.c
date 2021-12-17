#include<stdio.h>
#include<stdlib.h>
#define MAX 20
typedef struct{
  char name[30];
  char tl[12];
  char mail[30];
} pa;
int main(int argc, char *argv[]){
  if(argc != 2){
    printf("error syntax!\n");
    printf("True: fread <filename>\n");
    return 1;
  }
  FILE *fptr;
  pa a[MAX];
  int irc=0,i=0;
  int count=0;
  if((fptr= fopen(argv[1],"r+b")) == NULL){
      printf("Cannot open file\n");
      return 1;
    }
  while(!feof(fptr)){
    irc += fread(a+i, sizeof(pa),1, fptr);
    i++;
  }
  for(i=0;i<irc;i++){
    printf("%s-", a[i].name);
    printf("%s-", a[i].tl);
    printf("%s\n",a[i].mail);
  }
  return 0;
}
