#include<stdio.h>
#include<stdlib.h>
#define MAX 100
typedef struct{
  char name[30];
  char tl[12];
  char mail[30];
} pa;
int main(int argc, char *argv[]){
  if(argc != 2){
    printf("ERROR SYNTAX!\n");
    printf("TRUE: ex4 <filename>\n");
    exit(1);
  }
  pa  *b;
  FILE *fptr;
  int n,i,irc,m1,m2;
  fptr = fopen(argv[1],"r+b");
  printf("Modify address.\n");
  printf("Enter the first: ");
  scanf("%d", &m1);
  printf("Enter the end: ");
  scanf("%d", &m2);
  b = (pa*)malloc((m2-m1+1)*sizeof(pa));
  if( b == NULL){
    printf("Memory allocation failed!\n");
    return 1;
  }
  if(fseek(fptr, (m1-1)*sizeof(pa), SEEK_SET) != 0){
    printf("Fseek failed\n");
    return 1;
  }
  irc = fread(b, sizeof(pa), m2-m1+1,fptr);
  for(i=0;i<(m2-m1+1);i++){
    printf("%s-", (b+i)->name);
    printf("%s-", (b+i)->tl);
    printf("%s\n",(b+i)->mail);
  }
  printf("Enter new dress.\n");
  for(i=0;i<(m2-m1+1); i++){
    printf("User 1\n");
    printf("Name: ");
    scanf("%s",(b+i)->name);
    printf("Phone number: ");
    scanf("%s",(b+i)->tl);
    printf("Email: ");
    scanf("%s", (b+i)->mail);
  }
  if(fseek(fptr, (m1-1)*sizeof(pa), SEEK_SET) != 0){
    printf("Fseek failed\n");
    return 1;
  }
  fwrite(b, sizeof(pa), (m2-m1+1), fptr);
  free(b);
  fclose(fptr);
  return 0; 
}
