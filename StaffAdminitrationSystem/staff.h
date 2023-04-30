#pragma once
#include <iostream>
#include <string>
using namespace std;

// virtual class don't need to be achieved
class Staff
{
public:
    virtual void showInfo() = 0;
    virtual string getDepname() = 0;
    virtual ~Staff(){};
    
    int m_id;
    string m_name;
    int m_depId;
};