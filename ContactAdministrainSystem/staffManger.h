/*
interacting with users:
1 interacting menu
2 add/delete/search/modify staffs
3 write/read file
*/
#pragma once
#include <iostream>
#include "staff.h"
#include "employee.h"
#include "manager.h"
#include "boss.h"
#include <fstream>
#include <sstream>
#define FILENAME "empFile.txt"
using namespace std;

class StaffManger
{
public:
    StaffManger();

    void showMenu();
    void exitSystem();
    void addEmp();
    void save();
    int getEmpNum();
    void init_Emp();
    void showStaff();
    int isExist(int id);
    void delStaff();
    void modify();
    void search();
    void sort();
    void clear();

    bool isEmpty;
    int m_empNum;
    Staff ** m_empArr;

    ~StaffManger();
};