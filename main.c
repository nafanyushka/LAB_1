//#include <stdio.h>
//#include <stdlib.h>
//
//int input();
//int* makearray(int);
//int outputarray(int*, int);
//int creatematrix(int*, int);
//
//int main() {
//    int* sizes;
//    int** matrix;
//    int N = input();
//    sizes = (int*)malloc(N * sizeof(int));
//    matrix = creatematrix(sizes, N);
//    outputarray(sizes, N);
//    printf("\n%d", matrix[1][0]);
//    printf("\n");
//    system("pause");
//    return 0;
//}
//
////OTHER FUNCS
//
//int input(){
//    int a;
//    printf("input int: ");
//    while(scanf("%d", &a) != 1 || a <= 0) {
//        printf("input int: ");
//        while(getchar() != '\n');
//    }
//    return a;
//}
//
//int* makearray(int n){
//    int* a = (int*)malloc(n * sizeof(int));
//    for(int i = 0; i < n; i++){
//        printf("Input array element number %d: ", i);
//        a[i] = input();
//    }
//    return a;
//}
//
//int outputarray(int* a, int n){
//    printf("{ ");
//    for(int i = 0; i < n; i++){
//        printf("%d ", a[i]);
//    }
//    printf("}\n");
//    return 0;
//}
//
//int creatematrix(int* a, int n){
//    int** A = (int**)malloc(n * sizeof(int*));
//    for(int i = 1; i <= n; i++){
//        printf("Input length of %d string: ", i);
//        int N = input();
//        *(a + i) = N;
//        A[i] = makearray(N);
//    }
//    return A;
//}

#include <stdio.h>
#include <locale.h>
#include <conio.h>
#include <stdlib.h>


int main(){
    setlocale(LC_ALL, "Rus");
    printf("Ввод матрицы:\n");



return 0;
}
