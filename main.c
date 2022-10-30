#include <stdio.h>
#include<stdlib.h>
#include "ma.h"
int main() {
    struct Matrix *matrix1,*matrix2,*matrix3,*matrix4,*matrix5,*matrix6,*matrix7,*matrix8,*matrix9 ;

    //check createMatrix_set,createMatrix,deleteMatrix

    printf("check createMatrix_set,createMatrix,deleteMatrix\n");
    createMatrix_set((struct Matrix *) &matrix1, 2, 2);
    createMatrix((struct Matrix *) &matrix2,2,2);
    print_matrix((struct Matrix *) &matrix1, 2, 2);
    print_matrix((struct Matrix *) &matrix2, 2, 2);
    deleteMatrix((struct Matrix *) &matrix1, 2, 2);
    print_matrix((struct Matrix *) &matrix1, 2, 2);
    createMatrix(NULL,2,2);

    //check copyMatrix
    printf("check copyMatrix\n");
    createMatrix_set((struct Matrix *) &matrix3, 2, 2);
    createMatrix((struct Matrix *) &matrix4,2,2);
    copyMatrix((struct Matrix *) &matrix4,(struct Matrix *) &matrix3,2,2);
    print_matrix((struct Matrix *) &matrix4,2,2);

    //check calculate
    createMatrix_set((struct Matrix *) &matrix5, 2, 2);
    createMatrix_set((struct Matrix *) &matrix6, 2, 2);
    createMatrix((struct Matrix *) &matrix7, 2, 2);
    addMatrix((struct Matrix *) &matrix7,(struct Matrix *) &matrix5,(struct Matrix *) &matrix6,2,2);
    print_matrix((struct Matrix *) &matrix7,2,2);
    subtractMatrix((struct Matrix *) &matrix7,(struct Matrix *) &matrix5,(struct Matrix *) &matrix6,2,2);
    print_matrix((struct Matrix *) &matrix7,2,2);
    multiplyMatrix((struct Matrix *) &matrix7,(struct Matrix *) &matrix5,(struct Matrix *) &matrix6,2,2,2,2,2,2);
    print_matrix((struct Matrix *) &matrix7,2,2);

    //check calculate with scalar
    createMatrix((struct Matrix *) &matrix8, 2, 2);
    add_scalar((struct Matrix *) &matrix8,2.0,2,2);
    print_matrix((struct Matrix *) &matrix8,2,2);
    subtract_scalar((struct Matrix *) &matrix8,1.0,2,2);
    print_matrix((struct Matrix *) &matrix8,2,2);
    multiply_scalar((struct Matrix *) &matrix8,3.0,2,2);
    print_matrix((struct Matrix *) &matrix8,2,2);

    //check find min,max
    createMatrix_set((struct Matrix *) &matrix9, 3, 4);
    printf("%.2f\n",find_max((struct Matrix *) &matrix9, 3, 4));
    printf("%.2f\n",find_min((struct Matrix *) &matrix9, 3, 4));

    return 0;

}
