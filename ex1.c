#include<stdio.h>
#include<stdlib.h>
int main(void){
  int i, n, *p;
  printf("How many numbers do you want to enter?\n");
  scanf("%d", &n);

  /* Allocate an int array of the proper size */
  p =(int *)malloc(n*sizeof(int));
  if( p == NULL){
    printf("Memory allocation fail!\n");
    return 1;
  }
  for(i=0;i<n;i++){
    printf("Phan tu %d: ",i+1);
    scanf("%d",&p[i]);
  }
  for(i=n-1;i>=0;--i){
    printf("%d\n",p[i]);
  }
  // free the allocated space
  free(p);
  return 0;
}
