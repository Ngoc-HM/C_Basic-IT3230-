#include<stdio.h>
#define MAX 100
int main(int argc, char *argv[]){
  if(argc != 3){
    printf("ERROR SYNTAX.\n");
    printf("TRUE SYNTAX: name <filename1> <filename2>\n");
    return 1;
  }
  int num;
  char buff[MAX];
  FILE *f1,*f2;
  f1= fopen(argv[1],"r");
  f2= fopen(argv[2],"w");
  if(f1 == NULL){
    printf("Cannot open %s.\n",argv[1]);
    return 1;
  }
  if(f2 == NULL){
    printf("Cannot open %s.\n",argv[2]);
    return 1;
  }
  while(!feof(f1)){
    num = fread(buff, sizeof(char), MAX-1, f1);
    buff[MAX*sizeof(char)] = '\0';
    
    printf("%s",buff);
    fwrite(buff, sizeof(char), num, f2);
  }
  return 0;
}
