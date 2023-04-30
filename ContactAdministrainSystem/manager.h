#pragma once
#include <iostream>
#include "staff.h"
using namespace std;

class Manager: public Staff
{
public:
    Manager(int id, string name, int depId);
    void showInfo();
    string getDepname();
    virtual ~Manager();
};