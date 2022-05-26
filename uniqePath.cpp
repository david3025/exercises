#include <iostream>

#define COLOUMNS 3

void printMatrix(int m, int n, int matrix[][COLOUMNS])
{
    for (size_t i = 0; i < n; i++)
    {
        for (size_t j = 0; j < m; j++)
        {
            std::cout << matrix[i][j]<<",";
        }
        std::cout<<std::endl;
    }
}

void xorToMatrix(int c, int r, int matrix[][COLOUMNS])
{
    for (size_t i = 0; i < r; i++)
    {
        for (size_t j = 0; j < c; j++)
        {
            matrix[i][j] ^= 1;
        }
    }
}

void initEageOfMatrix(int c, int r, int matrix[][COLOUMNS])
{
    bool token = 0;
    for (size_t i = 0; i < c; i++)
    {
        if(matrix[0][i] == 1)
        {
            while(i < c)
            {
                matrix[0][i] = 1;
                i++;
            }
        }
    }
    for (size_t j = 0; j < r; j++)
    {
        if(matrix[j][0] == 1)
        {
            while(j < r)
            {
                matrix[j][0] = 1;
                j++;
            }
        }
    }
}

int uniqPath(int c, int r, int matrix[][COLOUMNS])
{
    initEageOfMatrix(c, r, matrix);
    xorToMatrix(c, r, matrix);
    
    for (size_t i = 1; i < r; i++)
    {
        for (size_t j = 1; j < c; j++)
        {
            if(matrix[i][j]) matrix[i][j] = matrix[i-1][j] + matrix[i][j-1];
        }
    }
    return matrix[r-1][c-1];
}

void uniqPathRecursiv(int c, int r, int j, int i, int m[][COLOUMNS], int &counter)
{
    if(m[i][j] == 2){
        counter++;
        return;
    }
    if(m[i][j] == 1)
    {
        return;
    }
    if(i < r-1) uniqPathRecursiv(c,r,j,i+1,m,counter);
    if(j < c-1) uniqPathRecursiv(c,r,j+1,i,m,counter);
}

int uniqPath2(int c, int r, int m[][COLOUMNS])
{
    int counter = 0;
    uniqPathRecursiv(c,r,0,0,m,counter);
    return counter;
}

int main()
{
    int matrix[][3] = {{0,0,0},{0,1,0},{0,0,0}};
    std::cout << uniqPath(3,3,matrix) <<" uniqe path";
    //std::cout << uniqPath2(3,3,matrix) <<" uniqe path";
    return 0;
}