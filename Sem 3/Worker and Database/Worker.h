#pragma once

class Worker
{
    char* name_;
    char born_date_[5];
    float salary_;
    char hire_date_[11];
public:
    Worker();
    ~Worker();
    void SetName(char* name);
    void SetBornDate(char* born_date);
    void SetSalary(float salary);
    void SetHireDate(char* hire_date);
    char* GetName();
    char* GetBornDate();
    float GetSalary();
    char* GetHireDate();
    void UseKeyboardInput();
    void Print();
    friend bool operator==(const Worker& worker1, const Worker& worker2);
    Worker& operator=(const Worker& worker);
};