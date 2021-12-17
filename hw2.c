#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<stdio_ext.h>
#define MAX 200
typedef struct{
  int no;
  int Student_number;
  char First_name[30];
  char phone_number[15];
  double score;
} student;
int main(int argc, char *argv[])
{
  if(argc != 3){
    printf("ERROR SYNTAX\n");
    printf("TRUE SYNTAX: hw2 <filename1> <filename2>\n");
    exit(1);
  }
  student *a;
  char buff[MAX];
  FILE *fin, *fout;
  int n1, n2 = 1, n3 , count = 0, i = 0;
  fin = fopen(argv[1],"r");
  fout = fopen(argv[2], "w");
  if(fin == NULL){
    printf("cannot open %s\n",argv[1]);
    exit(1);
  }
  if(fout == NULL){
    printf("Cannot open %s\n",argv[2]);
    exit(2);
  }
  while(fgets(buff, MAX, fin) != NULL){
    count ++;
  }
  rewind(fin);
  a=(student*)malloc(count*sizeof(student));
  while(fscanf(fin,"%d%d%s%s",&(a+i)->no,&(a+i)->Student_number,(a+i)->First_name,(a+i)->phone_number) != EOF){
     printf("%-10d%-10d%-24s%-15s\n",(a+i)->no,(a+i)->Student_number,(a+i)->First_name,(a+i)->phone_number);
     i++;
  }
  n1 = i;
  for(i=0;i<n1;i++){
    printf("Diem  sinh vien %d: ",i+1);
    scanf("%lf",&(a+i)->score);
    }
  
  for(i=0;i<n1;i++){
    fprintf(fout,"%-10d%-10d%-24s%-15s%.2lf\n",(a+i)->no,(a+i)->Student_number,(a+i)->First_name,(a+i)->phone_number,(a+i)->score);
      }
  while(n2 != 0){
    n3 = n1;
    printf("Nhap so sinh vien muon them( Nhap 0 de thoat)\n");
    scanf("%d",&n2);
    n1=n1+n2;
    a=(student*)realloc(a, n1*sizeof(student));
    if( a == NULL){
      printf("Memory allocation failed.\n");
      exit(1);
    }
    for(i=0;i<n2;i++){
      printf("sinh vien thu %d:\n",n3+1+i);
      
      printf("mssv: ");
      scanf("%d",&(a+n3+i)->Student_number);
      printf("Ho va ten( ko co dau cach): ");
      scanf("%s",(a+n3+i)->First_name);
      __fpurge(stdin);
      printf("So dien thoai: ");
      scanf("%s",(a+n3+i)->phone_number);
      __fpurge(stdin);
      printf("Diem: ");
      scanf("%lf", &(a+n3+i)->score);
    }
  }
  for(i= count;i<n1;i++){
    fprintf(fout,"%-10d%-10d%-24s%-15s%.2lf\n",-(i+1),(a+i)->Student_number,(a+i)->First_name,(a+i)->phone_number,(a+i)->score);
  }
  fclose(fin);
  fclose(fout);
  free(a);
  return 0;
}
