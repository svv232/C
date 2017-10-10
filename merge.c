#include <stdlib.h>
#include <stdio.h>

void merge(int array1[], int array2[],const int size1, const int size2,int* merged){
    int c1 = 0, c2 = 0;
    while ((c1+c2) != (size1+size2)){
        while ((array1[c1] < array2[c2]) && (c1 < size1))
        { merged[c1+c2] = array1[c1++];}
        while ((array2[c2] < array1[c1]) && (c2 < size2))
        { merged[c1+c2] = array2[c2++];}
        if (c2 == size2){merged[c1+c2] = array1[c1++];}
        else if (c1 == size1){ merged[c1+c2] = array1[c1++];}
    }
}

void display(int* const array, const int size){
    for (size_t i = 0; i < size; i++)
        printf("%d ",array[i]);
    printf("\n");
}
    
void main(){
    int array1[] = {4,6,8,12,16,19,21,89,111};
    int array2[] = {17,27,29,32,35,43,76};
    int merged[16];
    merge(array1,array2,9,7,merged);
    display(merged, 16);
}
