#include <stdio.h>
#include <string.h>
#define SIZE 3
#define LEN_ARRAY(c) (sizeof(c)/sizeof(c[0])) // 宏

void vadd(int a[], int b[], int size);

void matrix_add(int a[][3], int b[][3], size_t m);

int main(void) {

    /***************************************
     * 示例0：查询成绩
     ***************************************/

    // int n;
    // printf("请输入学生人数：\n");
    // scanf("%d", &n);
    // float a[n];
    // for (int i=0; i<n; i++) {
    //     printf("请输入第 %d 个学生的成绩：\n", i);
    //     scanf("%f", &a[i]);
    // }
    // printf("请输入要查询的学生编号：\n");
    // int id;
    // scanf("%d", &id);
    // if (id < 0 || id >= n) {
    //     printf("输入的学生编号不合法！\n");
    // } else {
    //     printf("学生编号 %d 的成绩为：%.1f\n", id, a[id]);
    // }

    /***************************************
     * 示例1：内存中的数组
     ***************************************/
 
    // int a[5] = {0};
    // char a[5];
    // for (int i = 0; i < 5; i++) {
    //     printf("a[%d]内存地址: %p\n", i, &a[i]);
    // }

    /***************************************
     * 示例2：数组初始化
     ***************************************/

    // 定长数组
    // int a1[5]; // 不能用 int a1[]; 来声明
    // // int a2[SIZE] = {1,2,3};
    // for (int i = 0; i < 3; i++) {
    //     printf("a1[%d]: %d\n", i, a1[i]);
    // }

    // 变长数组
    // int n;
    // scanf("%d", &n);
    // int a3[n];

    // *指定初始化器（C99）
    // int a1[] = { [3]=4 };
    // for (int i = 0; i < 5; i++) {
    //     printf("a1[%d]: %d\n", i, a1[i]);
    // }
    // printf("%zd\n", sizeof(a1)/sizeof(int));

    // *注意3点：不指定大小；按序赋初值；覆盖初值
    // int a2[5] = { 1, 2, [0]=4, 5, 6 };
    // for (int i = 0; i < sizeof(a2)/sizeof(int); i++) {
    //     printf("a2[%d]: %d\n", i, a2[i]);
    // }

    /***************************************
     * 示例3：倒序输出
     ***************************************/

    // int i, a[10];
    // for(i=1; i<=10; i++)
    //     a[i-1] = i;
    // for(i=10; i>=1; i--)
    //     printf("%d ",a[i-1]);
    // printf("\n");

    // int i,a[10]={0,1,2,3,4,5,6,7,8,9},b[10];
    // a = {0,1,2,3,4,5,6,7,8,9};
    // b = a;
    // for(i=9; i>=0; i--)
    //     printf("%d ",a[i]);
    // printf("\n");

    /***************************************
     * 示例4：数组输入
     ***************************************/

    /* 已知数组长度 */
    // int n;
    // printf("n = ");
    // scanf("%d", &n);
    // int a[n];

    // for (int i=0; i<n; i++) scanf("%d", &a[i]); // 逐一输入
    // for (int i=n-1; i>=0; i--) printf("a[%d]=%d ", i, a[i]);
    // putchar('\n');

    /* 未知数组长度 */
    // int a[10000];
    // int i=0, num;

    // while (scanf("%d", &num) == 1)
    //     a[i++] = num;

    // for (int j=0; j<i; j++) printf("a[%d]=%d ", j, a[j]);
    // putchar('\n');

    /* 使用EOF */
    
    int i=0;
    int a[1000];
    while (scanf("%d",&a[i++]) != EOF);
    for (int j=0; j<i-1; j++) printf("a[%d]=%d ", j, a[j]);
    putchar('\n');
    
    // int b[100];
    // // printf("%zu\n", LEN_ARRAY(b));
    // printf("b = %p\n", b);
    // printf("&b[0] = %p\n", &b[0]);


    // memset(a, 0, sizeof(a));
    // for (int j=0; j<i-1; j++) printf("a[%d]=%d ", j, a[j]);
    // putchar('\n');

    /***************************************
     * 示例5：平均降水
     ***************************************/
    
    // double data[100], num;
    // int n=0;

    // /*读入一个数组，以 -1 作为结束*/
    // while (scanf("%lf",&num)==1 && num!=-1)
    //     data[n++] = num;

    // int raindays = 0;
    // double rain_total = 0;
    // for (int i=0; i<n; i++) {
    //     if (data[i] > 1e-7) {
    //         raindays++;
    //         rain_total += data[i];
    //     }
    // }

    // if (raindays)
    //     printf("Raindays %d, average rainfall %lf.\n", raindays, rain_total/raindays);
    // else
    //     printf("No rain.\n");

    /***************************************
     * 示例6：多维数组
     ***************************************/

    // int a[3][3] = { {1,2,3}, {4,5,6}, {7,8,9} };
    // for (int i=0; i<3; i++) {
    //     for (int j=0; j<3; j++) {
    //         // printf("a[%d][%d] = %d\n", i, j, a[i][j]);
    //         printf("a[%d][%d]内存地址: %p\n", i, j, &a[i][j]);
    //     }
    // }

    /***************************************
     * 示例6：数组与函数
     ***************************************/
    
    // int a[] = {1,2,3};

    // printf("Before vadd: \n");
    // for (int j=0; j<LEN_ARRAY(a); j++) printf("a[%d]=%d ", j, a[j]);
    
    // vadd(a, a, LEN_ARRAY(a));
    
    // printf("\nAfter vadd: \n");
    // for (int j=0; j<LEN_ARRAY(a); j++) printf("a[%d]=%d ", j, a[j]);
    // putchar('\n');

    // int a[3][3] = {1,2,3,4,5,6,7,8,9};
    // matrix_add(a, a, LEN_ARRAY(a));
    // for (int i=0; i<LEN_ARRAY(a); i++) {
    //     for (int j=0; j<LEN_ARRAY(a[i]); j++)
    //         printf("%4d", a[i][j]);
    //     printf("\n");
    // }   

        
    return 0;
}

void vadd(int a[], const int b[], int size){
    for (int i=0; i<size; i++) {
        a[i] += b[i];
    }
}

// void matrix_add(int a[][3], int b[][3], size_t m){
//     vadd(a, b, m*LEN_ARRAY(a[0]));
// }
