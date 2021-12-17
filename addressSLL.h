#include<stdio.h>
#include<stdlib.h>
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
node_addr *root = NULL, *cur = NULL, *prev = NULL;
node_addr* makenewnode(address addr){
  node_addr* new = (node_addr*)malloc(sizeof(node_addr));
  new->addr=addr;
  new->next = NULL;
  return new;
}
void insertathread(address addr){
  node_addr *new=makenewnode(addr);
  if(root==NULL){
    root=new;
    cur=root;
  }
  new->next=root;
  root=new;
  cur=root;
}
void insertaftercurrentpos(address addr){
  node_addr *new=makenewnode(addr);
  if(root == NULL && cur==NULL){
    return;
  }
  if(root == NULL){
    root=new;
    cur = root;
  }else{
    new->next = cur->next;
    cur->next=new;
    cur=cur->next;
  }
  return;
}
void insertbeforecurrent(address addr){
  node_addr *new=makenewnode(addr);
  if(root == NULL){
    root = new;
    cur = root;
    prev = NULL;
  } else {
    new->next=cur;
    if(cur == root){
      root = new;
    }
    else prev->next=new;
    cur = new;
  }
}
void deletefirstelement(){
  node_addr *del;
  del = root;
  root=root->next;
  free(del);
}
void deletefrommiddle(){
  node_addr *del = root;
  if(cur == NULL){
    return;
  }
  if(cur == root) deletefirstelement();
  else{
    prev->next = cur->next;
    free(cur);
    cur = prev->next;
  }
  return;
}
node_addr *list_reverse(node_addr *root){
  node_addr *cur, *prev;
  cur = prev = NULL;
  while(root != NULL){
    cur = root;
    root = root->next;
    cur->next = prev;
    prev = cur;
  }
  return prev;
}
