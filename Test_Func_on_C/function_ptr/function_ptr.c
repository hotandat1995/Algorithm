#include "call_libs.h"

typedef struct func_struct_test
{
    int *a;
    int *b;
    int (*plus)(int, int);
    double (*divide)(int, int);
    int (*multiple)(int, int);
} Func_struct_test;

int plus_operator(int a, int b)
{
    return a + b;
}

double divide_operator(int a, int b)
{
    return ((double)a / (double)b);
}

int multiple_operator(int a, int b)
{
    return a * b;
}

void Func_contructor(Func_struct_test *struct_in, int in_a, int in_b);
void Func_contructor(Func_struct_test *struct_in, int in_a, int in_b)
{
    struct_in->divide = &divide_operator;
    struct_in->multiple = &multiple_operator;
    struct_in->plus = &plus_operator;
    struct_in->a = (int *)malloc(sizeof(int));
    struct_in->b = (int *)malloc(sizeof(int));

    *struct_in->a = in_a;
    *struct_in->b = in_b;
}

void Func_destructor(Func_struct_test * struct_in){
    free(struct_in->a);
    free(struct_in->b);
}

void test_func_ptr()
{
    Func_struct_test *test = (Func_struct_test *)malloc(sizeof(Func_struct_test));
    Func_contructor(test, 10, 5);
    printf("--------------Test Function Pointer-----------------\n");
    printf("Plus : %d\n", test->plus(20,10));
    printf("Divide : %f\n", test->divide(5,2));
    printf("Multiple: %d\n", test->multiple(4,6));
    printf("---------------------END----------------------------\n");
    Func_destructor(test);
}