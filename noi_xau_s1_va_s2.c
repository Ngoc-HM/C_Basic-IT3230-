#include <stdio.h>
#include <stdlib.h>
#include <string.h>
void *hamstr(char *s1, char *s2)
{
    int Max1,Max2;
    char *strc;
    Max1 = strlen(s1);
    Max2 = strlen(s2);
    strc = (char*)malloc((Max1+Max2+1)*sizeof(char));
    if (strc==NULL)
    {
        printf("Cap phat that bai.\n");
        return 1;
    } else printf("Cap phat thanh cong.\n");

    strcpy(strc,s1);
    strcpy(strc+Max1,s2);
    return strc;
    

}
int main()
{
  char s1[100],s2[100];
  char *str;
  printf("Nhap 2 xau : \n");
  scanf("%100s",&s1);
  scanf("%100s",&s2);
    str = hamstr(s1,s2);
    if(str == NULL )
    {
        printf("cap phat bo nho loi. \n");
        return 1;
    }  
    else printf("2 xau tren khi noi lai la : %s",str);
    free(str);
    return 0;

}