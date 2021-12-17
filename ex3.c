#include<stdio.h>
int multiply(int n1, int n2){
  if(n1==1){
    return n2; 
  } else
    return (n2+multiply(n1-1,n2));
}
int main(){
  int n1, n2;
  scanf("%d", &n1);
  scanf("%d", &n2);
  printf("%d\n",multiply(n1,n2));
  return 1;
}
