#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <time.h>

int main(void) { 	
    int n = 630;

    int max_start, max_len = 0;
    for (int start = 2, len = 0; start<=n; start++) {
        for (int i=start, product=1; i<=n; i++) {
            product *= i;
            if (n % product == 0) len++;
            else break;
        }
        if (max_len < len) {
            max_len = len;
            max_start = start;
        }
    }
    printf("%d\n", max_len);
    for (int i=max_start; i<max_start+max_len; i++) {
        printf("%d ", i);
    }
    

    // int n = 630;
    // int max_start, max_len = 0;
    // for (int start = 2, len = 0; start<=n; start++) {
    //     for (int i=start, product=1; i<=n; i++) {
    //         product *= i;
    //         if (n % product == 0) len++;
    //         else break;
    //     }
    //     if (max_len < len) {
    //         max_len = len;
    //         max_start = start;
    //     }
    // }

    // printf("%d\n", max_len);
    // for (int i=max_start; i<max_start+max_len; i++)
    //     printf("%d ", i);   


    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    // int n, i=1;
    // double score, sum=0, avg;
    // scanf("%d", &n);

    // while(i<=n){
    //     scanf("%lf", &score);
    //     sum += score;
    //     i++;
    // }

    // avg = sum / n;
    // printf("average = %.2f\n", avg);

    // P1
    // int n, i = 1;
    // double score, sum = 0, avg;
    // scanf("%d", &n);

    // while (i <= n) {
    //     scanf("%lf", &score);
    //     sum += score;
    //     i++;
    // }

    // avg = sum / n;
    // printf("average = %.2f\n", avg);

    // P2
    // int n, i = 1, sum = 0;
    // scanf("%d ", &n);
    // printf("Here!\n");

    // while (i <= n) {
    //     sum += i;
    //     i++;
    // }
    

    // printf("%d\n", sum);
    
    // P3
    // int n=0;
    
    // printf("Input a string: ");
    // while(getchar()!='\n') n++;
    
    // printf("Number of characters: %d\n", n);

    // P4
    // int answer, guess;
    // srand((unsigned)time(NULL));
    // answer = rand() % 100 + 1; // 随机生成1-100间整数
    
    // while(1){
    //     printf("请输入一个 1~100 之间的整数：");
    //     scanf("%d", &guess);
    //     if (guess < answer) {
    //         printf("Too small!\n");
    //     } else if (guess > answer) {
    //         printf("Too large!\n");
    //     } else {
    //         printf("Correct!\n");
    //     }
    // }

    // int found = 0;
    // while (!found) {
    //     printf("请输入你的猜测：");
    //     scanf("%d", &guess);

    //     if (guess < answer) {
    //         printf("Too small!\n");
    //     }
    //     else if (guess > answer) {
    //         printf("Too large!\n");
    //     }
    //     else {
    //         printf("Correct!\n");
    //         found = 1;
    //     }
    // }

    // P5
    // int n, i = 1, sum = 0;
    // scanf("%d", &n);

    // while (i <= n) {
    //     sum += i;
    //     i++;
    // }

    // printf("%d\n", sum);


    // int sum, i;
    // for (int sum=0, i=1; i<=10; i++){
    //     sum += i;
    // }

    // printf("sum=%d\n", sum);

    // P6
    // for (int i=1, int j=10, int sum=0; i<=10; i++, j--) 
    //     sum += i*j;
    // printf("%d\n", sum);

    // P7
    // int n;
    // for (n=0; getchar()!='\n'; n++);
    // printf("%d\n", n);

    // P8
    // for (int i = 1; i <= 3; i++) {
    //     for (int j = 1; j <= 3; j++) {
    //         printf("%d*%d=%d\t", i, j, i * j);
    //     }
    //     printf("\n");
    // }

    // P9: 九九乘法表
    // for (int i=1; i<=9; i++) {
    //     for (int j=1; j<=i; j++) {
    //         printf("%d*%d=%d\t", i, j, i*j);
    //     }
    //     putchar('\n');
    // }



    // P10: break & continue 
    // for (int i=1; i<=10; i++) {
    //     if (i == 5) continue;
    //     printf("i = %d\n", i);
    // }

    // P11: 选择性打印1-100数
    // int n;
	// scanf("%d", &n);

    // for (int i=1, sum=0; i<=100; i++) {
    //     if (i % 3 == 0) continue;
    //     sum += i;
    //     printf("i=%d\tsum=%d\n", i, sum);
    //     if (sum > n) break;
    // }








	// for (int i=1, sum=0; i<=100; i++) {
	// 	if (i % 3 == 0) continue;
	// 	sum += i;
	// 	printf("i=%-5d sum=%d\n", i, sum);
	// 	if (sum > n) break;
	// }

    // P12: 浮点数比较
    // double x = 0.0;
	// while (x != 1.0) {
	// 	x += 0.1;
    //     printf("x=%lf\n", x);
	// }
	// printf("x=%lf\n", x);

    // P13: Fibonacci
    // int n;
    // scanf("%d", &n);
    
    // n=1, f(1)=1
    // n=2, f(2)=2
    // n=3, f(3)=f(1)+f(2)=3
    // n=4, f(4)=f(2)+f(3)=5

    // int f1=1, f2=2, f3=3; // f1：前一项，f2：当前项，f3：下一项

    // if (n==1) f2 = 1;
    // // n >= 3
    // for (int i=3; i<=n; i++) {
    //     f3 = f1 + f2;
    //     f1 = f2;
    //     f2 = f3;
    // }

    // printf("%d\n", f2);










    
    
    
    // int f1=1, f2=2, f; // f1：前一项，f2：当前项，f：下一项
    // if (n==1) f2=1;
    // for(int i=3; i<=n; i++){
    //     f = f1 + f2;
    //     f1 = f2;
    //     f2 = f;
    // }
    // printf("%d\n", f2);

    // P14: Prime
    // int n;
    // scanf("%d", &n);
    // int k = sqrt(n);
    // int is_prime = 1;
    // for (int i=2; i<=k; i++) {
    //     if (n % i == 0) {
    //         is_prime = 0;
    //         break;
    //     }
    // }
    // if (is_prime) printf("Yes!");
    // else printf("No!");

    // P15: Debug
    // int n = 5;
    // int f1 = 1, f2 = 2, f;

    // scanf("%d", &n);   // n >= 3

    // for (int i = 3; i <= n; i++) {
    //     f = f1 + f2;
    //     f1 = f2;   
    //     f2 = f;
    // }

    // printf("%d\n", f);


    return 0;							
}
