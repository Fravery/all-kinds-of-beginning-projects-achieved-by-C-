#include "manager.h"

Manager::Manager(int id, string name, int depId)
{
    this->m_id = id;
    this->m_name = name;
    this->m_depId = depId;
}

void Manager::showInfo()
{
    cout << "manager ID: " << this->m_id << "\tmanager name: " 
    << this->m_name << "\tmanager depID: " << this->m_depId << endl;
}

string Manager::getDepname()
{
    return string("manager");
};

Manager::~Manager(){}