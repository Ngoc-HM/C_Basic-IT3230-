#include<stdio.h>
typedef struct{
  char model[40];
  char space[10];
  char ssize[15];
  char price[20];
} phonedb;
#include "GenDLL.h"
phonedb inputnode(){
  phonedb a;
  printf("Enter model: ");scanf("%s",a.model);
  printf("Enter space: ");scanf("%s",a.space);
  printf("Enter screen size: "); scanf("%s",a.ssize);
  printf("Enter price: "); scanf("%s",a.price);
  return a;
}

void displaynode(node *p){
  if(p==NULL){
    printf("Null pointer error\n");
    return;
  }
  printf("%-30s%-10s%-10s%s\n",p->element.model,p->element.space,p->element.ssize,p->element.price);
}

void traversinglist(){
  node *p;
  for(p=root;p!=NULL;p=p->next){
    displaynode(p);
  }
  return;
}
int main(){
  int x;
  phonedb tmp;
  FILE *f1;
  printf("***************DOUBLY LINKED LIST***************\n");
  printf("1. Import from PhoneDB.dat(insertafter)\n");
  printf("2. Display (traverse)\n");
  printf("Your choice? ");
  scanf("%d", &x);
  switch(x){
  case 1:
    if((f1=fopen("PhoneDB.dat","r+b")) == NULL){
      printf("Cannot open file PhoneDB.dat\n");
      return 1;
    }
    if(fread(&tmp, sizeof(phonedb), 1, fin)!=NULL){
      inserathead(tmp);
    }
    printf("Done!\n");
    break;
  case 2:
    traversinglist();
    break;
  default break;
  }while(x!=12);
  return 0;
}
