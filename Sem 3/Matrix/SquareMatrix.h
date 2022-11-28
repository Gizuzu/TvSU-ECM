#include "Matrix.h"

class SquareMatrix : public Matrix
{
    SquareMatrix(int n = 3): Matrix(n, n) {}
    double ComputeDeterminant();
    void Step(int step);

    SquareMatrix operator=(Matrix& matrix);
};