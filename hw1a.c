#include<stdio.h>
#include<stdlib.h>
#define MAX 30
typedef struct{
  char name[30];
  char tl[12];
  char mail[30];
} pa;
int main(int argc, char *argv[]){
  if(argc != 5){
    printf("ERROR SYNTAX!\n");
    printf("TRUE SYNTAX: filesplit <filename> <number> <filename1> <filename2>\n");
    return 1;
  }
  FILE *f1,*f2,*f3;
  int n, irc1 =0, irc, i=0;
  pa  a[MAX],*a1,*a2;
  f1 = fopen(argv[1],"rb");
  f2 = fopen(argv[3],"w+b");
  f3 = fopen(argv[4],"w+b");
  if(f1 == NULL){
      printf("Cannot open %s\n",argv[1]);
      return 1;
    }
  if(f2 == NULL){
    printf("Cannot open %s\n", argv[3]);
    return 1;
  }
  if(f3 == NULL){
    printf("Cannot open %s\n", argv[4]);
    return 1;
  }
  n = atoi(argv[2]);
  while(!feof(f1)){
    irc1 +=fread(a+i, sizeof(pa), 1, f1);
    i++;
  }
  if(fseek(f1, 0, SEEK_SET) != 0){
    printf("Fseek failed!\n");
    return 1;
  }
  if((a1 =(pa*)malloc(n*sizeof(pa))) == NULL){
    printf("Meomory allocation failed!\n");
    return 1;
  }
  if((a2 =(pa*)malloc((irc1-n)*sizeof(pa))) == NULL){
    printf("Memory allocation failed!\n");
    return 1;
  }
  irc = fread(a1, sizeof(pa), n, f1);
  printf("%d\n",irc);
  fwrite(a1, sizeof(pa), irc, f2);
  if(fseek(f1,n*sizeof(pa), SEEK_SET) != 0){
    printf("Fseek failed!\n");
    return 1;
  }
  irc = fread(a2,sizeof(pa), irc1-n,f1);
  printf("%d\n", irc);
  fwrite(a2, sizeof(pa), irc, f3);
  free(a1);
  free(a2);
  fclose(f1);
  fclose(f2);
  fclose(f3);
  return 0;
}
