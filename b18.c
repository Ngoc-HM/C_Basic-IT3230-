#include<stdio.h>
#include <conio.h>
int main()
 {
 int A = 1;
 int B = 2;
 int C = 3;
 int *P1, *P2;
    P1=&A; //  lưu địa chỉ của biến A vào con trỏ P1
    P2=&C;  // lưu địa chỉ của biến C vào con trỏ P2
        *P1=(*P2)++; // giá trị của biến A = 4, nhưng toán tử hậu nên là in ra 3
                     // C = 3 vẫn giữ nguyên giá trị 
            printf("%d %d",*P1, *P2); // in ra lúc này A=3(A=4),C=3
    P1=P2;  printf(" ; ");
     printf("%d %d",*P1, *P2);
            printf(" ; "); //P1 và P2 cùng trỏ tới C
    P2=&B;  // P2 trỏ tới B
    *P1-=*P2; // giá trị của C = 3-2 = 1
            printf("%d %d",*P1, *P2);
            printf(" ; ");
    ++*P2;
    *P1*=*P2;
            printf("%d %d",*P1, *P2);
    A=++*P2**P1; printf(" ; ");
    P1=&A; 
            printf("%d",A);
    *P2=*P1/=*P2;printf(" ; ");
             printf("%d %d",*P1, *P2);
 return 0;
 }
