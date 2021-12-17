#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<stdio_ext.h>
typedef  struct node{
  elementtype element;
  struct node *next;
} node;

node *root=NULL, *cur = NULL, *prev = NULL;
node *makenewnode(elementtype element){
  node *new=(node*)malloc(sizeof(node));
  new->element=element;
  new->next=NULL;
  return new;
}
void insertathead(elementtype element){
  node  *new=makenewnode(element);
  if(root==NULL){
    root=new;
    cur=root;
    prev=NULL;
  } else{
    new->next=root;
    root=new;
    cur=root; // cap nhat con tro cur
  } 
}
void insertaftercurrent(elementtype element){
  node *new=makenewnode(element);
  if(root == NULL){
    root=new;
    cur=root;
  } else if(cur == NULL){
    printf("Current pointer is NULL.\n");
    return;
  }
  else{
    new->next=cur->next;
    cur->next=new;
    prev=cur;/*Update prev for use later*/
    cur=cur->next;
  }
  return;
}
void insertbefore(elementtype element){
  node *new=makenewnode(element);
  if(root==NULL){
    root=new;
    cur=root;
    prev=NULL;
  } else{
    new->next = cur;
    /* Neu cur o dau danh sach */
    if(cur==root){
      root=new;
    } else prev->next=new;
    cur=new;
  }
return;
}
void deletefirst(){
  node *p;
  p=root;
  root=root->next;
  cur=root;
  /*prev = NULL*/
  free(p);
  return;
}
void deletecurrent(){
  if(cur==NULL) return;
  if(cur == root) deletefirst();
  else{
    prev->next=cur->next;
    free(cur);
    cur=prev->next;
  }
}
void freelist(){
  node *freelist;
  while(root!=NULL){
    freelist=root;
    root=root->next;
    free(freelist);
  }
}
node* list_reverse(node* root){
  node *cur, *prev;
  cur = prev = NULL;
  while(root != NULL){
    cur = root;
    root = root->next;
    cur->next = prev;
    prev = cur;
  }
  root=cur;
  return prev;
}
