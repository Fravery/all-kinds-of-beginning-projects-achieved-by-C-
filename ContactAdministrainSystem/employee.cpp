#include "employee.h"

Employee::Employee(int id, string name, int depId){
    this->m_id = id;
    this->m_name = name;
    this->m_depId = depId;
}

void Employee::showInfo()
{
    cout << "employee ID: " << this->m_id << "\temployee name: " 
    << this->m_name << "\temployee depID" << this->m_depId << endl;
}


string Employee::getDepname()
{
    return string("employee");
};

Employee::~Employee(){};