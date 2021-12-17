#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<stdio_ext.h>
#define MAX 100
char *subStr(char *s1, int offset, int number){
  char *result;
  int i,n;
  
  if(offset < 0  ||number < 0){
    printf("ERROR SYNTAX!\n");
    printf("TRUE SYNTAX: subStr( <string name>, <character>, number(>=0)).\n");
    exit(1);
    }
  result=(char*)malloc((number+1)*sizeof(char));
  if(result == NULL){
    printf("Cannot allocate memory!\n");
    exit(1);
  }
  for(i=0;i<number;i++){
    *(result+i) = *(s1+offset+i);
  }
  return result;
}


int main(){
  char s1[MAX], *s2;
  int offset, number;
  printf("Enter string: ");
  gets(s1);
  printf("Enter offset:");
  scanf("%d", &offset);
  __fpurge(stdin);
  printf("Enter number:");
  scanf("%d", &number);
  s2 = subStr(s1, offset, number);
  printf("Substring is: %s\n",s2);
  free(s2);
  return 0;
}
