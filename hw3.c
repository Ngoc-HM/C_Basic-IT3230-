 #include<stdio.h>
#define MAX 100
typedef struct{
  int no;
  int Student_number;
  char First_name[30];
  char phone_number[15];
  double score;
} student;
int main(int argc,char *argv[]){
  if(argc != 3){
    printf("ERROR SYNTAX!\n");
    printf("TRUE SYNTAX: hw5 <filename1> <filename2>.\n");
        return 1;
  }
  student arr[MAX];
  int i=0,n;
  FILE *f1,*f2;
  f1=fopen(argv[1],"r");
  f2=fopen(argv[2],"w");
  if(f1 == NULL){
    printf("Cannot open %s\n",argv[1]);
    return 1;
  }
  if(f2 == NULL){
    printf("Canot open %s\n",argv[2]);
    return 1;
  }
  while(fscanf(f1,"%d%d%s%s",&arr[i].no,&arr[i].Student_number,arr[i].First_name,arr[i].phone_number) != EOF){
    printf("%-10d%-10d%-20s%-15s\n",arr[i].no,arr[i].Student_number,arr[i].First_name,arr[i].phone_number);
    i++;
  }
  n=i;
  for(i=0;i<n;i++){
    printf("Nhap diem sinh vien thu %d: ",i+1);
    scanf("%lf",&arr[i].score);
  }
  for(i=0;i<n;i++){
    fprintf(f2,"%d %d %s %s %.2lf\n",arr[i].no,arr[i].Student_number,arr[i].First_name,arr[i].phone_number,arr[i].score);
  }
  return 0;	
}
