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
  pa a[MAX];
  FILE *fptr;
  int n,i,irc;
  printf("Nhap so khach hang: ");
  scanf("%d", &n);
  for(i=0;i<n;i++){
    printf("Khach hang %d\n",i+1);
    printf("Ho va ten: ");
    scanf("%s", a[i].name);
    printf("so dien thoai: ");
    scanf("%s", a[i].tl);
    printf("Email: ");
    scanf("%s",a[i].mail);
  }
  if((fptr=fopen(argv[1],"r+b")) == NULL){
    printf("Cannot open %s\n",argv[1]);
    exit(1);
  }
  irc = fwrite(a, sizeof(pa), n, fptr);
  printf("fwrite return code = %d\n",irc);
  rewind(fptr);
  irc = fread(a, sizeof(pa), n, fptr);
  printf("fread return code = %d\n",irc);
  for(i=0;i<n;i++){
    printf("%s-",a[i].name);
    printf("%s-",a[i].tl);
    printf("%s\n",a[i].mail);
  }
  fclose(fptr);
  return 0; 
}

