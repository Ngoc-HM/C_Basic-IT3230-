#include<stdio.h>
#include<stdlib.h>
#include<string.h>
typedef element elementtype;
typedef struct node node;
struct node{
  elementtype element;
  node *prev;
  node *next;
};
node *root=NULL, *cur=NULL, *tail=NULL;
node *makenewnode(elementtype e){
  node *new=(node*)malloc(sizeof(node));
  new->element=e;
  new->next=NULL;
  new->prev=NULL;
  return new;
}
void insertathead(elementtype e){
  node *new=makenewnode(e);
  if(root==NULL){
    root=new;
    tail=new;
    cur=root;
  }else{
    new->next=root;
    root->prev=new;
    new->prev=NULL;
    root=new;
    cur=root;
  }
}
void insertatlast(elementtype e){
  node *new=makenewnode(e);
  if(root==NULL){
    root=new;
    tail=new;
    cur=root;
  } else{
    tail->next=new;
    new->prev=tail;
    new->next=NULL;
    tail=new;
  }
}
void insertatpos(elementtype e, int n){
  if(root==NULL){
    insertathead(e);
    return;
  }
  if(n==0){
    insertathead(e);
    return;
  }
  node *p;
  int i;
  node *new=makenewnode(e);
  for(p=root, i=1;p!=NULL&&i<n;p=p->next,i++);
  if(p==NULL){
    insertatlast(e);
    return;
  }
  new->next=p->next;
  p->next->prev=new;
  p->next=new;
  new->prev=p;
  cur=p->next;
}

void insertaftercurrent(elementtype e){
  node *new=makenewnode(e);
  if(root==NULL){
    root=new;
    tail=new;
    cur=root;
  }else{
    new->next=cur->next;
    if(cur->next!=NULL)
    cur->next->prev=new;
    cur->next=new;
    new->prev=cur;
    cur=cur->next;
  }
  if(new->next==NULL) tail=new;
  return;
}
void insertbeforecurrent(elementtype e){
  node *new=makenewnode(e);
  if(root==NULL){
    root=new;
    tail=new;
    cur=root;
  }else{
    new->prev=cur->prev;
    if(cur->prev != NULL){
      cur->prev->next=new;
    }
    new->next=cur;
    cur->prev=new;
    cur=new;
    if(new->prev==NULL) root=new;
  }
  
}
void deletefirst(){
  node *p;
  p=root;
  root=root->next;
  cur=root;
  cur->prev=NULL;
  free(p);
}
void deletelast(){
  node *p;
  p=tail;
  tail=tail->prev;
  cur=tail;
  tail->next=NULL;
  free(p);
}
void deletecurrent(){
  node *p=cur;
  if(cur==root){
    deletefirst();
    return;
  }
  if(cur==tail){
    deletelast();
    return;
  }
  cur->prev->next=cur->next;
  cur->next->prev=cur->prev;
  cur=cur->next;
  free(p);
}
void deleteatpos(int n){
  int i;
  node *p;
  if(n==0){
    deletefirst();
    return;
  }
  for(p=root, i=0;i<n&&p!=NULL;i++,p=p->next);
  if(p==NULL){
    deletelast();
    return;
  }
  p->prev->next=p->next;
  p->next->prev=p->prev;
  free(p);
}
void freelist(){
  node *del=root;
  while(del!=NULL){
    root=root->next;
    free(del);
    del=root;
  }
}


void  reverselist(){
  node *tmp, *cur=root;
  if(root==NULL){
    printf("Root points to NULL\n");
    return ;
  }
  while(cur!=NULL){
    tmp=cur->next;
    cur->next=cur->prev;
    cur->prev=tmp;
    cur=tmp;
  }
  tmp=root;
  root=tail;
  tail=tmp;
}
