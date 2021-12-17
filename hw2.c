#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define MAX 500
typedef struct{
  char model[40];
  char space[10];
  char ssize[15];
  char price[20];
} phonedb;
int main(){
  int y,x,i,n=0,irc,m1,m2;
  FILE *fin,*fout;
  phonedb *a,*b;
  char s[MAX];
  fin = fopen("PhoneDB.txt","r");
  fout= fopen("PhoneDB.dat","w+b");
  if(fin == NULL){
    printf("Cannot open %s\n","PhoneDB.txt");
    return 1;
  }
  if(fout == NULL){
    printf("Cannot open %s\n","PhoneDB.dat");
    return 1;
  }
  while(fgets(s, MAX,fin) != NULL){
    n++;
  }
  a=(phonedb*)malloc(n*sizeof(phonedb));
  if(a == NULL){
    printf("Memory allocation failed!\n");
    return 1;
  }
  if(fseek(fin,0,SEEK_SET) != 0){
    printf("Fseek failed!\n");
    return 1;
  }
  do{
    printf("*********Phone catalog*******\n");
    printf("1. Import DB from text\n");
    printf("2. Import from  DB\n");
    printf("3. Print All Database\n4. Search by  phone Model\n");
    printf("5. Exit\n");
    printf("Enter your choose: ");
    scanf("%d",&x);
    switch(x){
    case 1:
      i=0;
      while(fscanf(fin,"%s%s%s%s",(a+i)->model,(a+i)->space,(a+i)->ssize,(a+i)->price) != EOF){
	i++;
      }
      irc=fwrite(a, sizeof(phonedb), n, fout);
      if(fseek(fout, 0, SEEK_SET) != 0){
	printf("Fseek failed!\n");
	return 1;
      }
      getchar();
      break;
    case 2:
      printf("Enter your choose(1 to read from begining of file, 2 to read from end of file: ");
      scanf("%d",&y);
      switch(y){
      case 1:
	printf("Enter start position:(1->%d) ",n);
	scanf("%d", &m1);
	while(m1<1||m1>n){
	  printf("Re-enter start position: ");
	  scanf("%d", &m1);
	}
	printf("Enter the number of record you want to read: ");
	scanf("%d", &m2);
	b = (phonedb*)malloc((m1+m2)*sizeof(phonedb));
	if(b==NULL){
	  printf("Memory allocation failed!\n");
	  return 1;
	}
	if(fseek(fout, (m1-1)*sizeof(phonedb), SEEK_SET) !=0){
	  printf("Fseek failed!\n");
	  return 1;
	}
      fread(b, sizeof(phonedb), m2, fout);
      for(i=0;i<m2;i++){
	  printf("%-30s%-9s%-9s%-15s\n",(b+i)->model,(b+i)->space,(b+i)->ssize,(b+i)->price);
	}
      break;
      case 2:
	printf("Enter start position:(1->%d) ",n);
	scanf("%d", &m1);
	while(m1<1||m1>n){
	  printf("Re-enter start position: ");
	  scanf("%d", &m1);
	}
	printf("Enter the number of record you want to read: ");
	scanf("%d", &m2);
	b = (phonedb*)malloc((m1+m2)*sizeof(phonedb));
	if(b==NULL){
	  printf("Memory allocation failed!\n");
	  return 1;
	}
	if(fseek(fout, (m1-m2)*sizeof(phonedb), SEEK_SET) !=0){
	  printf("Fseek failed!\n");
	  return 1;
	}
	fread(b, sizeof(phonedb), m2, fout);
	for(i=0;i<m2;i++){
	  printf("%-30s%-9s%-9s%-15s\n",(b+i)->model,(b+i)->space,(b+i)->ssize,(b+i)->price);
	}
	break;
      }
	break;
	
    case 3:
      if(fseek(fout, 0, SEEK_SET) !=0){
	printf("Fseek failed!\n");
	return 1;
      }
      fread(a, sizeof(phonedb), n,fout);
      for(i=0;i<n;i++){
	printf("%-30s%-9s%-20s%-15s\n",(a+i)->model,(a+i)->space,(a+i)->ssize,(a+i)->price);
      }
      printf("Enter to continue\n");
      getchar();
      break;
    case 4:
      while(strcmp(s,"0") != 0){
	printf("Enter phone model (0 to exit):  ");
	scanf("%s",s);
	for(i=0;i<n;i++){
	  if(strcmp((a+i)->model,s) == 0){
	    printf("%-30s%-9s%-20s%-15s\n",(a+i)->model,(a+i)->space,(a+i)->ssize,(a+i)->price);
	  } 
	}
      }
      printf("Enter to continue\n");
      getchar();
      break;
    default: break;
    }
  } while(x != 5);
  fclose(fin);
  fclose(fout);
  free(a);
  free(b);
  return 0;
}
