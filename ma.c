//
// Created by 通 on 2022/10/28.
//
#include "ma.h"
#include<stdlib.h>
#include<stdio.h>
void createMatrix(struct Matrix *matrix,int rows,int cols){
    if(matrix==NULL){//好像只有指针类型能判断是否为null，所以参数只检查指针类型
        printf("Invalid pointer\n");
        return;
    }
    matrix->rows=rows;
    matrix->cols=cols;
    matrix->data=(float**)malloc(matrix->rows*sizeof(float *));
    for (int i = 0; i < rows; ++i) {
        matrix->data[i]=(float*)malloc(matrix->cols*sizeof(float *));
    }
    for (int i = 0; i < rows; ++i) {
        for (int r = 0; r < cols; ++r) {
            matrix->data[i][r]=0.0f;
        }
    }
}

void createMatrix_set(struct Matrix *matrix,int rows,int cols){//手动赋值
    matrix->rows=rows;
    matrix->cols=cols;
    matrix->data=(float**)malloc(matrix->rows*sizeof(float *));
    for (int i = 0; i < rows; ++i) {
        matrix->data[i]=(float*)malloc(matrix->cols*sizeof(float *));
    }
    for (int i = 0; i < rows; ++i) {
        for (int r = 0; r < cols; ++r) {
            printf("(%d,%d):",i,r);
            scanf("%f", &matrix->data[i][r]);
        }
    }
}


void deleteMatrix(struct Matrix *matrix,int rows,int cols){
    if(matrix==NULL){
        printf("Invalid pointer\n");
        return;
    }
    for (int i = 0; i < rows; ++i) {
        free(matrix->data[i]);
    }
    free(matrix->data);
    printf("delete successfully\n");
}

void copyMatrix(struct Matrix *matrix_copy,struct Matrix *matrix,int rows,int cols){
    if(matrix_copy==NULL){
        printf("Invalid pointer\n");
        return;
    }
    if(matrix==NULL){
        printf("Invalid pointer\n");
        return;
    }
    for (int i = 0; i < rows; ++i) {
        for (int r = 0; r < cols; ++r) {
            matrix_copy->data[i][r]=matrix->data[i][r];
        }
    }
}

void addMatrix(struct Matrix *matrix_sum,struct Matrix *matrix1,struct Matrix *matrix2,int rows,int cols){
    if(matrix_sum==NULL){
        printf("Invalid pointer\n");
        return;
    }
    if(matrix1==NULL){
        printf("Invalid pointer\n");
        return;
    }
    if(matrix2==NULL){
        printf("Invalid pointer\n");
        return;
    }
    for (int i = 0; i < rows; ++i) {
        for (int r = 0; r < cols; ++r) {
            matrix_sum->data[i][r]=matrix1->data[i][r]+matrix2->data[i][r];
        }
    }
}

void subtractMatrix(struct Matrix *matrix_subtract,struct Matrix *matrix1,struct Matrix *matrix2,int rows,int cols){//1-2
    if(matrix_subtract==NULL){
        printf("Invalid pointer\n");
        return;
    }
    if(matrix1==NULL){
        printf("Invalid pointer\n");
        return;
    }
    if(matrix2==NULL){
        printf("Invalid pointer\n");
        return;
    }
    for (int i = 0; i < rows; ++i) {
        for (int r = 0; r < cols; ++r) {
            matrix_subtract->data[i][r]=matrix1->data[i][r]-matrix2->data[i][r];
        }
    }
}

void add_scalar(struct Matrix *matrix,float scalar,int rows,int cols){
    if(matrix==NULL){
        printf("Invalid pointer\n");
        return;
    }
    for (int i = 0; i < rows; ++i) {
        for (int r = 0; r < cols; ++r) {
            matrix->data[i][r]=matrix->data[i][r]+scalar;
        }
    }
}

void subtract_scalar(struct Matrix *matrix,const float scalar,int rows,int cols){
    if(matrix==NULL){
        printf("Invalid pointer\n");
        return;
    }
    for (int i = 0; i < rows; ++i) {
        for (int r = 0; r < cols; ++r) {
            matrix->data[i][r]=matrix->data[i][r]-scalar;
        }
    }
}

void multiply_scalar(struct Matrix *matrix,float  scalar,int rows,int cols){
    if(matrix==NULL){
        printf("Invalid pointer\n");
        return;
    }
    for (int i = 0; i < rows; ++i) {
        for (int r = 0; r < cols; ++r) {
            matrix->data[i][r]=matrix->data[i][r]*scalar;
        }
    }
}

void multiplyMatrix(struct Matrix *matrix_mul,struct Matrix *matrix1,struct Matrix *matrix2,int rows1,int cols1,int rows2,int cols2,int rows_mul,int cols_mul){
    if(matrix_mul==NULL){
        printf("Invalid pointer\n");
        return;
    }
    if(matrix1==NULL){
        printf("Invalid pointer\n");
        return;
    }
    if(matrix2==NULL){
        printf("Invalid pointer\n");
        return;
    }
    if(cols1!=rows2 |rows1!=rows_mul|cols2!=cols_mul){
        printf("matrix A's column doesn't equal to matrix B's row");
        return;
    }
    for(int i = 0; i < rows1; i++){
        for(int j = 0; j < cols2; j++){
            for(int k = 0; k < rows2; k++){
                matrix_mul->data[i][j] += matrix1->data[i][k] * matrix2->data[k][j];
            }
        }
    }
}

float find_min(struct Matrix *matrix,int rows,int cols){
    if(matrix==NULL){
        printf("Invalid pointer\n");
        return 0.0f;
    }
    float a=matrix->data[0][0];
    for (int i = 0; i < rows; ++i) {
        for (int r = 0; r < cols; ++r) {
            if(matrix->data[i][r]<a){
                a=matrix->data[i][r];
            }
        }
    }
    return a;
};

float find_max(struct Matrix *matrix,int rows,int cols){
    if(matrix==NULL){
        printf("Invalid pointer\n");
        return 0.0f;
    }
    float a=matrix->data[0][0];
    for (int i = 0; i < rows; ++i) {
        for (int r = 0; r < cols; ++r) {
            if(matrix->data[i][r]>a){
                a=matrix->data[i][r];
            }
        }
    }
    return a;
};

void print_matrix(struct Matrix *matrix,int rows,int cols){
    if(matrix==NULL){//统一保留两位小数
        printf("Invalid pointer\n");
        return;
    }
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            printf("%.2f ",matrix->data[i][j]);
            if(j==cols-1){
                printf("\n");
            }
        }
    }
}

