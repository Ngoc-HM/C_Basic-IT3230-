#include<stdio.h>
#include<stdlib.h>
#include<string.h>
char* my_strcat(char *s1, char *s2){
  int i;
  int len1, len2;
  len1 = strlen(s1);
  len2 = strlen(s2);
  char *result;
  result=(char*)malloc((len1+ len2+ 1)*sizeof(char));
  if(result == NULL){
    printf("loi bo nho, kiem tra lai\n");
    return NULL;
  }
  for(i=0;i<len1;i++){
    result[i]=s1[i];
  }
  for(i=0;i<len2;i++){
    result[i+len1] = s2[i];
  }
  result[len1+len2+1]='\0';
  return result;
}
int main(){
  char s1[100], s2[100];
  char *s3;
  
  printf("Nhap s1: ");
  gets(s1);
  printf("Nhap s2: ");
  fgets(s2, sizeof(s2), stdin);
  s3=my_strcat(s1,s2);
  printf("chuoi noi: %s", s3);
 // free(result);
  return 0;
}
