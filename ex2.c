#include<stdio.h>
#include<stdlib.h>
#define MAX 100
typedef struct{
  int no;
  int Student_number;
  char First_name[30];
  char phone_number[15];
  double score;
} student;
int main(int argc, char *argv[]){
  if(argc != 3){
    printf("ERROR SYNTAX.\n");
    printf("TRUE SYNTAX: readst <filename1> <filename2>\n");
    return 1;
  }
  FILE *fin, *fout;
  student *a;
  int i=0,n,x;
  if((fin = fopen(argv[1], "r")) == NULL){
      printf("Cannot open %s\n", argv[1]);
      return 1; 
    }
  if((fout = fopen(argv[2],"w+b")) == NULL){
    printf("Cannot open %s\n",argv[2]);
    return 1;
  }
  printf("So sinh vien: ");
  scanf("%d",&n);
  a = (student*)malloc(n*sizeof(student));
  while(fscanf(fin,"%d%d%s%s%lf",&(a+i)->no, &(a+i)->Student_number, (a+i)->First_name, (a+i)->phone_number, &(a+i)->score) != EOF ){
    i++;
  }
  fwrite(a, sizeof(student), n, fout);
  if(fseek(fout, 0, SEEK_SET) != 0){
    printf("Fseek failed\n");
    return 1;
  }
  fread(a, sizeof(student), n, fout);
  for(i=0;i<n;i++){
    printf("%-5d%-10d%-24s%-15s%.2lf\n",(a+i)->no, (a+i)->Student_number, (a+i)->First_name, (a+i)->phone_number, (a+i)->score);
  }
  printf("Start search and Update.\n");
  printf("Enter student number that you want to update mark:(enter 0 to exit) \n");
  scanf("%d", &x);
  while(x!=0){
    printf("Enter new mark for student %s\n", (a+x-1)->First_name);
    scanf("%lf", &(a+x-1)->score);
    if(fseek(fout, sizeof(student)*(x-1),SEEK_SET) != 0){
      printf("Fseek failed!\n");
      return 1;
    }
    fwrite(a+x-1,sizeof(student), 1, fout);
    printf("Enter student number that you want to update mark:(enter 0 to exit) \n");
  scanf("%d", &x);
  }
  fclose(fin);
  fclose(fout);
  return 0;
}
  
