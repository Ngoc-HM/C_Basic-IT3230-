/*
* Trường CNTT & TT - Đại học Bách khoa Hà Nội 
* IT3220 - Lập Trình C Basic - Mã lớp : 126898
* Giảng viên : Trần Hồng Việt 
* Họ Tên : Hoàng Minh Ngọc - 20200440
*/
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX 50

typedef struct Address{
   char name[MAX];
   char phone[MAX];
   char email[MAX];
} danhsach;

danhsach List[100];

void push(danhsach *thong_tin, int i, char name[], char phone[], char email[]);
void hoan_doi_2_vi_tri(danhsach *x, danhsach *y);
void Tim_kiem(danhsach *thong_tin, char check[], int n, int option); 
void Tim_kiem_nhi_phan(danhsach *thong_tin, char name[], int n) ;
void sap_xep_theo_ten(danhsach *thong_tin, int n) ;


int main() {
  
   int n;
  
   FILE *input = fopen("input.txt", "r");

   if(input == NULL) printf("Doc danh sach loi\n");
   else printf("Doc danh sach thanh cong \n");
   // bắt đầu ghi danh sách 
   fscanf(input, "%d", &n);
   for (int i = 0; i < n; i++) {
      char name[MAX], email[MAX], phone[MAX];
      fscanf(input, "%s", name);
      fscanf(input, "%s", phone);
      fscanf(input, "%s", email);
      push(List, i, name, phone, email);
   }
   // in danh sách ra màn hình 
   printf("Danh sach la :\n");
   for (int i = 0; i < n; i++){
      printf("%s %s %s\n", List[i].name, List[i].phone, List[i].email);
   }

   // sắp xếp theo tên và in danh sách 
   sap_xep_theo_ten(List, n);
   printf("\n Danh sach sau khi da sap xep :\n");
   for (int i = 0; i < n; i++) {
      printf("%s %s %s\n", List[i].name, List[i].phone, List[i].email);
   }


   int chuongtrinh;
   
   do {
         printf("\n********************** Menu **********************\n");
         printf("1) Tim kiem theo ten \n");
         printf("2) Tim theo email\n");
         printf("3) Tim theo so dien thoai\n");
         printf("4) Tim kiem ten bang nhi phan \n");
         printf("5) Thoat chuong trinh \n");
         printf("***************************************************\n");
         printf("Chuc nang ban chon : ");
         scanf("%d", &chuongtrinh);
      char check[MAX];
      switch (chuongtrinh) {
      case 1: {

         printf("Nhap ten nguoi muon tim : "); scanf("%s", check);
         Tim_kiem(List, check, n, 1);
         printf("\nMoi ban nhap tiep chuong trinh\n");
         }   
         break;

      case 2: {
         printf("Nhap Email tim kiem: "); scanf("%s", check);
         Tim_kiem(List, check, n, 2);
         printf("\nMoi ban nhap tiep chuong trinh\n");
         }
         break;

      case 3:{
         printf("Nhap so dien thoai tim kiem : "); scanf("%s", check);
         Tim_kiem(List, check, n, 3);
         printf("\nMoi ban nhap tiep chuong trinh\n");
         }
         break;

      case 4:
         printf("Nhap ten nguoi can tim: "); scanf("%s", check);
         Tim_kiem_nhi_phan(List, check, n);
         printf("\nMoi ban nhap tiep chuong trinh\n");
         break;
      case 5:{printf("\nKet thuc chuong trinh, hen gap lai : \n"); exit(0);} ; break;
      default:
       printf("\nVui long nhap lai chuong trinh chuc nang tu 1->5 \n");
        break;
      }
   } while (1);
   fclose(input);
   return 0;
}

void push(danhsach *thong_tin, int i, char name[], char phone[], char email[]){
   strcpy((thong_tin+i)->name, name);
   strcpy((thong_tin+i)->phone, phone);
   strcpy((thong_tin+i)->email, email);
}

void hoan_doi_2_vi_tri(danhsach *x, danhsach *y){
   danhsach trung_gian;
   strcpy(trung_gian.name, y->name);
   strcpy(trung_gian.phone, y->phone);
   strcpy(trung_gian.email, y->email);
   strcpy(y->name, x->name);
   strcpy(y->phone, x->phone);
   strcpy(y->email, x->email);
   strcpy(x->name, trung_gian.name);
   strcpy(x->phone, trung_gian.phone);
   strcpy(x->email, trung_gian.email);
}

void Tim_kiem(danhsach *thong_tin, char check[], int n, int option) {
   int dieu_kien;
   for (int i = 0; i < n; i++) {
      dieu_kien = strcmp((thong_tin + i)->name, check);
      if (option == 1 && dieu_kien == 0) {
         printf("Tim kiem thanh cong : %s %s %s\n", (thong_tin+i)->name, (thong_tin+i)->phone, (thong_tin+i)->email);
         return;
      }
      dieu_kien = strcmp((thong_tin + i)->email, check) ; 
      if (option == 2 && dieu_kien == 0) {
         printf("Tim kiem thanh cong : %s %s %s\n", (thong_tin+i)->name, (thong_tin+i)->phone, (thong_tin+i)->email);
         return;
      }
      dieu_kien = strcmp((thong_tin + i)->phone, check) ;
      if (option == 3 && dieu_kien == 0) {
         printf("Tim kiem thanh cong : %s %s %s\n", (thong_tin+i)->name, (thong_tin+i)->phone, (thong_tin+i)->email);
         return;
      }
   }
   printf("Tim kiem khong thanh cong : \n ");
}

void Tim_kiem_nhi_phan(danhsach *thong_tin, char name[], int n) {
   int i = 0, max = n - 1;
   while (i <= max) {
      int trung_binh = (i + max) / 2;
      int so_sanh = strcmp(name, (thong_tin + trung_binh)->name);
      if (so_sanh == 0) {
         printf("Tim kiem thanh cong : %s %s %s\n", (thong_tin + trung_binh)->name, (thong_tin + trung_binh)->phone, (thong_tin + trung_binh)->email);
         return;
      }
      if (so_sanh > 0) i = trung_binh + 1;
      if (so_sanh < 0) max = trung_binh - 1;
   }
   printf(" Tim kiem khong thanh cong : \n");
}

void sap_xep_theo_ten(danhsach *thong_tin, int n) {
   for (int i = 0; i < n; i++) {
      for (int j = i + 1; j < n; j++) {
         if (strcmp((thong_tin + i)->name, (thong_tin + j)->name) > 0) {
            hoan_doi_2_vi_tri(thong_tin + i, thong_tin + j);
         }
      }
   }
}