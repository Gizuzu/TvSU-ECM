#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include "Database.h"

void showMenu();

int main()
{
	setlocale(0, "ru");
	int select;
	Database database;
	char filename[] = "Database.txt";

	do {
		showMenu();
		printf("Выберите пункт: ");
		scanf("%d", &select);

		switch (select)
		{
		case 1: {
			if (database.LoadFromFile(filename))
				printf("Произошла ошибка при загрузке файла\n");
			else
				printf("Успешно загружено\n");
			break;
		}
		case 2: {
			Worker worker;
			worker.UseKeyboardInput();
			database.Add(worker);
			printf("Успешно добавлено!\n");
			break;
		}
		case 3: {
			char name[30], inic[5];
			printf("Введите ФИО: ");
			scanf("%s%s", name, inic);
			strcat(name, " ");
			strcat(name, inic);

			if (database.Remove(name))
				printf("Запись не найдена\n");
			else
				printf("Успешно удалено\n");
			break;
		}
		case 4: {
			char name[30], inic[5];
			printf("Введите ФИО: ");
			scanf("%s%s", name, inic);
			strcat(name, " ");
			strcat(name, inic);

			if (database.Edit(name))
				printf("Запись не найдена\n");
			else
				printf("Успешно изменено\n");
			break;
		}
		case 5: database.Print(); break;
		case 6: {
			Database new_database = database;
			new_database.Print();
			break;
		}
		case 7: select = -1;
		default:
			break;
		}
	} while (select != -1);
	

	return 0;
}

void showMenu()
{
	printf("<<< МЕНЮ БАЗЫ ДАННЫХ >>>\n");
	printf("1. Загрузить из файла\n");
	printf("2. Добавить в базу\n");
	printf("3. Удалить из базы\n");
	printf("4. Изменить запись\n");
	printf("5. Печать базы\n");
	printf("6. Выполнить проверку копирования\n");
	printf("7. Выйти\n");
}