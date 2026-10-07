#include <stdio.h>
#include <math.h>

int main(void) { 					
    float a, b, c, disc, x1, x2, p, q;
    scanf("%f%f%f", &a, &b, &c);
    disc = b * b - 4 * a * c;

    if (disc < 0) {
        printf("No real roots!\n");
    } else {
        p = -b / (2.0 * a);
        q = sqrt(disc) / (2.0 * a);
        x1 = p + q;
        x2 = p - q;
        printf("x1=%7.2f\nx2=%7.2f\n", x1, x2);
    }

    // P1
    // float a, b, c;
    // float disc, x1, x2, p, q;

    // scanf("%f%f%f", &a, &b, &c);

    // disc = b * b - 4 * a * c;
    // p = -b / (2.0 * a);
    // q = sqrt(disc) / (2.0 * a);
    // x1 = p + q;
    // x2 = p - q;
    
    // printf("x1=%7.2f\nx2=%7.2f\n", x1, x2);

    // 2
    // int a = 2000000000;
    // unsigned int b = 3000000000;

    // printf("a=%d\nb=%u\n", a, b);
 
    // 3
    // unsigned short price = -1;	
    // printf("%hu\n", price);

    // 4
    // printf("%c %d\n", 'C', 'C');

    // 5
    // double x = 3.14159;
    // printf("%f\n", x);

    // float a, b;
    // b = 2e20 + 1.0;
    // a = b - 2e20;
    // printf("a = %f\n", a);

    // 6
    // printf("%zd\n", sizeof(double));

    // 7
    // int a = 071, b = 0xFF;
    // printf("%d %d\n", a, b);

    // int x = 100;
    // printf("%d, %o, %x\n", x, x, x);

    // 8
    // int num = 1.99;
    // float pi = 3.1415926536;
    // printf("%d, %.9f\n", num, pi);

    // int total;
    // total = 30 * 24 * 60 * 60 * 1000;
    // printf("total = %d\n", total);

    // 9
    // printf("%lf\n", 5.0);
    // printf("%.2lf\n", 5.0);
    // printf("%10lf\n", 5.0);
    // printf("%10.2lf\n", 5.0);
    // printf("%-10.2lf\n", 5.0);
    // printf("%+10.2lf\n", 5.0);
    // printf("% .2lf\n", 5.0);
    // printf("% .2lf\n", -5.0);
    // printf("%010.2lf\n", 5.0);
    // printf("%g\n", 5.0);

    // 10
    // char a,b,c;			//定义字符变量a,b,c
    // a=getchar();		//从键盘输入一个字符，送给字符变量a
    // b=getchar();		//从键盘输入一个字符，送给字符变量b
    // c=getchar();		//从键盘输入一个字符，送给字符变量c
    // putchar(a); 		//将变量a的值输出
    // putchar(b); 		//将变量b的值输出 
    // putchar(c); 		//将变量c的值输出
    // putchar('\n');	    //换行

    return 0;							
}
