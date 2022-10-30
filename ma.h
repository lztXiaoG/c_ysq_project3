//
// Created by 通 on 2022/10/28.
//

#ifndef UNTITLED_MA_H
#define UNTITLED_MA_H

#endif //UNTITLED_MA_H
struct Matrix{
    int rows;
    int cols;
    float  ** data;
};
void createMatrix(struct Matrix *matrix,int rows,int cols);//默认全设为0
void createMatrix_set(struct Matrix *matrix,int rows,int cols);//手动设置值，需要键盘输入
void deleteMatrix(struct Matrix *matrix,int rows,int cols);
void copyMatrix(struct Matrix *matrix_copy,struct Matrix *matrix,int rows,int cols);
void addMatrix(struct Matrix *matrix_sum,struct Matrix *matrix1,struct Matrix *matrix2,int rows,int cols);
void subtractMatrix(struct Matrix *matrix_subtract,struct Matrix *matrix1,struct Matrix *matrix2,int rows,int cols);
void add_scalar(struct Matrix *matrix, float  scalar,int rows,int cols);
void subtract_scalar(struct Matrix *matrix,float  scalar,int rows,int cols);
void multiply_scalar(struct Matrix *matrix,float  scalar,int rows,int cols);
void multiplyMatrix(struct Matrix *matrix_mul,struct Matrix *matrix1,struct Matrix *matrix2,int rows1,int cols1,int rows2,int cols2,int rows_mul,int cols_mul);
float find_min(struct Matrix *matrix,int rows,int cols);
float find_max(struct Matrix *matrix,int rows,int cols);
void print_matrix(struct Matrix *matrix,int rows,int cols);//打印保留2位小数
