#include<stdlib.h>
#define MAX 100
int main(int argc, char *argv[]){
  FILE *fptr1,*fptr2;
  char c[MAX];
  if(argc != 3){
    printf("ERROR SYNTAX\n");
    printf("TRUE: mycp filefrom fileto \n");
  }
  
  if((fptr1=fopen(argv[1],"r")) == NULL){
    printf("Cannot open %s.\n",argv[1]);
    return 1;
  }
  if((fptr2=fopen(argv[2],"w")) == NULL){
    printf("Cannot open %s.\n",argv[2]);
    return 1;
  }
  while(fgets(c, MAX, fptr1) != NULL){
    fputs(c, fptr2);
    printf("%s",c);
  }
  fclose(fptr1);
  fclose(fptr2);
  return 0;
}
