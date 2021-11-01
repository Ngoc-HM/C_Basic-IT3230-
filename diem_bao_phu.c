#include <stdio.h>
// tọa độ điểm 
typedef struct point
{
double x;
double y;
} diem;
// tọa độ hình tròn 
typedef struct circle
{
diem hinhtron;
double Ban_kinh;
} duongtron;
int check_toa_do(diem *p, duongtron *c)
{
double a, b;
a = p-> x - c -> hinhtron.x;
b = p-> y - c -> hinhtron.y;
return ((a * a + b * b) <= (c -> Ban_kinh * c -> Ban_kinh));
}
int main(void)
{
diem p;
duongtron c;
printf("Nhap toa do \n");
scanf("%lf%lf", &p.x, &p.y);
printf("nhap toa do hinh tron \n");
scanf("%lf%lf", &c.hinhtron.x, &c.hinhtron.y);
printf("Nhap ban kinh \n");
scanf("%lf", &c.Ban_kinh);
if (check_toa_do(&p, &c))
printf("nam trong hinh tron\n");
else
printf("nam ngoai hinh tron\n");
return 0;
}