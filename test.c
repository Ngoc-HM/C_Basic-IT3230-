#include<stdio.h>
#include<string.h>
#include<math.h>
int main(){
  char s[100];
  char c;
  int sum=0,x;
  int count,i,a[26];
  printf("Nhap chuoi: ");
  gets(s);
  for(i=0;i<strlen(s);i++);
  printf("So ki tu trong chuoi la: %d\n", i);
  for(i=0;i<26;i++){
    a[i]=0;
  }
  for(i=0;i<strlen(s);i++){
    if(s[i]>='A' && s[i]<='Z'){
      ++a[s[i]-'A'];
    }
  }
  for(i=0;i<26;i++){
    if(a[i] > 0){
      printf("Ki tu %c xuat hien %d lan\n", i+'A', a[i]);
    }
  }
  
  return 0;
}
