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
		printf("�������� ��������: ");
		scanf("%d", &choice);

		switch (choice)
		{
		case 1:
		{
			float vl, vr;
			printf("������� ����� (����� ������) --->\n");
			printf("1 �����: ");
			scanf("%f%f", &vl, &vr);
			Point a(vl, vr);

			printf("2 �����: ");
			scanf("%f%f", &vl, &vr);
			Point b(vl, vr);

			printf("3 �����: ");
			scanf("%f%f", &vl, &vr);
			Point c(vl, vr);

			Triangle T(a, b, c);
			
			triangles[count] = T;
			count++;
			printf("����������� ������!\n");
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
			printf("�������� ����������� �� ������������: ");
			for (int i = 0; i < count; i++)
			{
				printf("%s ", triangles[i].GetName());
			}
			printf("\n");
			int ch;
			scanf("%d", &ch);

			float area = triangles[ch - 1].GetArea();
			printf("������� ������������ ����� %f\n", area);
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
			printf("%s ����� ��������� ������� = %f\n", triangles[index].GetName(), areaMax);
			break;
		}
		case 5:
		{
			printf("�������� ����������� �� ������������: ");
			for (int i = 0; i < count; i++)
			{
				printf("%s ", triangles[i].GetName());
			}
			printf("\n");
			int ch;
			scanf("%d", &ch);

			float vx = 0, vy = 0;
			printf("����������� �� �����. 'x' �� ");
			scanf("%f", &vx);
			printf("����������� �� �����. 'y' �� ");
			scanf("%f", &vy);

			Point x(vx, vy);

			triangles[ch - 1].Move(x);

			printf("����������� ���������!\n");
			break;
		}
		case 6:
		{
			printf("�������� 1 �����������: ");
			for (int i = 0; i < count; i++)
			{
				printf("%s ", triangles[i].GetName());
			}
			printf("\n");
			int ch1;
			scanf("%d", &ch1);

			printf("�������� 2 �����������: ");
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
				printf("������ ����������� ������� �� ������\n");
			else
				printf("������ ����������� �� ������� �� ������\n");
			break;
		}
		case 7:
		{
			exit(0);
		}
		default:
			printf("������ �������� ���\n");
			break;
		}
		printf("\n");
	}

	return 0;
}

void showMenu()
{
	printf("<<< ���� >>>\n");
	printf("1. �������� ������������\n");
	printf("2. ������ �������������\n");
	printf("3. ���������� ������� ������������\n");
	printf("4. ���������� ������������ � ����. ��������\n");
	printf("5. ����������� ������������\n");
	printf("6. ������� �� ���� ����������� � ������\n");
	printf("7. �����\n");
}