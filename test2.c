#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<stdio_ext.h>

typedef struct{
  char name[30];
  char tel[12];
  char email[30];
} address;

struct list_el{
  address addr;
  struct list_el *next;
};
typedef struct list_el node_addr;
typedef address elementtype;
#include "linklist.h"
address readnode(){
  address a;
  printf("Enter name: "); gets(a.name);
  printf("Enter tel: "); gets(a.tel);
  printf("Enter email: "); gets(a.email);
  return a;
}

void displaynode(node_addr *p){
  printf("%-20s%-20s%-30s\n",p->addr.name,p->addr.tel,p->addr.email);
  return;
}

void traversinglist(){
  node_addr *p;
  for(p=root;p!=NULL;p=p->next){
    displaynode(p);
  }
  return;
}


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
