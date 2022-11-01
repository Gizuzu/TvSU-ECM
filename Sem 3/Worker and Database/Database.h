#pragma once
#include "Worker.h"

class Database
{
private:
	Worker* workers_;
	int index_, size_;
	void Resize(int size);
	int FindWorker(char* name);
public:
	Database();
	Database(int size);
	~Database();
	Database(const Database& object);
	int LoadFromFile(char* filename);
	void Print();
	void Add(Worker worker);
	int Remove(char* name);
	int Edit(char* name);

};