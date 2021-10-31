#include <stdio.h>
#include <string.h>
int main()
{
    int n=0;
    char c1[100], c2[100];
    printf("Nhap mang thu nhat : "); gets(c1) ; 
    printf("Nhap mang thu hai : "); gets(c2) ; 
    printf("2 mang vua nhap la : \n");
    for (int i = 0; i < strlen(c1); i++) printf("%c", c1[i]);
    printf("\n");
    for (int i = 0; i < strlen(c2); i++ ) printf("%c", c2[i]);
    printf("\n");
    if(strlen(c1)!=strlen(c2)) printf("0");
    else{
      if(memcmp(c1,c2,strlen(c1)) !=0 ) printf("0");
      else printf("1");
    }
    return 0;
}