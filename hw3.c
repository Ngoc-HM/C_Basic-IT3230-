#include<stdio.h>
#include<stdlib.h>
#include<string.h>
typedef struct {
  char model[40];
  char space[10];
  char ssize[15];
  char price[20];
} phonedb;
#include "GenSLL.h"

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

void traversinglist(node *root){
  node *p;
  for(p=root;p!=NULL;p=p->next){
    displaynode(p);
  }
  return;
}

int main(){
  FILE *fptr;
  int x, n1, n2, x1;
  char s[100];
  node *p;
  phonedb *a=(phonedb*)malloc(sizeof(phonedb));
  if((fptr=fopen("PhoneDB.dat","r+b"))==NULL){
    printf("Cannot open %s\n","PhoneDB.dat");
    return 1;
  }
  do{
    printf("1. Import from PhoneDB.dat(insertafter)\n2. Display (traverse)\n\
3. Add new phone(inserbefore/after)\n4. Insert at Position\n5. Delete at Position\n\
6. Delete current\n7. Delete first\n8.Search and update(search by model-update all field of information)\n9.Divide and extract(split)\n10. Reverse list\n11. Save to file\n12. Quit(free)\n  ");
    printf("\nEnter your choice: ");
    scanf("%d", &x);
    switch(x){
    case 1:
       root=NULL;cur=NULL;prev=NULL;
      if(fseek(fptr, 0, SEEK_SET) != 0){
	printf("Fseek failed!\n");
      }
      while(fread(a,sizeof(phonedb),1,fptr)!=0){
	insertaftercurrent(*a);
      }
      printf("successfully\n");
      break;
    case 2:
      traversinglist(root);
      break;
    case 3:
      do{
	printf("Enter your choice( 1 to insert after, 2 to insert before, 0 to quit\n");
	scanf("%d", &x1);
	switch(x1){
	case 1:
	  insertaftercurrent(inputnode());
	  break;
	case 2:
	  insertbefore(inputnode());
	  break;
	default:
	  break;
	}
      } while(x1!=0);
      break;
    case 4:
      printf("before insert..\n");
      printf("Enter position: ");
      scanf("%d", &x1);
      insertatposition(inputnode(), x1);
      break;
    case 5:
    printf("Before delete...\n");
    printf("Enter position: ");
    scanf("%d", &x1);
    deleteatposition(x1);
    break;
    case 6:
      deletecurrent();
      printf("Successfully!\n");
      break;
    case 7:
      deletefirst();
      printf("Successfully!\n");
      break;
    case 8:
      printf("Enter model: ");
      scanf("%s",s);
      for(p=root;p!=NULL;p=p->next){
	if(strcmp(s, p->element.model)==0){
	  displaynode(p);
	}
      }
      p->element=inputnode();
      printf("Completely!\n");
      break;
    case 9:
      printf("Enter n1(start position): ");
      scanf("%d", &n1);
      printf("Enter n2(number of element): ");
      scanf("%d", &n2);
      printtotext(splitlist(n1, n2),"congaduc");
      printf("Done\n");
      break;
    case 10:
      root=list_reverse();
      printf("Done!\n");
      break;
    case 11:
      if(fseek(fptr, 0, SEEK_SET) !=0){
	  printf("Fseek failed!\n");
	  return 1;
	}
      for(p=root;p!=NULL;p=p->next){
	fwrite(&p->element, sizeof(elementtype),1 , fptr);
      }
      printf("Done!\n");
	break;
    case 12:

      freelist();
      printf("Done!\n");
    }
  } while(x!=12);
  fclose(fptr);
  return 0;
}
