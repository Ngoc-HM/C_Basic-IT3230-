#include <stdio.h>
#include <string.h>
int main()
{
    char a[100];
    int max,i;
    gets(a);
    max=strlen(a);
    for (i = 0; i < max; i++)
    {
        if(a[i]==' ') {break; printf("\n");} 
        else printf("%c",a[i]);
        
    }

    for (int j = i ; j < max; i++)
    {
        printf("%c",a[j]);
    }
    return 0;

}