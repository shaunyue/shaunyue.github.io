#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void selected_sort_int(int *nums, size_t n);
void selected_sort(void *nums, size_t n, size_t m, int (*compar)(const void *, const void *));
int compfun(const void *p1, const void *p2);
int comp_doub(const void *p1, const void *p2);
int max(int, int);
int add(int a, int b);
void printx(const void *ptr, size_t bytes_count);

int main(void){

    /* const */
    // int const * const * const p;

    // p = NULL;     // A
    // *p = NULL;    // B
    // **p = 20;    // C
        
    // int x = 5;
    // int const *p1 = &x;
    // const int **p2 = &p1;

    // p2 = NULL;      // A
    // *p2 = NULL;     // B
    // **p2 = 20;      // C
    // x = 20;         // D

    // const int n = 1;  
    // // n = 2;  
    // int *p1 = NULL;
    // const int *p2 = &n;  
    // // p1 = p2; // 不合法
    // p1 = (int *)p2;
    // *p1 = 2;
    // printf("n=%d\n", n);

    
    /* void * */
    // int a = 10;
    // int *p1 = &a;
    // void *p2 = p1;
    // double b = 1.0;
    // p2 = &b;
    // p1 = &b;
    // // a = *p2;
    // printf("%p\n", p2);
    // printf("%p\n", &b);
    

    /* qsort */
    // int arr[12] = {8,4,5,3,7,1,2,9,6,0};
    // qsort(arr, 12, sizeof(arr[0]), compfun);
    // for(int i=0; i<12; i++)
    //     printf("arr[%d]=%d\n", i, arr[i]);

    // complete the function call
    // selected_sort(arr, 12, sizeof(arr[0]), compfun);
    
    // for(int i=0; i<12; i++)
    //     printf("arr[%d]=%d\n", i, arr[i]);
    

    /* function address */
    // printf("%p\n", scanf);
        
    // int (*p)(int,int);
    // p = max;    
    // printf("%d\n", p(10,100));
    

    /* malloc & memcpy */
    // void *p = malloc(100);
    // printf("%p\n",p);

    // const char src[50] = "http://www.google.com";
    // memcpy(p, src, strlen(src)+1);
    // printf("p = %s\n", (char *)p);
    
    // free(p);
    
    /* constant string*/
    // char const *p1 = "Coffe";
    // char *p2 = "Coff";
    // printf("p1 = %p\n", p1);
    // printf("p2 = %p\n", p2);
    
    // *p2 = 'H';
        
    char *ss[] = {"hello", "hello", "!"};
    // ss[0][0] = 'H';
    char sa[][10] = {"hello", "hello", "!"};
    sa[0][0] = 'H';
    //     free(p);
    // printf("%s\n", *ss);
    printf("%s\n", *sa);
    // printf("%d\n", ss[0] == ss[1]);

    // int x = 123456;
    // printx(&x, 4);


    /* string literal*/

    // char *p1 = "Coffee";
    // char *p2 = "Coffee";
    // printf("p1 = %p\n", p1);
    // printf("p2 = %p\n", p2);

    // char *ss[] = {"hello", "hello", "!"}; 
    // ss[0][0] = 'H';  
    // char sa[][10] = {"hello", "hello", "!"}; 
    // sa[0][0] = 'H'; 
        
    // printf("%s\n", *ss); 
    // printf("%s\n", *sa); 
    // printf("%d\n", ss[0] == ss[1]); 



    
    return 0;
}

int max(int a, int b){
    return a>b?a:b;
}

int add(int a, int b){
    return a+b;
}

int compfun(const void *p1, const void *p2){
    int *pr1 = (int *)p1;
    int *pr2 = (int *)p2;
    return *pr1 - *pr2;
}

int comp_doub(const void *p1, const void *p2){
    double *pr1 = (double *)p1;
    double *pr2 = (double *)p2;
    return *pr1 - *pr2;
}

void selected_sort_int(int *nums, size_t n) {
    for (int i=0; i<=n-2; i++) {
        // find minimum's idx
        int idx = i;
        for (int j=i+1; j<=n-1; j++)
            if (nums[j]<nums[idx])
                idx = j;
        // swap
        if (i != idx) {
            int temp = nums[i];
            nums[i] = nums[idx];
            nums[idx] = temp;
        }
    }
}

void selected_sort(void *nums, size_t n, size_t m, int (*compar)(const void *, const void *)){
    void *temp = malloc(m);
    for (int i=0; i<=n-2; i++) {
        // find minimum's idx
        int idx = i;
        for (int j=i+1; j<=n-1; j++)
            if ((*compar)((char *)nums+j*m, (char *)nums+idx*m) < 0)
                idx = j;
        // swap
        if (i != idx) {
            memcpy(temp, nums+i*m, m);
            memcpy(nums+i*m, nums+idx*m, m);
            memcpy(nums+idx*m, temp, m);
        }
    }
    free(temp);
}

void *mem_repeat(void *dest, void *src, size_t src_sz, size_t count) {
    unsigned char *p = dest;
    for (size_t i=0; i<count; i++) {
        memcpy(p, src, src_sz);
        p += src_sz;
    }
    return dest; 
}

void printx(const void *ptr, size_t bytes_count) {
    const unsigned char *p = ptr;
    for (size_t i=0; i<bytes_count; i++)
        printf("%02X", p[i]);
    printf("\n");
}

