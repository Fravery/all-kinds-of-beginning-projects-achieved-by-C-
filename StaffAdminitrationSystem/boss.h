#pragma once
#include <iostream>
#include "staff.h"
using namespace std;

class Boss: public Staff
{
public:
    Boss(int id, string name, int depId);
    void showInfo();
    string getDepname();
    virtual ~Boss();
};