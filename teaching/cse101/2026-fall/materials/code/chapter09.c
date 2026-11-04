#include <stdio.h>
#include <string.h>

int main(void) {

    /* 打印字符串 */
    // printf("Hello\0, World!\n");

    // printf("%zd\n", sizeof("China"));
    
    // char s[8] = "China";
    // printf("%s\n", s);
    
    // char *p2 = s;
    // printf("%s\n", p2);
    
    // const char *p1 = "China";
    // printf("%s\n", p1);

    // printf("%s %p %c\n", "We", "are", "space farers."[1]);


    /* 字符串初始化 */
//     char str[100] = "hello \
// world!\n";
    // char str1[100] = "hello";
    // printf("%s", str1);
    // printf("%s", "hello" " world!\n");



    // char a[8] = "hello"; 
    // gets(a);
    // printf("%zd\n", strlen(a));

    /* 字符串输出 */
    // char str[8] = "China";
    // printf("printf(\"%%s\", str)会打印: %s\n", str);
    // printf("puts(str,stdout) 会打印: ");
    // puts(str);
    // printf("fputs(str,stdout)会打印: ");
    // fputs(str, stdout);

    // char str1[] = "This is a string."; 
    // char str2[] = {'H', 'e', 'l', 'l', 'o'};
    // printf("%s\n\n", str1); // 字符串整体输出用%s
    // printf("%s\n\n", str2);

    
    /* scanf */
    // char str[10];
    // printf("Please enter a string less than 9 characters:\n");
    // scanf("%s", str); // student
    // printf("The string you enter is: %s\n\n", str);

    
    // 打印输入缓冲区剩余字符（包含换行符）
    // printf("\n");
    // char c;
    // while (printf("%c", c=getchar()) && c!='\n'); // printf返回成功输出的字符数
    
    /* gets */
    // char str[5];
    // gets(str);
    // printf("%s", str);
        
    // // 打印str的元素
    // printf("\n");
    // for(int i=0; i<5; i++) printf("str[%d]=%c\n",i,str[i]);
    
    /* fgets */
    // char str[1000], c;
    // fgets(str, sizeof(str), stdin);
    // printf("%s", str);
    
    // 打印输入缓冲区剩余字符（包含换行符）
    // printf("\n");
    // while (printf("%c",c=getchar()) && c!='\n');

    
    /* 练习 */
    // char str[100];
    // int len, t;
    // gets(str);
    // // fgets(str, 100, stdin);
    
    // for(len=0; str[len]!=0; len++);
    // // for(len=0; str[len]!='\n' && str[len]!=0; len++);
    // // str[len]=0; // 去掉换行符

    // for(int i=0, j=len-1; i<j; i++,j--)
    //     t=str[i], str[i]=str[j], str[j]=t;
    
    // printf("%s,%d", str, len);

    
    /* 字符串函数 */
    // char str[10] =  "China";
    // printf("%lu\n", strlen(str));

    char str1[20] = {"I love *********"};
    char str2[] = {"China!"};
    // printf("%s\n", strcat(str1, str2));
    // printf("%s\n", strncat(str1, str2, 2));

    // printf("%s\n", strcpy(str1, str2));
    printf("%s\n", strncpy(str1, str2, 10));
    printf("str1[8]=%c\n", str1[8]);
    
    // char str[] = "abcdedcbaf";
    // printf("%ld\n", strrchr(str, 'd') - str); // 'd'在str中第一次出现的下标
    // printf("%s\n", strrchr(str, 'd')); // 从第一次'd'出现开始的字符串

    return 0;
}

