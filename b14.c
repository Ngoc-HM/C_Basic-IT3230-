#include <stdio.h>
#include <string.h>

int main()
{
    char a[100];
    int max, check =0;
    gets(a);
    max = strlen(a);
   // printf("%d", max);
    for(int i=0 ; i<max ; i++)
    if(a[i]!=a[(max-1)-i]) check++;
    if(check==0) printf("Xau doi xung");
    else printf("Xau bat doi xung ");
    return 0; 
}