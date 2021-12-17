#include<stdio.h>
int sum(int n){
  int res;
  if(n==1){
    return 1;
  } else res= n+sum(n-1);
  return res;
}
int main(){
  int n;
  printf("Enter n: ");
  scanf("%d", &n);
  printf("%d\n", sum(n));
  return 0;
}
