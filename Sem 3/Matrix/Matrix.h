#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>

using namespace std;

class Matrix
{
protected:
	float** matrix_;
	int rows_, columns_;
public:
	Matrix(int n = 3, int m = 4);
	~Matrix();
	void Transpose();
	void UseKeyboardInput();
	void Print();
	void RandomFill();
	int GetRows();
	int GetColumns();

	Matrix operator=(const Matrix& matrix);
	float* operator[](int index);
	friend Matrix operator*(const Matrix& matrix1, const Matrix& matrix2);
	friend Matrix operator+(const Matrix& matrix1, const Matrix& matrix2);
	friend Matrix operator-(const Matrix& matrix1, const Matrix& matrix2);
	friend bool operator==(const Matrix& matrix1, const Matrix& matrix2);
	friend bool operator!=(const Matrix& matrix1, const Matrix& matrix2);
	friend ostream& operator<<(ostream& stream, const Matrix& matrix);
	friend istream& operator>>(istream& stream, const Matrix& matrix);
};