#include "SquareMatrix.h"

double SquareMatrix::ComputeDeterminant()
{
    double tmp;

    float** matrix = new float*[rows_];
    for (int i = 0; i < rows_; i++)
    {
        matrix[i] = new float[rows_];
        for (int j=0; j < rows_; j++)
            matrix[i][j] = matrix_[i][j];
    }

    for (int k = 0; k < rows_ - 1; k++) {
        for (int i = k + 1; i < rows_; i++) {
            tmp = -matrix[i][k] / matrix[k][k];
            for (int j = 0; j < rows_; j++) {
                matrix[i][j] += matrix[k][j] * tmp;
            }
        }
    }

    for (int i = 0; i < rows_; i++) {
        for (int j = 0; j < rows_; j++) {
            cout << fixed << matrix[i][j] << " ";
        }
        cout << endl;
    }

    double d = 1;
    for (int i = 0; i < rows_; i++) {
        d *= matrix[i][i];
    }

    for (int i = 0; i < rows_; i++)
        delete[] matrix[i];

    delete[] matrix;
    return d;
}

SquareMatrix SquareMatrix::operator=(Matrix& matrix)
{
    if (matrix.GetRows() != matrix.GetColumns()) return;

    for (int i = 0; i < rows_; i++)
        delete[] matrix_[i];
    delete[] matrix_;

    rows_ = matrix.GetRows(); columns_ = matrix.GetRows();

    matrix_ = new float*[matrix.GetRows()];
    for (int i = 0; i < rows_; i++)
    {
        matrix_[i] = new float[rows_];
        for (int j = 0; j < rows_; j++)
            matrix_[i][j] = matrix[i][j];
    }

    return *this;
}

void SquareMatrix::Step(int step)
{
    if (step <= 0) throw;

    Matrix temp(rows_, columns_);

    for (int i = 1; i < step; i++)
        temp = temp * temp;

    *this = temp;
}