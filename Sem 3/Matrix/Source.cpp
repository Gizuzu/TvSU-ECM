#include "Matrix.h"

void runMenu();
void showMenu();
void runTest();

int main()
{
	setlocale(0, "ru");

	runMenu();

	return 0;
}

void runTest()
{
	Matrix A(3, 3), B(3, 3), C(3, 3), D;

	A.RandomFill(); B.RandomFill(), C.RandomFill();
	cout << "A:\n" << A << "B:\n" << B << "C:" << C << endl;
	cout << "A + B" << endl;
	(A + B).Print();
	cout << "C*(A+B) = D" << endl;
	(C * (A + B)).Print();
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

void runMenu()
{
	int n, m;

	printf("Введите размер 1 матрицы (строки столбцы): ");
	scanf("%d%d", &n, &m);
	Matrix matrix1(n, m);
	printf("Введите размер 2 матрицы (строки столбцы): ");
	scanf("%d%d", &n, &m);
	Matrix matrix2(n, m);

	cin >> matrix1 >> matrix2;

	int selected;
	do {
		showMenu();
		printf("Выберите действие: ");
		scanf("%d", &selected);

		switch (selected)
		{
		case 1: {
			cin >> matrix1;
			break;
		}
		case 2: {
			cin >> matrix2;
			break;
		}
		case 3: {
			try {
				cout << (matrix1 * matrix2) << endl;
			} catch (int e) {
				if (e == 1)
					cout << "Невозможно выполнить операцию: количество строк второй матрицы не равно количеству столбцов 1 матрицы" << endl;
			}
			break;
		}
		case 4: {
			try {
				cout << (matrix1 + matrix2) << endl;
			} catch (int e) {
				if (e == 1)
					cout << "Невозможно выполнить операцию: количество строк не равно" << endl;
				else if (e == 2)
					cout << "Невозможно выполнить операцию: количество столбцов не равно" << endl;
			}
			break;
		}
		case 5: {
			try {
				cout << (matrix1 - matrix2) << endl;
			} catch (int e) {
				if (e == 1)
					cout << "Невозможно выполнить операцию: количество строк не равно" << endl;
				else if (e == 2)
					cout << "Невозможно выполнить операцию: количество столбцов не равно" << endl;
			}
			break;
		}
		case 6: {matrix1.Print();
			matrix2.Print();
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
			cout << matrix1 << endl << matrix << endl;
			break;
		}
		case 9: {
			matrix1.Transpose();
			cout << matrix1 << endl;
			break;
		}
		case 10: {
			matrix1.Transpose();
			cout << matrix1;
			break;
		}
		case 11: {
			cout << matrix1 << endl << matrix2 << endl;
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
}