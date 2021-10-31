#include <stdio.h>
#include <string.h>
int main()
{
    char c1,c2,chuoi[100];
    int Max; 
    printf("Nhap ki tu can chuyen sang = "); scanf("%s", &c1);
    printf("Nhap ki tu chuyen sang = "); scanf("%s", &c2);
    printf("Nhap chuoi ki tu can chuyen = "); fflush(stdin) ; gets(chuoi);
    Max = strlen(chuoi);
    for(int i=0 ; i < Max ; i++) if( chuoi[i] == c1 ) chuoi[i] = c2;
    printf("\n");
    printf("\nChuoi sau khi doi la : ");
    for (int  i = 0; i < Max; i++)
    {
      printf("%c",chuoi[i]);
    }
    
}