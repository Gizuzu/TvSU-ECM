#pragma once

class Matrix
{
	float** matrix_;
	int rows_, columns_;
public:
	Matrix(int n = 3, int m = 4);
	~Matrix();
	void Transpose();
	void UseKeyboardInput();
	void Print();

	Matrix& operator=(const Matrix& matrix);
	friend Matrix& operator*(const Matrix& matrix1, const Matrix& matrix2);
	friend Matrix& operator*(const Matrix& matrix1, const int num);
	friend Matrix& operator+(const Matrix& matrix1, const Matrix& matrix2);
	friend Matrix& operator-(const Matrix& matrix1, const Matrix& matrix2);
	friend bool operator==(const Matrix& matrix1, const Matrix& matrix2);
	friend bool operator!=(const Matrix& matrix1, const Matrix& matrix2);
};