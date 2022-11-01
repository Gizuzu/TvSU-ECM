#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include "Database.h"

Database::Database()
{
	index_ = -1;
	size_ = 10;
	workers_ = new Worker[size_];
}

Database::Database(int size)
{
	index_ = -1;
	size_ = size;
	workers_ = new Worker[size_];
}

Database::Database(const Database& object)
{
	index_ = object.index_;
	size_ = object.size_;
	workers_ = new Worker[size_];

	for (int i = 0; i <= index_; i++)
		workers_[i] = object.workers_[i];
}

Database::~Database()
{
	delete[] workers_;
}

int Database::LoadFromFile(char* filename)
{
	FILE* file;

	if ((file = fopen(filename, "r")) == NULL) return 1;

	char name[30], inic[5], born_date[5], hire_date[11];
	float salary;

	while (fscanf(file, "%s%s%s%f%s", name, inic, born_date, &salary, hire_date) == 5)
	{
		strcat(name, " ");
		strcat(name, inic);

		Worker worker;
		worker.SetName(name);
		worker.SetBornDate(born_date);
		worker.SetSalary(salary);
		worker.SetHireDate(hire_date);
		if (index_ + 1 >= size_)
			Resize(size_ * 2);

		index_++;
		workers_[index_] = worker;
	}

	fclose(file);
	return 0;
}

void Database::Resize(int size)
{
	Worker* workers = new Worker[size];

	int i;
	for (i = 0; i < size && i < size_; i++)
		workers[i] = workers_[i];

	size_ = size;
	index_ = i-1;
	delete[] workers_;
	workers_ = workers;
}

void Database::Print()
{
	for (int i = 0; i <= index_; i++)
		workers_[i].Print();
}

// TODO: Fix weird bug
void Database::Add(Worker worker)
{
	if (index_ + 1 >= size_)
		Resize(size_ * 2);

	index_++;
	workers_[index_] = worker;
}

int Database::FindWorker(char* name)
{
	int index = -1;

	for (int i = 0; i <= index_; i++)
	{
		if (strcmp(workers_[i].GetName(), name) == 0)
		{
			index = i;
			break;
		}
	}

	return index;
}

int Database::Remove(char* name)
{
	int index;
	if ((index = FindWorker(name)) == -1)
		return 1;

	Worker* workers = new Worker[size_];

	int i, j = 0;
	for (i = 0; i < index; i++)
	{
		workers[j] = workers_[i];
		j++;
	}

	for (i = index + 1; i < index_; i++)
	{
		workers[j] = workers_[i];
		j++;
	}

	delete[] workers_;
	workers_ = workers;
	index_ = j-1;

	return 0;
}

int Database::Edit(char* name)
{
	int index;
	if ((index = FindWorker(name)) == -1)
		return 1;

	char name2[30], inic[5];
	float salary;

	workers_[index].Print();
	printf("Введите новое ФИО (0 0 чтобы не менять): ");
	scanf("%s%s", name2, inic);
	if (name2[0] != '0' && inic[0] != '0')
	{
		strcat(name2, " ");
		strcat(name2, inic);
		workers_[index].SetName(name2);
	}

	printf("Введите новую зар. плату (-1 чтобы не менять): ");
	scanf("%f", &salary);
	if (salary != -1)
	{
		workers_[index].SetSalary(salary);
	}

	return 0;
}