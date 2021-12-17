#include<stdio.h>
#define MAX 81
int main(int argc, char *argv[]){
  int a,b;
  char c1[MAX], c2[MAX];
  if(argc != 4){
    printf("ERROR SYNTAX\n");
    printf("TRUE is: ex5 <file1> <file2> <file3>\n");
  }
  FILE *f1,*f2,*f3;
  f1 = fopen(argv[1],"r");
  f2 = fopen(argv[2],"r");
  f3 = fopen(argv[3],"a");
  if(f1==NULL || f2 == NULL || f3 == NULL){
    printf("cannot open file\n");
    return 1;
  }
  while(fgets(c1, MAX, f1) != NULL && fgets(c2, MAX, f2) != NULL){
    fputs(c1, f3);
    fputs(c2, f3);
  }
  if(fgets(c1, MAX, f1) != NULL){
    fputs(c1, f3);
  }
  while(fgets(c1, MAX, f1) != NULL) fputs(c1, f3);
  while(fgets(c2, MAX, f2) != NULL) fputs(c2, f3);
  fclose(f1);
  fclose(f2);
  fclose(f3);
  return 0;
}
