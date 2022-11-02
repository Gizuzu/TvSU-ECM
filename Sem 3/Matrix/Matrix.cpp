#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include "Matrix.h"

using namespace std;

Matrix::Matrix(int n, int m)
{
	columns_ = m;
	rows_ = n;
	matrix_ = new float* [rows_];

	for (int i = 0; i < rows_; i++)
		matrix_[i] = new float[columns_];
}

Matrix::~Matrix()
{
	for (int i = 0; i < rows_; i++)
		delete[] matrix_[i];

	delete[] matrix_;
}

void Matrix::Transpose()
{
	float** matrix = new float* [columns_];

	for (int i = 0; i < rows_; i++)
		matrix[i] = new float[rows_];

	for (int i = 0; i < rows_; i++)
		for (int j = 0; j < columns_; j++)
			matrix[j][i] = matrix_[i][j];

	for (int i = 0; i < rows_; i++)
		delete[] matrix_[i];

	delete[] matrix_;
	matrix_ = matrix;
	int temp = rows_;
	rows_ = columns_;
	columns_ = temp;
}

void Matrix::UseKeyboardInput()
{
	float temp;
	for (int i = 0; i < rows_; i++)
	{
		printf("Введите %d строку: ", i+1);

		for (int j = 0; j < columns_; j++)
		{
			scanf("%f", &temp);
			matrix_[i][j] = temp;
		}
	}
}

void Matrix::Print()
{
	cout << rows_ << " " << columns_ << endl;
	for (int i = 0; i < rows_; i++)
	{
		printf("| ");
		for (int j = 0; j < columns_; j++)
			printf("%f ", matrix_[i][j]);
		printf("|\n");
	}
	printf("\n");
}
Matrix& operator*(const Matrix& matrix1, const Matrix& matrix2)
{
	if (matrix1.columns_ != matrix2.rows_)
		throw 1;

	Matrix* matrix = new Matrix(matrix1.rows_, matrix1.columns_);

	int sum;
	for (int j = 0; j < matrix1.rows_; j++)
	{
		for (int i = 0; i < matrix1.rows_; i++)
		{
			sum = 0;
			for (int r = 0; r < matrix1.columns_; r++)
			{
				sum += matrix1.matrix_[j][r] * matrix2.matrix_[r][i];
			}
			matrix->matrix_[j][i] = sum;
		}
	}

	return *matrix;
}
Matrix& operator+(const Matrix& matrix1, const Matrix& matrix2)
{
	if (matrix1.rows_ != matrix2.rows_) throw 1;
	if (matrix1.columns_ != matrix2.columns_) throw 1;

	Matrix* matrix = new Matrix(matrix1.rows_, matrix1.columns_);

	for (int i = 0; i < matrix1.rows_; i++)
		for (int j = 0; j < matrix1.columns_; j++)
			matrix->matrix_[i][j] = matrix1.matrix_[i][j] + matrix2.matrix_[i][j];

	return *matrix;
}
Matrix& Matrix::operator=(const Matrix& matrix)
{
	for (int i = 0; i < rows_; i++)
		delete[] matrix_[i];
	delete[] matrix_;

	rows_ = matrix.rows_;
	columns_ = matrix.columns_;
	matrix_ = new float* [rows_];
	for (int i = 0; i < rows_;i++)
	{
		matrix_[i] = new float[columns_];
		for (int j = 0; j < columns_; j++)
			matrix_[i][j] = matrix.matrix_[i][j];
	}

	return *this;
}
Matrix& operator-(const Matrix& matrix1, const Matrix& matrix2)
{
	if (matrix1.rows_ != matrix2.rows_) throw 1;
	if (matrix1.columns_ != matrix2.columns_) throw 1;

	Matrix* matrix = new Matrix(matrix1.rows_, matrix1.columns_);

	for (int i = 0; i < matrix1.rows_; i++)
		for (int j = 0; j < matrix1.columns_; j++)
			matrix->matrix_[i][j] = matrix1.matrix_[i][j] - matrix2.matrix_[i][j];

	return *matrix;
}
bool operator==(const Matrix& matrix1, const Matrix& matrix2)
{
	if (matrix1.rows_ != matrix2.rows_) return false;
	if (matrix1.columns_ != matrix2.columns_) return false;

	for (int i = 0; i < matrix1.rows_; i++)
		for (int j = 0; j < matrix1.columns_; j++)
			if (matrix1.matrix_[i][j] != matrix2.matrix_[i][j])
				return false;

	return true;
}
bool operator!=(const Matrix& matrix1, const Matrix& matrix2)
{
	return !(matrix1 == matrix2);
}