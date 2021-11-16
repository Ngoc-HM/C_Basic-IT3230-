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
        if(a[i]==' ' & a[i+1]!=' ' ) {printf("\n");} 
        else printf("%c",a[i]);
        
    }
    return 0;
}