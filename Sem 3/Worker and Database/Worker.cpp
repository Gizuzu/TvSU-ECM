#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include "Worker.h"

Worker::Worker()
{
	name_ = new char[30];
	name_[0] = 0; 
	born_date_[0] = 0; 
	hire_date_[0] = 0; 
	salary_ = 0;
}

Worker::~Worker()
{
	delete[] name_;
}

void Worker::SetName(char* name)
{
	strcpy(name_, name);
}

void Worker::SetBornDate(char* born_date)
{
	strcpy(born_date_, born_date);
}

void Worker::SetHireDate(char* hire_date)
{
	strcpy(hire_date_, hire_date);
}

void Worker::SetSalary(float salary)
{
	salary_ = salary;
}

char* Worker::GetName()
{
	return name_;
}

char* Worker::GetBornDate()
{
	return born_date_;
}

char* Worker::GetHireDate()
{
	return hire_date_;
}

float Worker::GetSalary()
{
	return salary_;
}

void Worker::Print()
{
	printf("| %30s | %4s | %7.2f | %10s |\n", name_, born_date_, salary_, hire_date_);
}

bool operator==(const Worker& worker1, const Worker& worker2)
{
	return strcmp(worker1.name_, worker2.name_) == 0;
}

Worker& Worker::operator=(const Worker& worker)
{
	strcpy(name_, worker.name_);
	strcpy(born_date_, worker.born_date_);
	strcpy(hire_date_, worker.hire_date_);
	salary_ = worker.salary_;

	return *this;
}

void Worker::UseKeyboardInput()
{
	char inic[5];

	printf("Введите ФИО: ");
	scanf("%s%s", name_, inic);
	strcat(name_, " ");
	strcat(name_, inic);
	printf("Введите год рождения: ");
	scanf("%s", born_date_);
	printf("Введите зар. плату");
	scanf("%f", &salary_);
	printf("Введите дату поступления на работу: ");
	scanf("%s", hire_date_);
}