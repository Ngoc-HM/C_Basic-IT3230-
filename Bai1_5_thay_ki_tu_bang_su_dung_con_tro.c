#include <stdio.h>
void chuongtrinh(double d, double r)
{
    return printf(" C = %.2lf, S = %.2lf",(d+r)*2, d*r);
}
int main(){
    double d,r;
    printf("Nhap chieu dai : "); scanf("%lf", &d);
    printf("Nhap chieu rong :  "); scanf("%lf", &r);
    chuongtrinh(d,r);
    return 0;
}
