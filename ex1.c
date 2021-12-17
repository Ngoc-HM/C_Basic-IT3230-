#include<stdio.h>
typedef int element;
#include "queuelist.h"
int main(){
  queue *front=NULL, *rear=NULL;
  int a[5];
  int i;
  printf("Enter 5 numbers:\n");
  for(i=0;i<5;i++){
    scanf("%d",&a[i]);
  }
  for(i=0;i<5;i++){
    enQ(&front, &rear, a[i]);
  }
  for(i=0;!empty(front);i++){
    printf("%d\n", deQ(&front, &rear));
    }
  return 0;
}
