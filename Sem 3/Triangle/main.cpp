#define _CRT_SECURE_NO_WARNINGS
#include "Triangle.h"
#include "Point.h"
#include <iostream>
#include <Windows.h>

void showMenu();

int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	int choice;
	int count = 0;

	Triangle* triangles = new Triangle[5];

	while (true)
	{
		showMenu();
		printf("Выберите действие: ");
		scanf("%d", &choice);

		switch (choice)
		{
		case 1:
		{
			float vl, vr;
			printf("Введите точки (через пробел) --->\n");
			printf("1 точка: ");
			scanf("%f%f", &vl, &vr);
			Point a(vl, vr);

			printf("2 точка: ");
			scanf("%f%f", &vl, &vr);
			Point b(vl, vr);

			printf("3 точка: ");
			scanf("%f%f", &vl, &vr);
			Point c(vl, vr);

			Triangle T(a, b, c);
			
			triangles[count] = T;
			count++;
			printf("Треугольник создан!\n");
			break;
		}
		case 2:
		{
			for (int i = 0; i < count; i++)
				triangles[i].Print();
			break;
		}
		case 3:
		{
			printf("Выберите треугольник из существующих: ");
			for (int i = 0; i < count; i++)
			{
				printf("%s ", triangles[i].GetName());
			}
			printf("\n");
			int ch;
			scanf("%d", &ch);

			float area = triangles[ch - 1].GetArea();
			printf("Площадь треугольника равна %f\n", area);
			break;
		}
		case 4:
		{
			float areaMax = 0;
			float areaTmp;
			int index;

			for (int i = 0; i < count; i++)
			{
				areaTmp = triangles[i].GetArea();

				if (areaTmp > areaMax)
				{
					areaMax = areaTmp;
					index = i;
				}
			}
			printf("%s имеет набольшую площадь = %f\n", triangles[index].GetName(), areaMax);
			break;
		}
		case 5:
		{
			printf("Выберите треугольник из существующих: ");
			for (int i = 0; i < count; i++)
			{
				printf("%s ", triangles[i].GetName());
			}
			printf("\n");
			int ch;
			scanf("%d", &ch);

			float vx = 0, vy = 0;
			printf("Переместить по коорд. 'x' на ");
			scanf("%f", &vx);
			printf("Переместить по коорд. 'y' на ");
			scanf("%f", &vy);

			Point x(vx, vy);

			triangles[ch - 1].Move(x);

			printf("Треугольник перемещён!\n");
			break;
		}
		case 6:
		{
			printf("Выберите 1 треугольник: ");
			for (int i = 0; i < count; i++)
			{
				printf("%s ", triangles[i].GetName());
			}
			printf("\n");
			int ch1;
			scanf("%d", &ch1);

			printf("Выберите 2 треугольник: ");
			for (int i = 0; i < count; i++)
			{
				if (i == ch1 - 1)
					continue;

				printf("%s ", triangles[i].GetName());
			}
			printf("\n");
			int ch2;
			scanf("%d", &ch2);

			if (triangles[ch1 - 1].isIncluded(triangles[ch2 - 1]))
				printf("Первый треугольник включен во второй\n");
			else
				printf("Первый треугольник не включен во второй\n");
			break;
		}
		case 7:
		{
			exit(0);
		}
		default:
			printf("Такого действия нет\n");
			break;
		}
		printf("\n");
	}

	return 0;
}

void showMenu()
{
	printf("<<< МЕНЮ >>>\n");
	printf("1. Создание треугольника\n");
	printf("2. Печать треугольников\n");
	printf("3. Вычисление площади треугольника\n");
	printf("4. Вычисление треугольника с макс. площадью\n");
	printf("5. Перемещение треугольника\n");
	printf("6. Включён ли один треугольник в другой\n");
	printf("7. Выход\n");
}