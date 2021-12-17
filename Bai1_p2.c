#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 50
typedef struct Adress { 
   char name[MAX];
   char phone[MAX];
   char email[MAX];
   struct Adress *next;
} danhsach;

void cap_nhat_danh_sach(danhsach *thong_tin, char name[], char phone[], char email[]);
void tim_kiem(danhsach *thong_tin, char name[]);

int main() {
   // Doc File
   int n;
   FILE *input = fopen("input.txt", "r");
   if(input == NULL) printf("Doc danh sach khong thanh cong\n");
   else printf("Doc danh sach thanh cong");

   danhsach *root = NULL;

   root = (danhsach *)malloc(sizeof(danhsach));

   fscanf(input, "%d", &n);
   for (int i = 0; i < n; i++) {
      char name[MAX], email[MAX], phone[MAX];
      fscanf(input, "%s", name);
      fscanf(input, "%s", phone);
      fscanf(input, "%s", email);
      cap_nhat_danh_sach(root, name, phone, email);
   }

   printf("Doc du lieu thanh cong, danh sach la :\n");
   // in ra toàn bộ danh sách 
   danhsach *tmp = root;
   while (tmp != NULL) {
      printf("%s %s %s\n", tmp->name, tmp->phone, tmp->email);
      tmp = tmp->next;
   }

   int chuc_nang;
   do {
       printf("\n**********************Menu**********************\n");
       printf("1) Tim kiem theo ten \n");
       printf("2) Thoat chuong trinh \n");
       printf("\nNhap chuc nang ");
       scanf("%d", &chuc_nang);
      char tmp[MAX];
      switch (chuc_nang) {
      case 1:{
         printf("Nhap ten can tim : ");
         scanf("%s", tmp);
         tim_kiem(root, tmp);
      }break;

      case 2: printf("Ket thuc chuong trinh : "); exit(0); break; 

      default: printf("Nhap lai chuc nang \n") ; break;
      }
   } while (5);
   fclose(input);
}


// truyền tên, số điện thoại, email vào danh sách 
void cap_nhat_danh_sach(danhsach *thong_tin, char name[], char phone[], char email[]) {
   danhsach *tmp = thong_tin;
   tmp = (danhsach *)malloc(sizeof(danhsach));
   strcpy(tmp->name, name);
   strcpy(tmp->phone, phone);
   strcpy(tmp->email, email);
   tmp->next = NULL;
   while (thong_tin->next != NULL) {
      thong_tin = thong_tin->next;
   }
   thong_tin->next = tmp;
}

// Tim kiem theo ten
void tim_kiem(danhsach *thong_tin, char name[]) {
   danhsach *thong_tinNode;
   thong_tinNode = thong_tin;
   while (thong_tinNode != NULL) {
      if (strcmp(thong_tinNode->name, name) == 0) {
         printf("Tim kiem thanh cong : %s %s %s\n", thong_tinNode->name, thong_tinNode->phone, thong_tinNode->email);
         return;
      }
      thong_tinNode = thong_tinNode->next;
   }
   printf("Tim kiem khong thanh cong ");
}
