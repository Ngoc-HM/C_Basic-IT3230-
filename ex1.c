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
node_addr *root = NULL, *cur = NULL, *prev = NULL;
node_addr* makenewnode(address addr){
  node_addr* new = (node_addr*)malloc(sizeof(node_addr));
  new->addr=addr;
  new->next = NULL;
  return new;
}
address readnode(){
  address tmp;
  __fpurge(stdin);
  printf("Nhap ho ten: ");
  gets(tmp.name);
  __fpurge(stdin);
  printf("Nhap so dien thoai: ");
  gets(tmp.tel);
  __fpurge(stdin);
  printf("Nhap email: ");
  gets(tmp.email);
  return tmp;
}
void displaynode(node_addr* p){
  if(p==NULL){
    printf("Loi con tro NULL\n");
    return;  
  }
  printf("Name: %s\n", (*p).addr.name);
  printf("Tel: %s\n", (*p).addr.tel);
  printf("Email: %s\n",(*p).addr.email);
  return ;
}
void traversinglist(){
  node_addr *p;
  for(p=root;p!=NULL;p=p->next){
    displaynode(p);
  }
  return;
}
void insertathead(address addr){
  node_addr *new=makenewnode(addr);
  if(root==NULL){
    root=new;
    cur=root;
  } else{
  new->next=root;
  root=new;
  cur=root;
  }
}
void insertaftercurrentpos(address addr){
  node_addr *new=makenewnode(addr);
  if(root==NULL){
    root=new;
    cur=root;
  }else if(cur == NULL){
    printf("Current pointer is NULL.\n");
    return;
  }
  else{
    new->next = cur->next;
    cur->next = new;
    prev = cur; /* Update prev for use later*/
    cur=cur->next;
  }
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
void deletecurrentelement(){
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
int main(){
  address tmp;
  int i;
  // testing at step 1 with makenewnode(), readnode, displaynode function
  /*
    tmp= readnode();
    root= makenewnode(tmp);
    displaynode(root); */
  // testing insertathead
  
  for(i=0;i<2;i++){
    insertathead(readnode());
  }
  traversinglist();
  printf("Testing for the insertion after current position of pointer. Before insert..\n");
  traversinglist();
  for(cur=root;cur->next != NULL; cur=cur->next);
  tmp = readnode();
  insertaftercurrentpos(tmp);
  traversinglist(root);
  printf("Testing for the insertion before current position of pointer. before insert..\n");
  tmp = readnode();
  insertbeforecurrent(tmp);
  traversinglist();
  // test deletion tasks
  printf("Testing for the deletion o the first element..\n");
  deletefirstelement();
  traversinglist();
  printf("Testing for the deletion of the middle element..\n");
  deletecurrentelement();
  traversinglist();
  return 0;
}
