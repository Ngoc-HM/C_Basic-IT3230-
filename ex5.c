#include<stdio.h>
#define MAX 100
typedef struct{
  char name[20];
  char tel[11];
  char email[25];
} phoneaddress;
int main(int argc, char *argv[]){
  if(argc != 2){
    printf("ERROR.\n");
    return 1;
  }
  phoneaddress arr[MAX];
  int n,i,irc;
  FILE *fin;
  fin= fopen(argv[1],"w+b");
  if(fin == NULL || fout == NULL){
    printf("Cannot open file.\n");
    return 0;
  }
  printf("Nhap so nguoi dung(<20): ");
  scanf("%d",&n);
  for(i=0;i<n;i++){
    printf("Nguoi dung %d: ",i+1);
    printf("ten: ");
    fgets(arr[i].name, sizeof(arr[i].name), stdin);
    printf("So dien thoai:");
    fgets(arr[i].tel, sizeof(arr[i].name), stdin);
    printf("Email: ");
    fgets(arr[i].email, sizeof(arr[i].email), stdin);
  }
  // write the entire array into the file
  
  irc = fwrite(arr, sizeof(phoneaddress), n, fin);
  printf("fwite return code = %d\n",irc);
  fclose(fin);
  // read from this file to array agian
  
      return 0;
}

