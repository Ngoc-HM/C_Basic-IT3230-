#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#define MAX1 200
#define N 200
void CC(FILE *f1, FILE *f2){
  int c;
  while((c = fgetc(f1)) != EOF){
    fputc(c, f2);
  }
}
void CL(FILE *f1, FILE *f2){
  char s[MAX1];
  while(fgets(s, MAX1, f1) != NULL){
    fputs(s, f2);
  }
}
void CB(FILE *f1, FILE *f2){
  int irc;
  char s[N];
  irc = fread(s, sizeof(char), N, f1);
  fwrite(s, sizeof(char), N, f2);
}
int main(int argc, char *argv[]){
  if(argc != 3){
    printf("ERROR SYNTAX!\n");
    printf("TRUE SYNTAX: hw3 <filename1> <filename2>");
    exit(1);
  }
  int x;
  FILE *fin, *fout;
  double time_use;
  clock_t start,end;
  if((fin = fopen(argv[1],"r")) == NULL){
    printf("cannot open %s\n",argv[1]);
    return 1;
  }
  if((fout = fopen(argv[2],"w")) == NULL){
    printf("Cannot open %s\n",argv[2]);
   return 1;
  }
  do{
    printf("-----------MENU------------\n");
    printf("1. Copy by chracter\n");
    printf("2. Copy by line\n");
    printf("3. Copy by block-optinal size\n");
    printf("4. exit\n");
    
    printf("Enter your choose: ");
    scanf("%d",&x);
    switch(x){
    case 1:
      start = clock();
      CC(fin, fout);
      end = clock();
      time_use =(double)(end - start)/CLOCKS_PER_SEC;
      printf("Copy by character take %.5lf second\n", time_use);
      rewind(fin);
      rewind(fout);
      break;
    case 2:
      start = clock();
      CL(fin, fout);
      end = clock();
      time_use =(double)(end - start)/CLOCKS_PER_SEC;
      printf("Copy by line take %.5lf second\n", time_use);
      rewind(fin);
      rewind(fout);
      break;
    case 3:
      start = clock();
      CB(fin, fout);
      end = clock();
      time_use =(double)(end - start)/CLOCKS_PER_SEC;
      printf("Copy by line take %.5lf second\n", time_use);
      rewind(fin);
      rewind(fout);
      break;
    }
  } while(x!= 4);
  fclose(fin);
  fclose(fout);
  return 0;
}
