#include <stdio.h>
#include <math.h>

int main(void) { 					

    // P1
    // float a, b, c;
    // float disc, x1, x2, p, q;

    // scanf("%f%f%f", &a, &b, &c);

    // disc = b * b - 4 * a * c;

    // if(disc >= 0) {
    //     x1 = (-b + sqrtf(disc)) / (2.0 * a);
    //     x2 = (-b - sqrtf(disc)) / (2.0 * a);
    //     printf("x1=%.2f\nx2=%.2f\n", x1, x2);
    // } else 
    //     printf("no real roots!\n");

    // printf("real roots!\n");

    // P2
    // int a=1, b=0;
    // printf("%d\n", ! a && b);
    // printf("%d\n", (!a + 1 > 0) && (b < 10));

    // P3
    // int i=0;
    // int j=1;
    // i && ++j;
    // printf("j=%d\n", j);

    // int a, b, c, d;
    // a = b = c = -1;
    // d = ++a && ++b && ++c;
    // printf("%d %d %d %d\n", a, b, c, d);

    // int a, b, c, d;
    // a = b = c = 0;
    // d = a++ || ++b || c++;
    // printf("%d %d %d %d\n", a, b, c, d);

    // P4
    // int x;
    // scanf("%d", &x);
    // if(x >= 0) printf("%d", x);

    // if (x >= 0) {
    //     printf("%d是正数\n", x);
    // } else {
    //     printf("%d是负数\n", x);
    // }


	// int a, b, max;
	// printf("输入两个整数：");
	// scanf("%d%d", &a, &b);

	// if (a < b) max = a;
    // else max = b;

    // printf("%d和%d的较大值是：%d\n", a, b, (a > b) ? a : b);

    // int a = 1, b = 2, c = 3;
    // printf("%d\n", (a>b) ? ((a>c)?a:c) : ((b>c)?b:c) );

    char c;
    scanf("%c", &c);
    printf("%c\n", c);


    // P5
    // int score;
    // scanf("%d", &score);

    // if (score > 100) {
    //     printf("Error!\n");
    //     return 0;
    // }

    // if (score >= 90) printf("A\n");
    // else if (score >= 80) printf("B\n");
    // else if (score >= 70) printf("C\n");
    // else if (score >= 60) printf("D\n");
    // else printf("F\n");

    // P6
    // int score;
    // scanf("%d", &score);

    // if (score < 90) {
	// 	if (score > 60)
	// 		printf("Need to work harder!\n");
    // }
	// else
	// 	printf("You're so good!\n");

    // P7
    // int a;
    // printf("Input integer number:");
    // scanf("%d",&a);
    // switch(a){
    //     case 1: 
    //     case 2: 
    //     case 3: printf("Wednesday\n");	break;
    //     case 4: printf("Thursday\n"); 	break;
    //     case 5: printf("Friday\n"); 	break;
    //     case 6: printf("Saturday\n"); 	break;
    //     case 7: printf("Sunday\n"); 	break;
    //     default:printf("error\n"); 	    break;
    // }


    return 0;							
}
