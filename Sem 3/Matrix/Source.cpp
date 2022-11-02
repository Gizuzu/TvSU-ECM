#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include "Matrix.h"

void showMenu();

int main()
{
	setlocale(0, "ru");
	int n, m;

	printf("Введите размер 1 матрицы (строки столбцы): ");
	scanf("%d%d", &n, &m);
	Matrix matrix1(n, m);
	printf("Введите размер 2 матрицы (строки столбцы): ");
	scanf("%d%d", &n, &m);
	Matrix matrix2(n, m);

	matrix1.UseKeyboardInput();
	matrix2.UseKeyboardInput();

	int selected;
	do {
		showMenu();
		printf("Выберите действие: ");
		scanf("%d", &selected);

		switch (selected)
		{
		case 1: {
			matrix1.UseKeyboardInput();
			break;
		}
		case 2: {
			matrix1.UseKeyboardInput();
			break;
		}
		case 3: {
			(matrix1 * matrix2).Print();
			break;
		}
		case 4: {
			(matrix1 + matrix2).Print();
			break;
		}
		case 5: {
			(matrix1 - matrix2).Print();
			break;
		}
		case 6: {
			if (matrix1 == matrix2)
				printf("Матрицы равны\n");
			else
				printf("Матрицы неравны\n");
			break;
		}
		case 7: {
			if (matrix1 != matrix2)
				printf("Матрицы неравны\n");
			else
				printf("Матрицы равны\n");
			break;
		}
		case 8: {
			Matrix matrix = matrix1;
			matrix1.Print();
			matrix.Print();
			break;
		}
		case 9: {
			matrix1.Transpose();
			matrix1.Print();
			break;
		}
		case 10: {
			matrix1.Transpose();
			matrix1.Print();
			break;
		}
		case 11: {
			matrix1.Print();
			matrix2.Print();
			break;
		}
		case 12: {
			selected = -1;
			break;
		}
		default:
			break;
		}
	} while (selected != -1);

	return 0;
}

void showMenu()
{
	printf("<<< МЕНЮ МАТРИЦ >>>\n");
	printf("1. Ввести новую 1 матрицу\n");
	printf("2. Ввести новую 2 матрицу\n");
	printf("3. Перемножить матрицы\n");
	printf("4. Сложить матрицы\n");
	printf("5. Разность матриц\n");
	printf("6. Проверка равенства\n");
	printf("7. Проверка неравенства\n");
	printf("8. Проверка присваивания\n");
	printf("9. Транспонировать матрцу 1\n");
	printf("10. Транспонировать матрцу 2\n");
	printf("11. Показать матрицы\n");
	printf("12. Выйти\n");
}