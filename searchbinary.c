#include<stdio.h>
#define notfound (-1)
typedef int elementtype;
int binarysearch(elementtype A[], elementtype x, int n){
  int low, mid, high;
  low=0;high=n-1;
  while(low<=high){
    mid=(low+high)/2;
    if(A[mid]<x)
      low=mid+1;
    else if(A[mid]>x)
      high=mid-1;
    else return mid-1; /*found*/
  }
  return notfound; /* notfound is define as -1*/
}
int main(){
  static int A[] = {1,3,5,7,9,13,15};
  int sizeofA=sizeof(A)/sizeof(A[0]);
  int i;
  for(i=0;i<20;i++)
    printf("Binarusearch of %d returns %d\n",i,binarysearch(A,i,sizeofA));
  return 0;
}
