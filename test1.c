#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<stdio_ext.h>
#include "linklist.h"
int main(){
  int i,x;
  do{
    printf("*******TEST*********\n");
    printf("1.test insertathead function.\n");
    printf("2.test insertaftercurrent function.\n");
    printf("3.Test insertbefore function.\n");
    printf("4.Test deletefirst function\n");
    printf("5.Test deletecurrent function.\n");
    printf("6.test freelist function\n");
    printf("7. Test list_reverse function\n");
    printf("8. Display list\n");
    printf("9. Exit\n");
  /* printf("testing 3 first! before test..\n");
  displaynode(makenewnode(readnode()));
  printf("\n\n");*/
    printf("Enter your choice: ");
    scanf("%d",&x);
    __fpurge(stdin);
    switch(x){
    case 1:
      printf("testing insertathead function. Before insert...\n");
      for(i=0;i<2;i++){
	insertathead(readnode());
      }
      traversinglist();
      printf("\n\n");
      break;
    case 2:
      printf("testing insertaftercurrent function. Before insert...\n");
      insertaftercurrent(readnode());
      traversinglist();
      printf("\n\n");
      break;
    case 3:
      printf("testing insertbefore function. Before insert...\n");
      insertbefore(readnode());
      traversinglist();
      break;
    case 8:
      traversinglist();
      break;
    case 4:
      printf("testing deletefirt function.\n");
      deletefirst();
      traversinglist();
      break;
    case 5:
      printf("Testing deletecurrent function\n");
      deletecurrent();
      traversinglist;
      break;
    case 6:
      freelist();
      break;
    case 7:
      printf("Testing list_reverse function!\n");
      list_reverse(root);
      traversinglist();
      break;
    }
  } while(x!=9);
  return 0;
  
}
