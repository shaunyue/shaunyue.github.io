#include <stdio.h>
#include <string.h>
#define SIZE 3
#define LEN_ARRAY(a) (sizeof(a)/sizeof(a[0]))

void vadd(int a[const], int b[], int size);
void matrix_add(int a[][SIZE], const int b[][SIZE], int size);
void matrix_add1(int a[][SIZE], int b[][SIZE], size_t size);
void matrix_add2(int **a, int **b, size_t m, size_t n);
void matrix_add3(size_t m, size_t n, int (*a)[n], int (*b)[n]);
void cswap(int *a, int *b);

int main(void) {

    /***************************************
     * 示例1：一维数组与函数
     ***************************************/
      
    // int a[SIZE] = {60,55,62};
    // printf("Before vadd: \n");
    // for (int j=0; j<LEN_ARRAY(a); j++) printf("a[%d]=%d ", j, a[j]);
    
    // int b[SIZE] = {13,20,18};
    // vadd(a, b, SIZE); // 完善该函数

    // printf("\nAfter vadd: \n");
    // for (int j=0; j<LEN_ARRAY(a); j++) printf("a[%d]=%d ", j, a[j]);
    // putchar('\n');
    
    /***************************************
     * 示例2：二维数组与函数
     ***************************************/
    
    // int a[SIZE][3] = {6,7,8,9,5,6,7,8,9};
    // matrix_add(a, a, SIZE); // 完善该函数

    // // 打印矩阵
    // for (int i=0; i<LEN_ARRAY(a); i++) {
    //     for (int j=0; j<LEN_ARRAY(a[i]); j++)
    //         printf("%4d", a[i][j]);
    //     printf("\n");
    // }
    
    // // 另一种方式
    // matrix_add1(a,a,SIZE); // 完善该函数
    // for (int i=0; i<LEN_ARRAY(a); i++) {
    //     for (int j=0; j<LEN_ARRAY(a[i]); j++)
    //         printf("%4d",a[i][j]);
    //     printf("\n");
    // }
    
    /***************************************
     * 示例3：指针变量的声明与打印
     ***************************************/
    // int a = 1;
    // int * p = &a;
    // printf("&a=%p\n", &a);

    // int *p = NULL;
    // printf("p=%p\n", p);

    // if (p) printf("*p=%d\n",*p); 
    // else printf("NULL pointer!");
    
    /***************************************
     * 示例4：指针运算符
     ***************************************/
    
    // int a = 0;
    // int *p = &a;
    // *p = 10;  //对变量a赋值10
    // printf("value *p=%d, a=%d\n", *p, a);
    // printf("&a=%p, &*p=%p\n", &a, &*p);
    // // printf("&*a=%p\n", &*a);
    // printf("*&a=%d\n", *&a);
    
    /***************************************
     * 示例5：指针算数运算
     ***************************************/
    
    // int *p = NULL; // 0
        
    // p+i
    // printf("p   = %p\n", p);
    // printf("p+1 = %p\n", p+1);
    // printf("p+2 = %p\n", p+2);
    // printf("p+3 = %p\n", p+3);
    // printf("p+4 = %p\n", p+4);
    
    // p-i
    // int *q = p + 4;
    // printf("%d\n", q - p);
    // printf("p   = %p\n", p);
    // printf("p-1 = %p\n", p-1);
    // printf("p-2 = %p\n", p-2);
    // printf("p-3 = %p\n", p-3);
    // printf("p-4 = %p\n", p-4);

        
    // not demonstrated
    // int *p = NULL;
    // int *q = NULL + 6;
    // printf("q-p = %ld\n", q-p);
    // printf("sizeof(*NULL) = %zd\n", sizeof(*NULL));
        
    // int arr[] = {0,1,2,3,4,5};
    // int *p = arr;
    // int *q = &arr[sizeof(arr)/sizeof(int)];
    // printf("q-p=%td\n", q-p);
    // for (; p<q; p++)
    //     printf("%d", *p);  //正向遍历
    // printf("\n");
    // for (q=q-1; q>=arr; q--)
    //     printf("%d", *q);  //反向遍历
    // printf("\n");
    
    /***************************************
     * 示例6：指针与数组（下标运算）
     ***************************************/
    
    // int a[3] = {1,2,3}; 
    // int *p = a;
    // printf("a[1]=%d *(a+1)=%d\n", a[1], *(a+1));
    // printf("p[2]=%d *(p+2)=%d\n", p[2], *(p+2));
    
    // printf("a[2]=%d 2[a]=%d\n", a[2], 2[a]);
    // 2[a] = 7;
    // printf("p[2]=%d 2[p]=%d\n", p[2], 2[p]);

    /***************************************
     * 示例7：指针的数组
     ***************************************/
    
    // int a[3] = {1,2,3};
    // int *p[SIZE] = {}; // 解释为 int * 类型的数组（'[]' 取成员运算符高于其他一元运算符）
    
    // for(int i=0; i<SIZE; i++)
    //     p[i] = &a[i];
    // // for(int i=0; i<SIZE; i++) 
    // //     printf("*p[%d]=%d\n", i, *p[i]);
        
    // for (int i=0; i<SIZE; i++) {
    //     for (int j=0; j<SIZE-i; j++) 
    //         printf("%-4d", p[i][j]);
    //     putchar('\n');
    // }

    /***************************************
     * 示例8：数组的指针
     ***************************************/

    // int arr[][SIZE] = {{1,2,3}, {2,3}, {3}};
    // int (*q)[SIZE] = arr; 	//注意用括号，区别指针的数组 
    // 				        //解释为 int[] 类型的指针 
    // for(int i=0; i<SIZE; i++) {
    //     // printf("*q[%d] = %d\n", i, *q[i]);
    //     for(int j=0; j<SIZE-i; j++)
    //         printf("%4d", q[i][j]);
    //     printf("\n");
    // }

    // printf("q[1][2]=%d, p[1][2]=%d\n", q[1][2], p[1][2]);

    /***************************************
     * 示例9：指向指针的指针
     ***************************************/

    // int var = 10;
    // int *p1 = &var;
    // int **p2 = &p1;
    // printf("p1=%p\n", p1);
    // printf("*p1=%d\n", *p1);
    // printf("p2=%p\n", p2);
    // printf("*p2=%p\n", *p2);
    // printf("**p2=%d\n", **p2); // *p1 == var

    /***************************************
     * 示例10：指向数组的指针 vs 指针的数组 vs 指向指针的指针
     ***************************************/

    // int m[3][4] = {1,2,3,4,5,6,7,8,9,10,11,12}; // 
    // int q;
    // int (*p)[4] = m; //指向数组的指针：(*p)代表p是指针（放地址）->什么类型变量的地址？->
    // *p == *m;
    // for (int i=0; i<3; i++) 
    //     printf("%p, %p\n", p[i], m[i]);
    // int *(mp[3])     //(指向数组的)指针的数组 
    //     = {m[0],m[1],m[2]}; // m[1]是m的第二个元素，第二行（一个数组{5,6,7,8}）
    // int **pp = &m[0];   //(指向)指针(数组)的指针 
    // for (int i=0; i<3; i++) {
    //     for (int j=0; j<4; j++)
    //         printf("%4d", pp[i][j]);
    //     printf("\n");
    // }   

    // int **a = m;

    // printf("%d\n", (*(pp + 1))[2]);

    /***************************************
     * 示例11：指针与函数参数
     ***************************************/

    // int a = 3, b = 4;
    // printf("a = %d, and b = %d\n", a, b);
    // cswap(&a, &b);
    // printf("a = %d, and b = %d\n", a, b);

    /***************************************
     * 示例12：矩阵相加
     ***************************************/

    // int m[3][4] = {1,2,3,4,5,6,7,8,9,10,11,12};

    // not demonstrated
    // matrix_add2(m, m, 3, 4);
    
    // matrix_add3(3, 4, m, m);

    // for (int i=0; i<3; i++) {
    //     for (int j=0; j<4; j++)
    //         printf("%-4d",m[i][j]);
    //     printf("\n");
    // }   

    /***************************************
     * 示例13：函数指针
     ***************************************/

    // void (*f)(size_t m, size_t n, int (*a)[n], int (*b)[n]) = matrix_add3;
    // f(3, 4, m, m);
    // for (int i=0; i<3; i++) {
    //     for (int j=0; j<4; j++)
    //         printf("%-4d",m[i][j]);
    //     printf("\n");
    // }   

    // 函数指针
    void (*g)(int *, int *) = cswap;
    int a=1, b=2;
    (*g)(&a, &b); // g(&a, &b)
    printf("a=%d, b=%d\n", a, b);

    int *p = &a; 
    *p = 10; 

    printf("abc\n\0defdafj;lgjf");
    printf("def\n");


    
    
    return 0;
}

void vadd(int a[const], int b[], int size){
    for (int i=0; i<size; i++) {
        a[i] += b[i];
    }
}

void matrix_add(int a[][SIZE], const int b[][SIZE], int size){
    for (int i=0; i<size; i++)
        for (int j=0; j<SIZE; j++)
            a[i][j] += b[i][j];
}

// void matrix_add1(int a[][SIZE], int b[][SIZE], size_t sz){
//     vadd(a, b, sz*LEN_ARRAY(a[0]));
// }

// void matrix_add2(int **a, int **b, size_t m, size_t n) {
//     int (*p)[n] = a;  //VLA指针, 恢复数组结构 
//     int (*q)[n] = b;
//     for (int i=0; i<m; i++) 
//         for (int j=0; j<n; j++)
//             p[i][j] += q[i][j]; 
// }

void matrix_add3(size_t m, size_t n, int (*a)[n], int (*b)[n]) {
    for (int i=0; i<m; i++) 
        for (int j=0; j<n; j++)
            a[i][j] += b[i][j]; 
}

void cswap(int *a, int *b) {
    int m = *a;
    *a = *b;
    *b = m;
}
