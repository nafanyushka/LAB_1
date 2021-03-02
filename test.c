#include <stdio.h>
#include <stdlib.h>


int* createarray(int*);
int input();
int outputarray(int*, int*);
int** CRMATRIX(int*, int*);
int outputmatrix(int**, int*, int*);
float middlen(int*, int*);
float numlen(int);
int** matrix_OTBOR(int**, int*, int*, int*, int);
int* array_OTBOR_middlen(int*, int*, int*);
int* array_OTBOR_midlenum(int*, int*, int*);
void freematrix(int**, int*);
int* array_OTBOR_3len(int*, int*, int*);

int main(){

    while (1 == 1){
        int *sizes = NULL;
        int *new_sizes = NULL;
        int **M = NULL;
        int **NEW = NULL;
        int swit = 0;

        printf("Input len of matrix: ");
        int STRINGS = 0;
        while(STRINGS <= 0)
            STRINGS = input();
        sizes = (int *) malloc(STRINGS * sizeof(int));
        new_sizes = (int *) malloc(STRINGS * sizeof(int));
        printf("\n");
        M = CRMATRIX(sizes, &STRINGS);
        printf("\n\tLook, your matrix:\n\n");
        outputmatrix(M, sizes, &STRINGS);
        printf("\n");
        //NEW MATRIX
        printf("\tTime to OTBOR!\nPlease, input:\n\t1 - OTBOR by middle len.\n\t2 - OTBOR by middle number.\n\t3 - OTBOR only 3-len numbers.\n");
        while (swit < 1 || swit > 3) {
            printf("Choose your variant: ");
            swit = input();
        }
        printf("Your OTBOR matrix:\n");
        NEW = matrix_OTBOR(M, sizes, &STRINGS, new_sizes, swit);
        printf("\n");
        outputmatrix(NEW, new_sizes, &STRINGS);
        //CLEAR MEMORY
        freematrix(M, &STRINGS);
        freematrix(NEW, &STRINGS);
        free(sizes);
        free(new_sizes);
        printf("Try again? Enter 1 if you want to exit: ");
        int restart = input();
        if (restart == 1) {
            break;
        }
        else{
            printf("\nDo you need to clear screen? Enter 1 if you do: ");
            int clear = input();
            if (clear == 1)
                system("cls");
        }
    }
    return 0;

}

int* createarray(int* N){
    int* array;
    array = (int*)malloc(*N * sizeof(int));
    for(int i = 0; i < *N; i++){
        printf("\tInput %d element of array: ", i);
        *(array++) = input();
//        printf("%p", array);
    }
    array -= *N;
//    printf("%p\n", array);
    return array;
}

int input(){
    int a;
    while(scanf("%d", &a) != 1) {
        printf("Try again: ");
        while(getchar() != '\n');
    }
    return a;
}

int outputarray(int* a, int* N){
    for(int i = 0; i < *N; i++){
        printf("%d ", *(a++));
    }
    a -= *N;
    return 0;
}

int** CRMATRIX(int* a, int* N){
    int** array = (int**)malloc(*N * sizeof(int*));
    for(int i = 0; i < *N; i++) {
        printf("\nLen of %d string of marix: ", i);
        int n = 0;
        while(n <= 0)
                n = input();
        printf("\n");
        *(a++) = n;
        *(array++) = createarray(&n);
    }
    array -= *N;
    a -= *N;
    return array;
}

int outputmatrix(int** a, int* b, int* n){
    for(int i = 0; i < *n; i++){
        outputarray(*(a++), (b++));
        printf("\n");
    }
    b -= *n;
    a -= *n;
    return 0;
}

float middlen(int* a, int* N){
    float SUM = 0;
    for(int i = 0; i < *N; i++)
        SUM = SUM + numlen(*(a++));
    a -= *N;
    return (SUM/(float)*N);
}

float middlenum(int* a, int* N){
    float SUM = 0;
    for(int i = 0; i < *N; i++)
        SUM = SUM + (float)*(a++);
    a -= *N;
    return(SUM/(float)*N);
}

float numlen(int a){
    float n = 0;
    while(a != 0){
        a = a/10;
        n = n + 1;
    }
    return n;
}

int* array_OTBOR_middlen(int* A, int* N, int* p){
    int* B = (int*)calloc(*N, sizeof(int));
    int n = 0, k = 0;
    float mdlen = middlen(A, N);
    for(int i = 0; i < *N; i++, A++){
        if(numlen(*(A)) > mdlen){
            n++;
            *(B++) = *(A);
        }
        else
          k++;
    }
    B -= *N - k;
    A -= *N;
    *p = n;
    B = (int*)realloc(B, n * sizeof(int));
    return B;
}

int** matrix_OTBOR(int** A, int* sizes, int* N, int* new_sizes, int swit){
    int** B = (int**)malloc(*N * sizeof(int*));
    for(int i = 0; i < *N; i++){
        int k = 0;
        if(swit == 1)
            *(B++) = array_OTBOR_middlen(*(A++), (sizes + i), &k);
        if(swit == 2)
            *(B++) = array_OTBOR_midlenum(*(A++), (sizes + i), &k);
        if(swit == 3)
            *(B++) = array_OTBOR_3len(*(A++), (sizes + i), &k);
        *(new_sizes + i) = k;
    }
    A -= *N;
    B -= *N;
    return B;
}

void freematrix(int** A, int* N){
    for(int i = 0; i < *N; i++){
        free(*(A++));
        }
    A -=*N;
    free(A);
}

int* array_OTBOR_midlenum(int* A, int* N, int* p){
    int* B = (int*)calloc(*N, sizeof(int));
    int n = 0, k = 0;
    float mdnum = middlenum(A, N);
    for(int i = 0; i < *N; i++, A++){
        if((float)(*(A)) > mdnum){
            n++;
            *(B++) = *(A);
        }
        else
            k++;
    }
    B -= *N - k;
    A -= *N;
    *p = n;
    B = (int*)realloc(B, n * sizeof(int));
    return B;
}

int* array_OTBOR_3len(int* A, int* N, int* p){
    int* B = (int*)calloc(*N, sizeof(int));
    int n = 0, k = 0;
    for(int i = 0; i < *N; i++, A++){
        if(numlen((*(A))) == 3){
            n++;
            *(B++) = *(A);
        }
        else
            k++;
    }
    B -= *N - k;
    A -= *N;
    *p = n;
    B = (int*)realloc(B, n * sizeof(int));
    return B;
}