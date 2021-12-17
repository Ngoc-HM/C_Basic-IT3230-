#include<stdio.h>
#include<stdlib.h>
typedef struct linklist{
  int x;
  struct linklist *next;
} ilist;
ilist *root, *cur;
ilist *makenewnode(int x){
  ilist *new=(ilist*)malloc(sizeof(ilist));
  new->x=x;
  new->next=NULL;
  return new;
}
int readlist(){
  int x;
  printf("Nhap so nguyen x: ");
  scanf("%d",&x);
  return x;
}
void insertathead(int x){
  ilist *new=makenewnode(x);
  if(root==NULL){
    root=new;
  } else{
    new->next=root;
    root=new;
    cur=root;
  }
  return;
}
void displaynode(ilist *p){
  if(p==NULL){
    printf("loi con tro null\n");
    return;
  }
  printf("%d\n",p->x);
  return;
}
void traversinglist(){
  ilist *p;
  for(p=root;p!=NULL;p=p->next){
    printf("%d\n",p->x);
  }
  return;
}
int main(){
  int n,i;
  printf("Nhap so luong so nguyen ban muon: ");
  scanf("%d", &n);
  for(i=0;i<n;i++){
    int x=readlist();
    insertathead(x);
  }
  traversinglist();
  return 0;
}


  
  
