#include<stdio.h>
int convertbinary(int x){
  if(x==0) return 0;
  else
    return x % 2 + 10*(convertbinary(x/2));
}
int main(){
  int x;
  printf("Nhap so he thap phan: ");
  scanf("%d", &x);
  printf("Ket qua: %d\n", convertbinary(x));
  return 0;
}
