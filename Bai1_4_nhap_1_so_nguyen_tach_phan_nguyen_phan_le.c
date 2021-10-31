#include <stdio.h>
int main()
{
    double c;
    int a;
    printf("Nhap so can xet : ") ; scanf("%lf",&c);
    a = (int)c;
    printf("phan nguyen : %d\n",a);
    printf("phan le : %lf",c-a);

}