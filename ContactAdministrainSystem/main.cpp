#include <iostream>
#include <string>
#include <fstream>
#include "staffManger.h"
#include "staff.h"
#include "employee.h"
#include "manager.h"
#include "boss.h"
using namespace std;

int main(){
    StaffManger sm;
    int choice;

    while (true)
    {
        sm.showMenu();
        cout << "please input your choice: " << endl;
        cin >> choice;
        switch(choice)
        {
        case 0:
            sm.exitSystem();
            return 0;    
        case 1:
            sm.addEmp();
            cout << "Add successfully!" << endl;
            break;
        case 2:
            sm.showStaff();
            break;
        case 3:
            sm.delStaff();
            cout << "Delete successfully!" << endl;
            break;
        case 4:
            sm.modify();
            cout << "Modify successfully!" << endl;
            break;
        case 5:
            sm.search();
            break;
        case 6:
            sm.sort();
            cout << "Sort successfully!" << endl;
            break;
        case 7:
            sm.clear();
            break;
        default:
            break;
        }
    system("read -n1 -r -p 'Press any key to continue...'");
    system("clear");
    }
    
    return 0;
} 