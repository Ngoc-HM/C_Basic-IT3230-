#include <stdio.h>
#include <string.h>

int main()
{
    int n,max,check[26]={0};
    char a[100];
    printf("Nhap chuoi ki tu : "); gets(a);
    max = strlen(a); 
    printf("chuoi %s co %d ki tu : ",a,max);
    for (int i = 0; i < max; i++)
    {
    if (a[i] >= 'a' && a[i] <= 'z') check[a[i] - 'a']+=1;
    if (a[i] >= 'A' && a[i] <= 'Z') check[a[i] - 'A']+=1;
    }
    printf("\n");
    for (int i = 0; i < 26 ; i++)
    {
       if (check[i]>0) printf("ki tu %c xuat hien %d lan \nDai", 'a'+i, check[i]);
    }
    
    
    return 0;

}