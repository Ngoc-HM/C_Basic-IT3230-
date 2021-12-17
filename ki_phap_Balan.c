#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define MAX 30 

char stack[MAX];
int so_Stack[MAX];
int size = 0, numSize = 0;

void push(char check);
char pop();
char getTop();
int get(char c);
void Them_so_vao_dinh_Stack(int x); 
int Lay_so_tren_dinh_Stack();

int main() {
   printf("Nhap bieu thuc trung to : ");
   char chuoi = getchar();
   printf("\nBieu thuc da chuyen doi hau to : ");
   int x;
   int ketqua = 0;
   do {
      if ('0' <= chuoi && chuoi <= '9') {
         Them_so_vao_dinh_Stack((int)chuoi - '0');
         putchar(chuoi);
         putchar(' ');
      } else {
         int  A = get(chuoi);
         while (size > 0 && get(getTop()) >= A ) {
            char check= pop();
            int temp = Lay_so_tren_dinh_Stack() ;
            
            if (check == '+') temp += Lay_so_tren_dinh_Stack();
            
            if (check == '-') temp = Lay_so_tren_dinh_Stack() - temp;
            
            if (check== '*') temp *= Lay_so_tren_dinh_Stack();
            
            if (check== '/') temp = Lay_so_tren_dinh_Stack() / temp;
            
            Them_so_vao_dinh_Stack(temp);
            
            putchar(check);
            
            putchar(' ');
         }
         push(chuoi);
      }
      chuoi = getchar();
   } while (chuoi != '\n');
   while (size > 0) 
   {
      char check = pop();
      int temp = Lay_so_tren_dinh_Stack();
      
      if (check== '+') temp += Lay_so_tren_dinh_Stack();
      
      if (check == '-') temp = Lay_so_tren_dinh_Stack()- temp;
      
      if (check == '*') temp *= Lay_so_tren_dinh_Stack();
      
      if (check == '/') temp = Lay_so_tren_dinh_Stack()/ temp ;

      Them_so_vao_dinh_Stack(temp);
      putchar(check);
      putchar(' ');
   }
   ketqua = Lay_so_tren_dinh_Stack() ;
   printf("\nKet qua  = %d", ketqua);
   return 0;
}


void push(char check) {  
   if (size == MAX - 1) {
      printf("Ngan xep da day");
      return;
   }
   stack[size] = check;
   size++;
}

char pop(){
   if (size == 0) {
      printf("Ngan xep trong");
      return '\n';
   }
   return stack[--size];
}

char getTop() { return stack[size - 1]; }

int get(char chuoi){
   if (chuoi == '+' || chuoi == '-')
      return 0;
   else
      return 1;
}

void Them_so_vao_dinh_Stack(int x) {
   if (numSize == MAX - 1) {
      printf("Ngan xep da day ");
      return;
   }
   so_Stack[numSize] = x;
   numSize++;
}

int Lay_so_tren_dinh_Stack(){
   if (numSize == 0){
      printf("Ngan xep trong ");
      return '\n';
   }
   return so_Stack[--numSize];
}

