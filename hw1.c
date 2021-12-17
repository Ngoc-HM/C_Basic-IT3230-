#include<stdio.h>
#include<string.h>
#define MAX 500
#define MAXl 10
int main(int argc, char  *argv[]){
  if( argc != 2 && argc != 3){
    printf("ERROR SYNTAX.\n");
    printf("TRUE SYNTAX: cat <filename> or cat <filename> -p \n");
    return 1;
  }
  char s[MAX];
  int count = 0,i=0;
  FILE *fptr;
  if(argc == 2){
    fptr = fopen(argv[1],"r");
    if(fptr == NULL){
      printf("Cannot open %s.\n",argv[1]);
      return 1;
    }
    while(fgets(s, MAX, fptr) != NULL){
      printf("%s",s);
    }
    fclose(fptr);
  }
  if(argc == 3){
    if(strcmp(argv[2],"-p") != 0 ){
      printf("ERROR SYNTAX:\n");
      printf("TRUE SYNTAX: cat <filename> or cat <filename> -p\n");
      return 1;
    } else
      {
	fptr=fopen(argv[1],"r");
	if(fptr == NULL){
	  printf("Cannot open %s.\n",argv[1]);
	  return 1;
	}
	while(fgets(s, MAX, fptr)!= NULL){
	  count++;
	  printf("%s",s);
	  if(count == MAXl){
	    ++i;
	    printf("%100d\n",i);
	    count =0;
	    getchar();
	  }
	}
	if(count < MAXl){
	    for(;count<MAXl;count++){
	      printf("\n");
	    }
	  }
	printf("%100d\n",i+1);
      }
  }
return 0;
}
