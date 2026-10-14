#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <time.h>
// #include "functions.h"

int is_prime(int m) {
    int is_prime = 1;
    for (int i = 2; i <= m / i; i++)
        if (m % i == 0)
        {
            is_prime = 0;
            break;
        }
    return is_prime? printf("%d is a prime number.\n", m) : printf("%d is not a prime number.\n", m);
}

void sum_1_100(void) {
	int i;
	int sum = 0;
	for (i=1; i<=100; i++)
		sum += i;
	printf("1 to 100 sum is %d.\n", sum);
}

int max(float x, float y) {
	// 返回表达式与多return语句
	float z;
	z = x > y ? x : y;
	return z;	
}

void swap(int a, int b) {	
	// 实参为浮点数
	int temp = a; 
	a = b; 
	b = temp; 
}

int encipher(int ch, int offset) {
    if (ch >= 'a' && ch <= 'z')
        ch = (ch - 'a' + offset) % 26 + 'a';
    else if (ch >= 'A' && ch <= 'Z')
        ch = (ch - 'A' + offset) % 26 + 'A';
    return ch;
}

int fac(int n) {
	if (n <= 1) return 1;
	else return n * fac(n-1);
}

int is_odd(int);

int is_even(int n) {
    if (n == 0)
        return 1;
    return is_odd(n - 1);
}

int is_odd(int n) {
    if (n == 0)
        return 0;
    return is_even(n - 1);
}

int sum(int n) {
    if (n != 0)
        // sum() function calls itself
        return n + sum(n - 1);
    else
        return n;
}

int f(int n) {
	if (n <= 2) return 1;
	else return f(n-1) + f(n-2);
}

int gcd(int a, int b) {
	if (a % b == 0) return b;
	else return gcd(b, a % b);
}

void hanoi(int n, char a, char b, char c) {
	if (n == 1) {
		printf("%c -> %c\n", a, c);
		return;
	}
	hanoi(n-1, a, c, b);
	printf("%c -> %c\n", a, c);
	hanoi(n-1, b, a, c);
}

int is_used(int num, int i) {
	while (num) {
		if (num % 10 == i) return 1;
		num /= 10;
	}
	return 0;
}

void permute(int num, int len, int n) {
	if (len == n) {
		printf("%d\n", num);
		return;
	}
	for (int i=1; i<=n; i++) {
		if (!is_used(num, i)) 
			permute(num*10+i, len+1, n);
	}
}

void f2(void) {
    static int cnt = 0;  // 只初始化一次
    cnt++;
    printf("%d\n", cnt);
}	

int sign(int n) {
	if (n >= 0) return 1;
	else return -1;
}

int sum_m_n(int m, int n) {
	int sum = 0;
	for (int i=m; i<=n; i++)
		sum += i;
	return sum;
}

int maximize(void);

int g = 1;

int main(void) { 			

    // P1: 有参函数与无参函数
	// is_prime(7);
    // sum_1_100();

	// printf("%d\n", sign(100));

	// P2: 练习1
	// float a = max(1.2, 3.3);
	// printf("Max is %.1f\n", a);	

	// P3: 练习2
	// int a = 10, b = 20;
	// swap(a, b);
	// printf("a=%d b=%d\n", a, b);

	// int m=5, n=10, sum=0;
	// sum = sum_m_n(m, n);

	// printf("floor(%f) = %f\n", 1.5, floor(1.5));

	// P4: 练习3
	// char ch;

    // // 读入一行电报
    // scanf("%c", &ch);

    // while (ch != '\n') {
    //     printf("%c", encipher(ch, 1));
    //     scanf("%c", &ch);
    // }

    // printf("\n");

	// P5: 阶乘
	// int n;
	// while (scanf("%d", &n) == 1) {
	// 	if ( n<0 || n>15 ) {
	// 		printf("Please input an integer from 0 to 15.\n");
	// 		continue;
	// 	}
	// 	printf("factorial %d = %d\n", n, fac(n));
	// }

	// 间接递归
	// int n = 10000001;
    // if (is_odd(n))
    //     printf("%d is odd\n", n);
    // else
    //     printf("%d is even\n", n);

	// P6: 累加
    // int number, result;
    // printf("Enter a positive integer: ");
    // scanf("%d", &number);
    // result = sum(number);
    // printf("sum = %d\n", result);

	// P7: Fibonacci
	// int n;
	// while(scanf("%d", &n) == 1)
	// 	printf("Fibonacci %d = %d\n", n, f(n));

	// P8: 辗转相除法
    // int a, b;
    // scanf("%d%d", &a, &b);
    // printf("gcd(%d, %d) = %d\n", a, b, gcd(a, b));

	// P9: 汉诺塔
    // int n;
    // scanf("%d", &n);
	// hanoi(n, 'a', 'b', 'c');

	// P10: 全排列
    // int n;
    // scanf("%d", &n);
	// permute(0, 0, n);

	// P11: local var and global var
	// printf("g = %d\n", g);
	// register int a = 10;
	// if (a > 0) {
	// 	int b = 20;
	// }
	// printf("a = %d\n", a);
	// printf("b = %d\n", b);

	// P12: register
	// register int i;
	// scanf("%d", &i);

	// P13: static
	// f2();
	// f2();
	// f2();

	// P14: extern
	int maximize();
	extern int a, b, c;  				
	printf("Please enter three integer numbers:\n");
	scanf("%d %d %d", &a, &b, &c);		
	printf("max is %d\n", maximize());

    return 0;							
}

int a, b, c;			
int maximize(void) {	
	int m;
	m = a > b ? a : b;		
	if(c > m) m = c;	
	return(m);		
}

