#pragma once
#include <iostream>
#include "staff.h"
using namespace std;

class Employee: public Staff
{
public:
    Employee(int id, string name, int depId);
    void showInfo();
    string getDepname();
    virtual ~Employee();
};