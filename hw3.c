#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#define MAX 500
typedef struct{
  char word[MAX];
} dic;
int main(){
  FILE *f1,*f2;
  char s[MAX];
  int i,n=0,i1,i2;
  dic *a;
  f1=fopen("vnedict.txt","r");
  f2=fopen("vnedict.dat","w+b");
  if(f1 == NULL){
    printf("Cannot open %s\n","vnedict.txt");
    return 1;
  }
  if(f2 == NULL){
    printf("Cannot open %s\n","vnedict.dat");
    return 1;
  }
  while(fgets(s, MAX, f1) != NULL){
    n++;
  }
  if(fseek(f1, 0, SEEK_SET) != 0){
    printf("Fseek failed\n");
    return 1;
  }
  printf("%d\n",n);
  a=(dic*)malloc(n*sizeof(dic));
  if(a == NULL){
    printf("Memory allocation failed!\n");
    return 1;
  }
  i = 0;
  while(fgets(s, MAX, f1) != NULL){
    strcpy((a+i)->word, s);
    fwrite(a+i, sizeof(dic), 1, f2); 
    i++;
  }
  if(fseek(f2, 0, SEEK_SET) != 0){
    printf("Fseek failed!\n");
    return 1;
    }
  while(!feof(f2)){
    fread(a, sizeof(dic), n, f2);
  }
  printf("Enter start number: ");
  scanf("%d", &i1);
  printf("Enter end number: ");
  scanf("%d", &i2);
  for(i=i1-1;i<i2;i++){
    printf("%-15d%s\n", i+1, (a+i+1)->word);
  }
  fclose(f1);
  fclose(f2);
  free(a);
  return 0;
}
