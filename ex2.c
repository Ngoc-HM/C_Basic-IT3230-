#include<stdio.h>
int numberdown(int n){
  if(n>=1){
    printf("%d\n",n);
    numberdown(n-1);
  }
}
int numberup(int n){
  if(n<=50){
    printf("%d\n",n);
    numberup(n+1);
  }
}
int main(){
  int n1=50;
  numberdown(n1);
  numberup(1);
  return 0;
}
