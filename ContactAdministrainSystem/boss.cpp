#include "boss.h"

Boss::Boss(int id, string name, int depId){
    this->m_id = id;
    this->m_name = name;
    this->m_depId = depId;
}

void Boss::showInfo()
{
    cout << "boss ID: " << this->m_id << "\tboss name: " 
    << this->m_name << "\tboss depID: " << this->m_depId << endl;
}


string Boss::getDepname()
{
    return string("boss");
}

Boss::~Boss(){};