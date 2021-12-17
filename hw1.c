#include<stdio.h>
#include<stdlib.h>
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

void traversinglist(){
  node *p;
  for(p=root;p!=NULL;p=p->next){
    displaynode(p);
  }
  return;
}
int main(){
  int x,x1;
  char s[100];
  phonedb tmp;
  node *p;
  FILE *f1;
  do{
    printf("***************DOUBLY LINKED LIST***************\n");
    printf("1. Import from PhoneDB.dat(insertafter)\n");
    printf("2. Display (traverse)\n3. add a new phone\n4. Insert at position\n");
    printf("5. Delete at position\n");
    printf("6. Delete current\n");
    printf("7. Delete first\n");
    printf("8. Delete last\n");
    printf("9. Search and Update\n");
    printf("10.Reverse list\n");
    printf("11. Save to file\n");
    printf("12. exit(free)\n");
    printf("Your choice? ");
    scanf("%d", &x);
    switch(x){
    case 1:
      root=NULL; cur=NULL; tail=NULL;
      if((f1=fopen("PhoneDB.dat","r+b")) == NULL){
	printf("Cannot open file PhoneDB.dat\n");
	return 1;
      }
      while(fread(&tmp, sizeof(phonedb), 1, f1)){
	insertaftercurrent(tmp);
      }
      fclose(f1);
      printf("Done!\n");
      break;
    case 2:
      traversinglist();
      break;
    case 3:
      do{
	printf("Add a new phone\n");
	printf("1. insertbefore\n2.insertafter\n3. insertatfirst\n4. insertappend\n5. exit\n");
	printf("your choice? ");
	scanf("%d", &x1);
	switch(x1){
	case 1: insertbeforecurrent(inputnode());break;
	case 2: insertaftercurrent(inputnode());break;
	case 3: insertathead(inputnode()); break;
	case 4: insertatlast(inputnode()); break;
	default: break;
	}
      } while(x1!=5);
      break;
    case 4:
      
      printf("Enter position: ");
      scanf("%d",&x1);
      if(x1<0){
	printf("x1 need > 0\n");
	break;
      }
      insertatpos(inputnode(), x1);
      printf("Done!\n");
      break;
    case 5:
      printf("Enter position: ");
      scanf("%d", &x1);
      if(x1<0){
	printf("x1 must >0\n");
	break;
      }
      deleteatpos(x1);
      printf("Done!\n");
      break;
    case 6:
      deletecurrent();
      printf("Done!\n");
      break;
    case 7:
      deletefirst();
      printf("Done!\n");
      break;
    case 8:
      deletelast();
      printf("Done!\n");
      break;
    case 9:
      printf("Enter model: ");
      scanf("%s", s);
      for(p=root;p!=NULL;p=p->next){
	if(strcmp(p->element.model,s)==0){
	  displaynode(p);
	  printf("Start update\n");
	  p->element=inputnode();
	}
      }
    case 10:
      reverselist();
      printf("Done!\n");
      break;
    case 11:
      if((f1=fopen("PhoneDB.dat","r+b")) == NULL){
	printf("Cannot open file PhoneDB.dat\n");
	return 1;
      }
      for(p=root;p!=NULL;p=p->next){
	fwrite(&p->element,sizeof(phonedb), 1, f1);
      }
      fclose(f1);
      printf("Done\n");
      break;
    default:
      break;
    }
  } while(x!=12);
  freelist();
  return 0;
}
