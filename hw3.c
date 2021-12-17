#include<stdio.h>
char capital(char *a){
  if(*a>='A' && *a<='Z'){
    return *a;
  }
  if(*a=='\0'){
    return '\0';
  }
  return capital(++a);
}
int main(){
  char A[100], b;
  printf("Input string: ");
  gets(A);
  b=capital(A);
  if(b=='\0'){
    printf("Capital character is not exit\n");
    return 1;
  }
  printf("Capital character is: %c\n", b);
  return 0;
}
